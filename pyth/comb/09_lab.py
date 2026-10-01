n = int(input("Рубли: "))
m = int(input("Копейки: "))

total = n * 100 + m

names = ["10 коп", "50 коп", "1 руб", "2 руб", "5 руб", "10 руб"]
values = [10, 50, 100, 200, 500, 1000]
limits = [None, None, 4, None, 10, None]

variants = []

def find(i, rest, current):
    if i == len(values):
        if rest == 0:
            variants.append(current[:])
        return
    max_count = rest // values[i]
    if limits[i] is not None:
        max_count = min(max_count, limits[i])
    for k in range(max_count + 1):
        current.append(k)
        find(i + 1, rest - k * values[i], current)
        current.pop()

find(0, total, [])

if not variants:
    print("Оплатить невозможно")
else:
    for v in variants:
        parts = [f"{names[i]}: {v[i]} шт." for i in range(len(v)) if v[i] > 0]
        print(", ".join(parts))
    print("Количество вариантов:", len(variants))
    best = min(variants, key=sum)
    parts = [f"{names[i]}: {best[i]} шт." for i in range(len(best)) if best[i] > 0]
    print("Минимальный набор:", ", ".join(parts), f"(всего монет: {sum(best)})")