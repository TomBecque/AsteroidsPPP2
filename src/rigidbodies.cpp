#include "rigidbodies.h"
#include "GLFunctions.h"

void RigidBodies::drawSphere()
{

  Vec4 red(1,0,0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
    glTranslatef(0,1,0);
    red.colourGL();
    GLFunctions::sphere(0.5,30);
  glPopMatrix();
}

void RigidBodies::update()
{
  m_time++;
}


bool RigidBodies::checkCollision(const RigidBodies& _obstacle)
{
  return(m_bodyBox.m_vecMax.m_x > _obstacle.m_bodyBox.m_vecMin.m_x &&
         m_bodyBox.m_vecMin.m_x < _obstacle.m_bodyBox.m_vecMax.m_x &&
         m_bodyBox.m_vecMax.m_y > _obstacle.m_bodyBox.m_vecMin.m_y &&
         m_bodyBox.m_vecMin.m_y < _obstacle.m_bodyBox.m_vecMax.m_y &&
         m_bodyBox.m_vecMax.m_z > _obstacle.m_bodyBox.m_vecMin.m_z &&
         m_bodyBox.m_vecMin.m_z < _obstacle.m_bodyBox.m_vecMax.m_z);
}
