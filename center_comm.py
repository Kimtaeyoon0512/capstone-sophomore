import pygame
import time

pygame.init()
screen = pygame.display.set_mode((640, 480), pygame.RESIZABLE)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                print("left")
            elif event.key == pygame.K_RIGHT:
                print("rights")
            elif event.key == pygame.K_UP:
                print("up")
            elif event.key == pygame.K_DOWN:
                print("down")
        
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                print("e")
            elif event.key == pygame.K_RIGHT:
                print("e")
            elif event.key == pygame.K_UP:
                print("e")
            elif event.key == pygame.K_DOWN:
                print("e")
        
        

    time.sleep(0.01)

pygame.quit()
