#ifndef MAP_H
#define MAP_H
#include "Vec4.h"

class Map
{
public:
  Map();
  void drawMap();

  Vec4 m_size;
  Vec4 m_camPosition;


};

#endif // MAP_H
