def check(letter, vowel, count, size):
    if(count >= size):
      return (True)
    if letter == vowel[count] or letter == vowel[count].upper():
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
      count = 0
      isVowel = check(i, vowels, count, size)
      if isVowel != False:
          newWord = newWord + (i)

  print("The original word was: %s" % word)
  print("The word without vowels is: %s" % newWord)
  
if __name__ == "__main__":
  main()

