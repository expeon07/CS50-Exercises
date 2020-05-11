def main():
    # get text to analyze
    text = input("Text: ")
    
    # letter count
    count_letters = 0
    # word count, start at 1 to account for first word
    count_words = 1
    # sentence count
    count_sentences = 0
    
    # go through each letter
    for letter in text:
        # count only alphabet characters
        if letter.isalpha():
            count_letters += 1
        
        # check for spaces
        if (letter == " "):
            count_words += 1

        # check for punctuation
        if letter == '.' or letter == '!' or letter == '?':
            count_sentences += 1
    
    L = (count_letters / count_words) * 100
    S = (count_sentences / count_words) * 100  
    
    index = int(round(0.0588 * L - 0.296 * S - 15.8))
    
    # output grade 
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1") 
    else:
        print("Grade " + str(index))
   
    
# execute main function
main()
