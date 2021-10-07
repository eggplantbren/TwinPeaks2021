#include "Context.h"
#include <cassert>

namespace TwinPeaks2021
{

bool all_greater(const std::vector<double>& xs,
                 const std::vector<double>& ys)
{
    assert(xs.size() == ys.size());

    for(size_t i=0; i<xs.size(); ++i)
        if(xs[i] <= ys[i])
            return false;

    return true;
}

bool Context::ucc_is_zero(const std::vector<double>& point) const
{
    for(const auto& context_point: points)
    {
        if(all_greater(context_point, point))
            return false;
    }
    return true;
}

} // namespace
