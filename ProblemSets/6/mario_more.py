from cs50 import get_int

# To get the right range
while True:
    num = get_int("Height: ")
    if num >= 1 and num <= 8:
        break

for i in range(1, num + 1):

    # To print the spaces before blocks
    for j in range(1, (num - i) + 1):
        print(" ", end='')

    # To Print the blocks
    for j in range(1, i + 1):
        print("#", end='')

    # To print the space between to opposite side of blocks
    print("  ", end='')

    # To Print the blocks
    for j in range(1, i + 1):
        print("#", end='')

    # To go to next line of blocks
    print("")