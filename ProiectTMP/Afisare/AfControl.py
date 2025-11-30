import Global
import pygame






def bg():
    Global.screen.fill((180, 180, 180))

def ecrannn():
    Global.suprafNN.blit()
def suprafete():
    match(Global.menusel):
        case 1:
            Global.suprafoptiuni.labels[0].text=str(len(Global.valoriNN)) + " Straturi"
            Global.suprafoptiuni.blit()

        case 2:
            Global.suprafhidden.blit()
        case 3:
            #print(Global.suprafweights.buttons[1].values)
            
            Global.suprafweights.blit()
        case 4:
            for i in range(len(Global.prevweights.buttons)):
                Global.prevweights.buttons[i].hidden=1
                Global.prevweights.buttons[i].active=0
                if(i>1):
                    Global.prevweights.textboxes[i-2].hidden=1
                    Global.prevweights.textboxes[i-2].active=0
            #Global.prevweights.buttons[0].hidden=0
            #Global.prevweights.buttons[0].active=1

            neuron=Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[1])
            for i in range((min(len(Global.prevweights.buttons), (len(neuron.weights)-Global.weightpos)+3))):
                Global.prevweights.buttons[i].hidden=0
                Global.prevweights.buttons[i].active=1
                if(i==0 or i>2):
                    Global.prevweights.textboxes[i-2].hidden=0
                    Global.prevweights.textboxes[i-2].active=1
            Global.prevweights.blit()
            Global.prevweights.clickdet()
        #case 5:
            #for i in range(len(Global.nextweights.buttons)):
            #    Global.nextweights.buttons[i].hidden=1
            #    Global.nextweights.textboxes[i].hidden=1

            #neuron=Global.suprafNN.retele[0].getNeuron(Global.selneuron[0], Global.selneuron[0])
            #for i in range(min(len(Global.nextweights.buttons), len(neuron.weights))):
            #    Global.nextweights.buttons[i].hidden=0
            #    Global.nextweights.textboxes[i].hidden=0
            #Global.nextweights.blit()

def main():
    bg()
    ecrannn()
    suprafete()
    pygame.display.flip()