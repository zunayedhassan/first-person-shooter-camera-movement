#ifndef MODEL_H
#define MODEL_H

#include "CommonTools.h"
#include "Texture.h"
#include "vertex.h"

class Model
{
private:
    vector<Vertex*> *vertices = nullptr;

    Vertex textureCoords[6] = {
        Vertex(0, 0),
        Vertex(0, 1),
        Vertex(1, 1),
        Vertex(1, 1),
        Vertex(1, 0),
        Vertex(0, 0)
    };

    float textureScaleFactor = 1.0f;

    bool isNormalEnable = true;
    fstream *verticesFile = nullptr;

    void init(bool isNormalEnable, float textureScaleFactor);
public:
    Texture *Textures = nullptr;

    Model(string fileNamePrefix, string modelName = "", bool isNormalEnable = true, float textureScaleFactor = 1);
    Model(string textureFileNamePrefix, string verticesFileName, string modelName = "", bool isNormalEnable = true, float textureScaleFactor = 1);
    void Draw(float angle = 0.0f, bool rotx = false, bool roty = false, bool rotz = false, float translateX = 0.0f, float translateY = 0.0f, float translateZ = 0.0f);
    float* GetNormal(float *coord1, float *coord2, float *coord3);
    ~Model();
};

#endif // MODEL_H
