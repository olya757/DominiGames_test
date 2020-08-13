#pragma once
enum class State
{
	White,
	Black,
	None
};

struct Position
{
	int X;
	int Y;
};

struct Vertex {
	double X;
	double Y;
};

struct Rect
{
	Position leftTop;
	Position rightBottom;
};

struct Move
{
	Position from;
	Position to;
};