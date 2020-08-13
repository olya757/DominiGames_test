#pragma once
//методы рисования фигур
class HelpGraphic {
public:
	//отрисовать клетку
	static void drawCell(HGE* hge, Vertex p1, Vertex p2, hgeColor color);
	//отрисовать треугольник
	static void drawTriangle(HGE* hge, Vertex p1, Vertex p2, Vertex p3, hgeColor color);
	//отрисовать круг
	static void drawCircle(HGE* hge, Vertex center, int radius, hgeColor color, int amount_of_triangles);
	//отрисовать пешку
	static void drawPawn(HGE* hge, Vertex center, int height, hgeColor color);
};