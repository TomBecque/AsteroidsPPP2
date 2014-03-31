#ifndef ROCKET_H
#define ROCKET_H
#include  <vector>
#include "Mat4.h"
#include "rigidbodies.h"
#include "bullet.h"

class Bullet;

class Rocket : public RigidBodies
{
public:
  typedef enum {
    TURN,
    THRUST
  } direction;

  Rocket(const Vec4& _pos,
         const Vec4& _colour,
         const Vec4& _size,
         const Vec4& _vecMin,
         const Vec4& _vecMax) :
     RigidBodies(_pos, _colour, _size, _vecMin, _vecMax), m_acceleration(0)
  {;}


  void move(float _offset, float _rotation);
  void getInput();
  void destroy();
  void draw();
  void fire();
  Vec4 getPlayerPosition();


private:
  //float m_bullets[16];
  float m_collisionRad;
  float m_rotation;
  float m_acceleration;
  std::vector<Bullet> m_bullets;

};

#endif // ROCKET_H
