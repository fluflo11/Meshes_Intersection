#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <vector>
#include <string>

class Point2D{
public :
    double x;
    double y;
    Point2D(double x_param, double y_param){
        x = x_param;
        y = y_param;
    }
    static std::vector<Point2D> getInputNodes(std::string file_path);
    static void printInputNodes(std::vector<Point2D> vect);
};

class Topology{
    //TODO 
};

#endif