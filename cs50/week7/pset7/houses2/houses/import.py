# TODO


# TODO
from cs50 import get_string
from cs50 import get_int
from sys import argv, exit
import csv
from cs50 import SQL

#check command line args

if len(argv) != 2:
    print("Missing command-line argument")
    exit(1)

csv_file = argv[1]


db = SQL("sqlite:///students.db")
#db.execute("CREATE TABLE students(firstName TEXT, middleName TEXT, lastName TEXT, house TEXT, birthYear NUMERIC)")


database = []

#open csv file given by command-line argument
with open(csv_file) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:


        database.append(row)


#for each row parse name
for i in range(1,len(database)):

    name = database[i][0].split(" ")
    house = database[i][1]
    year = database[i][2]

    print("name",name)
    print("House",house)
    print("year",year)
    #(names will have first/last & possibly middle name) # use none in place of middle name
    #insert each student into the students table of students.db
    if len(name) == 2:
        first_name = name[0]
        last_name = name[1]
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, None , last_name, house, year)
    else:
        first_name = name[0]
        mid_name = name[1]
        last_name = name[2]
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, mid_name, last_name, house, year)




"""
CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    first VARCHAR(255),
    middle VARCHAR(255),
    last VARCHAR(255),
    house VARCHAR(10),
    birth INTEGER
);
"""