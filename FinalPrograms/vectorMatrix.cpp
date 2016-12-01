#include <iostream>
#include <vector>

//idea for an array of pointers http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function

std::vector<std::vector<int>> addMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    // Creaate a pointer that will point to an array of pointers
    //int **matrix3 = nullptr;
    std::vector<std::vector<int>> matrix3;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    //matrix3 = new int*[3];
    int hold;
    //int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        //matrix3[i] = new int[3];
        std::vector<int> matrixHolder {};

        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {

            hold = matrix1[i][ii] + matrix2[i][ii];
            matrixHolder.push_back(hold);
            
        }
        matrix3.push_back(matrixHolder);
        //count++;
    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

std::vector<std::vector<int>> subMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    // Creaate a pointer that will point to an array of pointers
    std::vector<std::vector<int>> matrix3;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    //matrix3 = new int*[3];
    int hold;
    //int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        std::vector<int> matrixHolder {};

        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {
            hold = matrix1[i][ii] - matrix2[i][ii];
            matrixHolder.push_back(hold);
            
        }
        matrix3.push_back(matrixHolder);
        //count++;
    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

std::vector<std::vector<int>> multMatrix(const int matrix1[3][3], const int matrix2[3][3])
{

    // Creaate a pointer that will point to an array of pointers
    std::vector<std::vector<int>> matrix3;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    //matrix3 = new int*[3];
    int hold = 0;
    int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        std::vector<int> matrixHolder {};

        int iii = 0;
        int ii = 0;
        
        while(iii < 3)
        {

          while(ii < 3)
          {
            int calc = matrix1[i][ii] * matrix2[ii][iii];
            hold += calc;
            ii++;
          }

         matrixHolder.push_back(hold);
         iii++;
         ii = 0;
         hold = 0;
        }
        matrix3.push_back(matrixHolder);

    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

void print(const std::vector<std::vector<int>> holder, int numberOfRows, int numberOfColumns)
{
  int count = 0;
  
  for(int i = 0; i < numberOfRows; i++)
  {
    for(int ii = 0; ii < numberOfColumns; ii++)
    {
      std::cout << holder[i][ii] << " ";
      count ++;
          
      if(count%3 == 0)
      {
        std::cout << '\n';
      }
            
     }
   }
    
//   for(int i = 0; i < 3; i++)
//   {
//     delete [] holder[i];
//   }
    
//   delete [] holder;
    
   std::cout << std::endl;
}

int main()
{
    int matrix1[3][3]
    {
       {123,234,345},
       {456,567,678},
       {789,8910,91011}
    };
    
    int matrix2[3][3]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    // As the return is the address of a pointer pointing at an array of pointers this must be a pointer to them pointers 
    std::vector<std::vector<int>> add = addMatrix(matrix1,matrix2);
    
    int numberOfRows = add.size();
    int numberOfColumns = add[0].size();
    
    // int count = 0;
    
    // for(int i = 0; i < add.size(); i++)
    // {
    //   for(int ii = 0; ii < add[ii].size(); ii++)
    //   {
    //     std::cout << add[i][ii] << " ";
    //     count ++;
          
    //     if(count%add[ii].size() == 0)
    //     {
    //       std::cout << '\n';
    //     }
            
    //   }
    // }
  
    // std::cout << std::endl;
    
    print(add, numberOfRows, numberOfColumns);
    
    // std::cout << std::endl;
    
    std::vector<std::vector<int>> sub = subMatrix(matrix1,matrix2);
    
    numberOfRows = sub.size();
    numberOfColumns = sub[0].size();
    
    // count = 0;
    
    // for(int i = 0; i < sub.size(); i++)
    // {
    //   for(int ii = 0; ii < sub[ii].size(); ii++)
    //   {
    //     std::cout << sub[i][ii] << " ";
    //     count ++;
          
    //     if(count%sub[ii].size() == 0)
    //     {
    //       std::cout << '\n';
    //     }
            
    //   }
    // }
    
    print(add, numberOfRows, numberOfColumns);
    
    std::vector<std::vector<int>> mult = multMatrix(matrix1,matrix2);
    
    // std::cout << std::endl;
    
    numberOfRows = mult.size();
    numberOfColumns = mult[0].size();
    
    // count = 0;
    
    // for(int i = 0; i < mult.size(); i++)
    // {
    //   for(int ii = 0; ii < sub[ii].size(); ii++)
    //   {
    //     std::cout << mult[i][ii] << " ";
    //     count ++;
          
    //     if(count%mult[ii].size() == 0)
    //     {
    //       std::cout << '\n';
    //     }
            
    //   }
    // }
    
    print(mult, numberOfRows, numberOfColumns);
 
    return 0;
}