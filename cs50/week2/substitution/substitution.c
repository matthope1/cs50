#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_key_valid();
string create_cipher();
string key_to_upper();

int main(int argc, string argv[])
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //printf("%s\n",key);
    // checks if 1 argument was given
    if (argc != 2)
    {
        printf("Error: arg needs to be 1 string\n");
        return 1;
    }

    string key = argv[1];

    size_t len = strlen(key);

    if (len != 26)
    {
        printf("Error: Key must be 26 characters\n");
        return 1;
    }

    key = key_to_upper(key);


    int key_valid = is_key_valid(alphabet, key);


    if (key_valid == 0)
    {
        printf("key is NOT valid\n");
        return 1;
    }


    string plain_text = get_string("plaintext: ");

    string cipher_text = create_cipher(plain_text, alphabet, key);

    printf("ciphertext: %s\n", cipher_text);

    /*
    for (int i = 0; i < 26; i ++)
    {
        printf("%c\n",key[i]);
    }
    */


    return 0;
}

string key_to_upper(string key)
{
    for (int i = 0; i < 26; i ++)
    {
        key[i] = toupper(key[i]);
    }

    return key;
}


int is_key_valid(string alphabet, string key)
{
    // THIS FUNCTION MAKES SURE THERES 1 OF EVERY LETTER IN THE ALPHABET
    // you need a neseted for loop to find out if the key is valid
    // key needs to have 26 characters
    // key needs to have every letter of alphabet with no repeats
    // RETURN: 1 if valid, 0 if not valid

    int key_valid = 1; // starts off as true

    // outer loop will feed inner loop every letter of the alphabet to make sure
    // that key has 1 of each letter
    for (int i = 0; i < 26; i ++)
    {
        int current_letter_found = 0;

        //printf("%c\n",alphabet[i]);

        // inner for loop will search key for current letter in alphabet
        // if found loop will exit
        // if not found we should get invalid key
        for (int j = 0; j < 26; j++)
        {
            //printf("%c = %c? \n",alphabet[i],key[j]);

            if (alphabet[i] == key[j])
            {

                current_letter_found = 1;
                j = 26; // stop searching
                break;
            }
        }
        if (current_letter_found == 0)
        {
            //printf("Invalid key\n");
            key_valid = 0; // key was found to be invalid;
            break;
        }
    }

    return key_valid;
}


string create_cipher(string plain_text, string alphabet, string key)
{
    /*
    TODO: function needs to be able to handle upper and lower case
    breakpoint on line 130
    */

    string cipher = plain_text;

    int letter_index;

    //printf("%s\n",plain_text);

    size_t plain_text_len = strlen(plain_text);

    for (int i = 0; i < plain_text_len; i++)
    {
        letter_index = 0;

        for (int j = 0; j < 26; j++)
        {

            //printf("plain_text[i] = %c alphabet[j] = %c key[j] = %c\n", toupper(plain_text[i]), alphabet[j], key[j]);

            if (isalpha(plain_text[i]) == 0) // if the current letter in plain_text is not part of the alphabet then
            {
                cipher[i] = plain_text[i];
                break; // we stop the inner loop to go onto the next letter in plain_text
            }
            else if (toupper(plain_text[i]) == alphabet[j])
            {
                // we need to check if current letter in plain text
                // is alpha, we also need to be able to handle spaces and puncuation

                // how do we handle the case of the plain text?
                // if the letter in plain text is upper case
                // then we assign the cipher text character as upper case
                if (isupper(plain_text[i]) > 0) // this means its upper
                {
                    cipher[i] = key[j];
                }
                else // else the cipher text character is lower so we
                    // assign the cipher character as lower case
                {
                    cipher[i] = tolower(key[j]);
                }

                letter_index = j;

                break;// this is where we stop this inner loop
            }

        }
    }


    //printf("\n\n cipher: %s", cipher);


    return cipher;

}