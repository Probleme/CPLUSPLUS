import pygame
import os
import sys
import time
import signal

def handle_sigterm(signum, frame):
    lock_screen()

def lock_screen():
    os.system("osascript -e 'tell application \"Finder\" to sleep'")
    sys.exit(0)

def log_out():
    os.system("osascript -e 'tell application \"loginwindow\" to  «event aevtrlgo»'")
    sys.exit(0)

def curr_time():
    return time.time()

def timecount(start_time):
    curr = curr_time()
    count = curr - start_time
    if count > 60 * 60 * 1: # 1 hours
        log_out()

def main():
    pygame.init()
    screen_width, screen_height = pygame.display.Info().current_w, pygame.display.Info().current_h
    screen = pygame.display.set_mode((screen_width, screen_height), pygame.FULLSCREEN | pygame.NOFRAME)
    pygame.display.set_caption("ft_irc")
    pygame.mouse.set_visible(False)
    start_time = curr_time()
    running = True
    signal.signal(signal.SIGTERM, handle_sigterm)
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pass
        keys_pressed = pygame.key.get_pressed()
        if keys_pressed[pygame.K_LCTRL] and keys_pressed[pygame.K_ESCAPE] and keys_pressed[pygame.K_k]:
            running = False
        pygame.time.delay(1000)  # Delay to reduce CPU usage
        timecount(start_time)
    pygame.quit()

if __name__ == "__main__":
    main()