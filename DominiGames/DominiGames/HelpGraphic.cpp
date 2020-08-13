#include <hge.h>
#include <hgecolor.h>
#include "HelpStructures.h"
#include <math.h>
#include "HelpGraphic.h"

void HelpGraphic::drawCell(HGE* hge, Vertex p1, Vertex p2, hgeColor color)
{
	auto clr = 0xFFFFA000;
	hgeColor clr_hge = hgeColor(clr);
	auto clr2 = clr_hge.GetHWColor();
	hgeQuad rect =
	{
		{
			{p1.X,p1.Y,1, color.GetHWColor(),1,1},
			{p1.X,p2.Y,1, color.GetHWColor(),1,1},
			{p2.X,p2.Y,1, color.GetHWColor(),1,1},
			{p2.X,p1.Y,1, color.GetHWColor(),1,1},
		},
		0,
		BLEND_DEFAULT

	};
	hge->Gfx_RenderQuad(&rect);
}

void HelpGraphic::drawTriangle(HGE* hge, Vertex p1, Vertex p2, Vertex p3, hgeColor color) {
	hgeTriple triple = {
		{
			{p1.X,p1.Y,1, color.GetHWColor(),1,1},
			{p2.X,p2.Y,1, color.GetHWColor(),1,1},
			{p3.X,p3.Y,1, color.GetHWColor(),1,1},
		},
		0,
		BLEND_DEFAULT

	};
	hge->Gfx_RenderTriple(&triple);
}

void HelpGraphic::drawCircle(HGE* hge, Vertex center, int radius, hgeColor color, int amount_of_triangles = 100)
{
	double angle = 2*(M_PI) / amount_of_triangles;
	Vertex p1 = { center.X - radius,center.Y };
	for (int i = 0; i < amount_of_triangles; i++) {
		Vertex v1 = { p1.X - center.X, p1.Y - center.Y };
		Vertex v2 = {
			v1.X * cos(angle) - v1.Y * sin(angle),
			v1.X * sin(angle) + v1.Y * cos(angle)
		};
		Vertex p2 = {
			center.X + v2.X,
			center.Y + v2.Y
		};
		drawTriangle(hge, p1, center, p2, color);
		p1.X = p2.X;
		p1.Y = p2.Y;
	}
}


void HelpGraphic::drawPawn(HGE* hge, Vertex center, int height, hgeColor color)
{
	Vertex circlecenter = { center.X,center.Y - height / 4 };
	int circle_radius = height / 4;
	Vertex left = { center.X - height / 4,center.Y + height / 2 };
	Vertex right = { center.X + height / 4,center.Y + height / 2 };
	drawTriangle(hge, left, center, right, color);
	drawCircle(hge, circlecenter, circle_radius, color);
}