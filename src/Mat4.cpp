#include "Mat4.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#ifdef LINUX
	#include <GL/gl.h>
#endif
#ifdef DARWIN
	#include <OpenGL/gl.h>
#endif
#include <GL/gl.h>

Mat4::Mat4(float _s)
{
  memset(&m_m,0,sizeof(m_m));
  m_00=_s;
  m_11=_s;
  m_22=_s;
  m_33=_s;

}

void Mat4::identity()
{
  memset(&m_m,0,sizeof(m_m));
  m_00=1.0f;
  m_11=1.0f;
  m_22=1.0f;
  m_33=1.0f;
}

void Mat4::rotateX(float _deg)
{
  float beta=(_deg/180.0f) * M_PI;
  float sr = sin(beta);
  float cr = cos(beta);
  identity();
  m_11 = cr;
  m_21 = -sr;
  m_12 = sr;
  m_22 = cr;


}

void Mat4::rotateY(float _deg)
{
  float beta=(_deg/180.0f) * M_PI;
  float sr = sin(beta);
  float cr = cos(beta);
  identity();
  m_00 = cr;
  m_20 = sr;
  m_02 = -sr;
  m_22 = cr;

}

void Mat4::rotateZ(float _deg)
{
  float beta=(_deg/180.0f) * M_PI;
  float sr = sin(beta);
  float cr = cos(beta);
  identity();
  m_00 = cr;
  m_10 = -sr;
  m_01 = sr;
  m_11 = cr;
}





void Mat4::transpose()
{

}

void Mat4::loadModelView() const
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMultMatrixf(&m_openGL[0]);
}

void Mat4::loadProjection() const
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMultMatrixf(&m_openGL[0]);

}













Mat4::Mat4(const Mat4 &_r)
{
  memcpy(m_m,&_r.m_m, sizeof(m_m));
}


std::ostream & operator <<(std::ostream &_output, const Mat4 &_v)
{
std::cout.setf(std::ios::fixed |
               std::ios::adjustfield |
               std::ios::showpos
               );
std::cout.precision(std::numeric_limits<double>::digits10+1);
return _output
  <<"["<<_v.m_00<<","<<_v.m_10<<","<<_v.m_20<<","<<_v.m_30<<"]\n"
  <<"["<<_v.m_01<<","<<_v.m_11<<","<<_v.m_21<<","<<_v.m_31<<"]\n"
  <<"["<<_v.m_02<<","<<_v.m_12<<","<<_v.m_22<<","<<_v.m_32<<"]\n"
  <<"["<<_v.m_03<<","<<_v.m_13<<","<<_v.m_23<<","<<_v.m_33<<"]\n";

}


Mat4 Mat4::matXmat(Mat4 _mat1, Mat4 _mat2)
{
  Mat4 matResult;
  for(int k = 0; k < 4; k++)
  {
    for(int j = 0; j < 4; j++)
    {
      for(int i = 0; i < 4; i++)
      {
        matResult.m_m[k][j] += _mat1.m_m[i][j] * _mat2.m_m[k][i];
      }
    }
  }
  return matResult;
}
