#ifndef TwinPeaks2021_SamplerImpl_h
#define TwinPeaks2021_SamplerImpl_h

#include "Constants.h"
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

    std::cout << "done." << std::endl;


}


} // namespace

#endif
