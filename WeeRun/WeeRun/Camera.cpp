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

void Camera::Update(float p, float y)
{
	//!	Update pitch and yaw or whatever
	_pitch = (_pitch > TWOPI ? 0.0f : _pitch) + p;
	_yawn = (_yawn > TWOPI ? 0.0f : _yawn) + y;
}

vec3 Camera::GetPosition() const
{
	//LMAO RIP MEMORY
	return  vec3(_offset.x+_assigned->Position.x,_offset.y, _offset.z + _assigned->Position.y);
}

vec2 Camera::GetRotation() const
{
	return vec2(_pitch,_yawn);
}
