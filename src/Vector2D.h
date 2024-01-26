#pragma once

class Vector2D {
public:
	float x;
	float y;
	Vector2D(float xin, float yin);

	~Vector2D();

	void setPosition(float xin, float yin);

	Vector2D getVector();
};