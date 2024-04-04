#pragma once

enum class HexagonalDirection
{
	UP,
	RIGHT_UP,
	RIGHT_DOWN,
	DOWN,
	LEFT_DOWN,
	LEFT_UP
};

HexagonalDirection next(HexagonalDirection direction);
HexagonalDirection prev(HexagonalDirection direction);