def isPrime(num1, num2):
    if (num1 <= 1):
       #print("Hello 1")
       return(False)
    elif num1 == 2:
        #print("Hello 2")
        return(True)
    elif num1%num2 == 0:
        #print("Hello 3")
        return (False)
    elif num2 <= 1:
        #print("Hello 4")
        return(True)
    else:
        return(isPrime(num1, (num2-1)))

def main():
    num1 = int(input("Enter number: "))
    
    prime = isPrime(num1, (num1-1))
    #print(prime)
    
    #print(isPrime(num1, num1-1))
    
    if prime == True:
        print ("This is a Prime Number")
    elif prime == False:
        print("This is not a Prime Number")
    
    
main()