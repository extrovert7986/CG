#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.hpp"

using namespace glm;

Camera::Camera() {
	this->pos = vec4(1.0, 0.0, 0.0, 1.0);
	this->focus = vec4(0.0, 0.0, 0.0, 1.0);
	this->vup = vec4(0.0, 0.0, 1.0, 0.0);
}

Camera::Camera(vec3 pos, vec3 focus, vec3 vup) {
	this->pos = vec4(pos, 1.0);
	this->focus = vec4(focus, 1.0);
	this->vup = vec4(vup, 0.0);
}

Camera::~Camera(){
	return;
}

void Camera::curParam() {
	printf("pos:   %f %f %f\n", this->pos.x, this->pos.y, this->pos.z);
	printf("focus: %f %f %f\n", this->focus.x, this->focus.y, this->focus.z);
	printf("vup:   %f %f %f\n", this->vup.x, this->vup.y, this->vup.z);
	printf("******");
}

vec3 Camera::getFocus() {
	return vec3(this->focus);
}

vec3 Camera::getPos() {
	return vec3(this->pos);
}

vec3 Camera::getVup() {
	return vec3(this->vup);
}

void Camera::roll(float deg = 5.0) {
	vec3 w = normalize(vec3(this->focus - this->pos));
	mat4 rot = rotate(mat4(1.0f), radians(deg), w);

	//rotate vup
	this->vup = normalize(rot * this->vup);
}

void Camera::yaw(float deg = 5.0) {
	printf("yaw\n");
	mat4 rot = rotate(mat4(1.0f), float(radians(deg)), vec3(this->vup));

	vec4 focusBasedOnPos = this->focus - this->pos;
	float dist = distance(this->focus, this->pos);
	
	//rotate the focal point
	this->focus = dist * normalize(rot * focusBasedOnPos) + this->pos;
	this->curParam();
}

void Camera::pitch(float deg = 5.0) {
	printf("pitch\n");
	// rotation matrix
	vec3 w = normalize(vec3(this->pos - this->focus));
	vec3 u = normalize(cross(vec3(this->vup), w));
	mat4 rot = rotate(mat4(1.0f), deg, u);
	// distance
	float dist = distance(this->focus, this->pos);

	vec4 focusBasedOnPos = this->focus - this->pos;
	//rotate the focal point and vup vector
	this->focus = dist * normalize(rot * focusBasedOnPos) + this->pos;
	//rotate the vup vector
	this->vup = normalize(rot * this->vup);
	this->curParam();
}

void Camera::surge(float dist = 5.0) {

}

void Camera::heave(float dist = 5.0) {

}

void Camera::sway(float dist = 5.0) {

}
