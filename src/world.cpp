#include "World.h"
#include "GLFunctions.h"
#include "util.h"
#include "asteroid.h"
#include "bullet.h"
#include "Vec4.h"
#include "rigidbodies.h"

World::~World()
{
  std::cout<<"destructor called" ;
  BodyVector::iterator it;
  for (it = m_bodies.begin(); it != m_bodies.end(); ++it)
  {
    delete (*it);
  }

}

///------------------------------------------------------------------------------------
void World::update()
{
  //std::vector<Bullet>& bullets = m_player.getBullets();

  /*
  for(int i = 0; i<m_asteroids.size(); i++)
  {
    for(int j = 0; j<bullets.size(); j++)
    {
      if(bullets[j].checkCollision(m_asteroids[i]))
      {
        //m_asteroids.erase(m_asteroids.begin() + 1);
        std::cout<<"collision!";
      }
    }
  }*/
  BodyVector::iterator it, bit;
  for (it = m_bodies.begin(); it != m_bodies.end(); ++it) {
    for (bit = m_bodies.begin(); bit != m_bodies.end(); ++bit) {

      if ((it != bit) && ((*it)->checkCollision(*bit))) {
        std::cout<< "COLLISION\n";
        if ((((*it)->getType() == RigidBodies::BT_ASTEROID) &&
             ((*bit)->getType() == RigidBodies::BT_BULLET)) ||
            (((*it)->getType() == RigidBodies::BT_BULLET) &&
             ((*bit)->getType() == RigidBodies::BT_ASTEROID))) {

          std::cout<< "bullet & asteroid collide\n";
        }

        else if ((((*it)->getType() == RigidBodies::BT_ASTEROID) &&
                  ((*bit)->getType() == RigidBodies::BT_ROCKET)) ||
                 (((*it)->getType() == RigidBodies::BT_ROCKET) &&
                  ((*bit)->getType() == RigidBodies::BT_ASTEROID))) {

          std::cout<<"asteroid & rocket collide\n";
        }


      }

    }
  }

}
///------------------------------------------------------------------------------------
void World::draw()
{
  Vec4 background(0.0f, 0.0f, 0.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable (GL_DEPTH_TEST);
  background.colourGL();



  BodyVector:: iterator it;

  for(it = m_bodies.begin();it != m_bodies.end(); ++it)
//  for(  unsigned int i=0; i < m_bodies.size(); i++)
  {
    (*it)->draw();
  }

  glPushMatrix();
   // GLFunctions::sphere(m_worldSize,30);
  glPopMatrix();
}

///-----------------------------------------------------------------------------------
void World::movePlayer(float _move, float _rotation)
{
  m_player.update(_move, _rotation);
}
///-----------------------------------------------------------------------------------
void World::spawnAsteroid()
{
  Vec4 position = Vec4(util::floatRandRange(-m_worldSize, m_worldSize)*sin(util::floatRand((360)*PI)/180),
                       0,
                       util::floatRandRange(-m_worldSize, m_worldSize)*sin(util::floatRand((360)*PI)/180) );
  std::cout<<"The position is \n ";
  position.print();
  std::cout<<"\n";
  Vec4 colour = Vec4(0.36f, 0.25f, 0.2f);
  Vec4 scale = Vec4(5.0f, 5.0f, 5.0f);
  float radius = util::floatRand(m_worldSize/50);
  Vec4 direction = Vec4(util::floatRandRange(-0.1, 0.1),
                   0,
                   util::floatRandRange(-0.1, 0.1));

  //Asteroid tmp(position, colour, scale, radius, dest );

  m_bodies.push_back(new Asteroid(position, colour, scale, radius, direction ));
}
///-----------------------------------------------------------------------------------
void World::initAsteroid()
{
  for(int i=0;i<1;i++)
  {
    spawnAsteroid();

  }
}
///-----------------------------------------------------------------------------------
void World::fireBullet()
{
  m_player.fire();
}
///-----------------------------------------------------------------------------------
Vec4 World::getPlayerPosition()
{
  return m_player.getPlayerPosition();
}

//void World::playerAsteroidCheck()
//{
//  m_player.m_bodyBox.m_vecMax = getPlayerPosition() + 0.5;
//  m_player.m_bodyBox.m_vecMin = getPlayerPosition() - 0.5;
//  for(int i = 0; i <m_asteroids.size(); i++)
//  {
//    if(m_asteroids[i].checkCollision(m_player))
//    {
//      std::cout<<"collision!";
//    }
//  }
//}

///-----------------------------------------------------------------------------------
float World::getPlayerRotation()
{
  return m_player.m_rotation;
}

///-----------------------------------------------------------------------------------
void World::makeBullets()
{
  float _rotation = getPlayerRotation();
  Vec4 position( (0.1*sin((PI *_rotation)/180)),
                  0,
                 (0.1*cos((PI *_rotation)/180)) );
  Vec4 offset = getPlayerPosition();
  Vec4 colour = Vec4(1.0f, 1.0f, 1.0f);
  Vec4 size = Vec4(0.2f, 0.2f, 0.2f);

  Bullet* tmp = new Bullet(position, offset, colour, size );
             //Vec4(position.m_x - 0.1, position.m_y - 0.1, position.m_z - 0.1),
             //Vec4(position.m_x + 0.1,position.m_y + 0.1,position.m_z + 0.1));

  m_bodies.push_back(tmp);
}
///-------------------------------------------------------------------------------
void World::initRocket()
{
  BodyVector::iterator it;
  it = m_bodies.begin();
  it = m_bodies.insert(it, &m_player);
}
///------------------------------------------------------------------------------------
void World::drawAsteroids()
{

}
///-----------------------------------------------------------------------------------
void World::drawBullets()
{

}
///---------------------------------------------------------------------------------
void World::drawRocket()
{

}
