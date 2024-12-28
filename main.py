import pygame
import random
from pygame.locals import *

SIZE = [1000,1000]
DROPLET_HEIGHT = 50
DROPLET_WIDTH = 3
INITIAL_VELOCITY = 4
ACCELERATION= 1.52
X_POSITION = 0
Y_POSITION = 0
BACKGROUND_COLOR = (169,169,169)
DROPLET_COLOR = (190,0,254)
DROPLET_COUNT = 500

DROPLETS = list()



def main():
    droplets = initDroplets(SIZE,DROPLET_WIDTH, DROPLET_HEIGHT)
    
    pygame.init()
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("Arial" , 18 , bold = True)
    pygame.display.set_caption("Purple Rain")
    screen = pygame.display.set_mode(SIZE)

    #Properties of the character

    background = pygame.Surface(screen.get_size())
    background =background.convert()
    background.fill(BACKGROUND_COLOR)

    while True:
        clock.tick(60)
        for event in pygame.event.get():
                if event.type == QUIT:
                    return
              
        screen.blit(background,(0,0))

        drawDroplets(droplets,screen) 
        updateDroplets(droplets,INITIAL_VELOCITY)
        displayOverlay(clock,font,screen,DROPLET_COUNT)
        
        pygame.display.flip()
        


def initDroplets(SIZE,WIDTH,LENGTH):
    droplets =   [
        [random.randint(0, SIZE[0] - WIDTH), random.randint(-SIZE[1], 0), WIDTH, LENGTH]
        for _ in range(DROPLET_COUNT)
    ]
    return droplets

def drawDroplets(droplets,screen):
        for i in droplets:
            pygame.draw.rect(screen,DROPLET_COLOR,(i[0],i[1],i[2],i[3]))
def updateDroplets(droplets,INITIAL_VELOCITY):
     VELOCITY = INITIAL_VELOCITY
     for i in droplets:
          i[1]+=VELOCITY
          VELOCITY += ACCELERATION
          if i[1]>SIZE[1]:
               i[1]= random.randint(-SIZE[1], 0)
               VELOCITY = INITIAL_VELOCITY
          
          

def displayOverlay(clock,font,screen,DROPLET_COUNT):
    fps = str(int(clock.get_fps()))
    fps_t = font.render(fps , 1, pygame.Color("RED"))
    screen.blit(fps_t,(0,0))
    droplet_count_text = font.render(f"Droplets: {DROPLET_COUNT}", 1, pygame.Color("RED"))
    screen.blit(droplet_count_text, (0, 20))
   

  

if __name__ == '__main__': main() 
