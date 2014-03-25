#ifndef ROCKET_H
#define ROCKET_H
#include "rigidbodies.h"
#include "Mat4.h"
#include "bullet.h"
#include <Vector>

class Rocket: public RigidBodies
{
public:
  typedef enum {
    LEFT,
    RIGHT,
    THRUST
  } direction;

  typedef enum {
    CWISE,
    ANTICWISE
  } rotation;



  Rocket(const Vec4& _pos,
         const Vec4& _colour,
         const Vec4& _size)
    : RigidBodies(_pos, _colour, _size), m_acceleration(0)
  {;}


  void turn(direction _move);
  void getInput();
  void destroy();
  void draw() const;
  void fire();



  float m_collisionRad;
  float m_rotation;




private:
  float m_acceleration;
  std::vector<Bullet> m_bullets;

};

#endif // ROCKET_H
