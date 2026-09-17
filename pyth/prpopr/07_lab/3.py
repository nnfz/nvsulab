numbers = list(map(int, input("Введите 10 чисел через пробел: ").split()))

numbers = [number for number in numbers if number % 2 != 0]

new_1 = int(input("Введите первый новый элемент: "))
new_2 = int(input("Введите второй новый элемент: "))

numbers.extend([new_1, new_2])

print("Получившийся список:", numbers)