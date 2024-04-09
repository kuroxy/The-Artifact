#include "ResourceBar.hpp"
#include "Camera.hpp"
#include "template.h"


void ResourceBar::draw(Engine::Camera& camera, Tmpl8::vec2 screenPosition, Tmpl8::Pixel barColor) const
{

	float progress = Tmpl8::Clamp(currentValue / maxValue, 0.f, 1.f);
	

	camera.drawBar(screenPosition.x + barLeft, screenPosition.y + barTop, screenPosition.x + barLeft + (barRight - barLeft) * progress -1, screenPosition.y + barBottom, barColor);

	camera.blitTexture(barTexture.get(), screenPosition.x, screenPosition.y);
}