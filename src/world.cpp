#include "World.h"
#include "GLFunctions.h"
#include "util.h"
#include "asteroid.h"
#include "bullet.h"
#include "Vec4.h"
#include "rigidbodies.h"



void World::update()
{
  for(int i = 0; i<m_asteroids.size(); i++)
  {
    std::vector<Bullet>& bullets = m_player.getBullets();
    for(int j = 0; j<bullets.size(); j++)
    {
      if(bullets[j].checkCollision(m_asteroids[i]))
      {
        /*m_asteroids.erase(m_asteroids.begin() + 1)*/std::cout<<"collision!";


      }
    }
  }
}

void World::draw()
{
  Vec4 background(0.0f, 0.0f, 0.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable (GL_DEPTH_TEST);
  background.colourGL();

  for(int i = 0; i<m_asteroids.size(); i++)
  {
    m_asteroids[i].draw();
  }


  glPushMatrix();
    //GLFunctions::sphere(m_worldSize,30);

  // Draw player/asteroids
    m_player.draw();
  glPopMatrix();
}


void World::movePlayer(float _move, float _rotation)
{
  m_player.move(_move,_rotation);
}


void World::spawnAsteroid()
{
  Vec4 position = Vec4(utils::floatRand(m_worldSize)*sin(utils::floatRand(360)*PI/180),
                       0,
                       utils::floatRand(-m_worldSize)*sin(utils::floatRand(360)*PI/180) );
  Vec4 colour = Vec4(0.36f, 0.25f, 0.2f);
  Vec4 scale = Vec4(1.0f, 1.0f, 1.0f);
  float radius = utils::floatRand(m_worldSize/50);
  Vec4 dest = Vec4(utils::floatRandRange(-m_worldSize, m_worldSize),
                   0,
                   utils::floatRandRange(-m_worldSize, m_worldSize));

  Asteroid tmp(position, colour, scale,Vec4(position.m_x-radius,position.m_y-radius,position.m_z-radius), Vec4(position.m_x + radius,position.m_y + radius,position.m_z + radius), radius, dest );

  m_asteroids.push_back(tmp);
}

void World::initAsteroid()
{
  for(int i=0;i<1;i++)
  {
    spawnAsteroid();
  }
}

void World::fireBullet()
{
  m_player.fire();
}

Vec4 World::getPlayerPosition()
{
  return m_player.getPlayerPosition();
}
