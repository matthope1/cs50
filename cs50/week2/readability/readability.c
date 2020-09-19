#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{

    string text = get_string("Text: ");
    float index;
    float l;
    float s;

    //printf("%s\n",text);

    int letter_count = count_letters(text);

    //printf("%i letter(s)\n", letter_count);

    int word_count = count_words(text);

    //printf("%i word(s)\n", word_count);

    int sentence_count = count_sentences(text);

    //printf("%i sentence(s)\n", sentence_count);


    l = ((float) letter_count / (float) word_count) * 100; // average number of letters per 100 words

    s = ((float) sentence_count / (float) word_count) * 100;

    //printf("%f %f\n", l, s);


    index = 0.0588 * l  - 0.296 * s - 15.8;

    index =  round(index);



    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }





}

int count_letters(string text)
{
    int letter_count = 0;
    //printf("%s\n",text);
    size_t length = strlen(text);

    //printf("Length of text is %i\n", (int) length);

    for (int i = 0; i < length; i ++)
    {
        if (isalpha(text[i]))
        {
            letter_count ++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;

    size_t length = strlen(text);

    for (int i = 0; i < length; i ++)
    {
        if (text[i] == ' ')
        {
            word_count ++;
        }
    }

    word_count ++; // end of loop means we got to last word but there is no space to signify this

    return word_count;

}

int count_sentences(string text)
{

    int sentence_count = 0;

    size_t length = strlen(text);

    for (int i = 0; i < length; i ++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count ++;
        }
    }

    return sentence_count;
}