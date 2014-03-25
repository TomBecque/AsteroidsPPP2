#include "rocket.h"
#include <iostream>
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "Vec4.h"
#include "math.h"
#include "bullet.h"

void Rocket::turn(Rocket::direction _move)
{
  int mouse_x=0, mouse_y=0;
  //SDL_GetMouseState(&mouse_x, &mouse_y);

  if(_move == RIGHT)
  {
    m_rotation == mouse_x ;
  }

  if(_move == LEFT)
  {
    m_rotation == -mouse_x;
  }

  if(_move == THRUST)
  {
    m_position.m_x -=0.1*sin((PI *m_rotation)/180);
    m_position.m_z -=0.1*cos((PI *m_rotation)/180);
  }

  std::cout << m_rotation << std::endl;
  std::cout << m_position.m_x << std::endl;
  std::cout << m_position.m_z << std::endl;

}


void Rocket::draw() const
{
  Vec4 red(1,0,0);

  glPushMatrix();
    glTranslatef(m_position.m_x, m_position.m_y, m_position.m_z);
    glRotatef(m_rotation, 0,1,0 );
    red.colourGL();
    GLFunctions::cube(0.5f,0.5f,0.5f);
  glPopMatrix();
}

void Rocket::fire()
{
  m_bullets.push_back(Bullet());
}



