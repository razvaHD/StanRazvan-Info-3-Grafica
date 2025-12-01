import pygame
import Evenimente
import Global
import sys





def ecrannn():
    Global.suprafNN.clickdet()

def menus():
    match(Global.menusel):
        case 1:
            Global.suprafoptiuni.clickdet()
        case 2:
            Global.suprafhidden.clickdet()
        case 3:
            Global.suprafweights.clickdet()
        case 4:
            Global.prevweights.clickdet()
        #case 5:
            #Global.nextweights.clickdet()

def eveniment():
    Evenimente.main()

def main():
    eveniment()
    
    ecrannn()
    menus()
