#include "VTK_Tools.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "structs.hpp"

bool VTK::VTK_Exporter::exportVTK(const std::string& file, const std::string& title){

    std::ofstream out(file);
    if(!out){
        std::cerr << "Error: " << file << " doesnt exist" << std::endl;
        return false;
    }

    /**
     * Header 
     */
    out << "# vtk DataFile Version 2.0" << std::endl;
    out << title << std::endl;
    out << "ASCII" << std::endl;
    out << "DATASET UNSTRUCTURED_GRID" << std::endl;
    
    out << "POINTS " << nodes.size() << " float" << std::endl;

    for(const auto& p: nodes){
        out << p.x << " " << p.y << std::endl;
    }

    int list_size = 0;
    
    //TODO: Rewrite these 3 loops as only 1 for loop (stock cells data in another stream structure while counting list_size)
    for(const auto& cell: topology.cells){
        list_size += 1 + cell.indices.size();
    }

    out << "CELLS " << topology.cells.size() << " " << list_size << std::endl;
    for(const auto& cell: topology.cells){
        out << cell.indices.size();
        for(int indice : cell.indices){
            out << " " << indice;
        }
        out << std::endl;
    }

    /**
     * In vtk 5 = triangle 9 = rectangle 7 = any
     */
    out << "CELL_TYPE " << topology.cells.size() << std::endl;
    for(const auto& cell: topology.cells){
        if(cell.indices.size() == 3) out << "5" << std::endl;
        if(cell.indices.size() == 4) out <<  "9" << std::endl;
        else {
            out << "7" << std::endl;
        }
    }

    //Maybe write cell data here to easily visualize differnt cells 

    std::cout << "End of the export, file produced : " << file << std::endl;
    return true;
}