#ifndef RIGIDBODIES_H
#define RIGIDBODIES_H
#include "Vec4.h"
//#include "rocket.h"

#include <iostream>

class RigidBodies
{
public:
  RigidBodies(const Vec4& _pos,
              const Vec4& _colour,
              const Vec4& _size,
              const Vec4& _vecMin,
              const Vec4& _vecMax)
    : m_colour(_colour), m_size(_size), m_position(_pos),
      m_direction(Vec4(0,0,0)), m_speed(0.0f), m_time(0)
  {
    m_bodyBox.m_vecMax = _vecMax;
    m_bodyBox.m_vecMin = _vecMin;
  }

  typedef struct BBOX
  {
    Vec4 m_vecMax;
    Vec4 m_vecMin;
  } bBox;


  void drawSphere();
  bool checkCollision(const RigidBodies& _obstacle);
  Vec4 getPos() const { return m_position; }

protected:
  Vec4 m_vertArray;
  Vec4 m_colour;
  Vec4 m_size;
  Vec4 m_position;
  Vec4 m_direction;
  float m_speed;
  int m_time;
  bBox m_bodyBox;


  void update();
};

#endif // RIGIDBODIES_H
