#include <stdio.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "CallbackFunc.hpp"

Camera CallbackFunc::cam = Camera(
			vec3(1.0, 0.0, 0.0),
			vec3(0.0, 0.0, 0.0),
			vec3(0.0, 0.0, 1.0)
			);

void CallbackFunc::display_func() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	vec3 pos = CallbackFunc::cam.getPos();
	vec3 focus = CallbackFunc::cam.getFocus();
	vec3 vup = CallbackFunc::cam.getVup();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pos.x, pos.y, pos.z, focus.x, focus.y, focus.z, vup.x, vup.y, vup.z);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f, -0.5f);
	glVertex3f(0.0f, 0.5f,  0.5f);
	glEnd();
	
	glutSwapBuffers();
	printf("calling\n");
	return;
}

void CallbackFunc::keyboard_func(unsigned char key, int x, int y) {
	switch(key) {
		case 'w':
			CallbackFunc::cam.pitch(5.0f);
			break;
		case 's':
			CallbackFunc::cam.pitch(-5.0f);
			break;
		case 'a':
			CallbackFunc::cam.yaw(5.0f);
			break;
		case 'd':
			CallbackFunc::cam.yaw(-5.0f);
			break;
	}
	glutPostRedisplay();
}
