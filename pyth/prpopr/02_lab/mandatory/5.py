a = float(input("Введите a: "))
b = float(input("Введите b: "))
c = float(input("Введите c: "))

if a > b > c:
    a *= 2
    b *= 2
    c *= 2
else:
    a = -a
    b = -b
    c = -c

print("a =", a)
print("b =", b)
print("c =", c)