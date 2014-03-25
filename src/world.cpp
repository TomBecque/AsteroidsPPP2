#include "World.h"
#include "GLFunctions.h"
#include "util.h"



void World::draw() const
{
  Vec4 background(0.0f, 0.0f, 0.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  background.colourGL();

  glEnable (GL_DEPTH_TEST);
  GLFunctions::sphere(m_worldSize,30);

  // Draw player/asteroids

  m_player.draw();



}

void World::movePlayer(Rocket::direction _move)
{
  m_player.turn(_move);
}

void World::spawnAsteroid()
{
  float radius = utils::floatRand(m_worldSize/8);
  Vec4 position = Vec4(utils::floatRand(m_worldSize), 0, utils::floatRand(m_worldSize));
  Vec4 colour = Vec4(0.5f, 0.5f, 0.5f);
  Vec4 scale = Vec4(1.0f, 1.0f, 1.0f);

  Asteroid tmp(position, colour, scale, radius);

  m_asteroids.push_back(tmp);
}



void World::initAsteroid()
{
  for(int i=0;i<10;i++)
  {
    spawnAsteroid();
  }
}

void World::initRocket()
{
//  Vec4 _position = Vec4(0,0,0);
//  Vec4 _colour = Vec4(0.5f,0.5f,0.5f);
//  Vec4 _size = Vec4(1,1,1);

//  m_player
}
