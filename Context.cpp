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

void Context::add(const std::vector<double>& rectangle)
{
    for(auto it=rectangles.begin(); it != rectangles.end(); ++it)
    {
        if(all_greater(rectangle, *it))
            it = rectangles.erase(it);
    }

    rectangles.push_front(rectangle);
}

bool Context::check(const std::vector<double>& point) const
{
    for(auto it=rectangles.begin(); it != rectangles.end(); ++it)
    {
        if(all_greater(*it, point))
            return false;
    }
    return true;
}

} // namespace
