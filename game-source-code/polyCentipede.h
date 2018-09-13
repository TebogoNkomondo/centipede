#include "centipedeSegment.h"
#include <vector>
//A centipede must know its length
#define length_of_centipede 12

//A poly centipede is a centipede train
class polyCentipede
{
public:
    //A centipede train must know its length
    polyCentipede(int lengthOfCentipede);
    //Create a vector of centepede objects 
    vector<centipedeSegment> myCentipede2;
    
private:
    int centipedeLength;
};