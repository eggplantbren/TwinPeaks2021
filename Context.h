#ifndef TwinPeaks2021_Context_h
#define TwinPeaks2021_Context_h

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
        std::vector<std::vector<double>> points;

    public:
        Context() = default;

        // Is the UCC of the given point zero?
        // Uses short circuiting.
        bool ucc_is_zero(const std::vector<double>& point) const;

};


} // namespace

#endif
