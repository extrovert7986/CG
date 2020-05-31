exe := Shader.exe

# different methods to compile obj in different file hierarchy 
MainObj := main.o
CallbackObj := CallbackFunc.o
ComponentObj := Camera.o

# Specify the compiler flag
CXXFLAGS = -lGL -lGLU -lglut -lGLEW

all: ${MainObj} ${CallbackObj} ${ComponentObj}
	${CXX} -o ${exe} ./obj/* ${CXXFLAGS}

${MainObj}: ./source/main.cpp ${CallbackObj} ${ComponentObj}
	${CXX} -c ./source/main.cpp -o ./obj/$@

${CallbackObj}:
	${CXX} -c ./source/callback/$*.cpp -o ./obj/$@

${ComponentObj}:
	${CXX} -c ./source/component/$*.cpp -o ./obj/$@
