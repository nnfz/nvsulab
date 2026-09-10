import math

a = float(input("Введите сторону a: "))
b = float(input("Введите сторону b: "))
x = float(input("Введите угол x: "))

xrad = math.radians(x)

# теорема косинусов
c = math.sqrt(a**2 + b**2 - 2 * a * b * math.cos(xrad))

print("Третья сторона c=", c)