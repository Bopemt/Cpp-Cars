#ifndef RECT_H
#define RECT_H

#include "sPos.h"
#include "sSize.h"

struct sRect {
	sPos pos;
	const sSize size;

	sRect(float x, float y, float w, float h) : pos(x, y), size(w, h) {}
};

#endif // !RECT_H
