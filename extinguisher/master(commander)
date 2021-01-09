
import pygame,sys,random
from pygame.locals import *
import serial

pygame.init()

WINDOWWIDTH = 400
WINDOWHEIGHT= 400

windowSurface = pygame.display.set_mode( (WINDOWWIDTH, WINDOWHEIGHT), 0, 32 )
pygame.display.set_caption('Practice keyboardInput')

port = ''
brate = 9600

moveLeft=False
moveRight = False
moveUp = False
moveDown = False
 
MOVESPEED = 0

ser = serial.Serial(port, baudrate = brate, timeout = None)

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        if event.type == KEYDOWN:
            ##방향키
            if event.key == K_LEFT: 
                temp = '3'
                ser.write(temp.encode('utf-8'))
            if event.key == K_RIGHT:
                temp = '4'
                ser.write(temp.encode('utf-8'))
            if event.key == K_UP :
                temp = '1'
                ser.write(temp.encode('utf-8'))
            if event.key == K_DOWN :
                temp = '2'
                ser.write(temp.encode('utf-8'))
            
            ## 각도 조절
            if event.key == ord('a'):
                temp = 'a'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('d'):
                temp = 'd'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('w'):
                temp = 'w'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('s'):
                temp = 's'
                ser.write(temp.encode('utf-8'))
                
            ##물쏘기
            if event.key == K_SPACE:
                temp = 'g'
                ser.write(temp.encode('utf-8'))
                
        if event.type == KEYUP:
            if event.key == K_ESCAPE:
                pygame.quit()
                sys.exit()
             ##방향키
            if event.key == K_LEFT: 
                moveLeft = False
                temp = '7'
                ser.write(temp.encode('utf-8'))
            if event.key == K_RIGHT:
                moveRight = False
                temp = '8'
                ser.write(temp.encode('utf-8'))
            if event.key == K_UP :
                moveUp = False
                temp = '5'
                ser.write(temp.encode('utf-8'))
            if event.key == K_DOWN :
                moveDown = False
                temp = '6'
                ser.write(temp.encode('utf-8'))
            
            ##각도조절
            if event.key == ord('a'):
                moveLeft = False
                temp = 'A'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('d'):
                moveRight = False
                temp = 'D'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('w'):
                moveUp = False
                temp = 'W'
                ser.write(temp.encode('utf-8'))
            if event.key == ord('s'):
                moveDown = False
                temp = 'S'
                ser.write(temp.encode('utf-8'))
                
            ## 물쏘기
            if event.key == K_SPACE:
                moveDown = False
                temp = 'G'
                ser.write(temp.encode('utf-8'))    
            

    if moveDown and player.bottom < WINDOWHEIGHT:
        player.top += MOVESPEED
    if moveUp and player.top > 0:
        player.top -= MOVESPEED
    if moveLeft and player.left > 0 :
        player.left -= MOVESPEED
    if moveRight and player.right < WINDOWWIDTH:
        player.left += MOVESPEED
