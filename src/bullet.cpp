#include "bullet.h"
#include "rigidbodies.h"
#include "GLFunctions.h"
#include "rocket.h"

//Bullet::Bullet(const Vec4 &_pos, const Vec4 &_colour, const Vec4 &_size)
//{

//}

void Bullet::draw()
{
//  Vec4 position = m_offset + m_position + (m_offset - m_position) * m_time ;// + (( m_time));
//  Vec4 position = m_offset + ((m_position - m_offset)*0.1*m_time );


  glPushMatrix();

    m_colour.colourGL();
    m_position.translateGL();
    GLFunctions::cube( 0.2f, 0.2f, 0.2f );

  glPopMatrix();

  update();
}

//Bullet::~Bullet()
//{
//  //delete this;
//  std::cout<<"bullet dtor called";
//}

Vec4 Bullet::getBulletPosition()
{
  return m_position;
}

void Bullet::update()
{

//  Vec4 position = ( (0.1*sin((PI *_rotation)/180)),
//                  0,
//                 (0.1*cos((PI *_rotation)/180)) );

//  m_position = m_offset + (position * (m_time));

  RigidBodies::update();
  m_position = m_offset + (m_destination*m_time*3);//((m_position - m_offset)*0.1*m_time );

}
