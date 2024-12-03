#pragma once
#ifndef __playerReference_h_
#define __playerReference_h_


class PlayerReference {
private:
	int* _entityData;



	float _fov;
	float _pitch;
	float _yaw;

	


public:

	/// <summary>
	/// Creates Player Reference
	/// </summary>
	/// <param name="data"></param>
	/// <param name="fov"></param>
	PlayerReference(int* data,float fov);
};

#endif
