#ifndef HUD_H
#define HUD_H
#include "map.h"
class HUD
{
public:
  HUD();
  void incScore();
  void loseLife();
  int printScore();

private:
  int m_score;
  int m_lives;
};

#endif // HUD_H
