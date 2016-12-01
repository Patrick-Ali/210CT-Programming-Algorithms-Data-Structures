def check(letter, vowel, count, size):
    #apple = "This letter is not a vowel"
    #print(letter)
    if(count >= size):
      #print("Count is %d" % count)
      #print("Hit")
      return (True)
    #print("Vowel is: %s" % vowel[count].upper())
    if letter == vowel[count] or letter == vowel[count].upper():
      #print("Working")
      return (False)
    else:
        return check(letter, vowel, count+1, size)
def main():
  word = input("Please enter a word: ")
  vowels = "aeiou"
  newWord = ""
  count = 0
  size = len(vowels)

  for i in word:
      #print(i)
      count = 0
      isVowel = check(i, vowels, count, size)
      #print("This letter is %s a vowel" % isVowel)
      if isVowel != False:
          newWord = newWord + (i)

  print("The original word was: %s" % word)
  print("The word without vowels is: %s" % newWord)
  
if __name__ == "__main__":
  main()

