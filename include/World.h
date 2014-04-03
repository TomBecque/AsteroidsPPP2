#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "rocket.h"
#include "asteroid.h"
#include "Vec4.h"

typedef std::vector<RigidBodies*> BodyVector;

class World
{
public:
  World(float _worldSize, const Vec4& _spawnPosition = Vec4(0,0,0))
    : m_worldSize(_worldSize), m_player(_spawnPosition, Vec4( 0.5f, 0.5f, 0.5f ),
                                                        Vec4(1.0f, 1.0f, 1.0f) )
  {;}

  virtual ~World();

  void update();
  void draw();
  void spawnAsteroid();
  void initAsteroid();
  void fireBullet();
  Vec4 getPlayerPosition();
  void movePlayer(float _move, float _rotation);
//  void playerAsteroidCheck();
  void makeBullets();
  float getPlayerRotation();
  void initRocket();
  void drawRocket();
  void drawAsteroids();
  void drawBullets();

private:
  float m_worldSize;
  Rocket m_player;
  std::vector<RigidBodies*> m_bodies;
};

#endif // WORLD_H

