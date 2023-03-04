// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"
#include "MathUtil.h"

Star::Star()
{
}

Star::~Star()
{
}


//Converting from polar to 3D cartesian coordinates where:
//radius:distance, Horizontal rotation(from x-axis):Right Acension, Vertical rotation(from x-axis):Declination.
FVector EquitorialToCartesian(float distance, float rightAcension, float declination)
{
    float x;
    float y;
    float z;

    x = distance * FMath::Cos(rightAcension);
    y = distance * FMath::Sin(rightAcension);
    z = distance * FMath::Cos(declination);

    return Fvector(x,y,z);
}

double RightAcensionNotationToRadians(int hours, int minutes, double seconds)
{
    double degrees;
    double radians;

    degrees = (double)hours + ((double)minutes / 60) + (seconds/3600)

    radians = degrees * TMathUtilConstants::DegtoRad;

    return radians;
}

double DegreesToRadians(double degrees)
{
    return degrees * TMathUtilConstants::DegtoRad;
}