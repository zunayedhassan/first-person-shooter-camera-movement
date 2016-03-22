#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
public:
    float X, Y, Z;

    Vertex(float x = 0, float y = 0, float z = 0);

    float* GetArray();

    ~Vertex();
};

#endif // VERTEX_H
