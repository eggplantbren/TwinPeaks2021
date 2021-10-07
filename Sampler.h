#ifndef TwinPeaks2021_Sampler_h
#define TwinPeaks2021_Sampler_h

#include "Tools/RNG.hpp"

namespace TwinPeaks2021
{

template<typename T>
class Sampler
{
    private:
        Tools::RNG rng;
        std::vector<T> particles;
        std::vector<std::vector<double>> scalars;

    public:
        Sampler() = delete;
        Sampler(Tools::RNG&& _rng);

};

} // namespace

#endif

#include "SamplerImpl.h"
