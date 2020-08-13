#pragma once
#include "hge.h"

class IDrawable {
public:
	virtual void draw(HGE *hge)=0;
};