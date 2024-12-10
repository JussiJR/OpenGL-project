#include "Camera.h"
Camera::Camera(Entity* assignation, glm::vec3 offset, float p, float y)
	: _assigned(assignation), Offset(offset), Rotation(glm::vec3(p, y, 0)) {
}

Camera::Camera(Entity* assignation, glm::vec2 rotation, glm::vec3 offset)
	: _assigned(assignation), Offset(offset), Rotation(glm::vec3(rotation.x, rotation.y, 0)) {

}

Camera::Camera(){
	_assigned = nullptr;
	Offset = glm::vec3(0); 
	Rotation = glm::vec3(0);
}
Entity* Camera::getPointed(void) const
{
	return _assigned;
}

void Camera::Update(float p, float y)
{
	//!	Update roll and yaw or whatever
	Rotation.x = (Rotation.x > fullCycle ? 0.0f : Rotation.x) + p;
	Rotation.z = (Rotation.z > fullCycle ? 0.0f : Rotation.z) + y;
}

glm::vec3 Camera::GetPosition(void) const
{
	return  _assigned ? glm::vec3(Offset.x+(float)_assigned->x,Offset.y, Offset.z + (float)_assigned->y) : Offset;
}
