#include <iostream>
#include <vector>
#include <string>

int main()
{
    bool working = true;
    while(working)
    {
        std::vector<int> test;
        std::string push;
        std::cout << "Enter Array List (Specify end of list with: End): ";
        std::cin >> push;
        
        try 
        {
            if (push == "End")
            {
                working = false;
            }
            while(push != "End")
            {
                int input = stoi(push);
                test.push_back(input);
                std::cin >> push;
            }
        }
        catch()
        {
           continue; 
        }
    }
    
    for(int i = 0; i < test.size(); i++)
    {
        std::cout << test[i];
    }
    
    
    return 0;
}