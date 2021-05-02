#include <algorithm>
#include <iostream>
#include <libgeometry/parse.h>
#include <string>

using namespace std;

string parse_name(string* input)
{
    string figureName;
    if (input->substr(0, 1) == " ") {
        input->erase(0, input->find_first_not_of(" "));
    }

    if (input->substr(input->find("(") - 1, 1) == " ") {
        input->erase(input->find(" "), input->find("(") - input->find(" "));
    }

    figureName = input->substr(0, input->find("("));
    return figureName;
}

Figures identify(string figure)
{
    string figureName;

    figureName = "circle";
    if (figure == figureName)
        return CIRCLE;

    return ERROR;
}
void parse_circle(string input, circle* circl)
{
    size_t end;
    input = input.erase(0, 6);
    if (input[0] == '(') {
        input.erase(0, 1);
        circl->x = stod(input, &end);
        input = input.erase(0, end);
        circl->y = stod(input, &end);
        input = input.erase(0, end + 1);
        circl->radius = stod(input, &end);
    };
}
