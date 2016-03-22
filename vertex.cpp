#include "vertex.h"

Vertex::Vertex(float x, float y, float z)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
}

float* Vertex::GetArray()
{
    float *point = new float[3];

    point[0] = this->X;
    point[1] = this->Y;
    point[2] = this->Z;

    return point;
}

Vertex::~Vertex()
{

}

