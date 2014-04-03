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
  m_position.m_y = _m_player.m_y + 1 ;
  m_position.m_z = _m_player.m_z + 4 ;// + 0.1*cos((PI *m_rotation)/180);
}

void Camera::rotateCam(Vec4 _player)
{
  int mouse_x = 0, mouse_y = 0;
  SDL_GetMouseState(&mouse_x,&mouse_y);
  m_rotation = 0.5*mouse_x;
  //m_lookPos.set(1,1,1);

  m_lookPos.set(1,1,1);

  Mat4 translate;
  translate.identity();
  translate.m_30 =  _player.m_x;
  translate.m_31 =  _player.m_y;
  translate.m_32 = -_player.m_z;


  m_position.set(1,1,1);
  m_rotMat.rotateY(m_rotation);
  translate = translate.matXmat(m_rotMat, translate);

//  Mat4 offset;
//  offset.identity();
//  offset.m_30 = m_position.m_x;
//  offset.m_31 = m_position.m_y + 1;
//  offset.m_32 = m_position.m_z + 4;

//  translate = translate.matXmat(translate, offset);

  m_lookPos = m_lookPos.matXVec(translate, m_lookPos);





//  m_position.m_x = _player.m_x;
//  m_position.m_y = _player.m_y + 1;
//  m_position.m_z = _player.m_z + 4;// + 0.1*cos((PI *m_rotation)/180);




}

