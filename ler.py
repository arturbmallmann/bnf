#!/usr/bin/python3
# Author: Artur Bernardo Mallmann
# Mail: arturbmallmann@gmail.com
# License: Make what you want, and if you want pay me a beer!!!
# Version: 0.000.000.r2alphace
import sys
import math
#print (args[1:3]) listas como usar: https://youtu.be/W8KRzm-HUcc
class MyException(LookupError):
    '"my exception"'
    
class File():
    def __init__(self, path):
        try:
            self.file=open(path)
        except:
            raise MyException();
    def read(self):
        self.file.seek(0)
        return int(self.file.readline())
    def write(self,value):
        print('Write> '+str(value))
        self.file.seek(0)
        self.file.write(str(value)+'\n')
        self.file.flush()

class Bright(File):
    def __init__(self,path,maxvalue):
        self.file=open(path,'+r')
        self.maxvalue=maxvalue
    def increase(self):
        value=math.log(self.read())
        value+=.25
        if math.exp(value)>=self.maxvalue:
            value=math.log(self.maxvalue)
        print (value)
        self.write(int(math.exp(value)))
    def decrease(self):
        value=math.log(self.read())
        value-=.25
        if value<=2:
            return
        print(value)
        self.write(int(math.exp(value)))

#def getBright(filename):
#    try:
#        file=open(filename)
#        num=int(file.readline())
#        file.close()
#        return num
#    except:
#        raise MyException();

    
args=sys.argv
def main():
    filename="/sys/class/backlight/intel_backlight/brightness"
    filemax="/sys/class/backlight/intel_backlight/max_brightness"
#    filename="/home/artur/teste"
#value=getBright(file)
    maxfile=File(filemax)
    maxvalue=maxfile.read();
    myFile=Bright(filename,maxvalue)
    
    for item in args:
        if item=='up':
            myFile.increase()
        elif item=='down':
            myFile.decrease()
        elif item=='read':
            print(myFile.read())
            
if __name__=='__main__':
    main()
