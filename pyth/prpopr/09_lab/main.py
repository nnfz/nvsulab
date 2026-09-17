from pathlib import Path


BASE_DIR = Path(__file__).resolve().parent.parent / "8_lab" / "folder"
STUDENTS_FILE = BASE_DIR / "students.txt"
RESULT_FILE = BASE_DIR / "students_new.txt"


def count_files(directory: Path = BASE_DIR) -> int:
    """Посчитать файлы в указанной папке и вывести результат."""
    if not directory.is_dir():
        print(f"Папка не найдена: {directory}")
        return 0

    file_count = sum(item.is_file() for item in directory.rglob("*"))
    print(f"Количество файлов в папке: {file_count}")
    return file_count


def read_students(file_path: Path = STUDENTS_FILE) -> list[list[object]]:
    """Считать students.txt в список списков."""
    students: list[list[object]] = []
    with file_path.open("r", encoding="utf-8") as file:
        for line in file:
            line = line.strip()
            if not line or line.startswith("№;"):
                continue

            number, full_name, age, group = line.split(";", maxsplit=3)
            students.append([int(number), full_name, int(age), group])
    return students


def sort_students_by_group(students: list[list[object]]) -> list[list[object]]:
    """Отсортировать и показать студентов по номеру группы (вариант 3)."""
    students.sort(key=lambda student: str(student[3]))
    print("\nСтуденты, отсортированные по группе:")
    for student in students:
        print(";".join(map(str, student)))
    return students


def increase_group_age(students: list[list[object]]) -> list[list[object]]:
    """Увеличить возраст студентов выбранной группы на один год."""
    group = input("Введите номер группы: ").strip()
    changed = 0
    for student in students:
        if student[3] == group:
            student[2] = int(student[2]) + 1
            changed += 1

    print(f"Возраст изменён у студентов группы {group}: {changed}")
    for student in students:
        print(";".join(map(str, student)))
    return students


def save_students(students: list[list[object]], file_path: Path = RESULT_FILE) -> None:
    """Сохранить текущие данные студентов в новый файл."""
    with file_path.open("w", encoding="utf-8") as file:
        file.write("№;ФИО;Возраст;Группа\n")
        for student in students:
            file.write(";".join(map(str, student)) + "\n")
    print(f"Новые данные сохранены в файл: {file_path}")


def print_menu() -> None:
    print(
        "\nМеню:\n"
        "0 - Выход из программы\n"
        "1 - Подсчитать количество файлов\n"
        "2 - Отсортировать студентов по группе\n"
        "3 - Увеличить возраст студентов группы\n"
        "4 - Сохранить данные студентов в файл\n"
    )


def want_to_continue() -> bool:
    """Запросить продолжение работы после выполнения функции."""
    answer = input("Вы хотите продолжить? ").strip().lower()
    return answer in {"да", "yes", "y", "1"}


def main() -> None:
    students: list[list[object]] = read_students()

    while True:
        print_menu()
        choice = input("Выберите пункт меню: ").strip()

        if choice == "0":
            print("Программа завершена.")
            return
        if choice == "1":
            count_files()
        elif choice == "2":
            students = sort_students_by_group(students)
        elif choice == "3":
            students = increase_group_age(students)
        elif choice == "4":
            save_students(students)
        else:
            print("Ошибка: выберите пункт от 0 до 4.")
            continue

        if not want_to_continue():
            print("Программа завершена.")
            return


if __name__ == "__main__":
    main()
