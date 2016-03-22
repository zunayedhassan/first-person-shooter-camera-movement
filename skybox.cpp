#include "skybox.h"

Skybox::Skybox(string pathName)
{
    for (int i = 0; i < TOTAL_NUMBER_OF_PLANES_IN_A_CUBE; i++)
    {
        this->SkyboxPlanes[i] = new Model(pathName + "\\" + this->fileNamePrefixes[i], this->fileNamePrefixes[i], false);
    }
}

void Skybox::Draw()
{
    for (int i = 0; i < TOTAL_NUMBER_OF_PLANES_IN_A_CUBE; i++)
    {
        this->SkyboxPlanes[i]->Draw();
    }
}

Skybox::~Skybox()
{

}

