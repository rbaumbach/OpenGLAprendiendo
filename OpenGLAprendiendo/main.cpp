#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "Triangle.hpp"

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

GLFWwindow* window;

int setupOpenGL();
void teardownOpenGL();

int setupGLFW(int* screenWidth, int* screenHeight);
void teardownGLFW();
int setupGLEW();

void processInput(GLFWwindow *window);

int main()
{
    if (setupOpenGL() == -1)
    {
        return -1;
    }

    Triangle triangle;
    triangle.setup();
    
    // display loop

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        triangle.render();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    triangle.teardown();
    
    teardownOpenGL();
    
    return 0;
}

int setupOpenGL()
{
    int screenWidth;
    int screenHeight;
    
    if (setupGLFW(&screenWidth, &screenHeight) == -1)
    {
        return -1;
    }
    
    if (setupGLEW() == -1)
    {
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    return 0;
}

void teardownOpenGL()
{
    teardownGLFW();
}

int setupGLFW(int* screenWidth, int* screenHeight)
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    // this is required for macOS
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Aprendiendo", NULL, NULL);
    
    // this is required for macOS due to retina screens
    
    glfwGetFramebufferSize(window, screenWidth, screenHeight);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;

        glfwTerminate();

        return -1;
    }
    
    glfwMakeContextCurrent(window);

    return 0;
}

void teardownGLFW()
{
    glfwTerminate();
}

int setupGLEW()
{
    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    
    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
