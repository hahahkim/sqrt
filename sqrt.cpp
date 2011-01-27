#include <cassert>
#include <cmath>

template<int x,int c=99>
class const_sqrt
{
        public:
        static const double value =
        (const_sqrt<x, c-1>::value+x/const_sqrt<x,c-1>::value)/2;
};
template<int x>

class const_sqrt<x,1>
{
        public:
        static const double value = 1;
};

int main()
{
        assert(std::abs(const_sqrt<1>::value - std::sqrt(1)) < 0.000000001);
        assert(std::abs(const_sqrt<2>::value - std::sqrt(2)) < 0.000000001);
        assert(std::abs(const_sqrt<10>::value - std::sqrt(10)) < 0.000000001);
        assert(std::abs(const_sqrt<50>::value - std::sqrt(50)) < 0.000000001);
        assert(std::abs(const_sqrt<1235>::value - std::sqrt(1235)) < 0.000000001);
        return 0;
}
