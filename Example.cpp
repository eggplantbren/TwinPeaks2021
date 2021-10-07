#include "Example.h"
#include "Tools/Misc.hpp"

namespace TwinPeaks2021
{

Example::Example(Tools::RNG& rng)
:xs(SIZE)
{
    for(double& x: xs)
        x = rng.rand();
}

double Example::perturb(Tools::RNG& rng)
{
    int reps = static_cast<int>(pow(SIZE, rng.rand()));
    int k;
    for(int i=0; i<reps; ++i)
    {
        k = rng.rand_int(SIZE);
        xs[k] += rng.randh();
        Tools::wrap(xs[k]);
    }
    return 0.0;
}

std::vector<double> Example::scalars() const
{
    double f = 0.0;
    double g = 0.0;
    for(double x: xs)
    {
        f += -0.5*1E4*pow(x - 0.5, 2);
        g += -1E2*x;
    }
    return {f, g};
}

} // namespace
