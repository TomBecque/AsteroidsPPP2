#ifndef ASTEROID_H
#define ASTEROID_H
#include "rigidbodies.h"

class Asteroid : public RigidBodies
{
public:
  Asteroid(const Vec4& _pos,
           const Vec4& _colour,
           const Vec4& _size,
           float _radius)
    : RigidBodies(_pos, _colour, _size), m_radius(_radius)
  {;}

  void destroy();
  void split();
  void draw() const;

private:
  float m_radius;

};

#endif // ASTEROID_H
