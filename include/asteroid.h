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
           Vec4 _direction)
    : RigidBodies(_pos, _colour, _size, BT_ASTEROID), m_radius(_radius), m_direction(_direction)
  {
//    m_bodyBox.m_vecMax = Vec4((_pos.m_x + (m_radius) /2),
//                          (_pos.m_y + (m_radius) /2),
//                          (_pos.m_z + (m_radius) /2) );

//    m_bodyBox.m_vecMin = Vec4((_pos.m_x - (m_radius) /2),
//                          (_pos.m_y - (m_radius) /2),
//                          (_pos.m_z - (m_radius)  /2) );
            m_bodyBox.m_vecMax = Vec4(m_radius,m_radius,m_radius)/*Vec4(m_position.m_x + (_size.m_x/2),
                                     m_position.m_y + (_size.m_y/2),
                                     m_position.m_z + (_size.m_z/2) )*/;

            m_bodyBox.m_vecMin = Vec4(-m_radius,-m_radius,-m_radius)/*(m_position.m_x - (_size.m_x/2),
                                      m_position.m_y - (_size.m_y/2),
                                      m_position.m_z - (_size.m_z/2) )*/
  ;}

  void destroy();
  void split();
  void draw();
  Vec4 getAsteroidPos();
  void update();

private:
  float m_radius;
  Vec4 m_dest;
  Vec4 m_direction;


};

#endif // ASTEROID_H
