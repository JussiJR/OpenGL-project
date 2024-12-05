#pragma once
#ifndef __camera_h_
#define __camera_h_

#define TWOPI 6.28318530718

#include "Entity.h"

class Camera {
private:

	/// <summary>
	/// pointer to assigned object
	/// </summary>
	Entity* _assigned;
	vec3 _offset;

	float _pitch;
	float _yawn;

public:
	Camera(Entity* assignation, vec3 offset = vec3(0), float p = 0.0f, float y = 0.0f);
	Camera(Entity* assignation, vec2 rotation = vec2(0), vec3 offset = vec3(0));
	Camera();

	Entity* getPointed() const;
	void Update(float p,float y);

	vec3 GetPosition() const;
};

#endif