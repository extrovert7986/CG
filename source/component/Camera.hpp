#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

using namespace glm;

class Camera {
public:
	Camera(void);
	Camera(vec3 pos, vec3 focus, vec3 vup);
	~Camera();

	// getter
	vec3 getFocus();
	vec3 getPos();
	vec3 getVup();
	// 6 axis movement
	void roll(float deg);
	void yaw(float deg);
	void pitch(float deg);
	void surge(float dist);
	void heave(float dist);
	void sway(float dist);

private:
	// printer
	void curParam();
	vec4 pos;
	vec4 focus;
	vec4 vup;
};

#endif
