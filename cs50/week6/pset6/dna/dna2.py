from cs50 import get_string
from cs50 import get_int
from sys import argv, exit
import csv


if len(argv) != 3:
    print("Missing command-line argument")
    exit(1)

csv_file = argv[1]
txt_file = argv[2]



file1 = open(txt_file,"r")
dna = file1.read()


#AGATC, AATG, TATC
database = []


with open(csv_file) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:


        database.append(row)

# print(dna)


str_count = {}



for x in range(1, len(database[0])):

    current_str = database[0][x]
    str_len = len(database[0][x])
    # print("current str",current_str)


    longest_consec = 0
    current_consec = 0

    y = 0

    while y < len(dna) - str_len:
    # for y in range(len(dna) - str_len):
        # print(dna[x:x + str_len], end= " ")
        # print(x, x + str_len)

        if dna[y:y + str_len] == current_str:
            # print(dna[y:y + str_len], " = ", current_str)
            current_consec = current_consec + 1
            y = y + str_len

        else:
            # print(dna[y:y + str_len], " != ", current_str)
            y = y + 1
            if current_consec > longest_consec:
                longest_consec = current_consec
                current_consec = 0


    # print("longest consecutive " + current_str +  " " + str(longest_consec))

    str_count[current_str] = longest_consec



# print()
# print()
# for x in str_count:
#     print(x, str_count[x])

# print()
# print()
# print("keys")
keys = list(str_count.values())
# print(keys)
# print()
# print()




for x in range(1, len(database)):

    current_person = database[x]
    match = True

    for y in range(1, len(current_person)):
        # print("dna",database[x][y])
        # print("key",keys[y - 1])
        # print()

        if int(current_person[y]) != keys[y - 1]:
            match = False
            break


    if match == True:
        print(current_person[0]) #print current person 0
        break
    elif match == False and x == len(database) - 1:
        print("No match")


    # print()
    # print()
    # print(database[x])
    
    