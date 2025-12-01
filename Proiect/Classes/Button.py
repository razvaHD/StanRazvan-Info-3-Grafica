import pygame
import Global
import math

def dist(a, b):
    return math.sqrt((((a[0]-b[0])**2)+((a[1]-b[1])**2)))


class Button:
    pressed=False
    text=""
    active=1
    hidden=0
    circle=1
    def __init__(self, surface, color, values, offset, ID, text):
        self.surface=surface
        self.color=color
        self.defaultcolor=color
        self.values=values
        self.offset=offset
        self.hovercolor=(max(0, color[0]-30), max(0, color[1]-30), max(0, color[2]-30))
        self.text=text
        self.values1=[self.values[0], self.values[1]+(self.values[3]//2)]
        self.values2=[self.values[0]+self.values[2], self.values[1]+(self.values[3]//2)]
        self.ID=ID
    def draw(self):
        if(self.hidden==0):
            x=2
            if(self.circle==1):                                  #Draws the button circular
                pygame.draw.circle(self.surface, (0,0,0), self.values1, (self.values[3]//2))
                pygame.draw.circle(self.surface, self.color, self.values1, (self.values[3]//2)-2)
                pygame.draw.circle(self.surface, (0,0,0), self.values2, (self.values[3]//2))
                pygame.draw.circle(self.surface, self.color, self.values2, (self.values[3]//2)-2)
                x=0
            pygame.draw.rect(self.surface, (0,0, 0), self.values)
            pygame.draw.rect(self.surface, self.color, [self.values[0]+x, self.values[1]+2, self.values[2]-(2*x), self.values[3]-4])
            self.text_surface = Global.cs.render(self.text, False, (0, 0, 0))
            self.surface.blit(self.text_surface, (self.values[0]+((self.values[2]//2)-(len(self.text)*4.9)),self.values[1]+15))
    def detect(self):                                   #Detects if the mouse is over the button
        if(self.active==1):
            if((Global.mousepos[0]>self.values[0]+self.offset[0] and Global.mousepos[0]<self.values[0]+self.values[2]+self.offset[0] and Global.mousepos[1]>self.values[1]+self.offset[1] and Global.mousepos[1]<self.values[1]+self.values[3]+self.offset[1]) or ((dist(Global.mousepos, (self.values1[0]+self.offset[0], self.values1[1]+self.offset[1]))<(self.values[3]//2)) or (dist(Global.mousepos, (self.values2[0]+self.offset[0], self.values2[1]+self.offset[1]))<(self.values[3]//2)))):
                self.color=self.hovercolor
                return True
            else:
                self.color=self.defaultcolor
        return False
    def clickdet(self):                                     #Detects if the button is clicked
        
        if(self.detect() and Global.mouse[0] and not(self.pressed)):
            self.pressed=True
            return False
        elif(self.detect() and not Global.mouse[0] and self.pressed):
            self.pressed=False
            Global.buttonbuffer.append(self.ID)
            #Effect.effect(self)
            return True
    def sethover(self, hovercolor):
        self.hovercolor=hovercolor
    def setText(self, text):
        self.text=text
    def getText(self):
        return self.text