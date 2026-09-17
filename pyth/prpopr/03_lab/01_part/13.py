A = int(input("Введите A: "))
B = int(input("Введите B: "))

total = 0

for num in range(A, B + 1):
    total += num

print("Сумма чисел:", total)