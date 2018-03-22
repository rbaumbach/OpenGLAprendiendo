#ifndef Triangle_hpp
#define Triangle_hpp

#include "ShaderManager.hpp"

class Triangle
{
public:
    // This constuctor exists to handle loading of the shaders differently if we are on macOS vs. iOS
    
    Triangle(GLboolean isMacOS = true);
    
    void setup();
    void teardown();
    void render();
    
private:
    GLboolean isMacOS;
    GLuint VAO;
    GLuint VBO;
    ShaderManager shaderManager;
};

#endif
