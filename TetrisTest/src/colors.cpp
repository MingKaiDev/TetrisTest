#include "colors.h"

const Color darkGrey = {26,32,40,255};
const Color green = {47,240,47,255};
const Color red = {232,18,18,255};
const Color orange = {232,126,18,255};
const Color blue = {18,18,232,255};
const Color yellow = {232,232,18,255};
const Color purple = {126,18,232,255};
const Color cyan = {18,232,232,255};
const Color lightBlue = {0,0,255,255};
const Color darkBlue = {0,0,139,255};

std::vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow,purple,cyan,blue};
}