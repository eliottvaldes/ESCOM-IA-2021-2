#Sumador binario

print("Introduce el primer numero binario")
num1=input()
print("Introduce el segundo numero binario")
num2=input()
sum=bin(int(num1,2)+int(num2,2))
print("El resultado de sumar los 2 numeros es: ")
print(sum[2:])