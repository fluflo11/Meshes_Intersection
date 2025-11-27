#ifndef UTILS_HPP
#define UTILS_HPP
#include "structs.hpp"

/**
 * Just a toolbox with a lot of code borrowed and adapted from Numerical Recipes
 */

namespace Utils{

/**
 * "If you wish to make an apple pie from scratch, you must first invent the universe"
 * TODO
 */
double distance(const Point2D& a, const Point2D& b);
Point2D subtract(const Point2D& a, const Point2D& b);
double norm(const Point2D& v);
double dotProduct(const Point2D& a, const Point2D& b);
double crossProduct(const Point2D& a, const Point2D& b);
bool isPointInPolygon(const Point2D& p, const std::vector<Point2D>& polygon);
std::vector<Point2D> getPolygonIntersection(const std::vector<Point2D>& p1, const std::vector<Point2D>& p2);

}



#endif