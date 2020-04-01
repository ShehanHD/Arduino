import serial
from visual import *

myProj=display(title="prova")
myProj.width=600;
myProj.height=600;

myProj.autoscale=False
myProj.range=(50,50,50)
target= box(length=2, width=30, height=15)
mytext= label(text="distanza:",width=50, height=15, pos=(-5,20,0))

arduinoData=serial.Serial("COM6", 115200)

while (1==1):
    rate(25)
    while(arduinoData.inWaiting()==0):
        pass
    text=arduinoData.readline()
    values= text.split(",")
    red= float(values[0])
    green= float(values[1])
    blue= float(values[2])
    dis=float(values[3])
    mylabel="distanza: "+values[3]
    mytext.text=mylabel

    red=red*1.
    blue=blue*1.
    green=green*1.

    target.color=(red/255., green/255., blue/255.)
    target.pos=(dis*-1,-5,45)
