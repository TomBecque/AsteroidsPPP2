#ifndef BULLET_H
#define BULLET_H
#include "rigidbodies.h"
#include "rocket.h"



class Bullet : public RigidBodies
{
public:
  Bullet(const Vec4& _pos,
         const Vec4& _offset,
         const Vec4& _colour,
         const Vec4& _size)
    : RigidBodies(_pos, _colour, _size, BT_BULLET), m_offset(_offset)
  {    /*m_bodyBox.m_vecMax = Vec4(_pos.m_x + (_size.m_x/2),
                                 _pos.m_y + (_size.m_y/2),
                                 _pos.m_z + (_size.m_z/2) );

       m_bodyBox.m_vecMin = Vec4(_pos.m_x - (_size.m_x/2),
                                 _pos.m_y - (_size.m_y/2),
                                 _pos.m_z - (_size.m_z/2) )*/;}

//  virtual ~Bullet();

  void draw();
  void destroy();
  Vec4 getBulletPosition();
  void update();


private:
  Vec4 m_offset;   // Used to move the bullet's origin to the where it was fired
  Vec4 velocity;
};

#endif // BULLET_H
