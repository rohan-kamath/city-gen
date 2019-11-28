#ifndef HOUSE_H
#define HOUSE_H
#include <igl/opengl/glfw/Viewer.h>

class House {
    public:
        Eigen::MatrixXd V;
        Eigen::MatrixXi F;
        void initialize();
};

#endif