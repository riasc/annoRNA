#include <boost/program_options.hpp>
#include "GeneralFeatureFormat.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std; // namespace for standard library
namespace po = boost::program_options;

int main(int argc, char *argv[])
{
  // declare supported options
  int opt;
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "display this help message")
    ("input-file", po::value<vector<string>>(), "input-file")  
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm); 

  if (vm.count("help"))
  {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("input-file"))
  {
    cout << vm["input-file"].as<vector<string> >() 
         << "\n"; 
  }

 

  


}

