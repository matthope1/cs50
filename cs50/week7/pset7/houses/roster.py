#houses
# TODO

from sys import argv, exit
import csv
from cs50 import SQL



if len(argv) != 2:
    print("Missing command-line argument")
    exit(1)

house = argv[1]

db = SQL("sqlite:///students.db")

rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last, first", house)

for row in rows:


    #two possible outputs, with middle name and without middle name

    if row["middle"] != None:
        #print with middle name
        print(row["first"], row["middle"], row["last"] + ", born", row["birth"])

    else:
        #same printout but without mid name
        print(row["first"], row["last"] + ", born", row["birth"])