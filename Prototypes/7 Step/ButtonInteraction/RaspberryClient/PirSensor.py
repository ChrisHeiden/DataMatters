import RPi.GPIO as GPIO
import time

class PirSensor:
    
    def __init__(self, pirPin):
        self.pin = 4
        self.oldMotion = False
        self.motionNoticed = False
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(4, GPIO.IN) 

    def detectMotion(self):
        print(GPIO.input(4))
        if GPIO.input(4):
            if self.oldMotion != self.motionNoticed:
                self.motionNoticed = True
                self.oldMotion = self.motionNoticed
        else:
            self.motionNoticed = False
            self.oldMotion = self.motionNoticed

    def getMotion(self):
        return self.motionNoticed

    def getOldMotion(self):
        return self.oldMotion
