from pathlib import Path

folder = Path(__file__).parent / "folder"
file_path = folder / "students.txt"
new_file_path = folder / "students_new.txt"

students = []

with open(file_path, "r", encoding="utf-8") as file:
    for line in file:
        line = line.strip()

        if not line or line.startswith("№;"):
            continue

        number, full_name, age, group = line.split(";")

        students.append([
            int(number),
            full_name,
            int(age),
            group
        ])

students.sort(key=lambda student: student[3])

print(students)

selected_group = input("\nВведите номер группы: ")

for student in students:
    if student[3] == selected_group:
        student[2] += 1

print("\nИзменённый список:")
print(students)

with open(new_file_path, "w", encoding="utf-8") as file:
    file.write("№;ФИО;Возраст;Группа\n")

    for number, full_name, age, group in students:
        file.write(f"{number};{full_name};{age};{group}\n")

print(f"\nНовые данные сохранены в файл: {new_file_path}")