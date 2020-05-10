#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // get text from user
    string text = get_string("Text: ");
    
    // letter count
    float count_letters = 0;
    // word count, start at 1 to account for first word
    float count_words = 1;
    // sentence count
    float count_sentences = 0;
    
    // go through each letter
    for (int i = 0; i < strlen(text); i++)
    {
        // count only alphabet characters
        if (isalpha(text[i]))
        {
            count_letters++;
        }
        
        // check for spaces
        if (isspace(text[i]))
        {
            count_words++;
        }
        
        // check for punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
        }

    }
    
    //printf("%f letter(s)\n", count_letters);
    //printf("%f words(s)\n", count_words);
    //printf("%f sentences(s)\n", count_sentences);
    
    float L = (count_letters / count_words) * 100;
    float S = (count_sentences / count_words) * 100;  
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index > 16)
    {
        printf("Grade 16+\n"); 
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n"); 
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
