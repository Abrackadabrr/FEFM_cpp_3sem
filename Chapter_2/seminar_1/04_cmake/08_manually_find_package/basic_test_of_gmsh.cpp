#include <set>
#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::model::add("test");
  double lc = 1e-2;
  gmsh::model::geo::addPoint(0, 0, 0, lc, 1);

  gmsh::model::geo::addPoint(.1, 0, 0, lc, 2);
  gmsh::model::geo::addPoint(.1, .3, 0, lc, 3);

  int p4 = gmsh::model::geo::addPoint(0, .3, 0, lc);

  gmsh::model::geo::addLine(1, 2, 1);
  gmsh::model::geo::addLine(3, 2, 2);
  gmsh::model::geo::addLine(3, p4, 3);
  gmsh::model::geo::addLine(4, 1, p4);

  gmsh::model::geo::addCurveLoop({4, 1, -2, 3}, 1);

  gmsh::model::geo::addPlaneSurface({1}, 1);

  gmsh::model::geo::synchronize();

  gmsh::model::mesh::generate(2);

  gmsh::write("test.msh");

  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) gmsh::fltk::run();

  gmsh::finalize();

  return 0;
}
