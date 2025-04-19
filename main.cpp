#include "src/base/square.h"
#include "src/input/input_manager.h"
#include <glad/glad.h>
// Force
#include <GLFW/glfw3.h>
#include <iostream>

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float currentFrame = 0.0f;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "The Platformer", NULL, NULL);
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

  Square s{};
  s.scale(glm::vec3(0.3f));

  InputManager inputManager{window, s, deltaTime};

  while (!glfwWindowShouldClose(window)) {
    currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    inputManager.processInput();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Render code goes here
    s.render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  return 0;
}

// TODO: Setup Physics on basic game object
// TODO: Setup Collision/Trigger on basic game object
// TODO: Proper camera
