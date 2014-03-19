#include "World.h"
#include "GLFunctions.h"
#include <cstdlib>

void World::draw() const
{
  Vec4 background(0.5f, 0.5f, 0.5f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  background.colourGL();

  glEnable (GL_DEPTH_TEST);
  GLFunctions::sphere(m_worldSize,30);

  // Draw player/asteroids

}

void World::movePlayer(Rocket::direction _move)
{
  m_player.strafe(_move);
}

void World::spawnAsteroid()
{
//  m_asteroids.push_back( new Asteroid( Vec4(rand%m_worldSize/5,
//                                            rand%m_worldSize/5,
//                                            rand%m_worldSize/5) ) );
}

void World::initAsteroid()
{

}

void World::initRocket()
{

}
