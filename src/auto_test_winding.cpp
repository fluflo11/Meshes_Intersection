#include <iostream>
#include <vector>
#include "structs.hpp"
#include "utils.hpp"

/**
 * Made by copilot
 */
void runTest(const std::string& label, const Point2D& p, const std::vector<Point2D>& poly) {
    bool result = Utils::winding(p, poly);
    std::cout << "Test " << label << " (" << p.x << ", " << p.y << ") -> " 
              << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    std::vector<Point2D> square;
    
    square.emplace_back(Point2D(0.0, 0.0, 1));   // Bas-Gauche
    square.emplace_back(Point2D(10.0, 0.0, 2));  // Bas-Droite
    square.emplace_back(Point2D(10.0, 10.0,3)); // Haut-Droite
    square.emplace_back(Point2D(0.0, 10.0,4));  // Haut-Gauche

    std::cout << "=== BEGINNING OF THE TEST isPointInPolygon ===\n";
    std::cout << "Polygon : Square (0,0) -> (10,10)\n\n";

    // We expect true here
    Point2D p_in(5.0, 5.0,5);
    runTest("Interieur", p_in, square);
    
    return 0;
}