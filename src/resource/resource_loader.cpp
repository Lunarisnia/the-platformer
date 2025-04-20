#include "resource_loader.h"
Shader ResourceLoader::LoadShader(std::string vertexPath,
                                  std::string fragmentPath) {
  Shader s = Shader(vertexPath.c_str(), fragmentPath.c_str());
  return s;
}
