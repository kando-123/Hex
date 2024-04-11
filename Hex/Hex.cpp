#include "Hex.h"
#include "Pixel.h"
#include <exception>

using Exception = std::exception;

Hex::Hex()
{
	pCoord = 0;
	qCoord = 0;
	rCoord = 0;
}

Hex::Hex(int p, int q, int r)
{
	if (p + q + r == 0)
	{
		pCoord = p;
		qCoord = q;
		rCoord = r;
	}
	else
	{
		throw Exception("Hex.<init> : invalid coords");
	}
}

Hex::Hex(const Hex& other)
{
	pCoord = other.pCoord;
	qCoord = other.qCoord;
	rCoord = other.rCoord;
}

Hex& Hex::operator=(const Hex& other)
{
	if (this != &other)
	{
		pCoord = other.pCoord;
		qCoord = other.qCoord;
		rCoord = other.rCoord;
	}
	return *this;
}

Hex Hex::clone() const
{
	return operator+();
}

Hex Hex::operator+() const
{
	return Hex(+pCoord, +qCoord, +rCoord);
}

bool Hex::equals(const Hex& other) const
{
	return operator==(other);
}

bool Hex::operator==(const Hex& other) const
{
	return pCoord == other.pCoord && qCoord == other.qCoord && rCoord == other.rCoord;
}

bool Hex::operator!=(const Hex& other) const
{
	return !operator==(other);
}

Hex Hex::getOrigin()
{
	return Hex(0, 0, 0);
}

int Hex::getP() const
{
	return pCoord;
}

int Hex::getQ() const
{
	return qCoord;
}

int Hex::getR() const
{
	return rCoord;
}

Hex& Hex::add(const Hex& other)
{
	return operator+=(other);
}

Hex& Hex::subtract(const Hex& other)
{
	return operator-=(other);
}

Hex& Hex::multiply(int factor)
{
	return operator*=(factor);
}

Hex& Hex::operator+=(const Hex& other)
{
	pCoord += other.pCoord;
	qCoord += other.qCoord;
	rCoord += other.rCoord;
	return *this;
}

Hex& Hex::operator-=(const Hex& other)
{
	pCoord -= other.pCoord;
	qCoord -= other.qCoord;
	rCoord -= other.rCoord;
	return *this;
}

Hex& Hex::operator*=(int factor)
{
	pCoord *= factor;
	qCoord *= factor;
	rCoord *= factor;
	return *this;
}

Hex Hex::plus(const Hex& other) const
{
	return operator+(other);
}

Hex Hex::minus(const Hex& other) const
{
	return operator-(other);
}

Hex Hex::times(int factor) const
{
	return operator*(factor);
}

Hex Hex::operator+(const Hex& other) const
{
	int p = pCoord + other.pCoord;
	int q = qCoord + other.qCoord;
	int r = rCoord + other.rCoord;
	return Hex(p, q, r);
}

Hex Hex::operator-(const Hex& other) const
{
	int p = pCoord - other.pCoord;
	int q = qCoord - other.qCoord;
	int r = rCoord - other.rCoord;
	return Hex(p, q, r);
}

Hex Hex::operator*(int factor) const
{
	int p = pCoord * factor;
	int q = qCoord * factor;
	int r = rCoord * factor;
	return Hex(p, q, r);
}

Hex& Hex::reverse()
{
	pCoord = -pCoord;
	qCoord = -qCoord;
	rCoord = -rCoord;
	return *this;
}

Hex Hex::opposite() const
{
	return operator-();
}

Hex Hex::operator-() const
{
	return Hex(-pCoord, -qCoord, -rCoord);
}

Hex& Hex::rotateRight()
{
	int p = -qCoord;
	int q = -rCoord;
	int r = -pCoord;
	pCoord = p;
	qCoord = q;
	rCoord = r;
	return *this;
}

Hex& Hex::rotateLeft()
{
	int p = -rCoord;
	int q = -pCoord;
	int r = -qCoord;
	pCoord = p;
	qCoord = q;
	rCoord = r;
	return *this;
}

Hex Hex::rotatedRight() const
{
	return Hex(-rCoord, -rCoord, -pCoord);
}

Hex Hex::rotatedLeft() const
{
	return Hex(-rCoord, -pCoord, -qCoord);
}

Hex& Hex::shift(HexagonalDirection direction)
{
	switch (direction)
	{
	case HexagonalDirection::UP:
		--qCoord;
		++rCoord;
		break;
	case HexagonalDirection::RIGHT_UP:
		++pCoord;
		--qCoord;
		break;
	case HexagonalDirection::RIGHT_DOWN:
		++pCoord;
		--rCoord;
		break;
	case HexagonalDirection::DOWN:
		++qCoord;
		--rCoord;
		break;
	case HexagonalDirection::LEFT_DOWN:
		--pCoord;
		++qCoord;
		break;
	case HexagonalDirection::LEFT_UP:
		--pCoord;
		++rCoord;
		break;
	}
	return *this;
}

Hex Hex::neighbor(HexagonalDirection direction) const
{
	int p = pCoord;
	int q = qCoord;
	int r = rCoord;
	switch (direction)
	{
	case HexagonalDirection::UP:
		--q;
		++r;
		break;
	case HexagonalDirection::RIGHT_UP:
		++p;
		--q;
		break;
	case HexagonalDirection::RIGHT_DOWN:
		++p;
		--r;
		break;
	case HexagonalDirection::DOWN:
		++q;
		--r;
		break;
	case HexagonalDirection::LEFT_DOWN:
		--p;
		++q;
		break;
	case HexagonalDirection::LEFT_UP:
		--p;
		++r;
		break;
	}
	return Hex(p, q, r);
}

Vector<Hex> Hex::neighbors() const
{
	Vector<Hex> hexes = Vector<Hex>(6);
	hexes.push_back(neighbor(HexagonalDirection::UP));
	hexes.push_back(neighbor(HexagonalDirection::RIGHT_UP));
	hexes.push_back(neighbor(HexagonalDirection::RIGHT_DOWN));
	hexes.push_back(neighbor(HexagonalDirection::DOWN));
	hexes.push_back(neighbor(HexagonalDirection::LEFT_DOWN));
	hexes.push_back(neighbor(HexagonalDirection::LEFT_UP));
	return hexes;
}

int Hex::distance(const Hex& other) const
{
	int pDistance = abs(pCoord - other.pCoord);
	int qDistance = abs(qCoord - other.qCoord);
	int rDistance = abs(rCoord - other.rCoord);
	return (pDistance + qDistance + rDistance) / 2;
}

bool Hex::isRadial() const
{
	return pCoord == 0 || qCoord == 0 || rCoord == 0;
}

inline int abs(int x)
{
	return x < 0 ? -x : x;
}

int Hex::ring() const
{
	return (abs(pCoord) + abs(qCoord) + abs(rCoord)) / 2;
}

Pixel Hex::getCenter(int outerRadius, int innerRadius)
{
	int x = pCoord * outerRadius * 1.5;
	int y = (qCoord - rCoord) * innerRadius;
	return Pixel(x, y);
}

int Hex::hashCode()
{
	constexpr int BITS_PER_HALF_INT = sizeof(int) * 8 / 2;
	constexpr int MAX_HALF_INT = ~((~0U) << BITS_PER_HALF_INT);
	return ((pCoord & MAX_HALF_INT) << BITS_PER_HALF_INT) | (qCoord & MAX_HALF_INT);
}

Hex operator*(int factor, const Hex& hex)
{
	return hex * factor;
}
