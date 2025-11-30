import Global
from Clase import Suprafete
from Clase import Retea


def initsuprafNN():
    Global.suprafNN=Suprafete.Suprafete(Global.screen, (200,200,255), [0,0, Global.WIDTH, Global.HEIGHT])
    Global.suprafNN.addButton((0,0,255), [1695, 0, 30, 50], 1, "")
    #Global.suprafNN.addRetea((255, 255, 255), [[3, 3, 3, 3]], [0, 0, 50, 250, 250])

def initsuprafoptiuni():
    Global.suprafoptiuni=Suprafete.Suprafete(Global.screen, (130,130,230), [Global.WIDTH-550,50, 500, 500])
    Global.suprafoptiuni.addButton((0,0,255), [150, 330, 200, 50], 2, "Initializare Retea")
    #Global.suprafoptiuni.addButton((0,0,255), [400, 150, 30, 50], 3, "")
    #Global.suprafoptiuni.addButton((0,0,255), [400, 250, 30, 50], 4, "")
    #Global.suprafoptiuni.addButton((0,0,255), [400, 350, 30, 50], 5, "")
    Global.suprafoptiuni.addButton((0,0,255), [125, 225, 50, 50], 6, "-")
    Global.suprafoptiuni.buttons[1].cerc=0
    Global.suprafoptiuni.addButton((0,0,255), [325, 225, 50, 50], 7, "+")
    Global.suprafoptiuni.buttons[2].cerc=0
    #Global.suprafoptiuni.addTextBox((200,200,200), [50, 50, 250, 50], 1, "", "0123456789")
    #Global.suprafoptiuni.addTextBox((200,200,200), [50, 150, 250, 50], 2, "", "0123456789")
    #Global.suprafoptiuni.addTextBox((200,200,200), [50, 250, 250, 50], 3, "", "0123456789")
    #Global.suprafoptiuni.addTextBox((200,200,200), [50, 350, 250, 50], 4, "", "0123456789")
    #Global.suprafoptiuni.addTextBox((200,200,200), [200, 425, 100, 50], 5, "")

    Global.suprafoptiuni.addLabel((0,0,0), [195, 237, 40], "Strat")

def initsuprafhidden():
    Global.suprafhidden=Suprafete.Suprafete(Global.screen, (130,130,230), [Global.WIDTH-550,50, 500, 500])
    Global.suprafhidden.addButton((0,0,255), [100, 450, 75, 100], 8, "Iesire")
    Global.suprafhidden.buttons[0].cerc=0
    Global.suprafhidden.addButton((0,0,255), [275, 450, 110, 100], 9, "Adaugare")
    Global.suprafhidden.buttons[1].cerc=0
    Global.suprafhidden.addButton((0,0,255), [260, 280, 200, 50], 10, "Sigmoidala")
    Global.suprafhidden.addLabel((0,0,0), [50, 292, 35], "Activation:")
    Global.suprafhidden.addButton((0,0,255), [260, 350, 200, 50], 5, "Suma")
    Global.suprafhidden.addLabel((0,0,0), [50, 362, 35], "Input:")

    Global.suprafhidden.addTextBox((200,200,200), [260, 0, 200, 50], 5, "", "0123456789")
    Global.suprafhidden.addLabel((0,0,0), [50, 13, 35], "Neuroni pe strat:")
    Global.suprafhidden.addTextBox((200,200,200), [260, 70, 200, 50], 6, "", "0123456789.")
    Global.suprafhidden.addLabel((0,0,0), [50, 82, 35], "Sigma:")
    Global.suprafhidden.addTextBox((200,200,200), [260, 140, 200, 50], 7, "", "0123456789.")
    Global.suprafhidden.addLabel((0,0,0), [50, 152, 35], "g:")
    Global.suprafhidden.addTextBox((200,200,200), [260, 210, 200, 50], 21, "", "0123456789.")
    Global.suprafhidden.addLabel((0,0,0), [50, 222, 35], "a:")

    #Global.suprafhidden.addTextBox((200,200,200), [50, 350, 250, 50], 6, "", "0123456789")


def initsuprafweights():
    Global.suprafweights=Suprafete.Suprafete(Global.screen, (130,130,230), [Global.WIDTH-550,50, 500, 500])
    #Global.suprafweights.addLabel((0,0,0), [50, 62, 35], "Valoare:")
    Global.suprafweights.addTextBox((200,200,200), [50, 50, 100, 50], 8, "", "0123456789.")
    Global.suprafweights.addButton((0,0,255), [200, 50, 250, 50], 11, "Change Value")
    Global.suprafweights.addButton((0,0,255), [200, 150, 250, 50], 12, "Greutati strat precedent")
    #Global.suprafweights.addButton((0,0,255), [200, 250, 200, 50], 13, "Greutati strat urmator")

def initprevweights():
    Global.prevweights=Suprafete.Suprafete(Global.screen, (130,130,230), [Global.WIDTH-550,50, 500, 500])
    #Global.suprafweights.addLabel((0,0,0), [50, 62, 35], "Valoare:")
    Global.prevweights.addTextBox((200,200,200), [150, 0, 100, 50], 14, "", "0123456789.")
    Global.prevweights.addButton((0,0,255), [300, 30, 50, 50], 11, "Salt")
    Global.prevweights.addButton((0,0,255), [450, 175, 50, 50], 3, "Sus")
    Global.prevweights.buttons[1].cerc=0
    Global.prevweights.addButton((0,0,255), [450, 325, 50, 50], 4, "Jos")
    Global.prevweights.buttons[2].cerc=0
    Global.prevweights.addTextBox((200,200,200), [50, 130, 100, 50], 15, "", "0123456789.")
    Global.prevweights.addButton((0,0,255), [200, 130, 200, 50], 15, "Schimba Greutatea")
    Global.prevweights.addTextBox((200,200,200), [50, 230, 100, 50], 16, "", "0123456789.")
    Global.prevweights.addButton((0,0,255), [200, 230, 200, 50], 16, "Schimba Greutatea")
    Global.prevweights.addTextBox((200,200,200), [50, 330, 100, 50], 17, "", "0123456789.")
    Global.prevweights.addButton((0,0,255), [200, 330, 200, 50], 17, "Schimba Greutatea")
    Global.prevweights.addTextBox((200,200,200), [50, 430, 100, 50], 18, "", "0123456789.")
    Global.prevweights.addButton((0,0,255), [200, 430, 200, 50], 18, "Schimba Greutatea")

def initnextweights():
    Global.nextweights=Suprafete.Suprafete(Global.screen, (180, 180, 180), [Global.WIDTH-550,50, 500, 500])
    #Global.suprafweights.addLabel((0,0,0), [50, 62, 35], "Valoare:")
    Global.nextweights.addTextBox((200,200,200), [50, 50, 100, 50], 8, "", "0123456789.")
    Global.nextweights.addButton((0,0,255), [200, 50, 200, 50], 11, "Change Value")



def main():
    initsuprafNN()
    initsuprafoptiuni()
    initsuprafhidden()
    initsuprafweights()
    initprevweights()
    #initnextweights()