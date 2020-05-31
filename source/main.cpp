#include <stdio.h>
#include <GL/freeglut.h>

#include "callback/CallbackFunc.hpp"

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL 430");

	glutDisplayFunc(CallbackFunc::display_func);
	glutKeyboardFunc(CallbackFunc::keyboard_func);

	glutMainLoop();
	return 0;
}

