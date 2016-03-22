#include "camera.h"

Camera::Camera(float x, float y, float z)
{
    this->Initialize(x, y, z);
}

Camera::~Camera()
{

}

void Camera::Initialize(float x, float y, float z)
{
    this->m_yaw = 0.0f;
    this->m_pitch = 0.0f;

    this->SetPosition(x, y, z);
}

void Camera::Refresh()
{
    // Camera parameter according to Riegl's co-ordinate system
    // x / y for flat, z for height
    this->m_lx = cos(this->m_yaw) * cos(this->m_pitch);
    this->m_ly = sin(this->m_pitch);
    this->m_lz = sin(this->m_yaw) * cos(this->m_pitch);

    this->m_strafe_lx = cos(this->m_yaw - M_PI_2);
    this->m_strafe_lz = sin(this->m_yaw - M_PI_2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(this->m_x, this->m_y, this->m_z, this->m_x + this->m_lx, this->m_y + this->m_ly, this->m_z + this->m_lz, false, true, false);

    //cout << "Camera: " << this->m_x << " " << this->m_y << " " << this->m_z <<  " Direction vector:" << endl << this->m_lx << " " << m_ly << " " << m_lz << endl;
}

void Camera::SetPosition(float x, float y, float z)
{
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;

    this->Refresh();
}

void Camera::GetPosition(float &x, float &y, float &z)
{
    x = this->m_x;
    y = this->m_y;
    z = this->m_z;
}

void Camera::GetDirectionVector(float &x, float &y, float &z)
{
    x = this->m_lx;
    y = this->m_ly;
    z = this->m_lz;
}

void Camera::Move(float incr)
{
    float lx = cos(this->m_yaw) * cos(this->m_pitch);
    float ly = sin(this->m_pitch);
    float lz = sin(this->m_yaw) * cos(this->m_pitch);

    this->m_x = this->m_x + incr * lx;
    this->m_y = this->m_y + incr * ly;
    this->m_z = this->m_z + incr * lz;

    this->Refresh();
}

void Camera::Strafe(float incr)
{
    this->m_x = this->m_x + incr * this->m_strafe_lx;
    this->m_z = this->m_z + incr * this->m_strafe_lz;

    this->Refresh();
}

void Camera::Fly(float incr)
{
    this->m_y = this->m_y + incr;

    this->Refresh();
}

void Camera::RotateYaw(float angle)
{
    this->m_yaw += angle;

    this->Refresh();
}

void Camera::RotatePitch(float angle)
{
    angle = -angle;

    const float limit = 89.0 * M_PI / 180.0;

    this->m_pitch += angle;

    if (this->m_pitch < -limit)
    {
        this->m_pitch = -limit;
    }

    if (this->m_pitch > limit)
    {
        this->m_pitch = limit;
    }

    this->Refresh();
}

void Camera::SetYaw(float angle)
{
    this->m_yaw = angle;

    this->Refresh();
}

void Camera::SetPitch(float angle)
{
    this->m_pitch = angle;

    this->Refresh();
}
