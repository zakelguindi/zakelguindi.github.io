import random as r
import numpy as np 

# selecting the number to be guessed 
computer_number = r.randint(1, 1000)

# generating user input
print("I am thinking of a number between 1 and 1000. Enter a number and I will tell you if it's lesser than or greater than my number. Guess my number in the fewest attempts possible!")
user_number = int(input("Enter your first guess!\n"))

# keeping track of the user's guesses
guesses = 1

# repeats until user guesses correct number
while(user_number != computer_number):
    if user_number > computer_number:
        print("You guessed too high! Pick a lower number. ")
        guesses += 1
    else:
        print("You guessed too low! Pick a higher number. ")
        guesses += 1
    user_number = int(input("Enter your next guess!\n"))

print("Congratulations! You've completed the Number Guessing game in " +str(guesses)+ " guesses!")