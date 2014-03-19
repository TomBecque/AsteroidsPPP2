#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "rocket.h"
#include "asteroid.h"

class World
{
public:
  World(float _worldSize, const Vec4& _spawnPosition = Vec4(0,0,0))
    : m_worldSize(_worldSize), m_player(_spawnPosition,
                                        Vec4( 0.5f, 0.5f, 0.5f ),
                                        Vec4(1.0f, 1.0f, 1.0f)
                                       )
  {;}

  void draw() const;
  void spawnAsteroid();
  void initAsteroid();
  void initRocket();

  void movePlayer(Rocket::direction _move);

private:
  float m_worldSize;
  Rocket m_player;
  std::vector<Asteroid> m_asteroids;
};

#endif // WORLD_H
