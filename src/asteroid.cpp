#include "asteroid.h"
#include "GLFunctions.h"

void Asteroid::draw()
{
  glPushMatrix();
    m_colour.colourGL();
    m_position.translateGL();
    GLFunctions::sphere(m_radius, 30);
  glPopMatrix();
}

void Asteroid::split()
{

}

