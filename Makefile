debug:
	# Solution to linking found here: https://stackoverflow.com/questions/73142912/glfw-undefined-symbols-for-architecture-arm64
	clang++ --debug ./main.cpp ./src/glad.c ./src/shader/shader.cpp ./src/stb.cpp ./src/base/game_object.cpp ./src/base/square.cpp -I/usr/local/include -L/usr/local/lib -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit --std=c++17 -o ./build/debug
run:
	./build/debug
