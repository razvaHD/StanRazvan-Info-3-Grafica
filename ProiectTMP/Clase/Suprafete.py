import pygame
from Clase import Button
from Clase import TextBox
from Clase import Label
from Clase import Retea


nr=0

class Suprafete:
    def __init__(self, parentsurface, color, values):
        self.parentsurface=parentsurface
        self.color=color
        self.values=values
        self.pos=[values[0], values[1]]
        self.size=[values[2], values[3]]
        self.surface = pygame.Surface(self.size)
        global nr
        self.buttons=[]
        self.textboxes=[]
        self.labels=[]
        self.retele=[]
        nr+=1
    def clickdet(self):
        for button in self.buttons:
            button.clickdet()
        for textbox in self.textboxes:
            textbox.clickdet()
        for retea in self.retele:
            retea.clickdet()
    def draw(self):
        self.surface.fill(self.color)
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
    def blit(self, pos=None):
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
    def addRetea(self, color, values, valdesen):
        self.retele.append(Retea.Retea(self.surface, color, values, valdesen, self.pos))

