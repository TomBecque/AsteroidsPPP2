#ifndef CAMERA_H
#define CAMERA_H
#include "Vec4.h"
#include "World.h"

/**
 * @brief The Camera class
 */

class Camera
{
public:
  Camera();
  void rotateCam(Vec4 _player);
  void setPos(Vec4 _m_player);

  Vec4 m_position;
  Vec4 m_lookPos;

private:

  float m_rotation;
  Mat4 m_rotMat;



};

#endif // CAMERA_H
