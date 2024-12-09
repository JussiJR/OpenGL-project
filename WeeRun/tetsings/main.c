#include <math.h>
#include <stdio.h>
int main(int argc, char** argv) {
	
	float x = 9.0f;
	long t = *(long*)&x;
	printf("%f\n", x);
}