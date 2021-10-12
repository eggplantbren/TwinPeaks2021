#ifndef TwinPeaks2021_SamplerImpl_h
#define TwinPeaks2021_SamplerImpl_h

#include "Constants.h"
#include <fstream>
#include <iomanip>
#include <iostream>

namespace TwinPeaks2021
{

template<typename T>
Sampler<T>::Sampler(Tools::RNG&& _rng)
:rng(_rng)
,iteration(0)
{

    std::cout << "Initialising sampler." << std::endl;
    std::cout << "Generating " << Constants::NUM_PARTICLES << " particles ";
    std::cout << "from the prior..." << std::flush;

    for(int i=0; i<Constants::NUM_PARTICLES; ++i)
    {
        T t(rng);
        std::vector<double> ss = t.scalars();
        particles.emplace_back(std::move(t));
        scalars.emplace_back(std::move(ss));
    }

    std::cout << "done." << std::endl;
}


template<typename T>
void Sampler<T>::update()
{
    ++iteration;

    std::cout << "Iteration " << iteration << '.' << std::endl;

    // Compute UCCs
    // TODO: No need to fully recompute this each iteration
    std::cout << "Computing UCCs..." << std::flush;
    std::vector<int> uccs(Constants::NUM_PARTICLES, 0);
    for(int i=0; i<Constants::NUM_PARTICLES; ++i)
    {
        for(int j=0; j<Constants::NUM_PARTICLES; ++j)
        {
            if(j != i && all_greater(scalars[j], scalars[i]))
                ++uccs[i];
        }
    }
    int max_ucc = *max_element(uccs.begin(), uccs.end());

    // Particles with maximal UCC
    std::vector<int> candidates;
    for(int i=0; i<Constants::NUM_PARTICLES; ++i)
        if(uccs[i] == max_ucc)
            candidates.push_back(i);

    // Particle to kill
    int which = candidates[rng.rand_int(candidates.size())];
    context.add(scalars[which]);

    std::cout << "done." << std::endl;

    // CSV output
    std::cout << "Saving worst particle..." << std::flush;
    auto mode = std::ios::out;
    if(iteration > 1)
        mode = mode | std::ios::app;
    std::fstream fout("output.csv", mode);
    fout << std::setprecision(12);
    if(iteration == 1)
        fout << "iteration,logp,f,g\n";
    double logp = iteration*log(1.0 - 1.0/(Constants::NUM_PARTICLES+1))
                        - log(Constants::NUM_PARTICLES + 1);
    fout << iteration << ',' << logp << ',';
    fout << scalars[which][0] << ',' << scalars[which][1] << std::endl;
    fout.close();
    std::cout << "done." << std::endl;

    // Replace particle
    std::cout << "Generating new particle..." << std::flush;
    replace_particle(which);
    std::cout << "done." << std::endl;

    std::cout << std::endl;
}


template<typename T>
void Sampler<T>::replace_particle(int which)
{
    int copy;
    while(true)
    {
        copy = rng.rand_int(Constants::NUM_PARTICLES);
        if(copy != which)
            break;
    }


    int& k = which;
    for(int i=0; i<Constants::MCMC_STEPS; ++i)
    {
        T proposal = particles[k];
        double logh = proposal.perturb(rng);
        if(rng.rand() <= exp(logh))
        {
            std::vector<double> proposal_scalars = proposal.scalars();
            if(context.check(proposal_scalars))
            {
                particles[k] = proposal;
                scalars[k] = proposal_scalars;
            }
        }
    }

}


} // namespace

#endif
