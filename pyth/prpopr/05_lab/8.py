strings = input("Введите слова через пробел: ").split()

print("Слова на букву r:")

for string in strings:
    if string.lower().startswith("r"):
        print(string, end=" ")