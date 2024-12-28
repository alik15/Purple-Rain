from turtle import *
import time
import random
speed(0)
screen=Screen()
hideturtle()

wn=Screen()
wn.bgcolor("black")
all_colors=[
    "grey"]

screen.setup(1000, 1000)


def square(a=0,b=5):
    for i in range(5000):
        color(random.choice(all_colors))
        right(3)
        for x in range(4):
            forward(b+2)
            right(a+90)
            b+=0.1
            
   
square()
