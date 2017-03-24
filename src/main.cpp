#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
//    typedef std::istream_iterator<int> in;

    std::vector<int> nums{1,2,3,4,5,6,7,8,9,0};
    auto print = [](const int& n) {std::cout << " " << n;};
    //std::for_each(nums.begin(),nums.end(),print);

}

