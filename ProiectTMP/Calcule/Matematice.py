import math
import Global

def is_float(string):
    try:
        float(string)
        return True
    except ValueError:
        return False

def suma(lista1, lista2):
    suma=0
    i=0
    
    for value in lista1:
        suma=suma+(value.output*lista2[i])
        i+=1
    #print(str(lista1[0].output)+str(lista2[0]))
    print(suma)
    return suma
def produs(lista1, lista2):
    produs=1
    i=0
    for value in lista1:
        produs=produs*(value.output*lista2[i])
        i+=1
    return produs
def minim(lista1, lista2):
    minim=lista1[0].output*lista2[0]
    i=0

    print(str(minim)+"]")
    
    for value in lista1:
        minim=min(minim,value.output*lista2[i])
        i+=1
    return minim

def maxim(lista1, lista2):
    #maxim=0

    #i=0
    #for value in lista1:
    #    if(maxim<((value.output*lista2[i]))):
    #        maxim=(value.output*lista2[i])
    #    i+=1

    maxim=lista1[0].output*lista2[0]
    i=0

    print(str(maxim)+"]")
    
    for value in lista1:
        maxim=max(maxim,value.output*lista2[i])
        i+=1
    return maxim


def semn(x, detaliilayer):
    
    fi=detaliilayer[2]

    if(x>=float(fi)):
        return 1
    elif(x<float(fi)):
        return -1
    return 0

def liniara(x, detaliilayer):
    a=detaliilayer[4]
    return x
    if(x<a):
        return -1
    elif(x>a):
        return 1
    else: return x
    return x
def treapta(x):
    if(x<0):
        return 0
    return 1

def sigmoida(x, detaliilayer):
    fi=detaliilayer[2]
    g=1
    if(detaliilayer[3]!=0):
        g=Global.suprafhidden.textboxes[2].getInt()
    
    e=math.e
    #if(is_float(Global.fi)):
    #    fi=float(Global.fi)
    #if(is_float(Global.g) and float(Global.g)!=0):
    #    g=float(Global.g)
    put=1/(1+(e**(((-g)*(x-fi)))))

    return put

    #if(is_float(Global.a)and is_float(Global.g)):
        #return (1/(1+(math.e**(-(float(Global.g)*(x-float(Global.fi)))))))
    #elif(is_float(Global.g)):
        #return (1/(1+(math.e**(-(float(Global.g)*x)))))
    #elif(is_float(Global.fi) and float(Global.fi)!=0):
        #return (1/(1+(math.e**(-(x-float(Global.fi))))))
    #return (1/(1+(math.e**-x)))


def tanh(x, detaliilayer):
    fi=detaliilayer[2]
    g=1
    if(detaliilayer[3]!=0):
        g=Global.suprafhidden.textboxes[2].getInt()
    e=math.e
    #if(is_float(Global.fi)):
    #    fi=float(Global.fi)
    #if(is_float(Global.g) and float(Global.g)!=0):
    #    g=float(Global.g)
    put=g*(x-fi)
        #return (math.e**((float(Global.g)*(x-float(Global.fi))) -(math.e**(float(Global.g)*(x-float(Global.fi)))))/(math.e**(float(Global.g)*(x-float(Global.fi)))+ math.e**(-(float(Global.g)*(x-float(Global.fi))))))

    return (((e**put)-(e**(-put)))/((e**(put))+(e**(-put))))

    #return ((math.e**x)-(math.e**(-x)))/((math.e**x)+(math.e**(-x)))


def Act(x, layer):
    if(layer>0):
        match(Global.suprafNN.retele[0].detaliilayer[layer][1]):
            case "Sigmoidala":
                print("ab")
                Global.activation=sigmoida(x, Global.suprafNN.retele[0].detaliilayer[layer])
                return(Global.activation)
            case "Tangenta":
                Global.activation=tanh(x, Global.suprafNN.retele[0].detaliilayer[layer])
                return(Global.activation)
            case "Treapta":
                
                Global.activation=treapta(x)
                return(Global.activation)
            case "Liniara":
                Global.activation=liniara(x, Global.suprafNN.retele[0].detaliilayer[layer])
                return(Global.activation)
            case "Semn":
                Global.activation=semn(x, Global.suprafNN.retele[0].detaliilayer[layer])
                return(Global.activation)

        #print(Global.In)
def In(layer, neuron):
    if(layer>0):
    
        match(Global.suprafNN.retele[0].detaliilayer[layer][5]):
            case "Suma":
                Global.inpu=suma(Global.suprafNN.retele[0].valretea[layer-1], neuron.weights)
                return(Global.inpu)
            case "Produs":
                Global.inpu=produs(Global.suprafNN.retele[0].valretea[layer-1], neuron.weights)
                return(Global.inpu)
            case "Minim":
                
                Global.inpu=minim(Global.suprafNN.retele[0].valretea[layer-1], neuron.weights)
                return(Global.inpu)
            case "Maxim":
                Global.inpu=maxim(Global.suprafNN.retele[0].valretea[layer-1], neuron.weights)
                return(Global.inpu)