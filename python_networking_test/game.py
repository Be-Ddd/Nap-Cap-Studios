# Example file showing a circle moving on screen
import pygame
import pygame_widgets
from pygame_widgets.slider import Slider
from pygame_widgets.textbox import TextBox

# pygame setup
pygame.init()
screen = pygame.display.set_mode((600, 600))
clock = pygame.time.Clock()
host = True #ill get to it later
running = True
held = False

bpm = 30
frames = 60
beats = 0
center_width = 20
dt = 0

center = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)
metronome_beat = pygame.mixer.Sound(f"audio_files\metronome_beat.wav")
bpm_slider = Slider(screen, 20, 20, 100, 20, min=10, max=100, step=1)
bpm_readout = TextBox(screen, screen.get_width() - 150, 0, 150, 45, fontSize=20)

while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    screen.fill("gray")

    # circle setup
    """
    pygame.draw.circle(screen, "black", center, center_width)
    pygame.draw.circle(screen, "red", center = center, radius=(screen.get_width()/3 - center_width) * (1 - beats/(frames/bpm)) + center_width, width=5)
    pygame.draw.circle(screen, "red", center = center, radius=(screen.get_width()/3 - center_width) + center_width, width=5)
    """
    #crypt of the necromancer dancer setup
    pygame.draw.rect(screen, "black", pygame.Rect(screen.get_width() / 2,screen.get_height() * .75,10,50), center_width)
    num_bars = 3
    for offset in range(num_bars):
        pygame.draw.rect(screen, "red", pygame.Rect((screen.get_width() / 2) * (beats/(frames/bpm)/num_bars) + offset * (screen.get_width() / (2*num_bars)),screen.get_height() * .75 + 10,10,30), center_width)

    # print(beats)



    pressed_keys = pygame.key.get_pressed()
    if pressed_keys[pygame.K_SPACE]:
        if held:
            pass
        else:
            held = True
            print((1 - beats/(frames/bpm)), "ms off")
    else:
        held = False
    
    bpm = bpm_slider.getValue()
    bpm_readout.setText(f"{bpm} bpm")

    # flip() the display to put your work on screen
    pygame_widgets.update(event)
    pygame.display.flip()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(frames) / 1000
    beats += dt
    if beats > frames/bpm:
        metronome_beat.play()
        beats = 0

pygame.quit()