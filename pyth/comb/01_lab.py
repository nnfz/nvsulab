def can_make_sum(amount):
    if amount < 0:
        return False
    if amount == 0:
        return True
    if amount == 1 or amount == 3:
        return False
    return True


def min_coins(amount, coins=[50, 10, 5, 2]):
    if not can_make_sum(amount):
        return None

    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    parent = [-1] * (amount + 1)

    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i and dp[i - coin] + 1 < dp[i]:
                dp[i] = dp[i - coin] + 1
                parent[i] = coin

    if dp[amount] == float('inf'):
        return None

    result = []
    curr = amount
    while curr > 0:
        coin = parent[curr]
        result.append(coin)
        curr -= coin

    return sorted(result, reverse=True)


def find_all_ways(amount, coins=[50, 10, 5, 2], index=0, current=[]):
    if amount == 0:
        return [current[:]]
    if amount < 0 or index >= len(coins):
        return []

    ways = []
    max_count = amount // coins[index]
    for count in range(max_count + 1):
        current.extend([coins[index]] * count)
        ways.extend(find_all_ways(amount - coins[index] * count, coins, index + 1, current))
        for _ in range(count):
            current.pop()

    return ways


def print_combination(coins_list):
    if not coins_list:
        return "Нет монет"

    from collections import Counter
    counter = Counter(coins_list)
    parts = []
    for coin in sorted(counter.keys(), reverse=True):
        count = counter[coin]
        if count == 1:
            parts.append(f"{coin}р")
        else:
            parts.append(f"{coin}р x {count}")

    return " + ".join(parts)


def solve(amount, max_ways=10):
    print(f"\nСумма: {amount} рублей")

    if not can_make_sum(amount):
        print(f"Невозможно набрать сумму {amount} рублей")
        return

    print(f"Сумму {amount} рублей можно набрать")

    min_combination = min_coins(amount)
    if min_combination:
        print(f"Минимальное количество монет: {len(min_combination)}")
        print(f"Комбинация: {print_combination(min_combination)}")

    all_ways = find_all_ways(amount)
    print(f"Всего способов набора: {len(all_ways)}")

    if len(all_ways) <= max_ways:
        print(f"Все способы:")
        for i, way in enumerate(all_ways, 1):
            print(f"  {i}. {print_combination(way)} = {len(way)} монет")
    else:
        print(f"Первые {max_ways} способов:")
        for i, way in enumerate(all_ways[:max_ways], 1):
            print(f"  {i}. {print_combination(way)} = {len(way)} монет")
        print(f"  ... и еще {len(all_ways) - max_ways} способов")


def main():
    print("Программа размена монет (2р, 5р, 10р, 50р)")

    while True:
        try:
            amount_str = input("\nВведите сумму в рублях (или 'q' для выхода): ").strip()

            if amount_str.lower() in ['q', 'quit', 'exit']:
                break

            amount = int(amount_str)

            if amount < 0:
                print("Сумма не может быть отрицательной")
                continue

            solve(amount)

        except ValueError:
            print("Введите целое число")
        except KeyboardInterrupt:
            print("\n")
            break


if __name__ == "__main__":
    print("\n")
    main()