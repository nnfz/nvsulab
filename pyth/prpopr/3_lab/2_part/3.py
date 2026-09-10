n = int(input("Введите число n: "))
m = int(input("Введите количество последних цифр m: "))

n = abs(n)
total = 0

for _ in range(m):
    total += n % 10
    n //= 10

print("Сумма последних цифр:", total)