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
#include <ft2build.h>
#include FT_FREETYPE_H

unsigned int loadTexture(char const * path);

struct Cube{
    glm::vec3 position;
};
struct Character {
unsigned int TextureID; // ID handle of the glyph texture
glm::ivec2 Size; // Size of glyph
glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
unsigned int Advance; // Offset to advance to next glyph
};
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
        Shader CharacterShader;
        unsigned int VBO, cubeVAO, lightCubeVAO, texture1, map, characterVAO, characterVBO;
        glm::vec3 lightPos;
        int width, height;
        Player player=Player();
        FT_Library ft;
        FT_Face face;
        std::map<char, Character> Characters;
        glm::mat4 projection = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f);

        Engine()
        {
            return;
        }

        Engine(GLFWwindow* window): 
            lightingShader("shaders/lightshader.vs", "shaders/lightshader.fs"),
            lightCubeShader("shaders/lightcubeshader.vs", "shaders/lightcubeshader.fs"),
            CharacterShader("shaders/character.vs", "shaders/character.fs")
        {
            glEnable(GL_DEPTH_TEST);
            glCullFace(GL_FRONT);
            glEnable(GL_DEPTH_TEST);

            characterInit();
            
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
            texture1 = loadTexture("assets/images/container2edt.png");
            map = loadTexture("assets/images/container2_specular.png");
            lightingShader.use();
            lightingShader.setInt("material.diffuse", 0);
            lightingShader.setInt("material.specular", 1);
            glGenVertexArrays(1, &characterVAO);
            glGenBuffers(1, &characterVBO);
            glBindVertexArray(characterVAO);
            glBindBuffer(GL_ARRAY_BUFFER, characterVBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6*4, NULL, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
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
        void RenderText(Shader &shader, std::string text, float x, float y, float scale, glm::vec3 color)
        {
            // activate corresponding render state	
            shader.use();
            glUniform3f(glGetUniformLocation(shader.ID, "textColor"), color.x, color.y, color.z);
            glActiveTexture(GL_TEXTURE0);
            glBindVertexArray(characterVAO);

            // iterate through all characters
            std::string::const_iterator c;
            for (c = text.begin(); c != text.end(); c++) 
            {
                Character ch = Characters[*c];

                float xpos = x + ch.Bearing.x * scale;
                float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

                float w = ch.Size.x * scale;
                float h = ch.Size.y * scale;
                // update VBO for each character
                float vert[6][4] = {
                    { xpos,     ypos + h,   0.0f, 0.0f },            
                    { xpos,     ypos,       0.0f, 1.0f },
                    { xpos + w, ypos,       1.0f, 1.0f },

                    { xpos,     ypos + h,   0.0f, 0.0f },
                    { xpos + w, ypos,       1.0f, 1.0f },
                    { xpos + w, ypos + h,   1.0f, 0.0f }           
                };
                // render glyph texture over quad
                glBindTexture(GL_TEXTURE_2D, ch.TextureID);
                // update content of VBO memory
                glBindBuffer(GL_ARRAY_BUFFER, characterVBO);
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vert), vert); // be sure to use glBufferSubData and not glBufferData

                glBindBuffer(GL_ARRAY_BUFFER, 0);
                // render quad
                glDrawArrays(GL_TRIANGLES, 0, 6);
                // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
                x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
            }
            glBindVertexArray(0);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
        bool collisioncheck( Camera* camera,glm::vec3 cube, float deltaTime)
        {   //float camerabox[3]={camera->Position.x-1.0f, camera->Position.y-1.8f, camera->Position.z-0.5f};
        //     float cubebox[3]={cube.x-1.0f, cube.y-1.0f, cube.z-1.0f};
        //     if((((camerabox[0])<=cube.x)&&(camera->Position.x>=cubebox[0]))&&(((camerabox[1])<=cube.y)&&(camera->Position.y>=cubebox[1]))&&(((camerabox[2])<=cube.z)&&(camera->Position.z>=cubebox[2])))
        //     {

        //     }
            float camerabottom[3]={camera->Position.x-0.3f, camera->Position.y-1.7f, camera->Position.z-0.3f};
            float cameratop[3]={camera->Position.x+0.3f, camera->Position.y+0.1f, camera->Position.z+0.3f};
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
            lookingAT(*camera);
            //cout<<floor(camera->Position.x)<<" "<<floor(camera->Position.y)<<" "<<floor(camera->Position.z)<<endl;
        }
        void lookingAT(Camera camera)
        {
            vector<int> block;
            block.push_back(static_cast<int>(floor(camera.Position.x)));
            block.push_back(static_cast<int>(floor(camera.Position.y)));
            block.push_back(static_cast<int>(floor(camera.Position.z)));
            vector<int> step;
            if(camera.Front.x>0)step.push_back(1);
            else if(camera.Front.x<0)step.push_back(-1);
            else step.push_back(0);
            if(camera.Front.y>0)step.push_back(1);
            else if(camera.Front.y<0)step.push_back(-1);
            else step.push_back(0);
            if(camera.Front.z>0)step.push_back(1);
            else if(camera.Front.z<0)step.push_back(-1);
            else step.push_back(0);
            float tmaxx, tmaxy, tmaxz;
            if(step[0]>0)tmaxx=(block[0]+1 - camera.Position.x)/camera.Front.x;
            else if(step[0]<0)tmaxx=(block[0] - camera.Position.x)/camera.Front.x;
            else tmaxx=INFINITY;
            isinf(tmaxx);
            if(step[1]>0)tmaxy=(block[1]+1 - camera.Position.y)/camera.Front.y;
            else if(step[1]<0)tmaxy=(block[1] - camera.Position.y)/camera.Front.y;
            else tmaxy=INFINITY;
            if(step[2]>0)tmaxz=(block[2]+1 - camera.Position.z)/camera.Front.z;
            else if(step[2]<0)tmaxz=(block[2] - camera.Position.z)/camera.Front.z;
            else tmaxz=INFINITY;
            float tdeltax, tdeltay, tdeltaz;
            if(step[0]!=0)tdeltax=1.0f/abs(camera.Front.x);
            else tdeltax=INFINITY;
            if(step[1]!=0)tdeltay=1.0f/abs(camera.Front.y);
            else tdeltay=INFINITY;
            if(step[2]!=0)tdeltaz=1.0f/abs(camera.Front.z);
            else tdeltaz=INFINITY;
            
        }
    private:
        void characterInit()
        {
            if (FT_Init_FreeType(&ft))
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" <<
            std::endl;
            if (FT_New_Face(ft, "fonts/amiri-regular.ttf", 0, &face))
            std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
            FT_Set_Pixel_Sizes(face, 0, 48);
            if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // no byte-alignment restriction
            // set size to load glyphs as

            // load first 128 characters of ASCII set
            for (unsigned char c = 0; c < 128; c++)
            {
                // Load character glyph 
                if (FT_Load_Char(face, c, FT_LOAD_RENDER))
                {
                    std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                    continue;
                }
                // generate texture
                unsigned int texture;
                glGenTextures(1, &texture);
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RED,
                    face->glyph->bitmap.width,
                    face->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    face->glyph->bitmap.buffer
                );
                // set texture options
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                // now store character for later use
                Character character = {
                    texture,
                    glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                    glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                    static_cast<unsigned int>(face->glyph->advance.x)
                };
                Characters.insert(std::pair<char, Character>(c, character));
            }
            glBindTexture(GL_TEXTURE_2D, 0);
            FT_Done_Face(face);
            FT_Done_FreeType(ft);

            }
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