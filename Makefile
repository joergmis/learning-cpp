all:
	gcc main.cpp -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl -o main -L/usr/lib64 -lGLEW -lGL -lX11 -lGLU
