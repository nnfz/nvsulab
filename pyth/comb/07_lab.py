from itertools import permutations

word = input("Введите слово: ")

result = sorted(set(''.join(p) for p in permutations(word)))

for w in result:
    print(w)
print("Количество:", len(result))