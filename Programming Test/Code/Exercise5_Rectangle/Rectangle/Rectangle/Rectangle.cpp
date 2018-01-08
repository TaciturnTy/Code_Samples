/*
	Tyler Paulley
	10/15/2017
	Exercise 5

	This program uses the formula found here: https://martin-thoma.com/how-to-check-if-a-point-is-inside-a-rectangle/
	If the summed area of the four triangles formed by a point and two points on a rectangle is greater than the area of the 
	rectangle, then the point is not within the rectangle.

	Assumptions:
	This program assumes that localX is intended to store the x coordinates of a vector of length 1 
	starting at a rectangle's center and pointing towards the top right corner of the rectangle.

	The same applies for localY but instead it stores the y coordinates of the normalized vector.

	For example, a rectangle with center (0, 0) and top right corner (1, 2) would have a localX of (0, .447)
	and localY of (0, .894) since sqrt(.894^2 + .447^2) = 1. 
*/
#include <iostream> 
#include <math.h>

struct s_Vector
{
	float x;
	float y;
};

struct s_Rectangle
{
	s_Vector center;		// center of the rect in world space
	s_Vector localX;		// local space X direction vector, normalized
	s_Vector localY;		// local space Y direction vector, normalized
	float fExtentsX;		// distance from the rect center to the right edge
	float fExtentsY;		// distance from the rect center to the top edge
};

bool IsPointWithinDistOfRectangle(s_Rectangle & rect, s_Vector & point, float distance)
{
	//find four points of rectangle in world space 
	s_Vector topRight = { rect.center.x + rect.fExtentsX + distance, rect.center.y + rect.fExtentsY + distance };
	s_Vector topLeft = { rect.center.x - rect.fExtentsX - distance, rect.center.y + rect.fExtentsY + distance };
	s_Vector bottomLeft = { rect.center.x - rect.fExtentsX - distance, rect.center.y - rect.fExtentsY - distance };
	s_Vector bottomRight = { rect.center.x + rect.fExtentsX + distance, rect.center.y - rect.fExtentsY - distance };
	std::cout << "Rectangle points after adding distance: "
			  << "(" << topRight.x << ", " << topRight.y << ") "
			  << "(" << topLeft.x << ", " << topLeft.y << ") "
			  << "(" << bottomLeft.x << ", " << bottomLeft.y << ") "
			  << "(" << bottomRight.x << ", " << bottomRight.y << ")\n";

	float rectWidth = 2 * (rect.fExtentsX + distance);
	float rectLength = 2 * (rect.fExtentsY + distance);
	float rectArea = rectLength * rectWidth;
	std::cout << "Rectangle Area: " << rectArea << "\n";

	//find the area of the four triangles formed by the point and the rectangle's points
	float areaTriangleTL_TR = abs(0.5 * (topLeft.x * (topRight.y - point.y) + topRight.x * (point.y - topLeft.y) + point.x * (topLeft.y - topRight.y)));
	float areaTriangleTL_BL = abs(0.5 * (topLeft.x * (bottomLeft.y - point.y) + bottomLeft.x * (point.y - topLeft.y) + point.x * (topLeft.y - bottomLeft.y)));
	float areaTriangleBR_BL = abs(0.5 * (bottomRight.x * (bottomLeft.y - point.y) + bottomLeft.x * (point.y - bottomRight.y) + point.x * (bottomRight.y - bottomLeft.y)));
	float areaTriangleBR_TR = abs(0.5 * (bottomRight.x * (topRight.y - point.y) + topRight.x * (point.y - bottomRight.y) + point.x * (bottomRight.y - topRight.y)));

	//sum the area of the four triangles
	float triangleAreaSum = areaTriangleBR_BL + areaTriangleBR_TR + areaTriangleTL_BL + areaTriangleTL_TR;
	std::cout << "Triangle Sum Area: " << triangleAreaSum << "\n";

	//if the sum of the area of the triangles is not equal to the area of the rectangle, 
	//then the point is not within the distance from the rectangle
	if (rectArea == triangleAreaSum)
		return true;
	else
		return false;
}

//knowing the normalized vector is of length 1, deltaX can be found by 1 / sqrt(slope^2 + 1)
float GetNormalizedX(float slope)
{
	float divisor = sqrt(slope * slope + 1);
	return 1 / divisor;
}

//knowing the normalized vector is of length 1, deltaY can be found by 1 / sqrt(1 / slope^2 + 1)
float GetNormalizedY(float slope)
{
	float divisor = sqrt(1 / (slope * slope) + 1);
	return 1 / divisor;
}

//prints details about the rectangle and whether the point is within the specified distance
void print(s_Rectangle & rect, s_Vector & point, float dist)
{
	std::cout << "The point (" << point.x << ", " << point.y << ") is within " << dist
			  << " unit(s) of the rectangle \nwith center (" << rect.center.x << ", "
			  << rect.center.y << "), X extent " << rect.fExtentsX << ", and Y extent "
			  << rect.fExtentsY << ": " << std::boolalpha << IsPointWithinDistOfRectangle(rect, point, dist)
			  << "\n\n";
}

int main(int argv, char** argc)
{
	//create two rectangles with different centers and extents for testing
	s_Vector center = { 0.0, 0.0 };
	float fExtentsX = 1.0;
	float fExtentsY = 2.0;
	float slope = fExtentsY / fExtentsX;
	s_Vector localX = { 0.0, GetNormalizedX(slope)};	//find x coordinates of the normalized vector to the top right point of the rectangle
	s_Vector localY = { 0.0, GetNormalizedY(slope)};	//find y coordinates of the normalized vector to the top right point of the rectangle

	s_Rectangle rect1 = { center, localX, localY, fExtentsX, fExtentsY };

	center = { 5.0, 5.0 };
	fExtentsX = 1.0;
	fExtentsY = 1.0;
	slope = fExtentsY / fExtentsX;
	localX = { 0.0, GetNormalizedX(slope) };
	localY = { 0.0, GetNormalizedY(slope) };

	s_Rectangle rect2 = { center, localX, localY, fExtentsX, fExtentsY };

	//create points and distances for testing
	s_Vector point1 = { 3, 4 };
	s_Vector point2 = { 1, 1 };
	float distance1 = 1.0; 
	float distance2 = 3.0;
	
	//test whether the points are within the distance from the rectangles
	print(rect1, point1, distance1);
	print(rect1, point2, distance1);
	print(rect1, point1, distance2);
	print(rect1, point2, distance2);

	print(rect2, point1, distance1);
	print(rect2, point2, distance1);
	print(rect2, point1, distance2);
	print(rect2, point2, distance2);

	std::getchar();
	return 0;
}

