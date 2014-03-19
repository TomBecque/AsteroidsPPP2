#ifndef ROCKET_H
#define ROCKET_H
#include "rigidbodies.h"
#include "Mat4.h"

class Rocket: public RigidBodies
{
public:
  typedef enum {
    LEFT,
    RIGHT
  } direction;

  Rocket(const Vec4& _pos,
         const Vec4& _colour,
         const Vec4& _size)
    : RigidBodies(_pos, _colour, _size), m_acceleration(0)
  {;}


  void strafe(direction _move);
  void rotate();
  void getInput();
  void destroy();


  float m_collisionRad;
  Mat4 m_rotation;



private:
  float m_acceleration;


};

#endif // ROCKET_H
