#include "CartesianPoint.h"
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
// constructor for CartesianPoint
CartesianPoint::CartesianPoint(int x, int y): m_x(x), m_y(y)
{
	//SetPoint(x, y);
}

void CartesianPoint::SetPoint(int x, int y)
{
	SetX(x);
	SetY(y);
}

void CartesianPoint::SetX(int x)
{
	m_x = x;
}

void CartesianPoint::SetY(int y)
{
	m_y = y;
}

int CartesianPoint::GetX() const
{
	return m_x;
}

int CartesianPoint::GetY() const
{
	return m_y;
}


/** GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/
double CartesianPoint::GetDistanceTo(const CartesianPoint& point_to) const
{
	// difference between x values
	int xDelta = point_to.m_x - m_x;

	// difference between y values
	int yDelta = point_to.m_y - m_y;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

/** ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/

std::string CartesianPoint::ToString() const
{
	// declare a stringstream object
	std::stringstream strOut;

	// build the string
	strOut << "(" << m_x << ", " << m_y << ")";

	// return the string
	return strOut.str();
}
CartesianPoint::~CartesianPoint()
{
}

double CartesianPoint::operator-(const CartesianPoint& point_to) const
{
	// difference between x values
	int xDelta = point_to.GetX() - m_x;

	// difference between y values
	int yDelta = point_to.GetY() - m_y;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

bool CartesianPoint::operator==(const CartesianPoint& other_point) const
{
	return ((GetX() == other_point.GetX()) && (GetY() == other_point.GetY()));
}
CartesianPoint::CartesianPoint(const CartesianPoint& point2)
{
	SetPoint(point2.GetX(), point2.GetY());
}
CartesianPoint CartesianPoint::operator+(const CartesianPoint& point2) const
{
	CartesianPoint tempPoint;
	tempPoint.SetX((*this).GetX() + point2.GetX());
	tempPoint.SetX((*this).GetY() + point2.GetY());

	return tempPoint;
}

std::ostream& operator<<(std::ostream& out, const CartesianPoint point)
{
	out << point.ToString();
	return out;
}

std::istream& operator>>(std::istream& in, const CartesianPoint point)
{
	in >> point.m_x;
	in.ignore();
	in >> point.m_y;

	return in;
}
