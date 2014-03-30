#include "camera.h"
#include "World.h"
#include <SDL.h>
#include "GLFunctions.h"
#include "Mat4.h"

Camera::Camera()
{
}

void Camera::setPos(Vec4 _m_player)
{
  int mouse_x = 0, mouse_y = 0;
  SDL_GetMouseState(&mouse_x,&mouse_y);

  m_rotation = 0.5*mouse_x;
  m_position.m_x =  _m_player.m_x;
  m_position.m_y = _m_player.m_y + 2;
  m_position.m_z = _m_player.m_z + 4;// + 0.1*cos((PI *m_rotation)/180);
}

void Camera::rotateCam(Vec4 _player)
{
  Vec4 cam;
  int mouse_x = 0, mouse_y = 0;
  SDL_GetMouseState(&mouse_x,&mouse_y);

  m_rotation = 0.5*mouse_x;
  m_rotMat.rotateY(m_rotation);
  m_lookPos = cam.matXVec(m_rotMat, _player );


}

