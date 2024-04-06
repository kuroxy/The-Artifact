#pragma once
#include <memory>

#include "Texture.hpp"


namespace Engine
{
	class Camera;
}
namespace Tmpl8
{
	class vec2;
}


class ResourceBar
{
public:
	ResourceBar(std::shared_ptr < Engine::Texture > texture,int barLeft, int barTop, int barRight, int barBottom, float minValue, float maxValue)
		: barTexture{ texture }
		, barLeft{ barLeft }
		, barTop{ barTop }
		, barRight{ barRight }
		, barBottom{ barBottom }
		, maxValue{ maxValue } {}

	ResourceBar(std::shared_ptr < Engine::Texture > texture, int barLeft, int barTop, int barRight, int barBottom, float maxValue)
		: barTexture{ texture }
		, barLeft{ barLeft }
		, barTop{ barTop }
		, barRight{ barRight }
		, barBottom{ barBottom }
		, maxValue{ maxValue } {}

	void setMaxValue(float maxValue) {
		this->maxValue = maxValue;
	}
	
	void setValue(float value) { currentValue = value; }

	float getValue() const { return currentValue; }


	void draw(Engine::Camera& camera, Tmpl8::vec2 screenPosition, Tmpl8::Pixel barColor) const;

private:
	std::shared_ptr < Engine::Texture > barTexture;
	// from which pixel the bar should start and where it should end. Because resource bars can have some decoration to the right/left of it.
	
	// offsets of the topleft of the texture. This forms the rectangle where the bar is being drawn.
	int barLeft = 0;
	int barTop = 0;

	int barRight = 10;
	int barBottom = 10;



	// the range of the resource bar
	float maxValue = 100.f;
	float currentValue = 0.f;

};