#include "Camera.h"

Camera::Camera(Entity* assignation, vec3 offset, float p, float y)
{
	_assigned = assignation;
	_offset = offset;
	_pitch = p;
	_yawn = y;
}

Camera::Camera(Entity* assignation, vec2 rotation, vec3 offset)
{
	_assigned = assignation;
	_offset = offset;
	_pitch = rotation.x;
	_yawn = rotation.y;
}

Camera::Camera()
{
	_assigned = nullptr;
	_offset = vec3(0);
	_pitch = 0.f;
	_yawn = 0.f;
}

Entity* Camera::getPointed() const
{
	return _assigned;
}
