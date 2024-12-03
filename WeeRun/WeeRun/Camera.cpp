#include "Camera.h"

Camera::Camera(Entity* assignation, vec3 offset, float p, float y)
{
	_assigned = assignation;
	_offset = offset;
	_pitch = p;
	_yawn = y;
}
