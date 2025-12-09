#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <bits/stdc++.h>

class Player
{
    public:
        float applygravity(float deltaTime)
        {
            if((gravity*deltaTime)+speed>terminalvelocity)
                return 0;
            return speed+=gravity*deltaTime;
        }
        void Jump(float deltaTime)
        {
            if(!falling)
                speed-=jumpspeed*deltaTime;
            falling=true;
        }
        float getspeed()
        {
            return speed;
        }
        float gravityreset()
        {
            return speed=0;
        }
        float getGravity()
        {
            return gravity;
        }
        void setGravity(float grav)
        {
            gravity=grav;
        }
        float getSpeed()
        {
            return speed;
        }
        void setSpeed(float spd)
        {
            speed=spd;
        }
        float getTerminal()
        {
            return terminalvelocity;
        }
        void setTerminal(float terminalvel)
        {
            terminalvelocity=terminalvel;
        }
        float getJump()
        {
            return jumpspeed;
        }
        void setJump(float jumpspd)
        {
            jumpspeed=jumpspd;
        }
        bool getFall()
        {
            return falling;
        }
        void setFall(bool fall)
        {
            falling=fall;
        }
    private:
        float gravity=0.6, speed=0, terminalvelocity=8.0, jumpspeed=10;
        bool falling=false;

};

#endif