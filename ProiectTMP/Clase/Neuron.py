import Global
import math
from Calcule import Matematice
#from Calcule import Matematice

def dist(a, b):
    return math.sqrt((((a[0]-b[0])**2)+((a[1]-b[1])**2)))

def functie3():
    pass


class Neuron():
    pressed=False
    def __init__(self, layer, value):
        self.value=value
        self.weights=[]
        self.inp=0
        self.act=0
        self.output=0
        self.layer=layer

    def inputs(self, layer):
        i=0
        self.inp=0
        #for neuron in layer:
        #    self.inp+=neuron.output*self.weights[i]
        #    i+=1
        self.inp=Matematice.In( self.layer, self)
    def activation(self):
        self.output=Matematice.Act(self.inp, self.layer)
    def outp(self):
        self.output=self.output
    def activate(self, layer):
        self.inputs(layer)
        self.activation()
        self.outp()
    def setWeights(self, weights):
        self.weights=weights
    def detect(self, valori):
        if(dist([(valori[0]+Global.globaloffset[0])*Global.globalsize, (valori[1]+Global.globaloffset[1])*Global.globalsize], Global.mousepos)<=valori[2]*Global.globalsize):
            return True
        return False
    def clickdet(self, valori):
        if(self.detect(valori) and Global.mouse[0] and self.pressed==False):
            self.pressed=True
            return False
        elif(self.detect(valori) and not Global.mouse[0] and self.pressed):
            self.pressed=False
            #Global.buttonbuffer.append(self.value)
            #Effect.effect(self)
            return True
    def setValue(self, value):
        self.output=value
