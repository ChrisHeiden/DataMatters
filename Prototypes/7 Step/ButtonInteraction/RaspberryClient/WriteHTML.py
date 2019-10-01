class WriteHTML:
      
    def __init__(self,htmlPath):
        self.htmlPath = htmlPath
                
    def write(self, text):
        f = open(self.htmlPath, 'w')
        message = "%s"%(text)
        print(message)
        f.write(message)
        f.close()
