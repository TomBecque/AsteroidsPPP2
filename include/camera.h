#ifndef CAMERA_H
#define CAMERA_H
#include "Vec4.h"
#include "World.h"

class Camera
{
public:
  Camera();
  void rotateCam(Vec4 _player);
  void panCam();
  void setPos(Vec4 _m_player);

  Vec4 m_position;
  float m_rotation;
  Mat4 m_rotMat;
  Vec4 m_lookPos;


};

#endif // CAMERA_H
