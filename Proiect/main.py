from Global import Variables as Variables
from Calc import BackEnd as BackEnd
from UI import FrontEnd as FrontEnd




def main():
    while Variables.running:
        Variables.clock.tick(60)
        BackEnd.Controller()
        FrontEnd.Controller()