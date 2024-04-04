#include "Pixel.h"

Pixel::Pixel()
{
	xCoord = 0;
	yCoord = 0;
}

Pixel::Pixel(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

Pixel::Pixel(const Pixel& other)
{
	xCoord = other.xCoord;
	yCoord = other.yCoord;
}

Pixel& Pixel::operator=(const Pixel& other)
{
	if (this != &other)
	{
		xCoord = other.xCoord;
		yCoord = other.yCoord;
	}
	return *this;
}

Pixel Pixel::clone() const
{
	return Pixel(xCoord, yCoord);
}

Pixel Pixel::operator+() const
{
	return Pixel(xCoord, yCoord);
}

bool Pixel::equals(const Pixel& other) const
{
	return operator==(other);
}

bool Pixel::operator==(const Pixel& other) const
{
	return xCoord == other.xCoord && yCoord == other.yCoord;
}

bool Pixel::operator!=(const Pixel& other) const
{
	return !operator==(other);
}

Pixel& Pixel::add(const Pixel& other)
{
	return operator+=(other);
}

Pixel& Pixel::subtract(const Pixel& other)
{
	return operator-=(other);
}

Pixel& Pixel::multiply(int factor)
{
	return operator*=(factor);
}

Pixel& Pixel::multiply(float factor)
{
	return operator*=(factor);
}

Pixel& Pixel::multiply(double factor)
{
	return operator*=(factor);
}

Pixel& Pixel::operator+=(const Pixel& other)
{
	xCoord += other.xCoord;
	yCoord += other.yCoord;
	return *this;
}

Pixel& Pixel::operator-=(const Pixel& other)
{
	xCoord -= other.xCoord;
	yCoord -= other.yCoord;
	return *this;
}

Pixel& Pixel::operator*=(int factor)
{
	xCoord *= factor;
	yCoord *= factor;
	return *this;
}

Pixel& Pixel::operator*=(float factor)
{
	xCoord *= factor;
	yCoord *= factor;
	return *this;
}

Pixel& Pixel::operator*=(double factor)
{
	xCoord *= factor;
	yCoord *= factor;
	return *this;
}

Pixel Pixel::plus(const Pixel& other) const
{
	return operator+(other);
}

Pixel Pixel::minus(const Pixel& other) const
{
	return operator-(other);
}

Pixel Pixel::times(int factor) const
{
	return operator*(factor);
}

Pixel Pixel::times(float factor) const
{
	return operator*(factor);
}

Pixel Pixel::times(double factor) const
{
	return operator*(factor);
}

Pixel Pixel::operator+(const Pixel& other) const
{
	int x = xCoord + other.xCoord;
	int y = yCoord + other.yCoord;
	return Pixel(x, y);
}

Pixel Pixel::operator-(const Pixel& other) const
{
	int x = xCoord - other.xCoord;
	int y = yCoord - other.yCoord;
	return Pixel(x, y);
}

Pixel Pixel::operator*(int factor) const
{
	int x = xCoord * factor;
	int y = yCoord * factor;
	return Pixel(x, y);
}

Pixel Pixel::operator*(float factor) const
{
	int x = (int)((float)xCoord * factor);
	int y = (int)((float)yCoord * factor);
	return Pixel(x, y);
}

Pixel Pixel::operator*(double factor) const
{
	int x = (int)((double)xCoord * factor);
	int y = (int)((double)yCoord * factor);
	return Pixel(x, y);
}

Pixel& Pixel::reverse()
{
	xCoord = -xCoord;
	yCoord = -yCoord;
	return *this;
}

Pixel Pixel::opposite() const
{
	return operator-();
}

Pixel Pixel::operator-() const
{
	return Pixel(-xCoord, -yCoord);
}

Pixel operator*(int factor, const Pixel& Pixel)
{
	return Pixel * factor;
}

Pixel operator*(float factor, const Pixel& Pixel)
{
	return Pixel * factor;
}

Pixel operator*(double factor, const Pixel& Pixel)
{
	return Pixel * factor;
}
