#include "asteroid.h"
#include "GLFunctions.h"
#include "util.h"


Asteroid:: ~Asteroid()
{;}



/**
 * @brief Asteroid::draw
 *draws the asteroid to the screen
 */
void Asteroid::draw()
{
//draws a brown sphere
  glPushMatrix();
    m_colour.colourGL();
    m_position.translateGL();
    GLFunctions::sphere(m_radius, 30);
  glPopMatrix();


  update();
}

/**
 * @brief Asteroid::update
 *updates the position so that the asteroid moves
 */


void Asteroid::update()
{
  m_position += m_direction;
}
