#ifndef Shader_hpp
#define Shader_hpp

#include <GL/glew.h>

class ShaderManager
{
public:
    void loadShadersFromPaths(const GLchar *vertexPath, const GLchar *fragmentPath);
    
    // Uses the current shaders
    
    void useProgram();
private:
    GLuint shaderProgram;
};

#endif
