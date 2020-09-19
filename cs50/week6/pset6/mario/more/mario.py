from cs50 import get_string
from cs50 import get_int




loop = True

while loop == True:

    height = get_int("Height: ")

    #set loop to false to break out of loop
    if height >= 1 and height <= 8:
        loop = False


for i in range(height):


        print(" " * (height - i - 1), end = "")

        print("#" * (i + 1), end="")

        print("  ", end = "")

        print("#" * (i + 1))

