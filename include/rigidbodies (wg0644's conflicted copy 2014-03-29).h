#ifndef RIGIDBODIES_H
#define RIGIDBODIES_H
#include "Vec4.h"

#include <string>

class RigidBodies

{
public:
  RigidBodies(const Vec4& _pos,
              const Vec4& _colour,
              const Vec4& _size)
    : m_colour(_colour), m_size(_size), m_position(_pos),
      m_direction(Vec4(0,0,0)), m_speed(0.0f), m_time(0)
  {
    std::cout << m_position;}

  void drawSphere();


protected:
  Vec4 m_vertArray;
  Vec4 m_colour;
  Vec4 m_size;
  Vec4 m_position;
  Vec4 m_direction;
  float m_speed;
  int m_time;

  void update();
};

#endif // RIGIDBODIES_H
