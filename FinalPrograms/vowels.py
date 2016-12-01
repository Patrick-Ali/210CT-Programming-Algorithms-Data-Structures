word = input("Please enter a word: ")
vowels = "aeiou"
newWord = ""
count = 0
number = 0

for i in word:
    print(i)
    count = 0
    number = 0
    for j in vowels:
        number += 1
        #print("working " + str(number))
        if i == j or i == j.upper():
            #print("Hit")
            count = -1
        elif i != j and count != -1 and  number == 5:
            #print(i + " is being added")
            newWord = newWord + (i)
            
    
    #newWord = newWord + (hold)
            
print("The new word is %s" % newWord)