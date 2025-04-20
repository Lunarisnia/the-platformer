#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H
#include "../shader/shader.h"
#include <string>
class ResourceLoader {
public:
  static Shader LoadShader(std::string vertexPath, std::string fragmentPath);
};
#endif
