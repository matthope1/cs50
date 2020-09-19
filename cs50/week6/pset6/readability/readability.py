from cs50 import get_string
from cs50 import get_int



def count_letters(text):

    letter_count = 0

    for char in text:
        if char.isalpha():
            letter_count = letter_count + 1

    return letter_count


def count_words(text):

    word_count = 0

    for char in text:
        if char == " ":
            word_count = word_count + 1

    word_count = word_count + 1

    return word_count

def count_sentences(text):

    sentence_count = 0

    for char in text:
        if char == "." or char == "!" or char == "?":
            sentence_count = sentence_count + 1

    return sentence_count




text = get_string("Enter text: ")

#index = 0.0588 * L - 0.296 * S - 15.8
#L is the average number of letters per 100 words in the text
#S is the average number of sentences per 100 words in the text.

l_count = count_letters(text)
w_count = count_words(text)
s_count = count_sentences(text)


# print(str(l_count) + " letters")
# print(str(w_count) + " words")
# print(str(s_count) + " sentences")

L = (l_count / w_count) * 100
S = (s_count / w_count) * 100

index =  round(0.0588 * L - 0.296 * S - 15.8)

# print(round(index))

if index < 1:
    print("Before Grade 1")

elif index >= 1 and index < 16:
    print("Grade", str(index))

else:
    print("Grade 16+")


