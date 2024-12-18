#pragma once
#ifndef __camera_h_
#define __camera_h_

#include <glm/matrix.hpp>
#include "Entity.h"


constexpr float fullCycle = 6.28318530718f;
constexpr float Sensitivity = 1.5f;

class Camera {
public:
	unsigned char dragging = 0;

	/// <summary>
	/// pointer to assigned object
	/// </summary>
	Entity* Assigned;

	/// <summary>
	/// Offset of the camera to assigned entity position
	/// </summary>
	glm::vec3 Offset;

	/// <summary>
	/// Vector representing rotation
	/// </summary>
	glm::vec2 Rotation;


	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="assignation">entity what camera will be using</param>
	/// <param name="offset">offse to entity object</param>
	/// <param name="p">pitch</param>
	/// <param name="y">yaw</param>
	Camera(Entity* assignation, glm::vec3 offset = glm::vec3(0), float p = 0.0f, float y = 0.0f);

	/// <summary>
	/// Constuctor without anythin else but glm objects
	/// </summary>
	/// <param name="assignation">entity to be assigned with camera</param>
	/// <param name="rotation">vec2 to represent rotations on pitch and yaw</param>
	/// <param name="offset">offset to position</param>
	Camera(Entity* assignation, glm::vec2 rotation = glm::vec2(0), glm::vec3 offset = glm::vec3(0));

	/// <summary>
	/// Empty constructor (sets all to 0 or null)
	/// </summary>
	Camera();

	/// <summary>
	/// Update method for camera
	/// </summary>
	/// <param name="p">Pitch to be added</param>
	/// <param name="y">Yaw to be added</param>
	void Update(float p, float y);

	/// <summary>
	/// Gets position in vec3
	/// </summary>
	/// <returns>vec3 representing Position of entity assigned to camera + offset</returns>
	glm::vec3 GetPosition(void) const;
};


#endif