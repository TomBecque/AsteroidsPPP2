#ifndef ASTEROID_H
#define ASTEROID_H
#include "rigidbodies.h"

class Asteroid : public RigidBodies
{
public:
  Asteroid(const Vec4& _pos,
           const Vec4& _colour,
           const Vec4& _size,
           float _radius,
           Vec4 _dest)
    : RigidBodies(_pos, _colour, _size, BT_ASTEROID), m_radius(_radius), m_dest(_dest)
  {
/*    m_bodyBox.m_vecMax = Vec4(_pos.m_x + (m_radius),//.m_x/2),
                          _pos.m_y + (m_radius),//.m_y/2),
                          _pos.m_z + (m_radius) );//.m_z/2) );

    m_bodyBox.m_vecMin = Vec4(_pos.m_x - (m_radius),//.m_x/2),
                          _pos.m_y - (m_radius),//.m_y/2),
                          _pos.m_z - (m_radius) );*///.m_z/2) );;
  }

  void destroy();
  void split();
  void draw();
  Vec4 getAsteroidPos();
  void update();

private:
  float m_radius;
  Vec4 m_dest;


};

#endif // ASTEROID_H
