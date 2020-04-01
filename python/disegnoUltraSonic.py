import serial
from visual import *

myProj=display(title="prova")
myProj.width=500;
myProj.height=500;

myProj.autoscale=False
myProj.range=(400,400,400)
ball = sphere(radius=15 , color=(1,0,0))
rod1 = cylinder(pos=(50,100,0), radius=5, color=(1,1,0))
rod2 = cylinder(pos=(-100,0,0), radius=5,color=(0,0,1))
rod3 = cylinder(pos=(50,-100,0), radius=5, color=(1,0,1))
rod4 = cylinder(pos=(200,0,0), radius=5, color=(0,1,1))
mytext= label(text="distanza:",width=50, height=15, pos=(0,-300,0))

arduinoData=serial.Serial("COM6", 9600)

while (1==1):
    rate(25)
    while(arduinoData.inWaiting()==0):
        pass
    text=arduinoData.readline()
    values= text.split(",")
    dis1=float(values[0])*10
    dis2=float(values[1])*10
    mylabel="distanza1: "+values[0]+"distanza2: "+values[1]
    mytext.text=mylabel


    ball.pos=(dis1-100,(dis2*-1)+100,0)
    rod1.axis=(dis1-150,dis2*-1,0)
    rod2.axis=(dis1,(dis2*-1)+100,0)
    rod3.axis=(dis1-150,(dis2*-1)+200,0)
    rod4.axis=(dis1-300,(dis2*-1)+100,0)
