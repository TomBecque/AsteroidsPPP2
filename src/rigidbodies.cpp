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


bool RigidBodies::AABBtoAABB(const bBox &tBox1, const bBox &tBox2)
{
  return(tBox1.m_vecMax.m_x > tBox2.m_vecMin.m_x &&
         tBox1.m_vecMin.m_x < tBox2.m_vecMax.m_x &&
         tBox1.m_vecMax.m_y > tBox2.m_vecMin.m_y &&
         tBox1.m_vecMin.m_y < tBox2.m_vecMax.m_y &&
         tBox1.m_vecMax.m_z > tBox2.m_vecMin.m_z &&
         tBox1.m_vecMin.m_z < tBox2.m_vecMax.m_z);
}
