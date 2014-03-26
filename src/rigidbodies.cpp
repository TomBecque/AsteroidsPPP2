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
