#include "Vector2D.h"

Vector2D::Vector2D(float xin, float yin)
	: x(xin), y(yin)
{
}

Vector2D::~Vector2D()
{
}

void Vector2D::setPosition(float xin, float yin)
{
	x = xin;
	y = yin;
}

Vector2D Vector2D::getVector() {
	Vector2D vec(x, y);

	return vec;
}
