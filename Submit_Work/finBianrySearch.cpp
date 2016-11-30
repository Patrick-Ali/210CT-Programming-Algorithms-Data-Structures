#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int>& array, int high, int low, int start, int end)
{
    /*
        Takes in an array of integers and a range, low and high marking the bounds
        of this range. Start and end tell the function where to find the middle
        as it is about halfway between these numbers thus allowing us to make the 
        search area smaller and smaller till we have a result. 
    */
    int middle = (start+end) / 2;
    
    
    if(start > array[array.size()-1]) 
    {
        return false;
    }
    
    if(array[middle] == low or array[middle] == high)
    {
        return true;
    }
    
    if (array[middle] > low and array[middle] < high)
    {
        return  true;
    }
    else if ((end - start) <= 1)
    {
        return false;
    }
    else if (high < array[middle])
    {
        end = middle;
        return binarySearch(array, high, low, start, end);
    }
   else if (low > array[middle])
    {
        start = middle;
        return binarySearch(array, high, low, start, end);
    }
    
}

int main()
{
    std::vector<int> array {1,2,3,4,5,6,7,8,9,10,11,12,13,14,400};
    int start = 0;
    int end = array.size()-1;
    
    int high = 20;
    int low = 10;

    bool inArray = binarySearch(array, high, low, start, end);
    
    inArray == 1 ? std::cout << "True" : std::cout << "False" << std::endl;
    
    return 0;
}