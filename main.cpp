#include <iostream>

using namespace std;

struct circle {
    float x;
    float y;
    float radius;
};

enum Figures {
    CIRCLE, ERROR
};

string parse_name(string input)
{
    string figureName;
    if (input.substr(0,1) == " "){
        input.erase(0, input.find_first_not_of(" "));
    }

    if (input.substr(input.find("(") - 1, 1) == " ") {
        input = input.erase(input.find(" "), input.find("(") - input.find(" "));
    }

    figureName = input.substr(0, input.find("("));
    return figureName;
}

void find_circle_param(circle circle_object)
{
    float per = 2 * 3.14 * circle_object.radius;
    float area = 3.14 * circle_object.radius * circle_object.radius;

    cout << " Perimetr: " << per << endl;
    cout << " Area: " << area << endl;
}

Figures identify(string figure) 
{
    string figureName;

    figureName = "circle";
    if (figure == figureName) return CIRCLE;

    return ERROR;
}

void parse_circle(string input, circle* circle_object)
{
    size_t end;  
    input = input.erase(0, 6);
    if (input[0] == '('){
        input.erase(0,1);
        circle_object->x = stod(input, &end);
        input = input.erase(0, end);
        circle_object->y = stod(input, &end);
        input = input.erase(0, end+1);
        circle_object->radius = stod(input, &end);
    };
}

int main()
{
    string input, figureName;
    getline(cin, input);

    figureName = parse_name(input);

    switch (identify(figureName)) {
    case CIRCLE:
        circle circle_object;
        parse_circle(input, &circle_object);
        find_circle_param(circle_object);
    break;

    case ERROR:
        cout << "Wrong name";
    }


    return 0;
}
