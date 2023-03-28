from cs50 import get_float

# The coins
quarter = 25
dime = 10
nickel = 5
penny = 1

# Counter for change owed
counter = 0

# To get the number from user
while True:
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break

# Converting to cents
cents = int(round(dollars * 100))

# Calculating the result
while cents != 0:

    if cents >= quarter:
        cents -= quarter
        counter += 1
        continue

    elif cents >= dime:
        cents -= dime
        counter += 1
        continue

    elif cents >= nickel:
        cents -= nickel
        counter += 1
        continue

    elif cents >= penny:
        cents -= penny
        counter += 1
        continue

# Printing the result
print(counter)