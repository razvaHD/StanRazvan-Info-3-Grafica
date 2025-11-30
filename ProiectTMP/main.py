
import Global

from Calcule import CalcControl
from Calcule import Initializare
from Afisare import AfControl


    



def main():
    Initializare.main()
    while True:
        Global.clock.tick(60)

        CalcControl.main()
        
        AfControl.main()

        

if __name__ == '__main__':
    main()