import RPi.GPIO as GPIO
import time

class LED:
    
    def __init__(self, pirPin):
        self.pin = 17
        self.oldMotion = False
        self.motionNoticed = False
        GPIO.setwarnings(False)
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(17, GPIO.OUT, initial=GPIO.LOW) 

    def activateLED(self):
        GPIO.output(17, GPIO.HIGH)
    
    def deactivateLED(self):
        GPIO.output(17, GPIO.LOW)