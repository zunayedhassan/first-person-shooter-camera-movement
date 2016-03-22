#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

class Camera
{
public:
    Camera(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    ~Camera();

    void Initialize(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    void Refresh();
    void SetPosition(float x, float y, float z);
    void GetPosition(float &x, float &y, float &z);
    void GetDirectionVector(float &x, float &y, float &z);
    void SetYaw(float angle);
    void SetPitch(float angle);

    // Navigation
    void Move(float incr);
    void Strafe(float incr);
    void Fly(float incr);
    void RotateYaw(float angle);
    void RotatePitch(float angle);

    float m_x, m_y, m_z;            // Position
    float m_lx, m_ly, m_lz;         // Direction vector of where we are looking at
    float m_yaw, m_pitch;           // Various rotation angles
    float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector

};

#endif // CAMERA_H
