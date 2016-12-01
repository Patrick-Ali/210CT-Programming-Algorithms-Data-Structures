def isPrime(num1, num2):
  
    if (num1 <= 1):
       return(False)
    elif num1 == 2:
        return(True)
    elif num2 <= 1:
        return(True)
    elif num1%num2 == 0:
        return (False)
    else:
        return(isPrime(num1, (num2-1)))

def main():
  
    num1 = int(input("Enter number: "))
    
    prime = isPrime(num1, (num1-1))
    
    if prime == True:
        print ("This is a Prime Number")
    elif prime == False:
        print("This is not a Prime Number")
    
    
if __name__ == "__main__":
  main()