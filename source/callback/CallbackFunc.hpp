#ifndef CALLBACKFUNC_HPP
#define CALLBACKFUNC_HPP

#include "../component/Camera.hpp"

class CallbackFunc {
public:
	CallbackFunc();
	~CallbackFunc();
	
	static void display_func();
	static void keyboard_func(unsigned char key, int x, int y);
private:
	static Camera cam;
};

#endif
