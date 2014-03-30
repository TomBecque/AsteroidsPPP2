#include "rocket.h"
#include <iostream>
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "Vec4.h"
#include "math.h"
#include "bullet.h"
#include "SDL.h"

void Rocket::move(float _offset, float _rotation)
{
  m_position.m_x += _offset * sin((PI *m_rotation)/180);
  m_position.m_z += _offset * cos((PI *m_rotation)/180);

  m_rotation = 0.5*_rotation;

  std::cout << m_rotation     << std::endl;
  std::cout << m_position.m_x << std::endl;
  std::cout << m_position.m_z << std::endl;
}

void Rocket::draw()
{
  for(uint i=0;i<m_bullets.size();i++)
  {
    m_bullets[i].draw();
    std::cout << m_bullets[i].getPos();
  }

  glPushMatrix();
    m_position.translateGL();
    glRotatef(m_rotation, 0,1,0 );
    glColor3f(1,0,0);
    GLFunctions::cube(0.5f,0.5f,0.5f);
  glPopMatrix();


}

void Rocket::fire()
{
  Vec4 position((0.1*sin((PI *m_rotation)/180)),
                 0,
                 0.1*cos((PI *m_rotation)/180));



  Vec4 colour = Vec4(1.0f, 1.0f, 1.0f);
  Vec4 size = Vec4(0.2f, 0.2f, 0.2f);

  Bullet tmp(position, colour, size);

  m_bullets.push_back(tmp);
}


Vec4 Rocket::getPlayerPosition()
{
  return m_position;
}
