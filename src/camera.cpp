#include "camera.h"
#include "World.h"
#include <SDL.h>
#include "GLFunctions.h"
#include "Mat4.h"

Camera::Camera()
{
}
/**
 * @brief Camera::setPos
 * @param _m_player
 *this will set the position of the camera to be the players position
 */

void Camera::setPos(Vec4 _m_player)
{
  //sets the rotation of the camera to the x value of the mouse
  int mouse_x = 0, mouse_y = 0;
  SDL_GetMouseState(&mouse_x,&mouse_y);
  m_rotation = 0.5*mouse_x;

  m_position.m_x =  _m_player.m_x;
  m_position.m_y = _m_player.m_y + 1 ;
  m_position.m_z = _m_player.m_z + 4 ;
}

/**
 * @brief Camera::rotateCam
 * @param _player
 * This should get the camera to rotate around the player
 *  I had a bit of trouble implementing this, spending hours and hours trying to get
 *it to smoothly rotate around the player so i settled for a static camera that looks at
 *the player. The part that calls this in main is commented out.
 */

void Camera::rotateCam(Vec4 _player)
{
  //again sets the rotation of the camera to the x value of the mouse
  int mouse_x = 0, mouse_y = 0;
  SDL_GetMouseState(&mouse_x,&mouse_y);
  m_rotation = 0.5*mouse_x;

  m_lookPos.set(1,1,1);
//makes a translation matrix with the players position
  Mat4 translate;
  translate.identity();
  translate.m_30 =  _player.m_x;
  translate.m_31 =  _player.m_y;
  translate.m_32 = -_player.m_z;

//creates a rotation matrix from the rotation
  m_position.set(1,1,1);
  m_rotMat.rotateY(m_rotation);

//multiplies the two matrices together
  translate = translate.matXmat(m_rotMat, translate);

//creates a translation matrix using the players position offset by
//1 in the y direction and 4 in the z
  Mat4 offset;
  offset.identity();
  offset.m_30 = m_position.m_x;
  offset.m_31 = m_position.m_y + 1;
  offset.m_32 = m_position.m_z + 4;

  translate = translate.matXmat(translate, offset);
//multiplies the transformation matrix by the vector
  m_lookPos = m_lookPos.matXVec(translate, m_lookPos);








}

