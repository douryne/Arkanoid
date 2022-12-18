#include "Border.h"


void Border::DrawBorder(Graphics& gfx)
{

	//top
	gfx.DrawRect(int(left), int(top), int(right), int(top)+ int(borderWidth), borderColor);
	//top
	//left
	gfx.DrawRect(int(left), int(top)+ int(borderWidth), int(left) + int(borderWidth), int(bottom) - int(borderWidth), borderColor);
	//left
	//right
	gfx.DrawRect(int(right), int(top)+ int(borderWidth) - 15, int(right) + int(borderWidth), int(bottom) - int(borderWidth) + 15, borderColor);
	//right
	//bottom
	gfx.DrawRect(int(left), int(bottom) - int(borderWidth), int(right), int(bottom), borderColor);
	//bottom
}
