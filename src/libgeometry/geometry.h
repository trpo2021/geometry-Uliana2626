#pragma once
#include <vector>
enum Figures { CIRCLE, ERROR };

struct circle {
    float x;
    float y;
    float radius;
};



double circle_perimeter(double radius);
double circle_area(double radius);
void find_circle_param(circle circl, double* perimeter, double* area);
double distance_between_points(double x1, double x2, double y1, double y2);
void print_circle(circle* circl, int num, double* perimeter, double* area, std::vector<std::vector<int>>&a, int n);
void intersect(circle circles[], std::vector<std::vector<int>>&a, int n);