#pragma once

class Pixel
{
public:
	int xCoord;
	int yCoord;

	Pixel();
	Pixel(int x, int y);
	Pixel(const Pixel& other);

	Pixel& operator=(const Pixel& other);

	Pixel clone() const;
	Pixel operator+() const;

	bool equals(const Pixel& other) const;
	bool operator==(const Pixel& other) const;
	bool operator!=(const Pixel& other) const;

	Pixel& add(const Pixel& other);
	Pixel& subtract(const Pixel& other);
	Pixel& multiply(int factor);
	Pixel& multiply(float factor);
	Pixel& multiply(double factor);
	Pixel& operator+=(const Pixel& other);
	Pixel& operator-=(const Pixel& other);
	Pixel& operator*=(int factor);
	Pixel& operator*=(float factor);
	Pixel& operator*=(double factor);

	Pixel plus(const Pixel& other) const;
	Pixel minus(const Pixel& other) const;
	Pixel times(int factor) const;
	Pixel times(float factor) const;
	Pixel times(double factor) const;
	Pixel operator+(const Pixel& other) const;
	Pixel operator-(const Pixel& other) const;
	Pixel operator*(int factor) const;
	Pixel operator*(float factor) const;
	Pixel operator*(double factor) const;

	Pixel& reverse();

	Pixel opposite() const;
	Pixel operator-() const;
};

Pixel operator*(int factor, const Pixel& hex);
Pixel operator*(int factor, const Pixel& hex);
Pixel operator*(int factor, const Pixel& hex);