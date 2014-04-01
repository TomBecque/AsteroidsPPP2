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
         const Vec4& _size,
         const Vec4& _vecMin,
         const Vec4& _vecMax)
    : RigidBodies(_pos, _colour, _size, _vecMin, _vecMax), m_offset(_offset)
  {;}

  ~Bullet();



  void draw();
  void destroy();
  Vec4 getBulletPosition();


private:


  Vec4 m_offset;   // Used to move the bullet's origin to the where it was fired
  Vec4 velocity;
};

#endif // BULLET_H
