#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stbimages/stb_image.h>
#include <iostream>
#include <objects/shader.h>
#include <GLFW/glfw3.h>
#include <objects/camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib>

float lastX;
float lastY;
bool firstMouse = true;

class window
{
    public:
        static Camera camera;
        GLFWwindow* window;
        void Window(int WIDTH, int HEIGHT, Camera cameraget)
        {    
            camera=cameraget;
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            #ifdef __APPLE__
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            #endif
            lastX=WIDTH / 2.0f;
            lastY= HEIGHT / 2.0f;
            window = glfwCreateWindow(1080, 720, "LearnOpenGL", NULL, NULL);

            if (!window) {
                std::cerr << "Failed to create GLFW window\n";
                glfwTerminate();
                exit(-1);
            }

            glfwMakeContextCurrent(window);
            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
            glfwSetCursorPosCallback(window, mouse_callback);
            glfwSetScrollCallback(window, scroll_callback);

        

            // glfw window creation
            // --------------------
            
            if (window == NULL)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return;
            }
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

            // glad: load all OpenGL function pointers
            // ---------------------------------------
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return;
            }
        }
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
    {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; 

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
    }

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }
};


#endif