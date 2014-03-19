#ifndef VEC4_H__
#define VEC4_H__
#include <ostream>

class Vec4
{
  public :
    ///@brief ctor
    ///@param [in] _x the x value default 0
    ///@param [in] _y the y value default 0
    ///@param [in] _z the z value default 0
    ///@param [in] _w the w value default 1

    Vec4(float _x=0.0f, float _y=0.0f, float _z=0.0f, float _w=1.0f
        ):
      m_x(_x), m_y(_y), m_z(_z), m_w(_w)
    {;}
    //----------------------------------------------------------------
    /// @brief method to print attributes
    //----------------------------------------------------------------
    void print() const;
    ///@brief length
    float length() const;
    ///@brief length^2
    float lengthSquared() const;
    //----------------------------------------------------------------
    /// @brief normalise the attributes
    //----------------------------------------------------------------
    void normalise();
    //----------------------------------------------------------------
    /// @brief dot product
    //----------------------------------------------------------------
    float dot(const Vec4 &_b) const;
    //----------------------------------------------------------------
    /// @brief dot product
    //----------------------------------------------------------------
    float dot(const Vec4 &_a, const Vec4 &_b) const;
    //----------------------------------------------------------------
    /// @brief cross product of this and b
    ///@param [in] _b the vector to cross _b
    ///@returns a new vector this cross _b
    //----------------------------------------------------------------
    Vec4 cross(const Vec4 &_b) const;
    //----------------------------------------------------------------
    /// @brief cross product of this and b
    ///@param [in] _b the vector to cross _b
    ///@returns a new vector this cross _b
    //----------------------------------------------------------------

    //Vec4 cross(const Vec4 &_a, const Vec4 &_b) const;

   //-----------------------------------------------------------------
    Vec4 operator *(float _rhs);
    Vec4 operator -(const Vec4 &_rhs);
    void operator *=(float _rhs);

    Vec4 operator +(const Vec4 &_rhs) const;
    void operator +=(const Vec4 &_rhs);
    void operator -=(const Vec4 &_rhs);
    bool operator ==(const Vec4 &_rhs) const;

    void colourGL() const;
    void normalGL() const;
    void vertexGL() const;
    void normalize();

    void set(float _x, float _y, float _z, float _w = 1.0);

    union
    {
      struct
      {

        ///@brief the x element of the vector
        float m_x;
        ///@brief the y element of the vector
        float m_y;
        ///@brief the z element of the vector
        float m_z;
        ///@brief the w element of the vector
        float m_w;
       };

      struct
      {

        ///@brief the x element of the vector
        float m_r;
        ///@brief the y element of the vector
        float m_g;
        ///@brief the z element of the vector
        float m_b;
        ///@brief the w element of the vector
        float m_a;
       };

      float m_openGL[4];

    };

};

std::ostream & operator<<(std::ostream &_output, const Vec4 &_v);

#endif
