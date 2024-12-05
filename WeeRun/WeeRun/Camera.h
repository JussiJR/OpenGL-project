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
	
	/// <summary>
	/// Offset of the camera to assigned entity position
	/// </summary>
	vec3 _offset;

	/// <summary>
	/// Pitch of the camera
	/// </summary>
	float _pitch;

	/// <summary>
	/// Yaw of the camera
	/// </summary>
	float _yawn;

public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="assignation">entity what camera will be using</param>
	/// <param name="offset">offse to entity object</param>
	/// <param name="p">pitch</param>
	/// <param name="y">yaw</param>
	Camera(Entity* assignation, vec3 offset = vec3(0), float p = 0.0f, float y = 0.0f);
	
	/// <summary>
	/// Constuctor without anythin else but glm objects
	/// </summary>
	/// <param name="assignation">entity to be assigned with camera</param>
	/// <param name="rotation">vec2 to represent rotations on pitch and yaw</param>
	/// <param name="offset">offset to position</param>
	Camera(Entity* assignation, vec2 rotation = vec2(0), vec3 offset = vec3(0));
	
	/// <summary>
	/// Empty constructor (sets all to 0 or null)
	/// </summary>
	Camera();

	/// <summary>
	/// used to get pointer to entity what is assigned to camera
	/// </summary>
	/// <returns>Pointer to entity no error handling</returns>
	Entity* getPointed() const;

	/// <summary>
	/// Update method for camera
	/// </summary>
	/// <param name="p">Pitch to be added</param>
	/// <param name="y">Yaw to be added</param>
	void Update(float p,float y);

	/// <summary>
	/// Gets position in vec3
	/// </summary>
	/// <returns>vec3 representing Position of entity assigned to camera + offset</returns>
	vec3 GetPosition() const;

	/// <summary>
	/// Gets rotation
	/// </summary>
	/// <returns>Vec2 representing rotations pitch and yaw</returns>
	vec2 GetRotation() const;
};

#endif