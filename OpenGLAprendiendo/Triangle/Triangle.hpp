#ifndef Triangle_hpp
#define Triangle_hpp

// Shader class includes GLEW

#include "ShaderManager.hpp"

class Triangle
{
public:
    Triangle();
    
    void setup();
    void teardown();
    void render();
    
private:
    GLuint VAO;
    GLuint VBO;
    ShaderManager shaderManager;
};

#endif
