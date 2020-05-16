#include <GL/freeglut.h>
#include "CallbackFunc.hpp"

void CallbackFunc::display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f( 0.5f, -0.5f);
	glVertex2f( 0.5f,  0.5f);
	glEnd();
	glFinish();
	
	glutSwapBuffers();

	return;
}
