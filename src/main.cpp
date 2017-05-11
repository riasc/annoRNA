#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include "GeneralFeatureFormat.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std; // namespace for standard library
namespace po = boost::program_options;
namespace fs = boost::filesystem;

// helper function
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
  return os;
}

int main(int argc, char *argv[]) {
     try {
               // declare supported options
              string config_file;
              vector<string> files;
              int opt;
              
              po::options_description generic("Generic Options");
              generic.add_options()
                ("version,v", "display version number") 
                ("help,h", "display this help message")
                ("config,c", po::value<string>(&config_file)->default_value("config.cfg"), "name of a configuration file") 
              ;

              // options that are allowed both on command line and in config file 
              po::options_description config("Configuration");
              config.add_options()
                ("input-folder,i",
                    po::value<string>(&config_file)->composing(), 
                    "folder of the annotations")
              ;

              // Hidden Options
              po::options_description hidden("Hidden Options");
              hidden.add_options()
                ("optimization,o", 
                    po::value<int>(&opt)->default_value(40), 
                    "optimization parameter")
              ;
              
              po::options_description cmdline_options;
              cmdline_options.add(generic).add(config).add(hidden);

              po::options_description config_file_options;
              config_file_options.add(config).add(hidden);

              po::options_description visible("Allowed Options");
              visible.add(generic).add(config);

              po::variables_map vm;
              store(po::command_line_parser(argc, argv).options(cmdline_options).run(), vm);
              notify(vm); 

              ifstream ifs(config_file.c_str());
              if(!ifs) {
                cout << "can not open config file: " << config_file << endl;
                return 0;
              }
              else {
                store(parse_config_file(ifs, config_file_options), vm);
                notify(vm);
              }

              if (vm.count("help")) {
                cout << visible << "\n";
                return 0;
              }

              if (vm.count("version")) {
                cout << "annoRNA, version 0.1\n";
                return 0;
              }

              if (vm.count("input-folder")) {
                cout  << "Directory of input files "  
                      << vm["input-folder"].as<string>()  << endl;
              }
              
              // list files in specified directory
              fs::path p = vm["input-folder"].as<string>();
              if(fs::exists(p)) {
                if(fs::is_regular_file(p)) { // check if path is a file 
                    cout << "include folder " << p.string() << " is a regular file" << endl;
                    files.push_back(p.string());
                } else if(fs::is_directory(p)) {
                    for(fs::directory_entry& x : fs::directory_iterator(p)) {
                      cout << "     " << x.path() << "\n";
                      files.push_back(x.path().string());
                    }
                  }
              }
              else {
                cout << p << " does not exist \n"; 
              }
             
              // create instance of gff
              GeneralFeatureFormat gff1(files[0]); 
        

      }
     catch(exception& e){
          cout << e.what() << endl;
          return 1;
     }
}

