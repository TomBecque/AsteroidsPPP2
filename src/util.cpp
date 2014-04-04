#include "util.h"
#include <cstdlib>
/*namespace*/ /*utils {*/

float util::floatRand(float a)
{
  return (float)rand()/(float)(RAND_MAX/a);
}

float util::floatRandRange(float _min, float _max)
{
//    float random = ((float) rand()) / (float) RAND_MAX;
//    float diff = b - a;
//    float r = random * diff;
//    return a + r;

return ((float)rand() / (float)RAND_MAX) * (_max - _min) + _min;
}


//}


