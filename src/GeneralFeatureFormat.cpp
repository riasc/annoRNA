#include "GeneralFeatureFormat.h"
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

GeneralFeatureFormat::GeneralFeatureFormat(){}
GeneralFeatureFormat::GeneralFeatureFormat( std::string inputfile )
{
  cout << "Parsing: " << inputfile << endl;
  ifstream infile(inputfile);
  string line;

  if(infile.is_open()) {
    while(getline(infile, line)) {
      cout << line << endl;
      vector<string> strs;
      boost::split(strs, line, boost::is_any_of("\t"));
      
      for(vector<string>::iterator pos = strs.begin(); pos != strs.end(); ++pos) {
        cout << *pos << endl; 
      
      }


      
      /*
      for(size_t i = 0; i < = strs.size(): i++) {
        //cout << strs[i] << endl; 
      }*/

      
    }
  
  }

}


GeneralFeatureFormat::~GeneralFeatureFormat(){}
/*void GeneralFeatureFormat::read_gff(std::string inputfile)
{
  std::cout << "bla" << std::endl;

}*/

  
  
