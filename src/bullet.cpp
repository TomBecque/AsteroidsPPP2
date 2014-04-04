#include "bullet.h"
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "rocket.h"


Bullet::~Bullet()
{

}

/**
 * @brief Bullet::draw
 *draws the bullet to the screen
 */

void Bullet::draw()
{

  glPushMatrix();
    m_colour.colourGL();
    m_position.translateGL();
    GLFunctions::cube( 0.2f, 0.2f, 0.2f );
  glPopMatrix();

  update();
}

/**
 * @brief Bullet::update
 *makes the bullet move in the direction the rocket is facing
 */

void Bullet::update()
{

  RigidBodies::update();
  m_position = m_offset + (m_destination*m_time*5);

}
