from pathlib import Path

folder = Path(__file__).parent / "folder"

if folder.is_dir():
    file_count = sum(1 for item in folder.rglob("*") if item.is_file())
    print("Количество файлов:", file_count)
else:
    print("Папка не найдена")