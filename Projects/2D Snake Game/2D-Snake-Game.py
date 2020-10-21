import pygame
import sys
import copy
import random
import time

pygame.init()

width = 500
height = 500
scale = 10
score = 0

food_x = 10
food_y = 10

display = pygame.display.set_mode((width, height))
pygame.display.set_caption("Feed the snake")
clock = pygame.time.Clock()

snake_speed = 10
background = (255, 204, 229)
snake_head = (152, 0, 152)
food_colour = (0, 0, 0)
snake_colour = (192, 192, 192)
text_colour = (255, 0 , 0)
text_colour_2 = (0, 51 , 102)

# Snake Class start---------------------------------------------------------------
class Snake:
    def __init__(self, x_start, y_start):
        self.x = x_start
        self.y = y_start
        self.w = 10
        self.h = 10
        self.x_dir = 1
        self.y_dir = 0
        self.history = [[self.x, self.y]]
        self.length = 1

    def reset(self):
        self.x = width/2-scale
        self.y = height/2-scale
        self.w = 10
        self.h = 10
        self.x_dir = 1
        self.y_dir = 0
        self.history = [[self.x, self.y]]
        self.length = 1

    def show(self):
        for i in range(self.length):
            if not i == 0:
                pygame.draw.rect(display, snake_colour, (self.history[i][0], self.history[i][1], self.w, self.h))
            else:
                pygame.draw.rect(display, snake_head, (self.history[i][0], self.history[i][1], self.w, self.h))

    def check_eaten(self):
        if abs(self.history[0][0] - food_x) < scale and abs(self.history[0][1] - food_y) < scale:
            return True

    def grow(self):
        self.length += 1
        self.history.append(self.history[self.length-2])

    def death(self):
        i = self.length - 1
        while i > 0:
            if abs(self.history[0][0] - self.history[i][0]) < self.w and abs(self.history[0][1] - self.history[i][1]) < self.h and self.length > 2 or self.history[0][0] >= width or self.history[0][0] < 0 or self.history[0][1] >= height or self.history[0][1] < 0:
                return True
                
            i -= 1

    def update(self):
        i = self.length - 1
        while i > 0:
            self.history[i] = copy.deepcopy(self.history[i-1])
            i -= 1
        self.history[0][0] += self.x_dir*scale
        self.history[0][1] += self.y_dir*scale
# Snake Class end ---------------------------------------------------------------
# Food Class start --------------------------------------------------------------
class Food:
    def new_location(self):
        global food_x, food_y
        food_x = random.randrange(1, width/scale-1)*scale
        food_y = random.randrange(1, height/scale-1)*scale

    def show(self):
        pygame.draw.rect(display, food_colour, (food_x, food_y, scale, scale))


def show_score():
    font = pygame.font.SysFont("comicsansms", 20)
    text = font.render("                                 Score: " + str(score), True, text_colour)
    display.blit(text, (scale, scale))
    
# Food Class end ----------------------------------------------------------------

# Function to display message
def message(msg, color, size):
    font_style = pygame.font.SysFont("comicsansms", size)
    message = font_style.render(msg, True, color)
    display.blit(message, (width/5 , height/2 - 30))

# Game Loop start ----------------------------------------------------------------
def gameLoop():
    loop = False

    global score

    snake = Snake(width/2, height/2)
    food = Food()
    food.new_location()

    while not loop:  
        # start menu      
        display.fill(background)  
        message("Press F5 to START or Q to Exit", text_colour_2, 20)     
        for event in pygame.event.get():            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_F5:                   
                    loop = True
                    break

                if event.key == pygame.K_q:
                    pygame.quit()
                    sys.exit()

            if event.type == pygame.QUIT:
                    pygame.quit()

        pygame.display.update()
        clock.tick(10)    
        
        #main game loop
        while loop: 
        
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()

                if event.type == pygame.KEYDOWN:
                    if snake.y_dir == 0:
                        if event.key == pygame.K_UP:
                            snake.x_dir = 0
                            snake.y_dir = -1
                        if event.key == pygame.K_DOWN:
                            snake.x_dir = 0
                            snake.y_dir = 1

                    if snake.x_dir == 0:
                        if event.key == pygame.K_LEFT:
                            snake.x_dir = -1
                            snake.y_dir = 0
                        if event.key == pygame.K_RIGHT:
                            snake.x_dir = 1
                            snake.y_dir = 0

            display.fill(background)

            snake.show()
            snake.update()
            food.show()
            show_score()

            if snake.check_eaten():
                food.new_location()
                score += 1
                snake.grow()

            if snake.death():
                score = 0
                message("   GAME OVER!", text_colour, 40)
                loop = False
                pygame.display.update()
                snake.reset()
                time.sleep(2)
                
            if snake.history[0][0] > width:
                snake.history[0][0] = 0
            if snake.history[0][0] < 0:
                snake.history[0][0] = width

            if snake.history[0][1] > height:
                snake.history[0][1] = 0
            if snake.history[0][1] < 0:
                snake.history[0][1] = height

            pygame.display.update()
            clock.tick(snake_speed)

gameLoop()
# Game Loop end ----------------------------------------------------------------