while True:
    try:
        height = int(input("Height: "))
        if height >= 1 and height <= 8:
            break
    except ValueError:
        continue


def printHash():
    print("#", end="")


def printHashInRange(n):
    for j in range(n):
        printHash()


for i in range(height):
    for j in range(height - i - 1):
        print(" ", end="")
    printHashInRange(i + 1)
    print("  ", end="")
    printHashInRange(i + 1)
    print()
