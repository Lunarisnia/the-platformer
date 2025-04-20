#include "src/base/game.h"
#include <glad/glad.h>
// Force
#include <GLFW/glfw3.h>
#include <iostream>

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float currentFrame = 0.0f;

float width = 800.0f;
float height = 600.0f;
Game game{width, height, deltaTime};

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
    game.keys[key] = true;
  } else if (action == GLFW_RELEASE) {
    game.keys[key] = false;
  }
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window =
      glfwCreateWindow(width, height, "The Platformer", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to initialize window" << std::endl;
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  glfwSetKeyCallback(window, key_callback);

  game.init();

  while (!glfwWindowShouldClose(window)) {
    currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    game.processInput();

    game.update();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    game.render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  return 0;
}

// TODO: Setup Physics on basic game object
// TODO: Texture
// TODO: Setup Collision/Trigger on basic game object
// TODO: Proper camera
