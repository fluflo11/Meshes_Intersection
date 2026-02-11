#include <iostream>
#include <string>
#include "structs.hpp"
#include "VTK_Tools.hpp"

int main(){

    std::string input_file = "resources/meshes_for_FR/unitsqmeshes/unitsqmesh_hexreg_000094_midedge/input_nodes.dat";
    std::vector<Point2D> my_vector = Point2D::getInputNodes(input_file);
    Point2D::printInputNodes(my_vector);
   
    input_file = "resources/meshes_for_FR/unitsqmeshes/unitsqmesh_hexreg_000094_midedge/input_topo.dat";
    Topology my_topology = Topology::getInputTopology(input_file);
    my_topology.printTopology();

    VTK::VTK_Exporter my_exporter(my_topology,my_vector);
    std::string output_file = "resources/VTK/mesh.vtk";
    
    if(my_exporter.exportVTK(output_file)){
        std::cout << "Yess" << std::endl;
    }
    else {
        std::cout << ":c " << std::endl;
    }

    return 0;
}