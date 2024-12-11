#include <math.h>
#include <stdio.h>

#define GAMEMANAGER_CONVERTER_DEGREE2RADIANS(fov) fov ;

int main(int argc, char** argv) {
	long value = 1044381696;
	float real = 0.5f;
	printf("%f\n", *(float*)&value);
	printf("%d\n", *(long*)&real);

}