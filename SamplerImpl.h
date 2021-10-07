#ifndef TwinPeaks2021_SamplerImpl_h
#define TwinPeaks2021_SamplerImpl_h

#include "Constants.h"
#include <iostream>

namespace TwinPeaks2021
{

template<typename T>
Sampler<T>::Sampler(Tools::RNG&& _rng)
:rng(_rng)
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



} // namespace

#endif
