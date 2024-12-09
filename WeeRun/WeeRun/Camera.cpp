#include "Camera.h"

Camera::Camera(Entity* assignation, vec3 offset, float p, float y)
{
	_assigned = assignation;
	_offset = offset;
	_rotation = vec3(p, 0, y);


}

Camera::Camera(Entity* assignation, vec2 rotation, vec3 offset)
{
	_assigned = assignation;
	_offset = offset;
	_rotation = vec3(rotation.x, 0, rotation.y);
}

Camera::Camera()
{
	_assigned = nullptr;
	_offset = _rotation = vec3(0);
}

Entity* Camera::getPointed() const
{
	return _assigned;
}

void Camera::Update(float p, float y)
{
	//!	Update roll and yaw or whatever
	_rotation.x = (_rotation.x > TWOPI ? 0.0f : _rotation.x) + p;
	_rotation.z = (_rotation.z > TWOPI ? 0.0f : _rotation.z) + y;
}

vec3 Camera::GetPosition() const
{
	//LMAO RIP MEMORY
	return  vec3(_offset.x+_assigned->Position.x,_offset.y, _offset.z + _assigned->Position.y);
}

vec3 Camera::GetRotation() const
{
	return _rotation;
}

mat4 Camera::GetProjection() const
{
	return _projection;
}
