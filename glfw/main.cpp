#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <objects/shader.h>
#include <cstdlib>
#include <objects/camera.h>
#include <objects/engine.cpp>
#include <objects/gameobjects.cpp>

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void processInput(GLFWwindow *window);
unsigned int loadTexture(char const * path);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;


// camera
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;


// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;



// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
float specularStrength = 0.5;

//glm::vec3 blocks[100][3][100];
//int sizes[]={sizeof(blocks)/sizeof(blocks[0]),sizeof(blocks[0])/sizeof(blocks[0][0]),sizeof(blocks[0][0])/sizeof(blocks[0][0][0])};

int sizes[]={100,4, 100};
Camera camera(glm::vec3(-0.5, 6.0f, -0.5));
// vector<glm::vec3> blocks=vector<glm::vec3>(sizes[0]*sizes[1]*sizes[2]);
World world=World();

Engine engine;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);



    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    engine=Engine(window);

    

    //blocks.resize(sizes[0]*sizes[1]*sizes[2]);
    int i, j, k;
    for(i=0;i<sizes[0];++i)
    {
        for(j=0;j<sizes[1];++j)
        {   
            for(k=0;k<sizes[2];++k)
            {
                
                //blocks[i*sizes[1]*sizes[2]+j*sizes[2]+k]=glm::vec3((float)i-(sizes[0]/2),(float)j-20,(float)k-(sizes[2]/2));
                world.setBlock(i-50, j, k-50, 1);
            }
        }

    }
    world.setBlock(53, 5, 51, 1);
    world.setBlock(50, 4, 51, 1);
    world.setBlock(56, 6, 51, 1);
    world.setBlock(56, 7, 48, 1);
    world.setBlock(54, 8, 48, 1);
    world.setBlock(52, 9, 48, 1);
    world.setBlock(50, 10, 48, 1);
    world.setBlock(47, 10, 45, 1);
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        {   
            world.setBlock(44-i, 11, 42-j, 1);
        }

    }


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        // input
        // -----
        processInput(window);

    

        // speed=min(speed+gravity,(terminalvelocity));
        // camera.Position-=speed*deltaTime;
        // render
            // ------
        int scrsize[2];
        scrsize[0]=SCR_WIDTH;
        scrsize[1]=SCR_HEIGHT;
        engine.calculations( &camera,deltaTime);
        engine.render(scrsize);
            
        engine.rendercubes(world, &camera, deltaTime);
        glBindVertexArray(engine.lightCubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &engine.cubeVAO);
    glDeleteVertexArrays(1, &engine.lightCubeVAO);
    glDeleteBuffers(1, &engine.VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if((glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS))
        camera.MovementSpeed=9;
    else
        camera.MovementSpeed=5;
    
    if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)&&(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
        camera.ProcessKeyboard(FORWARDLEFT, deltaTime);
    else if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)&&(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
        camera.ProcessKeyboard(FORWARDRIGHT, deltaTime);
    else if ((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)&&(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
        camera.ProcessKeyboard(BACKWARDLEFT, deltaTime);
    else if ((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)&&(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
       camera.ProcessKeyboard(BACKWARDRIGHT, deltaTime);
    else if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        engine.player.Jump(deltaTime);
    if (glfwGetKey(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        cout<<"a";
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        world.delBlock(floor(camera.Position.x), floor(camera.Position.y-2.2f), floor(camera.Position.z-1));
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        world.setBlock(floor(camera.Position.x), floor(camera.Position.y-1.2), floor(camera.Position.z), 1);
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
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
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
