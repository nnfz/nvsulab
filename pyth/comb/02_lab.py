from itertools import permutations

n = int(input("Введите трехзначное число: "))
digits = str(n)

result = set()
for p in permutations(digits):
    if p[0] != '0' and int(p[0]) >= int(digits[0]):
        result.add(int(''.join(p)))

for x in sorted(result):
    print(x)