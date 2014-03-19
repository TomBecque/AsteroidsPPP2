#ifndef CAMERA_H
#define CAMERA_H
#include "Vec4.h"

class Camera
{
public:
  Camera();
  void rotateCam();
  void panCam();

  Vec4 m_position;
  float m_rotation;

};

#endif // CAMERA_H
