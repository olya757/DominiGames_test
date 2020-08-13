#pragma once
#include "hge.h"
//абстрактный класс, отрисовка
class IDrawable {
public:
	virtual void draw(HGE *hge)=0;
};