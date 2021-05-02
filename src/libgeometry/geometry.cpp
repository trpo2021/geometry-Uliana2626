#include <cmath>
#include <iostream>
#include <libgeometry/geometry.h>
#include <string>
#include <vector>
using namespace std;

double circle_perimeter(double radius)
{
    double perimeter;
    perimeter = 2 * 3.14 * radius;
    return perimeter;
}

double circle_area(double radius)
{
    double area;
    area = 3.14 * radius * radius;
    return area;
}


void find_circle_param(circle circl, double* perimeter, double* area)
{
    *perimeter = circle_perimeter(circl.radius);
    *area = circle_area(circl.radius);
}

double distance_between_points(double x1, double x2, double y1, double y2)
{
    double rez = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return rez;
}

void intersect(circle circles[], vector<vector<int>>&a, int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if ((circles[i].radius + circles[j].radius)>=
			distance_between_points(circles[i].x, circles[j].x, circles[i].y, circles[j].y)) a[i][j] = 1;
		}
	}
}

void print_circle(circle* circl, int num, double* perimeter, double* area, vector<vector<int>>&a, int n)
{
    cout << num+1 << "."
         << "circle(" << circl->x << ' ' << circl->y << ", "
         << circl->radius << ")" << endl;
    find_circle_param(*circl, perimeter, area);
    cout << "Perimetr: " << *perimeter << endl;
    cout << "Area: " << *area << endl;
	cout << "Intersects: ";
	for (int j = 0; j < n; j++){
		if (num == j) continue;
		if (a[num][j] == 1) cout << j+1;
	}
	cout << endl;
}
