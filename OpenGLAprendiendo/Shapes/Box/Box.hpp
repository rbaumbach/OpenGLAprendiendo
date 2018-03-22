#ifndef Box_hpp
#define Box_hpp

#include "ShaderManager.hpp"

class Box
{
public:
    // This constuctor exists to handle loading of the shaders differently if we are on macOS vs. iOS
    
    Box(GLboolean isMacOS = true);
    
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
