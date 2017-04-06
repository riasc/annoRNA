#include "GeneralFeatureFormat.h"
#include <iostream>
#include <iterator>
#include <algorithm>

#include <boost/program_options.hpp>
namespace po = boost::program_options;
using namespace std; // easy  access on STL
int main()
{
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "display help message")
    ("annotation folder", po::value<vector<int>>(), "input folder")
  ;

}
