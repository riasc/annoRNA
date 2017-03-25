#include <string> 
class gff 
{
  public:
    void setSeqid(std::string s);
    
  private:
    std::string seqid;
    std::string source;
    std::string type;
    int start;
    int end;
    float score;	
};


