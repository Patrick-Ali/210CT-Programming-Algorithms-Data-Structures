#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;

matrix_t addMatrix(const matrix_t matrix1, const  matrix_t matrix2, int numberOfRows, int numberOfColumns)
{
    /*
        This function takes two matrices and adds them together so as to output a third matrix
        which is the result of the addition.
    */
    matrix_t matrix3;

    int hold;
    
    for(int i = 0; i < numberOfRows; i++)// for every row in matrix 1 and 2
    {

        std::vector<int> matrixHolder {};

        for(int j = 0; j < numberOfColumns; j++)// for every column in matrix 1 and 2
        {

            hold = matrix1[i][j] + matrix2[i][j];
            matrixHolder.push_back(hold);
            
        }
        matrix3.push_back(matrixHolder);
    }
    
    return matrix3;
}

matrix_t subMatrix(const matrix_t matrix1, const  matrix_t matrix2, int numberOfRows, int numberOfColumns)
{
    /*
        This function takes two matrices and subtracts the first from the second so 
        as to output a third matrix which is the result of the subtraction.
    */
    matrix_t matrix3;

    int hold;

    
    for(int i = 0; i < numberOfRows; i++)// for every row in matrix 1 and 2
    {
        std::vector<int> matrixHolder {};

        for(int j = 0; j < numberOfColumns; j++)// for every column in matrix 1 and 2
        {
            hold = matrix1[i][j] - matrix2[i][j];
            matrixHolder.push_back(hold);
            
        }
        matrix3.push_back(matrixHolder);
    }
    
    return matrix3;
}

matrix_t multMatrix(const matrix_t matrix1, const  matrix_t matrix2, matrix_t matrix3, int numberOfRows, int numberOfColumns, int count)
{
    /*
        This function takes two matrices and multiply them together so as to output a third matrix
        which is the result of the multiplication. This is created by multiplying each row of matrix 1
        by every column in matrix 2 then adding the results of each column together to make an entry in
        matrix 3. To accomplish this the function is recursive as it will take one row in matrix one
        and multiply it by each column in matrix 2 to generate the row in matrix 3.
    */
    int hold = 0;
    std::vector<int> matrixHolder = {};
 
    if(count > (numberOfRows-1))
    {
        return matrix3;
    }
    else
        for(int i = 0; i < numberOfRows; i++) // for every column in matrix 2
        {
            for(int j = 0; j < numberOfColumns; j++)// for every column in matrx 1 and row in matrix 2
            {
                int calc = matrix1[count][j]*matrix2[j][i];
                hold+=calc;
            }
            
            matrixHolder.push_back(hold);
            hold = 0;
        }

        matrix3.push_back(matrixHolder);
        return multMatrix(matrix1, matrix2, matrix3, numberOfRows, numberOfColumns, count+1);
}

matrix_t scalarAddMatrix(const matrix_t matrix, int scalar, int numberOfRows, int numberOfColumns)
{
    /*
        This function takes one matrix and adds a supplied number to it so as to output a second matrix
        which is the result of the addition.
    
    */
    matrix_t matrix2;

    int hold;
    
    for(int i = 0; i < numberOfRows; i++)// for every row in matrix 1
    {

        std::vector<int> matrixHolder {};

        for(int j = 0; j < numberOfColumns; j++)//for every column in matrix 1
        {

            hold = matrix[i][j] + scalar;
            matrixHolder.push_back(hold);
            
        }
        matrix2.push_back(matrixHolder);
    }
    
    return matrix2;
}

matrix_t scalarSubMatrix(const matrix_t matrix, int scalar, int numberOfRows, int numberOfColumns)
{
    /*
        This function takes one matrix and subtracts a supplied number so as to output
        a second matrix which is the result of the subtraction.
    */
    matrix_t matrix2;

    int hold;

    
    for(int i = 0; i < numberOfRows; i++)// for every row in matrix 1
    {
        std::vector<int> matrixHolder {};

        for(int j = 0; j < numberOfColumns; j++)//for every column in matrix 1
        {
            hold = matrix[i][j] - scalar;
            matrixHolder.push_back(hold);
            
        }
        matrix2.push_back(matrixHolder);
    }
    
    return matrix2;
}

matrix_t scalarMultMatrix(const matrix_t matrix, int scalar, int numberOfRows, int numberOfColumns)
{
    /*
        This function takes one matrix and multiply it by a supplied number so as to output a second matrix
        which is the result of the multiplication.
    
    */
    matrix_t matrix2;
  
    int hold = 0;
    
    for(int i = 0; i < numberOfRows; i++) // for every row in matrix 1
    {
       
        std::vector<int> matrixHolder {};

        for(int j = 0; j < numberOfColumns; j++) //for every column in matrix 1
        {
            hold = matrix[i][j] * scalar;
            matrixHolder.push_back(hold);
            
        }
        matrix2.push_back(matrixHolder);
    }
    
    return matrix2;
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
    
    int scalar = 2;
        
    bool mult = false;
    bool addSub = false;
    
    matrix_t matrix3;
    
    matrix_t matrixHolder1;
    
    matrix_t matrixHolder2;
    
    if(numberOfColumnsM1 > numberOfRowsM2 or numberOfRowsM2 > numberOfColumnsM1)
    {
        std::cout << "Matrix multipication can't happen as the matracies are diffrent sizes" << std::endl;
    }
    else
    {
      matrixHolder1 = multMatrix(matrix1,matrix2,matrix3,numberOfRowsM2,numberOfColumnsM1,0);
      mult = true;
    }
    
    if(numberOfRowsM1 != numberOfRowsM2 || numberOfColumnsM1 != numberOfColumnsM2)
    {
        std::cout<<"Matrix addition and subtraction can't happen as the matracies are diffrent sizes" << std::endl;
    }
    else
    {
        matrixHolder2 = addMatrix(matrix1,matrix2,numberOfRowsM1,numberOfColumnsM1);
        addSub = true;
    }
    
    if(addSub == true and mult == true)
    {
        matrix_t matrixHolder3 = scalarMultMatrix(matrixHolder2,scalar,numberOfRowsM1,numberOfColumnsM1);
        
        matrix3 = subMatrix(matrixHolder1,matrixHolder3,numberOfRowsM1,numberOfColumnsM1);
        print(matrix3, numberOfRowsM1, numberOfColumnsM1);
    }
    
    return 0;
}
