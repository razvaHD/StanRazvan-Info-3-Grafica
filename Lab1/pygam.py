import pygame
import sys
# Inițializăm Pygame
pygame.init()
# Dimensiunea ferestrei
WIDTH, HEIGHT = 800, 600
# Crearea ferestrei
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Laboratorul 1 - Grafica 2D cu Pygame")
# Culori
ALB = (255, 255, 255)
ROS = (255, 0, 0)
VERDE = (0, 255, 0)
ALBASTRU = (0, 0, 255)
MOV=(128, 0, 200)
ACOPERIS=(114, 38, 19)
CASA=(232, 223, 221)

def main():
    clock = pygame.time.Clock()
    running = True
    speed=5
    d=speed
    circlex=0
    while running:
        mousepos=pygame.mouse.get_pos()
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                pygame.quit()
                sys.exit()

        screen.fill(MOV)
        pygame.draw.circle(screen, ALBASTRU, (circlex, 100), 80)
        pygame.draw.rect(screen, VERDE, (mousepos[0]-25, mousepos[1]-10, 50, 20))
        pygame.draw.line(screen, ROS, (0, 0), (800, 600), 5)
        pygame.draw.polygon(screen, ACOPERIS, ((250,400),(400,300),(550,400)))
        pygame.draw.rect(screen, CASA, (300, 400, 200, 200))
        pygame.draw.rect(screen, (129, 80, 69), (400, 500, 50, 100))
        pygame.draw.circle(screen, (126, 86, 76), (410, 550), 8)
        pygame.draw.rect(screen, (129, 80, 69), (315, 445, 60, 110))
        pygame.draw.rect(screen, (209, 239, 253), (320, 450, 50, 100))
        pygame.draw.rect(screen, (129, 80, 69), (341, 445, 8, 110))
        pygame.draw.rect(screen, (129, 80, 69), (320, 495, 55, 8))
        pygame.display.flip()
        if(circlex<0 or circlex>WIDTH):
            d=-d
        circlex+=d

if __name__ == "__main__":
    main()