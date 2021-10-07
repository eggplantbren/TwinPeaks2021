#ifndef TwinPeaks2021_Example_h
#define TwinPeaks2021_Example_h

#include "Tools/RNG.hpp"
#include <vector>

namespace TwinPeaks2021
{

class Example
{
    private:
        static constexpr int SIZE = 20;
        std::vector<double> xs;

    public:
        Example() = delete;
        Example(Tools::RNG& rng);
        double perturb(Tools::RNG& rng);
        std::vector<double> scalars() const;
};


} // namespace

#endif
