#include <iostream> 

bool isPrime(int num1, int num2)
{
  
    if (num1 <= 1)
    {
       return false;
    }
    else if (num1 == 2)
    {
        return true;
    }
    else if (num2 <= 1)
    {
        return true;
    }
    else if (num1%num2 == 0)
    {
        return false;
    }
    else
    {
        return isPrime(num1, (num2-1));
    }
}    

int main()
{
  
    int num1;
    std::cout << "Enter number: ";
    std::cin >> num1;
    
    bool prime = isPrime(num1, (num1-1));
    
    prime == true ?  std::cout << "This is a Prime Number" << std::endl :
        std::cout << "This is not a Prime Number" << std::endl;

    return 0;
}