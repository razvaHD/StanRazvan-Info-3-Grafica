import pygame
import TooDSurface

class SurfaceController:
    toodsurfaces=[]
    def __init__(self):
        self.surfaces=[]
    def addSurface(self, x, y, width, length, background):
        self.surfaces.append(TooDSurface.TwoDSurface(self.surfaces, background, [x, y, width, length]))
    def drawbg(self):
        for surface in self.surfaces:
            surface.drawbg()
    def draw(self):
        for surface in self.surfaces:
            surface.draw()
    def blit(self):
        for surface in self.surfaces:
            surface.blit()

control=SurfaceController()