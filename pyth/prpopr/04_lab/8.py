numbers = list(map(int, input("Введите элементы через пробел: ").split()))

print("Нечётные элементы:", end=" ")

for number in numbers:
    if number % 2 != 0:
        print(number, end=" ")