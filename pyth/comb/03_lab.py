n = int(input("Рубли: "))
m = int(input("Копейки: "))

total = n * 100 + m
coins = [1000, 500, 200, 100, 50, 10, 5, 1]

for c in coins:
    count = total // c
    total %= c
    if count > 0:
        if c >= 100:
            print(f"{c // 100} руб: {count} шт.")
        else:
            print(f"{c} коп: {count} шт.")