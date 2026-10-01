from itertools import permutations

n = input("Введите четырехзначное число: ")

result = set()
for p in permutations(n):
    if p[0] != '0' and all(p[i] != p[i + 1] for i in range(3)):
        result.add(int(''.join(p)))

for x in sorted(result):
    print(x)