import pygame
import Global
def is_float(string):
    try:
        float(string)
        return True
    except ValueError:
        return False


class TextBox:
    pressed=False
    text=""
    allowed=""
    active=1
    text_surface = Global.cs.render("", False, (0, 0, 0))
    hidden=0

    def __init__(self, surface, color, values, offset, ID, text, allowed=None):
        self.surface=surface
        self.color=color
        self.defaultcolor=color
        self.values=values
        self.offset=offset
        self.hovercolor=color
        self.ID=ID
        self.text=text
        if allowed is not None:
            self.allowed=allowed
    def draw(self):
        if(self.hidden==0):
            pygame.draw.rect(self.surface, (0,0, 0), [self.values[0], self.values[1], self.values[2], self.values[3]])
            pygame.draw.rect(self.surface, self.color, [self.values[0]+2, self.values[1]+2, self.values[2]-4, self.values[3]-4])
            self.text_surface = Global.cs.render(self.text, False, (100, 0, 0))
            self.surface.blit(self.text_surface, (self.values[0]+10,self.values[1]+25))

    def detect(self):
        if(self.active==1):
            if((Global.mousepos[0]>self.values[0]+self.offset[0] and Global.mousepos[0]<self.values[0]+self.values[2]+self.offset[0] and Global.mousepos[1]>self.values[1]+self.offset[1] and Global.mousepos[1]<self.values[1]+self.values[3]+self.offset[1])):
                self.color=self.hovercolor
                return True
            else:
                self.color=self.defaultcolor
        return False
    def clickdet(self):
        if(self.detect() and Global.mouse[0]):
            self.pressed=True
        elif(self.detect() and not Global.mouse[0] and self.pressed):
            self.pressed=False
            Global.textboxselected=self.ID
            #print(Global.textboxselected)
    def setHover(self, hovercolor):
        self.hovercolor=hovercolor
    def setText(self, strng):
        self.text=strng
    def delLast(self):
        self.text=self.text[:-1]
    def delFirst(self):
        self.text=self.text[:1]
    def addLast(self, strng):
        #print('add')
        if(type(strng)!=type("ad")):
            strng=str(strng)
        if strng in self.allowed:
            self.text=self.text+strng
        #print(strng+"-"+str(self.allowed)+"-"+str(strng in self.allowed))
        
    def addFirst(self, strng):
        #print('add')
        if(type(strng)!=type("ad")):
            strng=str(strng)
        if strng in self.allowed:
            self.text=strng+self.text
    def deleteText(self, strng):
        self.text=""
    def setPos(self, width, height):
        self.values[0]=width
        self.values[1]=height
    def getValues(self):
        print(str(self.ID)+"-"+str(self.values))
    def getID(self):
        return self.ID
    def getInt(self):
        if(self.text.isnumeric()):
            return int(self.text)
        return 0
    def getFloat(self):
        if(is_float(self.text)):
            return float(self.text)
        return 0.0

