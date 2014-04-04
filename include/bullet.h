#ifndef BULLET_H
#define BULLET_H
#include "rigidbodies.h"
#include "rocket.h"

/**
 * @brief The Bullet class
 *This is the class which most of the information regarding the Bullets
 */

class Bullet : public RigidBodies
{
public:
  Bullet(const Vec4& _pos,
         const Vec4& _offset,
         const Vec4& _colour,
         const Vec4& _size,
         Vec4& _dest)
    : RigidBodies(_pos, _colour, _size, BT_BULLET),
      m_destination(_dest), m_offset(_offset)
  {
    //sets the max and min values of the bullet bbox to be half the size of the bullet

    m_bodyBox.m_vecMax = Vec4(_size.m_x / 2,
                              _size.m_y / 2,
                              _size.m_z / 2);

    m_bodyBox.m_vecMin = Vec4(-_size.m_x / 2,
                              -_size.m_y / 2,
                              -_size.m_z / 2 );
  }

  ~Bullet();
  void draw();
  void update();


private:
  Vec4 m_destination;
  Vec4 m_offset;   // Used to move the bullet's origin to the where it was fired
  Vec4 velocity;
};

#endif // BULLET_H
