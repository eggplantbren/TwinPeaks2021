#ifndef TwinPeaks2021_Context_h
#define TwinPeaks2021_Context_h

#include <list>
#include <vector>

namespace TwinPeaks2021
{

// Are all xs greater than the corresponding ys
bool all_greater(const std::vector<double>& xs,
                 const std::vector<double>& ys);


// Defines the target distribution
class Context
{
    private:
        std::list<std::vector<double>> rectangles;

    public:
        Context() = default;

        // Add a new rectangle (removing any redundant ones first)
        void add(const std::vector<double>& rectangle);
};


} // namespace

#endif
