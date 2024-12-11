#include "Camera.h"
Camera::Camera(Entity* assignation, glm::vec3 offset, float p, float y)
	: Assigned(assignation), Offset(offset), Rotation(glm::vec3(p, y, 0)) {
}

Camera::Camera(Entity* assignation, glm::vec2 rotation, glm::vec3 offset)
	: Assigned(assignation), Offset(offset), Rotation(glm::vec3(rotation.x, rotation.y, 0)),dragging(true) {
}

Camera::Camera():dragging(true){
	Assigned = nullptr;
	Offset = glm::vec3(0); 
	Rotation = glm::vec3(0);
}

void Camera::Update(float rotationz, float rotationX)
{


	//!	Update roll and yaw or whatever
	Rotation.x = (Rotation.x > fullCycle ? 0.0f : Rotation.x) + (rotationz * Sensitivity);
	Rotation.y = (Rotation.y > fullCycle ? 0.0f : Rotation.y)+ (rotationz * Sensitivity);
}

glm::vec3 Camera::GetPosition(void) const
{
	return Assigned != nullptr ? glm::vec3(Assigned->Position.x,0,Assigned->Position.y) + Offset : Offset;
}
