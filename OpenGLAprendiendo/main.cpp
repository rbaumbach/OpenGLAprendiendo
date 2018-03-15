#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include "Shader.hpp"

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

GLFWwindow* window;

GLfloat vertices[] = {
    // positions          // colors
    0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // bottom left
    0.0f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f    // top
};

int setupOpenGL();
void teardownOpenGL();

int setupGLFW(int* screenWidth, int* screenHeight);
void teardownGLFW();
int setupGLEW();

void setupTriangle(GLuint* vertexArrayObj, GLuint* vertexBufferObj);
void teardownTriangle(GLuint* vertexArrayObj, GLuint* vertexBufferObj);

void renderTriangle(Shader shader, int vertexArrayObj);

void processInput(GLFWwindow *window);

int main()
{
    if (setupOpenGL() == -1) {
        return -1;
    }
    
    Shader shader("vertex.glsl", "fragment.glsl");

    GLuint VAO, VBO;
    
    setupTriangle(&VAO, &VBO);
    
    // display loop

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        renderTriangle(shader, VAO);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    teardownTriangle(&VAO, &VBO);
    
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

void setupTriangle(GLuint* vertexArrayObj, GLuint* vertexBufferObj)
{
    glGenVertexArrays(1, vertexArrayObj);
    glGenBuffers(1, vertexBufferObj);
    
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    
    glBindVertexArray(*vertexArrayObj);
    
    glBindBuffer(GL_ARRAY_BUFFER, *vertexBufferObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // position attribute
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // color attribute
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    
    glBindVertexArray(0);
}

void teardownTriangle(GLuint* vertexArrayObj, GLuint* vertexBufferObj)
{
    glDeleteVertexArrays(1, vertexArrayObj);
    glDeleteBuffers(1, vertexBufferObj);
}

void renderTriangle(Shader shader, int vertexArrayObj)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    shader.useProgram();
    
    // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    
    glBindVertexArray(vertexArrayObj);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
