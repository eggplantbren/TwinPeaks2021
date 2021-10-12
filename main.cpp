#include "Example.h"
#include "Sampler.h"

using namespace TwinPeaks2021;

int main()
{
    Sampler<Example> sampler(Tools::RNG{});
    sampler.update();

    return 0;
}
