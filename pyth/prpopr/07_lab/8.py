my_len = [
    ["БО-331101", ["Акулова Алена", "Бабушкина Ксения", "Иванов Иван"]],
    ["БОВ-421102", ["Петров Петр", "Сидорова Анна"]],
    ["БО-331103", ["Смирнов Алексей", "Кузнецова Мария"]]
]

width = max(len(group_name) for group_name in my_len)

for group_name, students in my_len:
    for student in students:
        width = max(width, len(student))

for group_name, students in my_len:
    print(group_name.center(width))

    for student in students:
        print(student.center(width))

    print()