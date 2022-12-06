#include "plane.h"
#include <limits.h>

plane::plane()
{
    sourceAP = -1;
    destinationAP = -1; 
    weight = INT_MAX;
};

plane::plane(int s, int d)
{
    sourceAP = s;
    destinationAP = d; 
    weight = INT_MAX;
};

plane::plane(int s, int d, double w)
{
    sourceAP = s;
    destinationAP = d; 
    weight = w;
};

int plane::getSourceId() 
{
    return sourceAP;
}

int plane::getDestId() 
{
    return destinationAP;
}

double plane::getWeight() 
{
    return weight;
}

void plane::setWeight(double w) 
{
    weight = w;
}

void plane::setSource(double s) 
{
    sourceAP = s;
}

void plane::setDestination(double d) 
{
    destinationAP = d; 
}

bool plane::operator<(const plane& other) const 
{
    return weight < other.weight;
}

bool plane::operator==(plane& other) const 
{
    if (sourceAP != other.sourceAP)
        return false;
    if (destinationAP != other.destinationAP)
        return false;
    return true;
}