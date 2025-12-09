#ifndef ENGINE_CPP
#define ENGINE_CPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stbimages/stb_image.h>
#include <iostream>
#include <objects/shader.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib>
#include <objects/camera.h>
#include <vector>
#include <objects/gameobjects.cpp>
#include <objects/player.cpp>

unsigned int loadTexture(char const * path);

struct Cube{
    glm::vec3 position;
};
if (FT_Init_FreeType(&ft))
float offset=0.5;
float cubevertices[] = {
                // positions                              // normals           // texture coords
                -0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
                0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
                0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
                0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
                -0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
                -0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

                -0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
                0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
                0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
                0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
                -0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
                -0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

                -0.5f+offset,  0.5f+offset,  0.5f+offset, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                -0.5f+offset,  0.5f+offset, -0.5f+offset, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
                -0.5f+offset, -0.5f+offset, -0.5f+offset, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                -0.5f+offset, -0.5f+offset, -0.5f+offset, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                -0.5f+offset, -0.5f+offset,  0.5f+offset, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
                -0.5f+offset,  0.5f+offset,  0.5f+offset, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

                0.5f+offset,  0.5f+offset,  0.5f+offset,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                0.5f+offset,  0.5f+offset, -0.5f+offset,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
                0.5f+offset, -0.5f+offset, -0.5f+offset,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                0.5f+offset, -0.5f+offset, -0.5f+offset,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
                0.5f+offset, -0.5f+offset,  0.5f+offset,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
                0.5f+offset,  0.5f+offset,  0.5f+offset,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

                -0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
                0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
                0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
                0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
                -0.5f+offset, -0.5f+offset,  0.5f+offset,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
                -0.5f+offset, -0.5f+offset, -0.5f+offset,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

                -0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
                0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
                0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
                -0.5f+offset,  0.5f+offset,  0.5f+offset,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
                -0.5f+offset,  0.5f+offset, -0.5f+offset,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
            };


class Engine
{
    public:
        Shader lightingShader;
        Shader lightCubeShader;
        unsigned int VBO, cubeVAO, lightCubeVAO, texture1, map;
        glm::vec3 lightPos;
        int width, height;
        Player player=Player();

        Engine()
        {
            return;
        }

        Engine(GLFWwindow* window)
        {
            glEnable(GL_DEPTH_TEST);
            glCullFace(GL_FRONT);
            glEnable(GL_DEPTH_TEST);

            
            
            lightPos=glm::vec3(1.2f, 1.0f, 2.0f);
            

            // set up vertex data (and buffer(s)) and configure vertex attributes
            // ------------------------------------------------------------------
            
            glGenVertexArrays(1, &cubeVAO);
            glGenBuffers(1, &VBO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(cubevertices), cubevertices, GL_STATIC_DRAW);

            glBindVertexArray(cubeVAO);

            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);

            // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
            lightCubeVAO;
            glGenVertexArrays(1, &lightCubeVAO);
            glBindVertexArray(lightCubeVAO);

            // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            lightingShader=Shader("shaders/lightshader.vs", "shaders/lightshader.fs");
            lightCubeShader=Shader("shaders/lightcubeshader.vs", "shaders/lightcubeshader.fs");
            texture1 = loadTexture("assets/images/container2edt.png");
            map = loadTexture("assets/images/container2_specular.png");
            lightingShader.use();
            lightingShader.setInt("material.diffuse", 0);
            lightingShader.setInt("material.specular", 1);
        }
        void render(int* scr_size)
        {
            width=scr_size[0];
            height=scr_size[1];
            glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            lightingShader.use();
            lightPos=(glm::vec3(50.0f, 20.0f, 50.0f));

        }
        void rendercubes(World world, Camera* camera, float deltaTime)
        {   
            lightingShader.setVec3("light.ambient", 0.6f, 0.6f, 0.6f);
            lightingShader.setVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
            lightingShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
            lightPos=(glm::vec3(sin(glfwGetTime())*10, 20.0f, 50.0f));
            lightingShader.setVec3("light.position", lightPos);
            lightingShader.setFloat("material.shininess", 100.0f);
            int i,j,k;
            glm::mat4 projection;
            glm::mat4 view;
            glm::mat4 model;
            lightingShader.setVec3("viewPos", (*camera).Position);
            projection = glm::perspective(glm::radians((*camera).Zoom), (float)width / (float)height, 0.1f, 100.0f);
            view = (*camera).GetViewMatrix();
            lightingShader.setMat4("projection", projection);
            lightingShader.setMat4("view", view);
            vector <glm::vec3> blocks=world.getAllBlocks();
            int sizes=blocks.size();
            for(i=0;i<sizes;++i)
            {
                collisioncheck(camera, blocks[i], deltaTime);
                model = glm::mat4(1.0f);
                model = glm::translate(model, blocks[i]);
                lightingShader.setMat4("model", model);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, texture1);
                glActiveTexture(GL_TEXTURE1);
                glBindTexture(GL_TEXTURE_2D, map);
                glBindVertexArray(cubeVAO);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            lightCubeShader.use();
            lightCubeShader.setMat4("projection", projection);
            lightCubeShader.setMat4("view", view);
            model = glm::mat4(1.0f);
            model = glm::translate(model, lightPos);
            model = glm::scale(model, glm::vec3(5.0f));
            lightCubeShader.setMat4("model", model);
            glBindVertexArray(lightCubeVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        bool collisioncheck( Camera* camera,glm::vec3 cube, float deltaTime)
        {   //float camerabox[3]={camera->Position.x-1.0f, camera->Position.y-1.8f, camera->Position.z-0.5f};
        //     float cubebox[3]={cube.x-1.0f, cube.y-1.0f, cube.z-1.0f};
        //     if((((camerabox[0])<=cube.x)&&(camera->Position.x>=cubebox[0]))&&(((camerabox[1])<=cube.y)&&(camera->Position.y>=cubebox[1]))&&(((camerabox[2])<=cube.z)&&(camera->Position.z>=cubebox[2])))
        //     {

        //     }
            float camerabottom[3]={camera->Position.x-0.5f, camera->Position.y-1.7f, camera->Position.z-0.5f};
            float cameratop[3]={camera->Position.x+0.5f, camera->Position.y+0.1f, camera->Position.z+0.5f};
            float cubetop[3]={cube.x+1.0f, cube.y+1.0f, cube.z+1.0f};
            if((((cameratop[0])>=cube.x)&&(camerabottom[0]<=cubetop[0]))&&(((cameratop[1])>=cube.y)&&(camerabottom[1]<=cubetop[1]))&&(((cameratop[2])>=cube.z)&&(camerabottom[2]<=cubetop[2])))
             {
                float distx=std::min(cubetop[0]-camerabottom[0], cameratop[0]-cube.x);
                float disty=std::min(cubetop[1]-camerabottom[1], cameratop[1]-cube.y);
                float distz=std::min(cubetop[2]-camerabottom[2], cameratop[2]-cube.z);

                if(distx<disty && distx<distz)
                {
                    if(abs(distx)<0.3)
                    {
                        if(cameratop[0]<cube.x+0.5f)camera->Position.x-=distx;
                        else camera->Position.x+=distx;
                    }
                    
                }
                else if(disty<distx && disty<distz)
                {
                    if(abs(disty)<0.3)
                    {
                        if(cameratop[1]<cube.y+0.5f)camera->Position.y-=disty;
                        else camera->Position.y+=disty;
                        player.gravityreset();
                        player.setSpeed(0);
                        player.setFall(false);
                    }
                }
                else
                {
                    if(abs(distz)<0.3)
                    {
                        if(cameratop[2]<cube.z+0.5f)camera->Position.z-=distz;
                        else camera->Position.z+=distz;
                    }
                    
                }
                return true;
             }
            return false;
            //if(((camera->Position.x-camerabox[0])<=cube.x)&&(camera->Position.x>=cube.x-cubebox[0])&&((camera->Position.y-camerabox[1])>=cube.y)&&(camera->Position.y<=cube.y-cubebox[1])&&((camera->Position.z-camerabox[2])>=cube.z)&&(camera->Position.z<=cube.z-cubebox[2]))
                //cout<<"d";
        }

        void calculations(Camera* camera,float deltaTime)
        {
            (*camera).Position.y-=player.applygravity(deltaTime);
        }
    private:
};

unsigned int loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

#endif