import math

x = float(input("Введите x: "))

if x > 0:
    a = math.sin(x)
    b = math.cos(x)
    c = math.log(x)

    print("Минимум = ", min(a, b, c))
else: 
    print("x должен быть > 0")