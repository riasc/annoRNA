#include <string>
#include <vector>
class GeneralFeatureFormat 
{
  public:
    GeneralFeatureFormat();
    GeneralFeatureFormat(std::string inputfile);
    ~GeneralFeatureFormat();

    void read_gff(std::string inputfile);

  private:
    std::vector<std::string> seqid;
    std::vector<std::string> source;
    std::vector<std::string> type;
    std::vector<unsigned int> start;
    std::vector<unsigned int> end; 
    std::vector<float> score;
    std::vector<std::string> strand;
    std::vector<std::string> attributes;
    
};
