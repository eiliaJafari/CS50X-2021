from sys import argv, exit
import csv


def find_repeats(sequence, STR):

    length = len(STR)
    # Maximum repeat
    maximum = 0

    for i in range(len(sequence)):
        # Counter to find the maximum repeat
        count = 0
        # If it's a match
        if sequence[i: i + length] == STR:
            count += 1

            # If there's more match
            while sequence[i: i + length] == sequence[i + length: i + (2 * length)]:
                count += 1
                # Changing the value of i so it could iterate through sequence
                i += length

        # Determining the maximum count of sequence
        if count > maximum:
            maximum = count
    # Return the maximum match
    return maximum


def main():
    # To check if the number of inputs are alright
    if len(argv) != 3:
        print("python dna.py data.csv sequence.txt")
        exit(1)

    the_STR = []
    data = []

    # Open and read the file
    with open(argv[1], mode="r") as database:
        # read the csv file
        reader = csv.DictReader(database)
        # To determine the place of STRs
        the_STR = reader.fieldnames[1:]
        # To get the datas
        for row in reader:
            data.append(row)

    # To build a dictionary with STRs and their count
    sequence_count = dict.fromkeys(the_STR, 0)

    # To get the sequences
    with open(argv[2], mode="r") as sequences:
        # To read the line
        sequence = sequences.readline()
        # Itereate through the_STR list
        for STR in the_STR:
            # Update the value of key(str) with the count
            sequence_count[STR] = find_repeats(sequence, STR)

    # To find the person with that DNA
    for datas in data:
        count = 0

        for STR in the_STR:
            if int(datas[STR]) != sequence_count[STR]:
                continue

            count += 1

        if count == len(the_STR):
            print(datas['name'])
            exit(0)

    print("No match")
    exit(1)


if __name__ == "__main__":
    main()