#include "HexagonalDirection.h"

HexagonalDirection next(HexagonalDirection direction)
{
	HexagonalDirection result = HexagonalDirection::UP;
	switch (direction)
	{
	case HexagonalDirection::UP:
		result = HexagonalDirection::RIGHT_UP;
		break;
	case HexagonalDirection::RIGHT_UP:
		result = HexagonalDirection::RIGHT_DOWN;
		break;
	case HexagonalDirection::RIGHT_DOWN:
		result = HexagonalDirection::DOWN;
		break;
	case HexagonalDirection::DOWN:
		result = HexagonalDirection::LEFT_DOWN;
		break;
	case HexagonalDirection::LEFT_DOWN:
		result = HexagonalDirection::LEFT_UP;
		break;
	case HexagonalDirection::LEFT_UP:
		result = HexagonalDirection::UP;
		break;
	}
	return result;
}

HexagonalDirection prev(HexagonalDirection direction)
{
	HexagonalDirection result = HexagonalDirection::UP;
	switch (direction)
	{
	case HexagonalDirection::UP:
		result = HexagonalDirection::LEFT_UP;
		break;
	case HexagonalDirection::LEFT_UP:
		result = HexagonalDirection::LEFT_DOWN;
		break;
	case HexagonalDirection::LEFT_DOWN:
		result = HexagonalDirection::DOWN;
		break;
	case HexagonalDirection::DOWN:
		result = HexagonalDirection::RIGHT_DOWN;
		break;
	case HexagonalDirection::RIGHT_DOWN:
		result = HexagonalDirection::RIGHT_UP;
		break;
	case HexagonalDirection::RIGHT_UP:
		result = HexagonalDirection::UP;
		break;
	}
	return result;
}