#ifndef ASTEROID_H
#define ASTEROID_H
#include "rigidbodies.h"

class Asteroid : public RigidBodies
{
public:
  Asteroid(const Vec4& _pos,
           const Vec4& _colour,
           const Vec4& _size,
           Vec4 _direction,
           float _radius)
    : RigidBodies(_pos, _colour, _size, BT_ASTEROID), m_radius(_radius), m_direction(_direction)
  {
//sets the bbox max and min vector to be the radius or -radius of the asteroid
            m_bodyBox.m_vecMax = m_radius;

            m_bodyBox.m_vecMin = Vec4(-m_radius,-m_radius,-m_radius);
  }

  ~Asteroid();
  void draw();
  void update();

private:
  float m_radius;
  Vec4 m_dest;
  Vec4 m_direction;


};

#endif // ASTEROID_H
