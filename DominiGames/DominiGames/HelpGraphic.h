#pragma once

class HelpGraphic {
public:
	static void drawCell(HGE* hge, Vertex p1, Vertex p2, hgeColor color);

	static void drawTriangle(HGE* hge, Vertex p1, Vertex p2, Vertex p3, hgeColor color);

	static void drawCircle(HGE* hge, Vertex center, int radius, hgeColor color, int amount_of_triangles);

	static void drawPawn(HGE* hge, Vertex center, int height, hgeColor color);
};