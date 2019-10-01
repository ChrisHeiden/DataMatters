class TextReader:
    
    def __init__(self, textPath):
        self.text = textPath

    def readTxt(self):
        text = ''
        with open(self.text) as f:
            line = f.readline()
            while line:
                text = text + line
                line = f.readline()
        return text
        
    def readSpecificLine(self, textLine):
        fp = open(self.text)
        for i, line in enumerate(fp):
            if i == textLine:
                line = fp.readline()
                fp.close()
                return line
        fp.close()
        
    def getAmountOfLines(self):
        index = 0
        with open(self.text) as f:
            for i, l in enumerate(f):
                index = index + 1
        return index

    def getYearOfAnimalExtinction(self):
        line = ""
        with open(self.text) as f:
            line = f.readline()
        textList =  line.split(':')
        yearOfAnimalExtinction = textList[1].count(",")
        return yearOfAnimalExtinction
