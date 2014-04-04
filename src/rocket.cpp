#include "rocket.h"
#include <iostream>
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "Vec4.h"
#include "math.h"
#include "bullet.h"
#include "SDL.h"

void Rocket::update(float _offset, float _rotation)
{
  m_rotation = 0.5 * _rotation;

  m_position.m_x += _offset * sin((PI * m_rotation)/180);
  m_position.m_z += _offset * cos((PI * m_rotation)/180);

//  RigidBodies::update();

//  std::cout << m_rotation     << std::endl;
//  std::cout << m_position.m_x << std::endl;
//  std::cout << m_position.m_z << std::endl;
}

void Rocket::draw()
{


  glPushMatrix();
    m_position.translateGL();
    glRotatef(m_rotation, 0,1,0 );
    glColor3f(1,0,0);
    GLFunctions::cube(0.5f,0.5f,0.5f);
  glPopMatrix();


}




Vec4 Rocket::getPlayerPosition()
{
  return m_position;
}    

