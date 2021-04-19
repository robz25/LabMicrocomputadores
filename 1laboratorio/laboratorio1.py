#!/usr/bin/python3

#Laboratorio 1 - Robin Gonzalez, probado en Python 3.8.5
#Se lee un numero desde terminal y se encuentran todos los numeros primos
#iguales o menores. Se usa el agoritmo de la criba de aristotenes

N = int(input("Digite el numero N:\t")) #leer string y hacer casting a int
primos = [2]    #generar lista global, con el entero 2

for x in range(3,N+1): #itere entre 3 y N, aumentando x en 1
    for i in primos:    #para cada elemento de la lista:
        if x%i == 0:    #si el modulo es 0
            temp = 0    #borre temp
            break   #termine iteracion, no es posible que sea primo
        else:   #si el modulo es diferente de 0
            temp = x    #ponga el valor actual de x en temp
    if temp != 0:   #si encontro un valor primo
        primos.append(temp) #agreguelo a la lista

print(primos) #imprima la lista de numeros primos
