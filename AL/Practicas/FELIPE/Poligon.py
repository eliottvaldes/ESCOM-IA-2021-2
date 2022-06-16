import matplotlib.ticker as ticker
from os import remove
import math
from string import ascii_uppercase
import pandas as pd
import numpy as np
import itertools
import sys
from matplotlib import pyplot as plt
# ============================================
# ========== F U N C T I O N S ===============
# ============================================

def labels_gen():
    size = 1
    while True:
        for s in itertools.product(ascii_uppercase, repeat=size):
            yield "".join(s)
        size +=1



def Graphicate(contador, ruta):
    
    data=pd.read_csv(ruta ,header=0,delim_whitespace=True)

    centroide = np.mean(data, axis=0)

    # Cáculo del ángulo polar
    aux = data - centroide
    polar_angles = np.arctan2(aux.y, aux.x)

    # Obtenemos un nuevo DataFrame con los vértices ordenados
    data = data.reindex(polar_angles.argsort())


    ax = plt.subplot(111)

    # Creamos el polígono
    plygon = plt.Polygon(data, fill=True, facecolor="#ffb3b3", edgecolor='#ff0000', alpha=1, zorder=1)
    ax.add_patch(plygon)

    # Creamos los vértices
    ax.scatter(data.x, data.y, c='b', zorder=2)

    # Etiquetas para cada vértice y arista
    etiquetas = labels_gen()
    for i, vertice in enumerate(data.values):
        lb = next(etiquetas)
        ax.annotate(str(lb), xy=vertice + 0.1)
        punto_medio = (vertice +  data.values[(i + 1) % (data.shape[0])]) / 2
        ax.annotate(str(lb.lower()), xy=punto_medio)

    # Mostramos los ejes centrados en el origen
    ax.spines['left'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_position('zero')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')

    # Configuramos la rejilla
    ax.grid(color='gray', linestyle='dashed', linewidth=1, alpha=0.4)

    # Escalamos la gráfica
    ax.autoscale_view()
    ax.xaxis.set_major_locator(ticker.MultipleLocator(1))

    
    #Guardamos la gráfica
    nombreGrafica="grafica"+str(contador)+".png"
    plt.savefig(nombreGrafica)
    
    # Mostramos la gráfica
    plt.show()
    #return nombreGrafica


def Update(Matrix, path, n): #Funcion para actualizar las coordenadas despues de cada Transformation
    file = open(path, "w")
    file.write("x y\n")
    file.close()
    for i in range(0, n):
        x = Matrix[i][0]
        y = Matrix[i][1]
        cadena=str(x)+" "+str(y)
        with open(path, 'a') as f:
            f.write(cadena+"\r")
            f.close()


def Rotate(Matrix, c, axis, path):
            # Matriz Transformada
    Transformation = [[0] * 2 for i in range(2)]
    Transformation[0][0] = math.cos(math.radians(c))
    Transformation[0][1] = math.sin(math.radians(c))
    Transformation[1][0] = math.sin(math.radians(c))*(-1)
    Transformation[1][1] = math.cos(math.radians(c))
    # print(Transformation)
    Matrix=MultiplicateMatrix(Matrix, Transformation)
    print(Matrix)
    Update(Matrix, path, n)
    return Matrix


def MultiplicateMatrix(Matrix, Matrix2): #Funcion para multiplicar las matrices que contiene a las coordenadas
    matrixMultiplicate = [[0] * 2 for i in range(len(Matrix))]
    for i in range(len(matrixMultiplicate)):
        for j in range(len(matrixMultiplicate[i])):
            for k in range(len(Matrix2)):
                matrixMultiplicate [i][j] = matrixMultiplicate [i][j] + Matrix[i][k]*Matrix2[k][j]
    # print(matrixMultiplicate)
    return matrixMultiplicate

def Cut(Matrix, c, axis, path):
    if(axis=="X" or axis=="x"):
        # Matriz Transformada
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = 1
        Transformation[0][1] = 0
        Transformation[1][0] = c
        Transformation[1][1] = 1
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
        print(Matrix)
    elif(axis=="Y" or axis=="y"):
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = 1
        Transformation[0][1] = c
        Transformation[1][0] = 0
        Transformation[1][1] = 1
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
    Update(Matrix, path, n)
    return Matrix



def Reflection(Matrix, axis, path):
    if(axis=="Y" or axis=="y"):
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = -1
        Transformation[0][1] = 0
        Transformation[1][0] = 0
        Transformation[1][1] = 1
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
        print(Matrix)
    elif(axis=="X" or axis=="x"):
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = 1
        Transformation[0][1] = 0
        Transformation[1][0] = 0
        Transformation[1][1] = -1
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
    Update(Matrix, path, n)
    return Matrix

def Expand(Matrix, c, axis, path):
    if(axis=="X" or axis=="x"):
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = c
        Transformation[0][1] = 0
        Transformation[1][0] = 0
        Transformation[1][1] = 1
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
        print(Matrix)
    elif(axis=="Y" or axis=="y"):
        Transformation = [[0] * 2 for i in range(2)]
        Transformation[0][0] = 1
        Transformation[0][1] = 0
        Transformation[1][0] = 0
        Transformation[1][1] = c
        # print(Transformation)
        Matrix=MultiplicateMatrix(Matrix, Transformation)
    Update(Matrix, path, n)
    return Matrix


# ================================================
# ============== M A I N =========================
# ================================================

path = "Poligon.txt"
remove(path)
file = open(path, "w")
file.write("x y\n")
file.close()
n=0
print("================================================")
print("==== P O L I G O N - I N A T O R ===============")
print("================================================")
print("How many points do u need?")
n=int(input())
Matrix = [[0] * 2 for i in range(n)]
for i in range(0, n):
    print("Insert the value of x for the point: "+str(i+1))
    x=float(input())
    Matrix[i][0]=x
    print("Insert the value of Y for the point: "+str(i+1))
    y=float(input())
    Matrix[i][1]=y
    cadena=str(x)+" "+str(y)
    with open(path, 'a') as f:
        f.write(cadena+"\r")
        f.close()
# print(Matrix)


userOption = 0
cont = 0
# lisT
Graphs=[]
#Make the graph
Graphs.append(Graphicate(cont, path))
cont=int(cont)+1


while(userOption!=6):
    #REMAKING MY VARIABLES
    axis = ""
    c = 0
    # MENU
    print("Insert the T.L that u want?")
    print("1. Reflect")
    print("2. Expand")
    print("3. Cut")
    print("4. Rotate")
    print("5. Graphicate")
    print("6. Close the program")
    userOption=int(input())

    if(userOption==1):
        while(True):
            if(axis=="Y" or axis=="X" or axis=="y" or axis=="x"):
                break
            else:
                print("Insert the axis: ")
                axis=input()
        Matrix = Reflection(Matrix, axis, path)
        Graphs.append(Graphicate(cont, path))
        cont = int(cont)+1
    elif(userOption==2):
        while(True):
            if(axis=="Y" or axis=="X" or axis=="y" or axis=="x"):
                break
            else:
                print("Insert the axis: ")
                axis = input()
        print("Insert the value of a constant for expanding:")
        c = float(input())
        aux = c
        # print("The constatn is: "+str(aux))
        Matrix = Expand(Matrix, c, axis, path)
        Graphs.append(Graphicate(cont, path))
        cont = int(cont)+1
    elif(userOption==3):
        while(True):
            if(axis=="Y" or axis=="X" or axis=="y" or axis=="x"):
                break
            else:
                print("Insert the axis:  ")
                axis = input()
        print("Insert the value of a constant for cutting:")
        c = float(input())
        Matrix = Cut(Matrix, c, axis, path)
        Graphs.append(Graphicate(cont, path))
        cont = int(cont)+1
    elif(userOption==4):
        print("Inser the value of thetha")
        c = float(input())
        Matrix = Rotate(Matrix, c, axis, path)
        Graphs.append(Graphicate(cont, path))
        cont=int(cont)+1
    elif(userOption==5):
        Graphs.append(Graphicate(cont, path))
        cont = int(cont)+1
    elif(userOption==6):
        print("Have a Nice Day bro :)")
    else:
        print("Pls insert a correct option")

