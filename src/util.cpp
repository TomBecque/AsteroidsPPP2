#include "util.h"
#include <cstdlib>
namespace utils {

float floatRand(float a)
{
  return (float)rand()/(float)(RAND_MAX/a);
}

float floatRandRange(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


}


