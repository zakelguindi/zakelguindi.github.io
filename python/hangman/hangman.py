import random as r
import numpy as np

# this method is unnecessary but I wanted to attempt declaring a method in python as I haven't practiced this yet
def printArr(arr):
    print(arr)

# gathering user input
play_req = input("Do you want to play Hangman? Press 'no' to quit and anything else to continue\n")


while play_req != "no":
    # opening .txt file in python. the second parameter 'r' means "read"
    with open('./hangman/hangmanwords.txt', 'r') as file:
        lines = file.readlines()
    file.close()

    # selecting random word from word list
    wordIndex = r.randint(1, 50)

    # converting this word to an array that I can parse through 
    selection = lines[wordIndex]
    selectionArr = []
    size = 0
    for character in selection[:-1]: 
        selectionArr.append(character)
        size += 1

    # initializing empty return array 
    userResponse = [' '] * size

    # the actual game part- runs until user wins or loses
    misses = 0
    while userResponse != selectionArr and misses < 6:
        guess = input("Enter a letter you think appears in this " +str(size)+" letter word\n")
        success = False
        i = 0
        for char in selectionArr:
            if guess == char:
                success = True
                userResponse[i] = guess
            i += 1
        if success:
            print("You have guessed correctly!")
        else:
            print("You have guessed incorrectly")
            misses += 1
        
        print("Here's what you have thus far")
        printArr(userResponse)
        print("You have "+str(6-misses)+" misses left before you lose!")

    if(misses >= 6):
        print("You lose!")
    else:
        print("You win! Congratulations")

    play_req = input("Would you like to play again? Press 'no' to stop; press anything else to continue\n")

print("Have a nice day!")