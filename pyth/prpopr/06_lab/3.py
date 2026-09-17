import re

text = input("Введите строку: ")

words = re.findall(r"[^\W\d_]+", text, flags=re.UNICODE)

result = [word for word in words if 5 <= len(word) <= 10]

print("Новая строка:", " ".join(result))