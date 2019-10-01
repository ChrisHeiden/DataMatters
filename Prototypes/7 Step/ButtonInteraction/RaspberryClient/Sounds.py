import pygame

class Sounds:
    def __init__(self, songs):
        self.sounds = [songs[0], songs[1], songs[2], songs[3],songs[4]]
        self.index = 0
  
#    def play(self):
#        pygame.init()
#        pygame.mixer.music.load(self.sounds[self.index])
#        pygame.mixer.music.play()
#        while pygame.mixer.music.get_busy() == True:
#            continue
            
    def play(self, index):
        pygame.init()
        pygame.mixer.music.load(self.sounds[index])
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy() == True:
            continue
            
            
    def stopSong(self):
        pygame.mixer.music.stop
        self.index = self.index + 1
            
    def getSongLength(self):
        sec = pygame.mixer.music.get_length()
        return sec
    
    def stillPlaying(self):
        return pygame.mixer.music.get_busy()