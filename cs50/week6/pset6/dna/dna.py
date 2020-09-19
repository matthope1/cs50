from sys import argv, exit
import csv


def get_max_substring_repeats(string, substring):
    #calculate the max num of times a substring is repeated
    #how many times toes substring occur in string consec


    m = [0] * len(string)
    for x in range(len(string) - len(substring), -1, -1):
        if string[x: x + len(substring)] == substring:
            if x + len(substring) > len(string) - 1:
                m[x] = 1
            else:
                m[x] = 1 + m[x + len(substring)]

    return max(m)


def print_answer(reader,arr):
    for x in reader:
        person = x[0]
        values = [int(val) for val in x[1:]]
        if values ==  arr:
            print(person)
            return
    print("No match")


def main():

    if len(argv) != 3:
        print("Missing command-line argument")
        exit(1)

    csv_p = argv[1]
    with open(csv_p) as csv_file:
        reader = csv.reader(csv_file)

        # for row in reader:
        #     print(row)

        sequences = next(reader)[1:]


        txt_p = argv[2]
        with open(txt_p) as txt_file:
            sequence = txt_file.read()
            arr = [get_max_substring_repeats(sequence,seq) for seq in sequences]
            # print(seq)

            print_answer(reader,arr)



if __name__ == "__main__":
    main()