#include "bullet.h"
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "rocket.h"

//Bullet::Bullet(const Vec4 &_pos, const Vec4 &_colour, const Vec4 &_size)
//{

//}

void Bullet::draw()
{
  Vec4 position = m_position*(m_time/2);

  glPushMatrix();
    m_colour.colourGL();
    position.translateGL();
    GLFunctions::cube( 0.2f, 0.2f, 0.2f );
  glPopMatrix();

  update();

}

