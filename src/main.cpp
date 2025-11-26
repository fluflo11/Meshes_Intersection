#include <iostream>
#include <string>
#include "structs.hpp"

int main(){

    std::string input_file = "resources/meshes_for_FR/unitsqmeshes/unitsqmesh_hexreg_000094_midedge/input_nodes.dat";
    std::vector<Point2D> my_vector = Point2D::getInputNodes(input_file);
    Point2D::printInputNodes(my_vector);
    return 0;
}