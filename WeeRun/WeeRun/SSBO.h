#pragma once
#ifndef __ssbo_h_
#define __ssbo_h_

#include <glad/glad.h>


class SSBO {
public:
	GLuint ID;

	SSBO();

	void Update(void* data);

};

#endif