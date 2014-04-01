#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "rocket.h"
#include "asteroid.h"
#include "Vec4.h"
class World
{
public:
  World(float _worldSize, const Vec4& _spawnPosition = Vec4(0,0,0))
    : m_worldSize(_worldSize), m_player(_spawnPosition,
                                        Vec4( 0.5f, 0.5f, 0.5f ),
                                        Vec4(1.0f, 1.0f, 1.0f),
                                        Vec4( 0.5f, 0.5f, 0.5f ),
                                        Vec4() )
  {;}

  void update();
  void draw();
  void spawnAsteroid();
  void initAsteroid();
  void fireBullet();
  Vec4 getPlayerPosition();

  void movePlayer(float _move, float _rotation);


private:
  float m_worldSize;
  Rocket m_player;
  std::vector<Asteroid> m_asteroids;
};

#endif // WORLD_H
