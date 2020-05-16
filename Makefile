exe := Shader.exe

# different methods to compile obj in different file hierarchy 
CallbackObj := CallbackFunc.o
MainObj := main.o

# Specify the compiler flag
CFLAGS = -lGL -lglut -lGLEW

all: ${MainObj} ${CallbackObj}
	${CXX} -o ${exe} ./obj/* ${CFLAGS}

${MainObj}: *.cpp ${CallbackObj}
	${CXX} -c $< -o ./obj/$@ ${CFLAGS}

${CallbackObj}: ./Callback/*.cpp
	${CXX} -c $< -o ./obj/$@ ${CFLAGS}
