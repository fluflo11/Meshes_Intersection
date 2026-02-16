#ifndef VTK_TOOLS_H
#define VTK_TOOLS_H

#include <string>
#include "structs.hpp"

/**
 * VTK tool to export meshes as VTK files
 */
namespace VTK{

    class VTK_Exporter{
    public: 
        Topology topology;
        std::vector<Point2D> nodes;

        bool exportVTK(const std::string& file, const std::string& title="Really Cool Data");
        VTK_Exporter(Topology& topology, std::vector<Point2D> nodes):topology(topology),nodes(nodes){}
    };

}

#endif