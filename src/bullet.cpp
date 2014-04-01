#include "bullet.h"
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "rocket.h"

//Bullet::Bullet(const Vec4 &_pos, const Vec4 &_colour, const Vec4 &_size)
//{

//}

void Bullet::draw()
{
  Vec4 position = m_offset + m_position*(3* m_time);


  glPushMatrix();
    m_colour.colourGL();
    position.translateGL();
    GLFunctions::cube( 0.2f, 0.2f, 0.2f );

  glPopMatrix();
  update();
}

Bullet::~Bullet()
{

}

Vec4 Bullet::getBulletPosition()
{
  return m_position;
}
