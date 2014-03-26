#ifndef ROCKET_H
#define ROCKET_H
#include "rigidbodies.h"
#include "Mat4.h"
#include "bullet.h"
#include "vector"

class Rocket: public RigidBodies
{
public:
  typedef enum {
    TURN,
    THRUST
  } direction;



  Rocket(const Vec4& _pos,
         const Vec4& _colour,
         const Vec4& _size)
    : RigidBodies(_pos, _colour, _size), m_acceleration(0)
  {;}


  void move(direction _move, float _rotation);
  void getInput();
  void destroy();
  void draw();
  void fire();

  float m_collisionRad;
  float m_rotation;




private:
  float m_acceleration;
  std::vector<Bullet> m_bullets;

};

#endif // ROCKET_H
