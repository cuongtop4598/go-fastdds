#include "types.h"
#include <cstdlib>

extern "C" void *NewPubSubType()
{
    return (void *)new ShapePubSubType();
}

extern "C" void *NewShape(char *color)
{
    auto shape = new Shape();
    shape->color(color);
    shape->position_x(rand() % 100 + 1);
    shape->position_y(rand() % 100 + 1);
    return (void *)shape;
}