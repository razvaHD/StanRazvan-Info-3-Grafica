import random
from Clase import Neuron
import Global
import pygame



class Retea():
    def __init__(self, surface, color, valori, valdesen, offset):

        self.valretea=[]
        self.weightretea=[]
        self.surface=surface
        self.color=color
        self.offset=offset
        self.valdesen=valdesen
        self.detaliilayer=valori

        i=0
        for layer in valori:
            self.valretea.append([])
            #if(i>0):
                #self.weightretea.append([])
            #print(layer)
            for j in range (layer[0]):
                self.valretea[i].append(Neuron.Neuron(i, [valdesen[3]*i,valdesen[4]*j]))
                if(i>0):
                    weight=[]
                    #self.weightretea[i-1].append([])
                    for k in range(len(self.valretea[i-1])):
                        weight.append(random.random())
                        #weight.append((0.1+j)*k)
                        #self.weightretea[i-1][j].append()#random.random())
                        #print(self.weightretea[i-1])
                    self.valretea[i][j].setWeights(weight)
                    #self.valretea[i].setWeight(self.weightretea[i-1][j])
                else:
                    self.valretea[i][j].output=0
            i+=1
        #for val in self.valretea:
            #print("val:"+str(len(val)))

    def getWeight(self, layer, nr, value):
        #print(self.weightretea[layer][nr-1][nr])
        #print("weight:"+str(self.weightretea))
        for layer in self.valretea:
            for neuron in layer:
                print(neuron.weights)
    def clickdet(self):
        i=0
        for layer in self.valretea:
            j=0
            for neuron in layer:
                if(neuron.clickdet([neuron.value[0]+self.valdesen[0]+self.valdesen[2]-self.offset[0], neuron.value[1]+self.valdesen[1]+self.valdesen[2]-self.offset[1], self.valdesen[2]])):
                    Global.selneuron=[i,j]
                    ne=self.getNeuron(i,j).output
                    Global.suprafweights.textboxes[0].setText(str(float(f"{ne:.2f}")))
                    Global.menusel=3
                j+=1
            i+=1

    def draw(self):
        i=0
        self.font=pygame.font.SysFont('Comic Sans MS', int(30*Global.globalsize))

        for layer in self.valretea:
            j=0
            for neuron in layer:
                #print(self.valdesen[0])
                #print(neuron.output)

                if(i>0 and Global.linii==1):
                    for neuron2 in self.valretea[i-1]:
                        pygame.draw.line(self.surface, (0,0,0), ((neuron.value[0]+self.valdesen[0]+self.valdesen[2]+Global.globaloffset[0])*Global.globalsize, (neuron.value[1]+self.valdesen[1]+self.valdesen[2]+Global.globaloffset[1])*Global.globalsize), ((neuron2.value[0]+self.valdesen[0]+self.valdesen[2]+Global.globaloffset[0])*Global.globalsize, (neuron2.value[1]+self.valdesen[1]+self.valdesen[2]+Global.globaloffset[1])*Global.globalsize), 2)

                j+=1
            i+=1
        i=0
        
        for layer in self.valretea:
            j=0
            for neuron in layer:
                #print(self.valdesen[0])
       
                pygame.draw.circle(self.surface, self.color, [(neuron.value[0]+self.valdesen[0]+self.valdesen[2]+self.offset[0]+Global.globaloffset[0])*Global.globalsize, (neuron.value[1]+self.valdesen[1]+self.valdesen[2]+self.offset[1]+Global.globaloffset[1])*Global.globalsize], self.valdesen[2]*Global.globalsize)
                text_surface = self.font.render(str((float(f"{neuron.output:.2f}"))), False, (0, 0, 0))
                self.surface.blit(text_surface, [(neuron.value[0]+self.valdesen[0]+self.valdesen[2]+self.offset[0]+Global.globaloffset[0]-17)*Global.globalsize, (neuron.value[1]+self.valdesen[1]+self.valdesen[2]+self.offset[1]+Global.globaloffset[1]-10)*Global.globalsize])

            i+=1
    def getNeuron(self, layer, number):
        return self.valretea[layer][number]
    def pas(self):
        for i in range(1,len(self.valretea)):
            for j in range(len(self.valretea[i])):
                self.valretea[i][j].activate(self.valretea[i-1])

