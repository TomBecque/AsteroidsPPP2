#ifndef RIGIDBODIES_H
#define RIGIDBODIES_H
#include "Vec4.h"
//#include "rocket.h"

#include <iostream>

class RigidBodies
{
public:
  typedef enum {
    BT_BULLET,
    BT_ASTEROID,
    BT_ROCKET
  } BodyType;
public:
  RigidBodies(const Vec4& _pos,
              const Vec4& _colour,
              const Vec4& _size,
              const BodyType &_type)
  : m_colour(_colour), m_size(_size), m_position(_pos),m_direction(Vec4(0,0,0)),m_speed(0.0f), m_time(0), m_type(_type)
  {
    m_bodyBox.m_vecMax = Vec4(_pos.m_x + (_size.m_x/2),
                          _pos.m_y + (_size.m_y/2),
                          _pos.m_z + (_size.m_z/2) );

    m_bodyBox.m_vecMin = Vec4(_pos.m_x - (_size.m_x/2),
                          _pos.m_y - (_size.m_y/2),
                          _pos.m_z - (_size.m_z/2) );
  }

  BodyType getType() {return m_type;}

  typedef struct BBOX
  {
    Vec4 m_vecMax;
    Vec4 m_vecMin;
  } bBox;

  virtual void draw() = 0;


  void drawSphere();
  bool checkCollision(RigidBodies *_obstacle);
  Vec4 getPos() const { return m_position; }

  Vec4 m_vertArray;
  Vec4 m_colour;
  Vec4 m_size;
  Vec4 m_position;
  Vec4 m_direction;
  float m_speed;
  int m_time;
  bBox m_bodyBox;

  BodyType m_type;

protected:




  void update();
};

#endif // RIGIDBODIES_H
