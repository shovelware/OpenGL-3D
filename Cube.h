#ifndef CUBE_H
#define CUBE_H

#include "std.h"

class Cube  {
private:
	GLdouble aaa[3] = { 1, 1, 1 };
	GLdouble aab[3] = { 1, 1, -1 };
	GLdouble abb[3] = { 1, -1, -1 };
	GLdouble aba[3] = { 1, -1, 1 };
	GLdouble baa[3] = { -1, 1, 1 };
	GLdouble bab[3] = { -1, 1, -1 };
	GLdouble bba[3] = { -1, -1, 1 };
	GLdouble bbb[3] = { -1, -1, -1 };

	double r = 0;

public:
	Cube()
	{
		
	}
	void Draw()
	{
		r += 0.5;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glRotated(r, 1, 0, 0);
		glRotated(r, 0, 1, 0);
		glScaled(0.5, 0.5, 0.5);

		
	}
};

#endif