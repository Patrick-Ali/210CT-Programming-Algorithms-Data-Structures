def check(letter, vowel, count, size):
    if(count == size-1):
        print("Hit")
        return (True)
    elif letter == vowel[count] or letter == vowel[count].upper:
        return (None)
    else:
        check(letter, vowel, count+1, size)

word = input("Please enter a word: ")
vowels = "aeiou"
newWord = ""
count = 0
number = 0
size = len(vowels)

for i in word:
    print(i)
    count = 0
    number = 0
    isVowel = check(i, vowels, count, size)
    if isVowel != None:
        newWord = newWord + (i)
    #for j in vowels:
        #number += 1
        #print("working " + str(number))
        #if i == j or i == j.upper():
            #print("Hit")
            #count = -1
        #elif i != j and count != -1 and  number == 5:
            #print(i + " is being added")
            #newWord = newWord + (i)
            
    
    #newWord = newWord + (hold)
            
print("The new word is %s" % newWord)
