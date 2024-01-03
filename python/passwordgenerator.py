import numpy as np 
import random as r 

# initial request to begin game 
run = input("Enter 'stop' to stop generating passwords. Enter anything else to continue\n") 

while run.lower() != 'stop':
    passwordSize = input("Enter the desired length of your password\n")
    password = ""

    numbers = []
    numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    lettersUpper = [0] * 26
    lettersLower = [0] * 26
    specials = ['!', '@', '#', '$', "%", "^", "&", "*", "(", ")"]

    for i in range(26): 
        indexUpper = ord('A') + i 
        lettersUpper[i] = chr(indexUpper) 
        indexLower = ord('a') + i 
        lettersLower[i] = chr(indexLower)

    totalChars = np.concatenate((numbers, lettersLower, lettersUpper, specials))

    for char in range(int(passwordSize)):
        index = r.randint(0, totalChars.size)
        password = password + str(totalChars[index])

    print("\nYour password is: " +password)
    run = input("\nWould you like to make another password? Type 'stop' to exit the program\n")

print("\nHave a nice day!")