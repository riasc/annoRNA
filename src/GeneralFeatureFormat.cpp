#include <string>
#include <vector>

class GeneralFeatureFormat 
{
  public:
    void setSeqid(std::string seq);
    void setSource(std::string sou);
    void setType(std::string typ);
    void setStart(unsigned start);
    void setEnd(unsigned end);
    void setScore(float score);
    void setStrand(std::string strand);
    void setAttributes(std::string attributes);

    std::string getSeqid();
    std::string getSource();
    std::string getType();
    unsigned int getStart();
    unsigned int getEnd();
    float getScore();
    std::string getStrand();
    std::string getAttributes();

    // Default Constructor
    GeneralFeatureFormat(){}

    // Constructor
    GeneralFeatureFormat(
        std::string seqid_,
        std::string source_,
        std::string type_,
        unsigned int start_, 
        unsigned int end_, 
        float score_, 
        std::string strand_, 
        std::string attributes_)
      : 
      seqid(seqid_),
      source(source_),
      type(type_),
      start(start_),
      end(end_),
      score(score_),
      attributes(attributes_)
    {
      seqid = seqid_;
      source = source_;
      type = type_;
      start = start_;
      end = end_;
      score = score_;
      strand = strand_;
      attributes = attributes_;
    }
    ~GeneralFeatureFormat();
        
  private:
    std::string seqid;
    std::string source;
    std::string type;
    unsigned int start;
    unsigned int end; 
    float score;
    std::string strand;
    std::string attributes;
};

