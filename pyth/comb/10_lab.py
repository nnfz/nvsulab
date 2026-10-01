from itertools import combinations

n = input("Введите число: ")

digits = sorted(n)

result = []
for c in combinations(digits, 4):
    if c[0] != '0':
        result.append(int(''.join(c)))

for x in result:
    print(x)
print("Количество:", len(result))