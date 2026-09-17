a = float(input("Введите a: "))
b = float(input("Введите b: "))
c = float(input("Введите c: "))

if a > b > c:
    a *= 3
    b *= 3
    c *= 3
else:
    a = abs(a)
    b = abs(b)
    c = abs(c)

print("a =", a)
print("b =", b)
print("c =", c)