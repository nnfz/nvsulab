from itertools import permutations

n = input("Введите четырехзначное число: ")
k = int(input("Введите число: "))

result = set()
for p in permutations(n):
    if p[0] != '0' and sum(map(int, p)) >= k:
        result.add(int(''.join(p)))

for x in sorted(result):
    print(x)