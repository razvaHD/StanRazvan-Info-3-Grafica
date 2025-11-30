import Global
import pygame
import sys

def addTB(key):
    for box in Global.suprafNN.textboxes:
        if(box.ID==Global.textboxselected):
            box.addLast(chr(key))
    for box in Global.suprafoptiuni.textboxes:
        if(box.ID==Global.textboxselected):
            box.addLast(chr(key))
    for box in Global.suprafhidden.textboxes:
        if(box.ID==Global.textboxselected):
            box.addLast(chr(key))
    for box in Global.suprafweights.textboxes:
        if(box.ID==Global.textboxselected):
            box.addLast(chr(key))
    for box in Global.prevweights.textboxes:
        if(box.ID==Global.textboxselected):
            box.addLast(chr(key))
    #for box in Global.nextweights.textboxes:
        #if(box.ID==Global.textboxselected):
            #box.addLast(chr(key))
def delTB():
    for box in Global.suprafNN.textboxes:
        if(box.ID==Global.textboxselected):
            box.delLast()
    for box in Global.suprafoptiuni.textboxes:
        if(box.ID==Global.textboxselected):
            box.delLast()
    for box in Global.suprafhidden.textboxes:
        if(box.ID==Global.textboxselected):
            box.delLast()
    for box in Global.suprafweights.textboxes:
        if(box.ID==Global.textboxselected):
            box.delLast()
    for box in Global.prevweights.textboxes:
        if(box.ID==Global.textboxselected):
            box.delLast()
    #for box in Global.nextweights.textboxes:
    #    if(box.ID==Global.textboxselected):
    #        box.delLast()


def pyg():
    Global.mousepos = pygame.mouse.get_pos()
    Global.mouse = pygame.mouse.get_pressed()
    if(Global.rc==1):
        if(Global.mouse[2]==False):
            Global.rc=0        
        #print(str(Global.mouse[2])+str(Global.rc))

        Global.globaloffset=[ (Global.globaloffset[0]+((Global.mousepos[0]-Global.lastmousepos[0])/Global.globalsize)), (Global.globaloffset[1]+((Global.mousepos[1]-Global.lastmousepos[1])/(Global.globalsize)))]
        Global.lastmousepos=Global.mousepos
    
    if(Global.mouse[2] and Global.rc==0):
        Global.rc=1
        Global.lastmousepos=Global.mousepos
        
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
            return True
        if event.type == pygame.MOUSEWHEEL:
            if event.y == -1:
                Global.globalsize=max(Global.globalsize-0.05, 0.1)
            if event.y == 1:
                Global.globalsize+=0.05
        #if event.type == pygame.MOUSEBUTTONDOWN:

        if event.type == pygame.KEYDOWN:
            #print(event.key)
            if(event.key==8):
                delTB()
            else:
                if(chr(event.key)=="l"):
                    print(Global.linii)
                    Global.linii=(Global.linii+1)%2
                
                addTB(event.key)
    return False

def buttons():
    for buttonID in Global.buttonbuffer:
        match(buttonID):
            case 1:
                #if(Global.menusel2):
                if(Global.suprafNN.retele==[]):
                    Global.menusel=(Global.menusel+1)%2
                else:
                    Global.menusel=0

            case 2:
                if(len(Global.valoriNN)>2):
                    Global.suprafNN.addRetea((255, 255, 255), Global.valoriNN, [0, 0, 50, 250, 250])
                    Global.suprafNN.retele[0].pas()
                    Global.menusel=0
            case 3:
                Global.weightpos=max(0, Global.weightpos-1)
                neuron=Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1])
                for i in range(min(4 ,len(neuron.weights))):
                    ne=neuron.weights[i+Global.weightpos]
                    Global.prevweights.textboxes[i+1].setText(str(float(f"{ne:.2f}")))
                    Global.prevweights.buttons[i+3].setText("Schimba Greutatea "+str(i+Global.weightpos))
            case 4:

                neuron=Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1])
                Global.weightpos=min(len(Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[0]).weights)-4, Global.weightpos+1)

                for i in range(min(4 ,len(neuron.weights))):
                    ne=neuron.weights[i+Global.weightpos]
                    Global.prevweights.textboxes[i+1].setText(str(float(f"{ne:.2f}")))
                    Global.prevweights.buttons[i+3].setText("Schimba Greutatea "+str(i+Global.weightpos))
            case 5:
                match(Global.suprafhidden.buttons[3].getText()):
                    case "Suma":
                        Global.suprafhidden.buttons[3].setText("Produs")
                    case "Produs":
                        Global.suprafhidden.buttons[3].setText("Maxim")
                    case "Maxim":
                        Global.suprafhidden.buttons[3].setText("Minim")
                    case "Minim":
                        Global.suprafhidden.buttons[3].setText("Suma")
            case 6:
                if(Global.valoriNN):
                    Global.valoriNN.pop()
            case 7:
                Global.menusel=2
                if not(Global.valoriNN):
                    Global.suprafhidden.textboxes[1].hidden=1
                    Global.suprafhidden.textboxes[2].hidden=1
                    Global.suprafhidden.textboxes[3].hidden=1
                    Global.suprafhidden.textboxes[1].active=0
                    Global.suprafhidden.textboxes[2].active=0
                    Global.suprafhidden.textboxes[3].active=0
                    Global.suprafhidden.labels[0].hidden=1
                    Global.suprafhidden.labels[1].hidden=1
                    Global.suprafhidden.labels[3].hidden=1
                    Global.suprafhidden.labels[4].hidden=1
                    Global.suprafhidden.labels[5].hidden=1
                    Global.suprafhidden.buttons[2].hidden=1
                    Global.suprafhidden.buttons[3].hidden=1
                    Global.suprafhidden.buttons[2].active=0
                    Global.suprafhidden.buttons[3].active=0
                else:
                    Global.suprafhidden.textboxes[1].hidden=0
                    Global.suprafhidden.textboxes[2].hidden=0
                    Global.suprafhidden.textboxes[3].hidden=0
                    Global.suprafhidden.textboxes[1].active=1
                    Global.suprafhidden.textboxes[2].active=1
                    Global.suprafhidden.textboxes[3].active=1
                    Global.suprafhidden.labels[0].hidden=0
                    Global.suprafhidden.labels[1].hidden=0
                    Global.suprafhidden.labels[3].hidden=0
                    Global.suprafhidden.labels[4].hidden=0
                    Global.suprafhidden.labels[5].hidden=0
                    Global.suprafhidden.buttons[2].hidden=0
                    Global.suprafhidden.buttons[3].hidden=0
                    Global.suprafhidden.buttons[2].active=1
                    Global.suprafhidden.buttons[3].active=1

                Global.suprafhidden.textboxes[0].setText("")
                Global.suprafhidden.textboxes[1].setText("")
                Global.suprafhidden.textboxes[2].setText("")
            case 8:
                Global.menusel=1
            case 9:
                Global.valoriNN.append([min(10,Global.suprafhidden.textboxes[0].getInt()), Global.suprafhidden.buttons[2].getText(), Global.suprafhidden.textboxes[1].getInt(), Global.suprafhidden.textboxes[2].getInt(), Global.suprafhidden.textboxes[3].getInt(), Global.suprafhidden.buttons[3].getText()])
                Global.menusel=1
            case 10:

                match(Global.suprafhidden.buttons[2].getText()):
                    case "Sigmoidala":
                        Global.suprafhidden.buttons[2].setText("Tangenta")
                    case "Tangenta":
                        Global.suprafhidden.buttons[2].setText("Treapta")
                    case "Treapta":
                        Global.suprafhidden.buttons[2].setText("Liniara")
                    case "Liniara":
                        Global.suprafhidden.buttons[2].setText("Semn")
                    case "Semn":
                        Global.suprafhidden.buttons[2].setText("Sigmoidala")
            case 11:
                Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1]).setValue(Global.suprafweights.textboxes[0].getFloat())
                Global.suprafNN.retele[0].pas()
            case 12:
                Global.weightpos=0
                Global.menusel=4
                neuron=Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1])
                #print(neuron.weights)
                for i in range(min(4 ,len(neuron.weights))):
                    ne=neuron.weights[i+Global.weightpos]
                    Global.prevweights.textboxes[i+1].setText(str(float(f"{ne:.2f}")))
                    Global.prevweights.buttons[i+3].setText("Schimba Greutatea "+str(i+Global.weightpos))
                    Global.suprafNN.retele[0].pas()
                Global.suprafNN.retele[0].pas()
            case 13:
                Global.weightpos=0
                Global.menusel=5
            case 15:
                Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1]).weights[0+Global.weightpos]=Global.prevweights.textboxes[Global.weightpos+1].getFloat()
                Global.suprafNN.retele[0].pas()
            case 16:
                Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1]).weights[0+Global.weightpos]=Global.prevweights.textboxes[Global.weightpos+2].getFloat()
                Global.suprafNN.retele[0].pas()
            case 17:
                Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1]).weights[0+Global.weightpos]=Global.prevweights.textboxes[Global.weightpos+3].getFloat()
                Global.suprafNN.retele[0].pas()
            case 18:
                Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1]).weights[0+Global.weightpos]=Global.prevweights.textboxes[Global.weightpos+4].getFloat()
                Global.suprafNN.retele[0].pas()


    Global.buttonbuffer=[]

def main():
    pyg()
    buttons()