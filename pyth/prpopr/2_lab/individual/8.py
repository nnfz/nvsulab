a = float(input("Введите ребро a: "))
b = float(input("Введите ребро b: "))
c = float(input("Введите ребро c: "))

x = float(input("Введите сторону отверстия x: "))
y = float(input("Введите сторону отверстия y: "))

can_pass = (
    (a <= x and b <= y) or
    (a <= y and b <= x) or
    (a <= x and c <= y) or
    (a <= y and c <= x) or
    (b <= x and c <= y) or
    (b <= y and c <= x)
)

if can_pass:
    print("Кирпич пройдёт в отверстие")
else:
    print("Кирпич не пройдёт в отверстие")