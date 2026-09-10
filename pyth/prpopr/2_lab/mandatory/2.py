x = float(input("Введите x: "))
y = float(input("Введите y: "))
z = float(input("Введите z: "))

maxx = max(x + y + z, x * y * z)
minn = (min(x + y + z / 2, x * y * z) + 1) ** 2

print("Максимум: ", maxx)
print("Минимум: ", minn)