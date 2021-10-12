#ifndef TwinPeaks2021_Sampler_h
#define TwinPeaks2021_Sampler_h

#include "Context.h"
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
        Context context;
        int iteration;

    public:
        Sampler() = delete;
        Sampler(Tools::RNG&& _rng);
        void update();
        void replace_particle(int which);
};

} // namespace

#endif

#include "SamplerImpl.h"
