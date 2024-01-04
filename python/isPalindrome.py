print("A Palindrome is a word that can be spelled the same backwards as it does forwards!")
word = input("Enter a word and I will tell you if it's a palindrome!\n")

reverseWord = "" 
orderedwordArr = []
for letter in word: 
    orderedwordArr.append(letter)

for letter in word: 
    reverseWord += orderedwordArr.pop()

if reverseWord == word:
    print(word+" is a Palindrome!")
else:
    print(word+" is not a Palindrome")