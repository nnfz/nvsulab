from itertools import permutations

n = input("Введите четырехзначное число: ")

result = set()
for p in permutations(n):
    if p[0] != '0':
        a, b, c, d = map(int, p)
        if a + b == c + d:
            result.add(int(''.join(p)))

for x in sorted(result):
    print(x)