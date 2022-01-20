# Simple pygame program
# From https://realpython.com/pygame-a-primer/

# Import and initialize the pygame library
import pygame
import random

pygame.init()

# seed pseudo random generator
random.seed(1)

# Set up the drawing window
screen = pygame.display.set_mode([500, 500])

# Colors for the circle
red = 0
green = 0
blue = 0

# initial position and radius of circle
center = [250, 250]
radius = 25.0

# Run until the user asks to quit
running = True
while running:
    for event in pygame.event.get():
        # Did the user click the window close button?
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            pos = pygame.mouse.get_pos()
            # Check that user clicked circle
            if ((pos[0] - center[0]) ** 2) + ((pos[1] - center[1]) ** 2) <= (radius ** 2):
                # Create new circle of random size at random position
                center[0] = random.randint(0, 500)
                center[1] = random.randint(0, 500)
                radius = random.randint(10, 100)
                #  Give circle a random color
                red = random.randint(0, 250)
                green = random.randint(0, 250)
                blue = random.randint(0, 250)

    # Fill the background with white
    screen.fill((255, 255, 255))

    # Draw a solid blue circle in the center
    pygame.draw.circle(screen, (red, green, blue), center, radius)

    # Flip the display
    pygame.display.flip()

# Done! Time to quit.
pygame.quit()
