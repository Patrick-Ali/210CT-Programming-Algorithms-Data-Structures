#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;

matrix_t multMatrix(matrix_t matrix1, matrix_t matrix2, matrix_t matrix3, int numberOfRows, int numberOfColumns, int count)
/*
    This function takes two matrices and multiplys them togther so as to output a third matirx
    which is the result of the multiplication. This is created by multiplying each row of marix 1
    by every column in matrix 2 then adding the reults of each column togther to make an entry in
    matrix 3.
*/
{
    int hold = 0;
    std::vector<int> matrixHolder = {};
    // if(matrix3.size() != 0)
    // {
    //     for(int i = 0; i < matrix3.size(); i++)
    //     {
    //         for(int j = 0; i < matrix3[0].size(); j++)
    //         {
    //                 std::cout << matrix3[i][j] << " ";
    //         }
    //     }
    // }
    if(count > (numberOfRows-1))
    {
        //std::cout<<"final call"<<std::endl;
        // for(int i = 0; i < numberOfRows; i++)
        // {
        //     for(int j = 0; i < numberOfColumns; j++)
        //     {
        //         std::cout << matrix3[i][j] << " ";
        //     }
        // }
        return matrix3;
    }
    else
        for(int i = 0; i < numberOfRows; i++) // for every row in matrix 1
        {
            for(int j = 0; j < numberOfColumns; j++)
            {
                int calc = matrix1[count][j]*matrix2[j][i];
                //std::cout << "Uno "<<matrix1[count][j] << " Dos "<<matrix2[j][i] <<std::endl;
                //std::cout << "Hello "<<calc << std::endl;
                hold+=calc;
                //std::cout << "Total "<<hold << std::endl;
            }
            
            matrixHolder.push_back(hold);
            hold = 0;
        }
        // for(int i = 0; i < matrixHolder.size(); i++)
        // {
        //     std::cout << matrixHolder[i] << " "; 
        // }
        
        matrix3.push_back(matrixHolder);
        //std::cout << std::endl;
        return multMatrix(matrix1, matrix2, matrix3, numberOfRows, numberOfColumns, count+1);
}

void print(const matrix_t holder, int numberOfRows, int numberOfColumns)
/*
    This function takes a matrix and the number of columns and rows it has. 
    It uses this information to output the contents of the matrix to the screen. 
*/
{
  int count = 0;
  
  for(int i = 0; i < numberOfRows; i++)
  {
    for(int j = 0; j < numberOfColumns; j++)
    {
      std::cout << holder[i][j] << " ";
      count ++;
          
      if(count%numberOfColumns == 0) // Create a new line at the end of each row
      {
        std::cout << '\n';
      }
            
     }
   }
    
   std::cout << std::endl;
}

int main()
{
    matrix_t matrix1
    {
       {1,2,3},
       {4,5,6},
       {7,8,9}
    };
    
    int numberOfRowsM1 = matrix1.size();
    int numberOfColumnsM1 = matrix1[0].size();
    
    matrix_t matrix2
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    int numberOfRowsM2 = matrix2.size();
    int numberOfColumnsM2 = matrix2[0].size();
    
    matrix_t matrix3;
    std::vector<int>matrixHolder;
    
    //std::cout << matrix1[0][2] << std::endl;
    
    matrix_t matrixHolder1 = multMatrix(matrix1,matrix2,matrix3,numberOfRowsM1,numberOfColumnsM1,0);
    
    print(matrixHolder1, numberOfRowsM1, numberOfColumnsM2);
    
    
    return 0;
}