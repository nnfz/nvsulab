my_string = (
    "Ф;И;О;Возраст;Категория;"
    "Иванов;Иван;Иванович;23 года;Студент 3 курса;"
    "Петров;Семен;Игоревич;22 года;Студент 2 курса"
)

parts = my_string.split(";")

headers = parts[:5]
data = parts[5:]

print(f"{'ФИО':<25} | О студенте")
print("-" * 55)

for i in range(0, len(data), 5):
    surname = data[i]
    name = data[i + 1]
    patronymic = data[i + 2]
    age = data[i + 3]
    category = data[i + 4]

    fio = f"{surname} {name} {patronymic}"
    info = f"{category}, {age}"

    print(f"{fio:<25} | {info}")