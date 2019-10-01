from Sounds import *
from TextReader import *
from WebServer import *
from PirSensor import *
from WriteHTML import *
from LED import *
from http.server import HTTPServer
import _thread
import time

def startMotionAction(sleepTime, pirPin, animalExData, webpage, index, songs):
	textReader = TextReader(animalExData)
	lineNumber = textReader.getAmountOfLines()
	writeHTML = WriteHTML(webpage)
	playSound = Sounds(songs)
	index = 0		
	while True:
		playSound.play(index)
		time.sleep(60)
		if index >= 4:
			inde = 0
		else:
			index = index + 1
	for x in range(lineNumber):
		line = textReader.readSpecificLine(x)
		writeHTML.write(line)
		time.sleep(sleepTime)
		
	pirSensor = PirSensor(pirPin) 
	animalExIndex = index
	yearOfAnimalExtinction = textReader.getYearOfAnimalExtinction()

	led = LED(8)
	while True:
		pirSensor.detectMotion()
		if pirSensor.getMotion() == True:			
			if animalExIndex < yearOfAnimalExtinction:
				animalExIndex = animalExIndex + 1
			elif animalExIndex >= yearOfAnimalExtinction:
				animalExIndex = -1
		
			if soundIndex < playSound.getSoundArrayLength():
				soundIndex = soundIndex + 1
			elif soundIndex >= playSound.getSoundArrayLength():
				soundIndex = -1
				
			writeHTML.write(animalExIndex)
			
#test######################################################
#		print pirSensor.getMotionDetection()
#		if pirSensor.getMotionDetection():
#			led.activateLED()
#		else:
#			led.deactivateLED()
###########################################################

def startServer():
	try:
		PORT_NUMBER = 8889
		server = HTTPServer(('', PORT_NUMBER), WebServer)
		print ('Started httpserver on port ' , PORT_NUMBER)
		server.serve_forever()

	except KeyboardInterrupt:
		server.socket.close()
   
def main():
	sleepTime = 10
	pirPin = 4
	animalExData = '/home/pi/Desktop/DataMatters/Master/animalEx.txt'
	webpage = '/home/pi/Desktop/DataMatters/Master/index.html'
	index = -1
	songs = ['/home/pi/DataMatters/Master/Sounds/1970s.mp3','/home/pi/DataMatters/Master/Sounds/1980s.mp3','/home/pi/DataMatters/Master/Sounds/1990s.mp3','/home/pi/DataMatters/Master/Sounds/2000s.mp3','/home/pi/DataMatters/Master/Sounds/2010s.mp3']

	soundIndex = index

	_thread.start_new_thread(startServer,())		
	_thread.start_new_thread(startMotionAction,(sleepTime, pirPin, animalExData, webpage, index, songs))
	
	while 1:
		pass

if __name__ == '__main__':
	main()
