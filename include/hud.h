#ifndef HUD_H
#define HUD_H
#include "map.h"
#include "iostream"


class HUD
{
public:
  HUD(int _lives)
    : m_score(0), m_lives(_lives) {;}

  void incScore();
  static void loseLife();
  int printScore();
  void gameOver(bool _quit);
  void initScore();
  void initLives();


  int m_score;
  int m_lives;

private:

};

#endif // HUD_H
