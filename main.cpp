#include "Example.h"
#include "Sampler.h"

using namespace TwinPeaks2021;

int main()
{
    Sampler<Example> sampler(Tools::RNG{});

    for(int i=0; i<100000; ++i)
        sampler.update();

    return 0;
}
