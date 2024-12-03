#include "Player_refernce.h"

PlayerReference::PlayerReference(int* data, float fov)
{
	_entityData = data;
	_fov = fov;
	_pitch = _yaw = 0;
}
