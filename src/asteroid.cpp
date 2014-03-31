#include "asteroid.h"
#include "GLFunctions.h"
#include "util.h"

void Asteroid::draw()
{

  Vec4 position = (m_dest + m_position * (0.001 * m_time ));


  glPushMatrix();
    m_colour.colourGL();
    position.translateGL();
    GLFunctions::sphere(m_radius, 30);
  glPopMatrix();

  update();
}

void Asteroid::split()
{

}


