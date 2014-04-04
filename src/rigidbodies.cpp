#include "rigidbodies.h"
#include "GLFunctions.h"

void RigidBodies::drawSphere()
{
  glPushMatrix();
    glTranslatef(0,1,0);
    m_colour.colourGL();
    GLFunctions::sphere(m_size.m_x,30);
  glPopMatrix();
}

void RigidBodies::update(float _offset, float _rotation)
{
  m_time++;
}

//checks if one point of an object is inside another object and
//returns a true or false value

/**
 * @brief RigidBodies::checkCollision
 * @param _obstacle The obstacle I'm testing
 * @return true if collision happened
 */
bool RigidBodies::checkCollision(RigidBodies* _obstacle)
{
//  std::cout << "body bounds"<< m_bodyBox.m_vecMax << "|" << m_bodyBox.m_vecMin<<"\n" ;
//  std::cout << "obstacle bounds"<< _obstacle->m_bodyBox.m_vecMax << "," << _obstacle->m_bodyBox.m_vecMin<<"\n" ;

  Vec4 min = m_bodyBox.m_vecMin + m_position;
  Vec4 max = m_bodyBox.m_vecMax + m_position;

  Vec4 other_min = _obstacle->m_bodyBox.m_vecMin + _obstacle->m_position;
  Vec4 other_max = _obstacle->m_bodyBox.m_vecMax + _obstacle->m_position;

//  std::cout<< "min"<< min ;
//  std::cout<<"max" << max ;
  return((max.m_x > other_min.m_x) &&
         (min.m_x < other_max.m_x) &&
         (max.m_y > other_min.m_y) &&
         (min.m_y < other_max.m_y) &&
         (max.m_z > other_min.m_z) &&
         (min.m_z < other_max.m_z));

}


