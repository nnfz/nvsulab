my_number = 25

user_number = int(input("Введите число: "))

while user_number != my_number:
    print("Неверно, попробуйте ещё раз.")
    user_number = int(input("Введите число: "))

print("Вы угадали")