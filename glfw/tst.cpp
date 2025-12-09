#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <cstdlib>
#include <bits/stdc++.h>
#include <glm/gtc/matrix_transform.hpp>


using namespace std;

class Chunk{
    public:
        Chunk(glm::vec3 pos)
        {
            position=pos;
        }
        unsigned int getBlock(int x, int y, int z)
        {
            //cout<<"["<<x<<"]"<<endl;
            x=abs(x);
            y=abs(y);
            z=abs(z);
            return blocks[min(4095,16*16*x+16*y+z)];
        }
        void setBlock(int x, int y, int z, unsigned int value)
        {
            //cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"z:"<<z<<endl;
            if(x<0)
                x=16+x;
            if(y<0)
                y=16+y;
            if(z<0)
                z=16+z;
            blocks[(abs(min(4095,16*16*x+16*y+z)))]=value;
        }
        glm::vec3 get_position()
        {
            return position;
        }
        vector <glm::vec3> getAllBlocks()
        {
            int i=0;
            vector <glm::vec3> v;
            for(i=0;i<blocks.size();++i)
            {
                if(blocks[i]!=0)
                {   
                    int tmp1=i/256;
                    int tmp2=(i%256)/16;
                    int tmp3=(i%256)%16;
                    cout<<"-------"<<i<<" "<<tmp1<<" "<<tmp2<<" "<<tmp3<<" /"<<position.x<<" "<<position.y<<" "<<position.z<<endl;

                    v.insert(v.end(), glm::vec3(tmp1, tmp2, tmp3)+position);

                }
            };
            return v;
        }
        int getBlocksNr()
        {   int i, val=0;
            for(i=0;i<blocks.size();++i)
            {
                if(blocks[i]!=0)
                    ++val;
            }
            return val;
        }
        void delBlock(int x, int y, int z)
        {
            if(x<0)
                x=16+x;
            if(y<0)
                y=16+y;
            if(z<0)
                z=16+z;
            blocks[(abs(min(4095,16*16*x+16*y+z)))]=0;
            
        }

    private:
        glm::vec3 position=glm::vec3(0,0,0);
        vector<int> blocks=vector<int>(16*16*16);

};

class World{

    public:
        World()
        {
            chunks.push_back(Chunk(glm::vec3(0,0,0)));
            
        }
        Chunk getChunk(unsigned int nr)
        {
            return chunks[min((int)nr, (int)chunks.size()-1)];
        }
        unsigned getChunknr()
        {
            return chunks.size();
        }
        void setBlock(float pos[], unsigned value)
        {
            glm::vec3 posi=glm::vec3(floor(pos[0]/16)*16, floor(pos[1]/16)*16, floor(pos[2]/16)*16);
            int i;
            bool found=false;
            for(i=0;i<chunks.size();++i)
            {
                if(chunks[i].get_position()==posi)
                {
                    chunks[i].setBlock((int)pos[0]%16, (int)pos[1]%16, (int)pos[2]%16, value);
                    return;
                }
            }
            int tmp=0;
            for(i=0;i<chunks.size();++i)
                if(chunks[i].get_position().x>posi[0]&&chunks[i].get_position().y&&chunks[i].get_position().x)
                    break;
                else
                    ++tmp;
            
            chunks.insert(chunks.begin() + tmp, Chunk(posi));
            chunks[tmp].setBlock((int)pos[0]%16, (int)pos[1]%16, (int)pos[2]%16, value);

        }
        void setBlock(float x, float y, float z, unsigned value)
        {
            glm::vec3 posi=glm::vec3(floor(x/16)*16, floor(y/16)*16, floor(z/16)*16);
            int i;
            for(i=0;i<chunks.size();++i)
            {
                //cout<<"["<<1<<"]"<<endl;
                if(chunks[i].get_position()==posi)
                {
                    chunks[i].setBlock((int)x%16, (int)y%16, (int)z%16, value);
                    return;
                }
            }
            int tmp=0;
            for(i=0;i<chunks.size();++i)
                if(chunks[i].get_position().x>posi[0]&&chunks[i].get_position().y&&chunks[i].get_position().x)
                    break;
                else
                    ++tmp;
            chunks.insert(chunks.begin() + tmp, Chunk(posi));
            chunks[tmp].setBlock((int)x%16, (int)y%16, (int)z%16, value);
        }
        int getBlock(float x, float y, float z)
        {
            glm::vec3 posi=glm::vec3(trunc(x/16)*16, trunc(y/16)*16, trunc(z/16)*16);
            int i;
            for(i=0;i<chunks.size();++i)
            {
                //cout<<"["<<1<<"]"<<endl;
                if(chunks[i].get_position()==posi)
                {
                    return chunks[i].getBlock((int)x%16, (int)y%16, (int)z%16);
                }
            }
            return 0;
        }
        unsigned getBlock(float pos[])
        {
            glm::vec3 posi=glm::vec3(floor(pos[0]/16)*16, floor(pos[1]/16)*16, floor(pos[2]/16)*16);
            int i;
            bool found=false;
            for(i=0;i<chunks.size();++i)
            {
                if(chunks[i].get_position()==posi)
                {
                    return chunks[i].getBlock((int)pos[0]%16, (int)pos[1]%16, (int)pos[2]%16);
                }
            }
            return 0;

        }
        vector <glm::vec3> getAllBlocks()
        {
            int i=0;
            vector <glm::vec3> a, b;
            for(i=0;i<chunks.size();++i)
            {
                b=chunks[i].getAllBlocks();
                a.insert(a.end(), b.begin(), b.end());
            }
            return a;
        }
        void delBlock(float x, float y, float z)
        {
            glm::vec3 posi=glm::vec3(floor(x/16)*16, floor(y/16)*16, floor(z/16)*16);
            int i;
            for(i=0;i<chunks.size();++i)
            {
                //cout<<"["<<1<<"]"<<endl;
                if(chunks[i].get_position()==posi)
                {
                    chunks[i].delBlock((int)x%16, (int)y%16, (int)z%16);
                    if(chunks[i].getBlocksNr()==0)
                        chunks.erase(chunks.begin() + i);
                    return;
                }
            }
        }
        void delBlock(float pos[])
        {
            glm::vec3 posi=glm::vec3(floor(pos[0]/16)*16, floor(pos[1]/16)*16, floor(pos[2]/16)*16);
            int i;
            for(i=0;i<chunks.size();++i)
            {
                //cout<<"["<<1<<"]"<<endl;
                if(chunks[i].get_position()==posi)
                {
                    chunks[i].delBlock((int)pos[0]%16, (int)pos[1]%16, (int)pos[2]%16);
                    if(chunks[i].getBlocksNr()==0)
                        chunks.erase(chunks.begin() + i);
                    return;
                }
            }
        }
    private:
        vector<Chunk> chunks;
};
World world;
int main()
{
    int chunksize=16;
    float tst[3]={20,0,2};
    //cout<<world.getChunknr()<<endl;
    world.setBlock(tst,4);
    //cout<<world.getChunknr()<<endl;
    //cout<<world.getChunk(1).getBlock(4, 0, 0)<<endl;
    world.setBlock(-17,0,4,1);
    world.setBlock(-18,0,4,1);
    //cout<<world.getChunknr()<<endl;
    world.setBlock(11,0,-1, 1);
    //cout<<world.getBlock(100,0,1)<<endl;
    world.setBlock(-80,0,1, 1);
    world.setBlock(-15,15,15, 1);
    world.setBlock(0,0,0, 1);
    world.setBlock(-16,-20,0, 1);
    world.setBlock(-2000,-1000,0, 1);
    cout<<world.getChunknr()<<endl;
    world.setBlock(-1,-1,0, 1);
    cout<<world.getChunknr()<<endl;
    //cout<<world.getChunknr()<<endl;
    //cout<<world.getChunk(3).get_position().x<<endl;
    vector <glm::vec3> v=world.getAllBlocks();
    //cout<<"["<<v.size()<<"]"<<endl;
    int i;
    for(i=0;i<v.size();++i)
        cout<<"x:"<<v[i].x<<", y:"<<v[i].y<<", z:"<<v[i].z<<endl;
    cout<<world.getChunk(2).getBlocksNr()<<endl;
    world.delBlock(-18,0,4);
    cout<<world.getChunknr()<<endl;
    world.delBlock(-17,0,4);
    cout<<world.getChunknr()<<endl;

    return 0;
}