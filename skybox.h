#ifndef SKYBOX_H
#define SKYBOX_H

#include <iostream>

#include "model.h"

#define TOTAL_NUMBER_OF_PLANES_IN_A_CUBE 6

using namespace std;

class Skybox
{
private:
    string fileNamePrefixes[TOTAL_NUMBER_OF_PLANES_IN_A_CUBE] = {
        "skybox_front",
        "skybox_left",
        "skybox_right",
        "skybox_back",
        "skybox_top",
        "skybox_bottom"
    };

public:
    Model *SkyboxPlanes[TOTAL_NUMBER_OF_PLANES_IN_A_CUBE];

    Skybox(string pathName);

    void Draw();

    ~Skybox();
};

#endif // SKYBOX_H
