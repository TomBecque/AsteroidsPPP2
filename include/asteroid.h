#ifndef ASTEROID_H
#define ASTEROID_H
#include "rigidbodies.h"

class Asteroid : public RigidBodies
{
public:
  Asteroid(const Vec4& _pos,
           const Vec4& _colour,
           const Vec4& _size,
           const Vec4& _vecMin,
           const Vec4& _vecMax,
           float _radius,
           Vec4 _dest)
    : RigidBodies(_pos, _colour, _size, _vecMin, _vecMax), m_radius(_radius), m_dest(_dest)
  {;}

  void destroy();
  void split();
  void draw();

private:
  float m_radius;
  Vec4 m_dest;


};

#endif // ASTEROID_H
