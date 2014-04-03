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

void RigidBodies::update()
{
  m_time++;
}

//checks if one point of an object is inside another object and
//returns a true or false value

bool RigidBodies::checkCollision(RigidBodies* _obstacle)
{
  //std::cout << "body bounds"<< m_bodyBox.m_vecMax << "," << m_bodyBox.m_vecMin<<"\n" ;
 // std::cout << "obstacle bounds"<< _obstacle->m_bodyBox.m_vecMax << "," << _obstacle->m_bodyBox.m_vecMin<<"\n" ;

  return((m_bodyBox.m_vecMax.m_x > _obstacle->m_bodyBox.m_vecMin.m_x) &&
         (m_bodyBox.m_vecMin.m_x < _obstacle->m_bodyBox.m_vecMax.m_x) &&
         (m_bodyBox.m_vecMax.m_y > _obstacle->m_bodyBox.m_vecMin.m_y) &&
         (m_bodyBox.m_vecMin.m_y < _obstacle->m_bodyBox.m_vecMax.m_y) &&
         (m_bodyBox.m_vecMax.m_z > _obstacle->m_bodyBox.m_vecMin.m_z) &&
         (m_bodyBox.m_vecMin.m_z < _obstacle->m_bodyBox.m_vecMax.m_z));

}


