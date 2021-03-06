#ifndef MAT4_H__
#define MAT4_H__
#include <ostream>
class Mat4
{
  public:
  Mat4(float _s=1.0f);
  Mat4(const Mat4 &_r);
  void identity();
  void rotateX(float _deg);
  void rotateY(float _deg);
  void rotateZ(float _deg);
  void transpose();
  Mat4 matXmat(Mat4 _mat1, Mat4 _mat2);
  void loadModelView() const;
  void loadProjection() const;

    union
     {
      float m_m[4][4];
      float m_openGL[16];
      struct
      {
        float m_00;
        float m_01;
        float m_02;
        float m_03;
        float m_10;
        float m_11;
        float m_12;
        float m_13;
        float m_20;
        float m_21;
        float m_22;
        float m_23;
        float m_30;
        float m_31;
        float m_32;
        float m_33;
      };

    };
};

std::ostream & operator <<(std::ostream &_output, const Mat4 &_v);


#endif
