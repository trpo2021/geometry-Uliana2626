#include <algorithm>
#include <iostream>
#include <libgeometry/geometry.h>
#include <libgeometry/parse.h>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string input, figureName;

    int number_of_figures;
    cout << "Input the number of figures" << endl;
    cin >> number_of_figures;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector<int>> intersections(
            number_of_figures, vector<int>(number_of_figures, -1));
    circle circles[number_of_figures];

    for (int i = 0; i < number_of_figures; i++) {
        getline(cin, input);
        figureName = parse_name(&input);

        switch (identify(figureName)) {
        case CIRCLE:
            parse_circle(input, &circles[i]);
            break;
        case ERROR:
            cout << input << endl;
            cout << '^' << endl;
            cout << "Error in name of figure!";
        }
    }

    intersect(circles, intersections, number_of_figures);

    double perimeter, area;
    cout << endl;
    for (int i = 0; i < number_of_figures; i++) {
        print_circle(
                &circles[i],
                i,
                &perimeter,
                &area,
                intersections,
                number_of_figures);
    }
}