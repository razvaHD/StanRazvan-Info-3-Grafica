import pygame
WIDTH=1800
HEIGHT=900
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.init()
pygame.font.init()
textboxselected=0
cs = pygame.font.SysFont('Comic Sans MS', 30)
cm=pygame.font.SysFont('Comic Sans MS', 15)
mousepos=[0,0,0]
mouse=[0,0,0]
buttonbuffer=[]
clock = pygame.time.Clock()
menusel=0
selneuron=[]
valoriNN=[]
globaloffset=[0,0]
globalsize=1
weightpos=0
lastmousepos=[]
rc=0
linii=1