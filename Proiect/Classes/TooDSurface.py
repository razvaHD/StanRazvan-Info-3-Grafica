import pygame
import Button
import TextBox
import Label


class TooDSurface:                                              #The surface upon wich 2D Objects are drawn
    def __init__(self, parentsurface, color, values):
        self.parentsurface=parentsurface
        self.color=color
        self.values=values
        self.pos=[values[0], values[1]]
        self.size=[values[2], values[3]]
        self.surface = pygame.Surface(self.size)
        self.buttons=[]
        self.textboxes=[]
        self.labels=[]
        
    def clickdet(self):                                          #Detects if the mouse is over the objects
        for button in self.buttons:
            button.clickdet()
        for textbox in self.textboxes:
            textbox.clickdet()
        for retea in self.retele:
            retea.clickdet()
    def draw(self):                                              #Draws the objects on the screen
        for button in self.buttons:
            button.detect()
            button.draw()
        for textbox in self.textboxes:
            textbox.detect()
            textbox.draw()
        for label in self.labels:
            label.draw()
        for retea in self.retele:
            retea.draw()
    def blit(self, pos=None):                                    #Blits the objects on the parent surface
        if(pos==None):
            self.draw()
            self.parentsurface.blit(self.surface, self.pos)
        else:
            self.parentsurface.blit(self.surface, pos)
    def addButton(self, color, values, ID, text):
        self.buttons.append(Button.Button(self.surface, color, values, self.pos, ID, text))
    def addTextBox(self, color, values, ID, text, allowed=None):
        if allowed is not None:
            self.textboxes.append(TextBox.TextBox(self.surface, color, values, self.pos, ID, text, allowed))
        else:
            self.textboxes.append(TextBox.TextBox(self.surface, color, values, self.pos, ID, text))

    def addLabel(self, color, values, text):
        self.labels.append(Label.Label(self.surface, color, values, self.pos, text))
    def drawbg(self, color):                                      #Draws the background of the surface
        self.surface.fill(color)

