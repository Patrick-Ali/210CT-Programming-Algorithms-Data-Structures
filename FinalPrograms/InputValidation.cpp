#include <iostream>

int getInt()
{
    using namespace std;
    
    while(true)
    {
        cout<<"Enter guess: ";
        int guess;
        cin>>guess;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<"Invalid Input, Please try again. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return guess;
        };
    };
}

int getChar()
{
    using namespace std;
    
    while(true)
    {
        cout<<"Do you want to play again, enter Y to play again or N to exit. "<<endl;
        char again;
        cin>>again;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<"Invalid Input, Please try again. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return again;
        };
    };
}