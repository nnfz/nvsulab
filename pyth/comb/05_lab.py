from itertools import permutations

n = input("Введите четырехзначное число: ")
d = input("Введите цифру: ")

result = set()
for p in permutations(n):
    if p[0] != '0' and p.count(d) == 1:
        result.add(int(''.join(p)))

for x in sorted(result):
    print(x)