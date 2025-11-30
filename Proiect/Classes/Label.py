import pygame


class Label:
    text=""
    def __init__(self, surface, color, values, offset, text):
        self.surface=surface
        self.color=color
        self.pos=[values[0], values[1]]
        self.offset=offset
        self.text=text
        self.size=values[2]
        self.font=pygame.font.SysFont('Comic Sans MS', self.size)
        self.hidden=0
    def draw(self):
        if(self.hidden==0):
            self.text_surface = self.font.render(self.text, False, (0, 0, 0))
            self.surface.blit(self.text_surface, self.pos)