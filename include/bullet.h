#ifndef BULLET_H
#define BULLET_H
#include "rigidbodies.h"

class Bullet : public RigidBodies
{
public:
  Bullet(const Vec4& _pos,
         const Vec4& _colour,
         const Vec4& _size)
    : RigidBodies(_pos, _colour, _size)
  {;}
  void draw();
  void destroy();


private:
  Vec4 velocity;
};

#endif // BULLET_H
