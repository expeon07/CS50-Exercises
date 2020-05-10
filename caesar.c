#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void generate_cipher(int key, string message);

int main(int argc, string argv[])
{
    // return error if wrong number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1; 
    }

    // return error if argument is not a number
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1; 
        }
    }

    // convert 2nd argument to int
    int key = atoi(argv[1]); 

    // key should be a positive number
    if (key < 0)
    {
        printf("Usage: ./caesar key \n");
        return 1; 
    }
    
    // take in input from user
    string plaintext = get_string("plaintext: "); 
    // generate the cipher
    generate_cipher(key, plaintext);
    
    return 0;
}


void generate_cipher(int key, string plaintext)
{
    char ciphertext[strlen(plaintext)];
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // encrypt only alphabet
        if (islower(plaintext[i]))
        {
            ciphertext[i] = ((plaintext[i] + key - 'a') % 26) + 'a';
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = ((plaintext[i] + key - 'A') % 26) + 'A';
        }
        else 
        {
            // output space, punctuation as is
            ciphertext[i] = plaintext[i];
        }
    }
    
    printf("ciphertext: %s\n", ciphertext);
}
