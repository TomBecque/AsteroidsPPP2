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
    : m_worldSize(_worldSize), m_player(_spawnPosition, Vec4( 0.0f, 0.0f, 0.0f ),
                                                        Vec4(1.16f, 1.16f, 1.16f) )
  {;}

  ~World();

  void update();
  void draw();
  void spawnAsteroid();
  void initAsteroid();
  Vec4 getPlayerPosition();
  void movePlayer(float _move, float _rotation);
  void makeBullets();
  void initRocket();
  void splitAsteroids(RigidBodies* _selected);
private:

  float getPlayerRotation();

  float m_worldSize;
  Rocket m_player;
  std::vector<RigidBodies*> m_bodies;
};

#endif // WORLD_H

