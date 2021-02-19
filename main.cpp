#include <iostream>

using namespace std;

struct circle {
    int x;
    int y;
    int radius;
};

void find_circle_param(circle circ)
{
    float perimetr = 2 * 3.14 * circ.radius;
    float area = 3.14 * circ.radius * circ.radius;

    cout « " Perimetr: " « perimetr « endl;
    cout « " Area: " « area « endl;
}

int main()
{
    return 0;
}
