#include <iostream>
#include <vector>
using namespace std;

std::vector<int> greatestSubsequenceAsc(const std::vector<int>& sequence, int size)
{
  std::vector<int> hold;
  std::vector<int> temp;
  
  for(int i = 0; i < size; i++)
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
{
  std::vector<int> hold;
  std::vector<int> temp;
  
  for(int i = 0; i < size; i++)
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
  
  cout << "Greatest subsequence descending: ";
  
  for(int i = 0; i < subseqSize; i++)
  {
    cout << subsequence[i];
    
    if(i < (subseqSize-1))
    {
      cout << ", ";
    }
  }
  
  cout << endl;
  
  std::vector<int> sequence2 {1,0,1,4,5,1,2};
  int seqSize2 = sequence2.size();
  
  std::vector<int> subsequence2 = greatestSubsequenceAsc(sequence2,seqSize2);
  int subseqSize2 = subsequence2.size();
  
  cout << "Greatest subsequence ascending: ";
  for(int i = 0; i < subseqSize2; i++)
  {
    cout << subsequence2[i];
    
    if(i < (subseqSize2-1))
    {
      cout << ", ";
    }
  }
  
  return 0;

}
