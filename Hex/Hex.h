#pragma once
#include "HexagonalDirection.h"
#include "Pixel.h"
#include <vector>

template <typename T>
using Vector = std::vector<T>;

class Hex
{
private:
	int pCoord;
	int qCoord;
	int rCoord;

public:
	Hex();
	Hex(int p, int q, int r);
	Hex(const Hex& other);

	Hex& operator=(const Hex& other);

	Hex clone() const;
	Hex operator+() const;

	bool equals(const Hex& other) const;
	bool operator==(const Hex& other) const;
	bool operator!=(const Hex& other) const;

	static Hex getOrigin();

	int getP() const;
	int getQ() const;
	int getR() const;

	Hex& add(const Hex& other);
	Hex& subtract(const Hex& other);
	Hex& multiply(int factor);
	Hex& operator+=(const Hex& other);
	Hex& operator-=(const Hex& other);
	Hex& operator*=(int factor);

	Hex plus(const Hex& other) const;
	Hex minus(const Hex& other) const;
	Hex times(int factor) const; 
	Hex operator+(const Hex& other) const;
	Hex operator-(const Hex& other) const;
	Hex operator*(int factor) const;

	Hex& reverse();

	Hex opposite() const;
	Hex operator-() const;

	Hex& rotateRight();
	Hex& rotateLeft();

	Hex rotatedRight() const;
	Hex rotatedLeft() const;

	Hex& shift(HexagonalDirection direction);

	Hex neighbor(HexagonalDirection direction) const;
	Vector<Hex> neighbors() const;

	int distance(const Hex& other) const;
	bool isRadial() const;
	int ring() const;

	Pixel getCenter(int outerRadius, int innerRadius); 

	int hashCode();
};

Hex operator*(int factor, const Hex& hex);