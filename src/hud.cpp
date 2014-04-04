#include "hud.h"


void HUD::initLives()
{
  m_lives = 3;
}

void HUD::initScore()
{
  m_score = 0;
}

void HUD::loseLife()
{
//  m_lives-- ;
}

void HUD::gameOver(bool _quit)
{
  if( m_lives < 1)
  {
    _quit = true;
    std::cout<<"/n you scored "<< m_score << "points!";
  }
}


