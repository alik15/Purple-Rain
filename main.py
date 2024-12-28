import pygame

pygame.init()
size = [700, 600]
color_for_background=(169,169,169)
colour_droplet=(190,0,254)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Purple Rain")

#Properties of the character
x=10
y=56

width=3
height=50
velocity=8


#The main loop
run = True
while run:
    pygame.time.delay(100)
    
    pygame.draw.rect(screen,(190,0,254),(x,y,width,height))
    pygame.display.update()

       
    y+=velocity
    screen.fill((0,0,0))
    velocity+=1.52
    if y>600:
        y=56
        velocity=4
        
    
    
pygame.quit()        
  

