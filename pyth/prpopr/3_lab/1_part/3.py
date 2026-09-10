m = int(input("Введите m: "))
n = int(input("Введите n: "))

total = 0

for num in range(m, n + 1):
    if num % 2 != 0:
        total += num ** 2

print("Сумма квадратов нечётных чисел:", total)