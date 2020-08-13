#pragma once
//состояние клетки
enum class State
{
	White,//белая пешка
	Black,//черная пешка
	None//пустая клетка
};
//место клетки на доске
struct Position
{
	int X;
	int Y;
};
//точка
struct Vertex {
	double X;
	double Y;
};
//прямоугольник
struct Rect
{
	Position leftTop;
	Position rightBottom;
};
//ход, откуда и куда
struct Move
{
	Position from;
	Position to;
};