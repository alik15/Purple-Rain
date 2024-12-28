from turtle import *
import time

def square(a):
    for i in range(10000):
        speed(0)
        forward(300)
        right(a+90)
        a+=0.1
        
square(1)

"""
square()
while(True):
    forward(100)
    right(90)
    forward(100)
    right(90)
    forward(100)
    right(90)
    forward(100"""
