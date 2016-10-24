#import serial # Serial library imported
from Tkinter import *
#arduinoSerialData = serial.Serial('com3', 9600)

# Creating window
root = Tk()
theLabel = Label(root, text="This is a label.")
theLabel.pack()
root.mainloop()

# Reads the data from the Arduino print out line
#while(1 == 1):
 #   if(arduinoSerialData.inWaiting() > 0):
  #      myData = arduinoSerialData.readline()
   #     print myData
