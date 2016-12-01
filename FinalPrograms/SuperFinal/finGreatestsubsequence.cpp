#include <iostream>
#include <vector>

std::vector<int> greatestSubsequenceAsc(const std::vector<int>& sequence, int size)
/*
  Takes in both an array and the size of the array so as to find the largest 
  ascending sequence within the array.
*/
{
  std::vector<int> hold;
  std::vector<int> temp;
  
  for(int i = 0; i < size; i++)
  /*
    This runs through the sequence comparing the current index and the next 
    index. If the current index is smaller than the next it is added to the 
    list. This continues until either the whole list has been read or
    the next index is smaller than the current thus telling us the end of 
    the sequence. This subsequence is stored in hold and if bigger than the one 
    in temp it is stored there for later comparision. The largest is then returned
    to the user.
  */
  {
    if(sequence[i] < sequence[i+1] or sequence[i] == sequence[i+1])
    {
      hold.push_back(sequence[i]);
    }
    else if(sequence[i] > sequence[i+1])
    {
      hold.push_back(sequence[i]);
      int tempSize = temp.size();
      int holdSize = hold.size();
      
      if(holdSize > tempSize or (holdSize == tempSize and hold[0] < temp[0]))
      {
        temp = hold;
      }
      
      hold = {};
    }
  }
  
  if(temp.size() == 0 or hold.size() > temp.size())
  {
    return hold;
  }
  else
  {
    return temp;
  }
}

std::vector<int> greatestSubsequenceDesc(const std::vector<int>& sequence, int size)
/*
  Takes in both an array and the size of the array so as to find the largest 
  descending sequence within the array.
*/
{
  std::vector<int> hold;
  std::vector<int> temp;
  
  for(int i = 0; i < size; i++)
  /*
    This runs through the sequence comparing the current index and the next 
    index. If the current index is larger than the next it is added to the 
    list. This continues until either the whole list has been read or
    the next index is larger than the current thus telling us the end of 
    the sequence. This subsequence is stored in hold and if bigger than the one 
    in temp it is stored there for later comparision. The largest is then returned
    to the user.
  */
  {
    if(sequence[i] > sequence[i+1] or sequence[i] == sequence[i+1])
    {
      hold.push_back(sequence[i]);
    }
    else if(sequence[i] < sequence[i+1])
    {
      hold.push_back(sequence[i]);
      int tempSize = temp.size();
      int holdSize = hold.size();
      
      if(holdSize > tempSize or (holdSize == tempSize and hold[0] > temp[0]))
      {
        temp = hold;
      }
      
      hold = {};
    }
  }
  
  if(temp.size() == 0 or hold.size() > temp.size())
  {
    return hold;
  }
  else
  {
    return temp;
  }
}

int main() {
  
  std::vector<int> sequence {5,4,3,13,12,11,16};
  int seqSize = sequence.size();
  
  std::vector<int> subsequence = greatestSubsequenceDesc(sequence,seqSize);
  int subseqSize = subsequence.size();
  
  std::cout << "Greatest subsequence descending: ";
  
  for(int i = 0; i < subseqSize; i++)
  {
    std::cout << subsequence[i];
    
    if(i < (subseqSize-1))
    {
      std::cout << ", ";
    }
  }
  
  std::cout << std::endl;
  
  std::vector<int> sequence2 {1,0,1,4,5,1,2};
  int seqSize2 = sequence2.size();
  
  std::vector<int> subsequence2 = greatestSubsequenceAsc(sequence2,seqSize2);
  int subseqSize2 = subsequence2.size();
  
  std::cout << "Greatest subsequence ascending: ";
  for(int i = 0; i < subseqSize2; i++)
  {
    std::cout << subsequence2[i];
    
    if(i < (subseqSize2-1))
    {
      std::cout << ", ";
    }
  }
  
  return 0;

}
