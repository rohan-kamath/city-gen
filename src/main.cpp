#include <igl/opengl/glfw/Viewer.h>
#include "house.h"

int main(int argc, char *argv[])
{

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  House house1;
  house1.initialize();
  viewer.data().set_mesh(house1.V, house1.F);
  viewer.data().set_face_based(true);
  viewer.launch();
}
