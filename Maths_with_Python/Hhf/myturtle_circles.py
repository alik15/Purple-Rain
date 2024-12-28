from turtle import *
import time
speed(0)

def square(a=0,b=0):
    for i in range(5000):
        
        right(5)
        for x in range(4):
            forward(b+90)
            right(a+90)
            b+=0.2
            
   
square()
