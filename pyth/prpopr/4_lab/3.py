a = float(input("Введите a: "))
b = float(input("Введите b: "))
c = float(input("Введите c: "))

if c == a:
    print("Деление на ноль невозможно")
else:
    result = (
        1
        - a * b ** c
        - a * (b ** 2 - c ** 2)
        + (b - c + a) * (12 + b) / (c - a)
    )

    print("Результат:", abs(result))