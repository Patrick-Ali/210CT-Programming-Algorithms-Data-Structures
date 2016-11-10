#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int>& array, int high, int low, int start, int end)
{
    int middle = (start+end) / 2; 
    int starting = start;
    int ending = end;
    
    if(starting > array[array.size()-1]) 
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
        ending = middle;
        return binarySearch(array, high, low, start, ending);
    }
   else if (low > array[middle])
    {
        //return true;
        starting = middle;
        //std::cout << "Working" << std::endl;
        return binarySearch(array, high, low, starting, end);
    }
    
    
    //std::cout << array.size() << std::endl;    
}

int main()
{
    std::vector<int> array {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int start = 0;
    int end = array.size()-1;
    
    int high = 13;
    int low = 12;
    
    //std::cout << array.size() << std::endl;
    
    //std::cout << (array.size() - 1)/2 << std::endl;
    
    //std::cout << array[(array.size() - 1)/2] << std::endl;
    
    int arraySize = ((start+end) / 2);
    
    //std::cout << arraySize << std::endl;
    
    bool inArray = binarySearch(array, high, low, start, end);
    
    inArray == 1 ? std::cout << "True" : std::cout << "False" << std::endl;
    
    return 0;
}