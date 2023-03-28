from cs50 import get_string

# First, some functions


def formula(L, S):

    grade = (0.0588 * L) + (-0.296 * S) - 15.8
    grade = round(grade)
    result = int(grade)
    return result


def char_count(text):

    length = len(text)
    count = 0

    for i in range(0, length):
        ch = text[i].lower()

        if ch >= 'a' and ch <= 'z':
            count += 1

    return float(count)


def word_count(text):

    space_count = 0
    length = len(text)

    for i in range(0, length):
        if text[i] == ' ':
            space_count += 1

    if space_count == 0:
        return float(space_count)

    else:
        space_count += 1
        return float(space_count)


def sentence_count(text):

    length = len(text)
    count = 0

    for i in range(0, length):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1

    return float(count)


# To get the text from user
text = get_string("Text: ")

# Counting characters, words and sentences
char_counted = char_count(text)
word_counted = word_count(text)
sentence_counted = sentence_count(text)

# Calculating L and S
L = (char_counted * 100) / word_counted
S = (sentence_counted * 100) / word_counted

# Calculating the grade
grade = formula(L, S)

# Printing the grade
if grade >= 1 and grade < 16:
    print(f"Grade {grade}")

# If it's more than 16
elif grade >= 16:
    print("Grade 16+")

# If it's less than 1
elif grade < 1:
    print("Before Grade 1")