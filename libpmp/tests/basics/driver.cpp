#include <pmp/surface_mesh.h>

// Needs to be provided to gain access
// to 'read' and 'write' functions.
//
#include <pmp/io/io.h>

#undef NDEBUG
#include <cassert>

int main() {
  pmp::SurfaceMesh mesh;
  pmp::read(mesh, "input.obj");
  // .. do awesome things with your mesh
  pmp::write(mesh, "output.obj");
}
