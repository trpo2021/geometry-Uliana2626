#pragma once

#include <libgeometry/geometry.h>
#include <string>

using namespace std;

string parse_name(string* input);
Figures identify(string figure);
void parse_circle(string input, circle* circl);