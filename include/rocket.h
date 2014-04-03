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
         const Vec4& _size) :
     RigidBodies(_pos, _colour, _size, BT_ROCKET), m_acceleration(0)
  {    m_bodyBox.m_vecMax = Vec4(_pos.m_x + (_size.m_x/2),
                                 _pos.m_y + (_size.m_y/2),
                                 _pos.m_z + (_size.m_z/2) );

       m_bodyBox.m_vecMin = Vec4(_pos.m_x - (_size.m_x/2),
                                 _pos.m_y - (_size.m_y/2),
                                 _pos.m_z - (_size.m_z/2) );}


  void move(float _offset, float _rotation);
  void getInput();
  void destroy();
  void draw();
  void fire();
  Vec4 getPlayerPosition();
  std::vector<Bullet>& getBullets() {return m_bullets;}

  float m_collisionRad;
  float m_rotation;
  float m_acceleration;
  std::vector<Bullet> m_bullets;

private:




};

#endif // ROCKET_H
