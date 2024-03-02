#include "types.h"

extern "C" void* NewPubSubType() 
{
    return (void *)new ShapePubSubType();
}

extern "C" void* NewShape(char *color) 
{ 
    auto shape = new Shape();
    shape->color(color);
    shape->position_x(45);
    return (void*)shape;
}