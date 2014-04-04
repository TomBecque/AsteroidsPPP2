#include "asteroid.h"
#include "GLFunctions.h"
#include "util.h"


void Asteroid::draw()
{
  //m_position = (m_dest + (m_position * (0.02*m_time )));

//  std::cout<< "asteroid position"<< position;


  glPushMatrix();
    m_colour.colourGL();
    m_position.translateGL();
    GLFunctions::sphere(m_radius, 30);
  glPopMatrix();

  //RigidBodies::update();
  update();
}

void Asteroid::split()
{

}


Vec4 Asteroid::getAsteroidPos()
{
  return (m_dest + m_position * (0.001 * m_time ));
}

void Asteroid::update()
{
//  m_position = m_position + ((m_dest - m_position) * 0.001 * m_time);
  //m_position += /*(m_dest - m_position) * (0.001 * m_time )*/m_direction;
  RigidBodies::update();
}
