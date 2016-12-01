#include <iostream>

//idea for an array of pointers http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function

int** addMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    // Creaate a pointer that will point to an array of pointers
    int **matrix3 = nullptr;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    matrix3 = new int*[3];
    int hold;
    int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        matrix3[i] = new int[3];

        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {

            hold = matrix1[i][ii] + matrix2[i][ii];
            matrix3[i][ii] = hold;
            
        }
        count++;
    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

int** subMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    // Creaate a pointer that will point to an array of pointers
    int **matrix3 = nullptr;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    matrix3 = new int*[3];
    int hold;
    int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        matrix3[i] = new int[3];

        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {
            hold = matrix1[i][ii] - matrix2[i][ii];
            matrix3[i][ii] = hold;
            
        }
        count++;
    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

int** multMatrix(const int matrix1[3][3], const int matrix2[3][3])
{

    // Creaate a pointer that will point to an array of pointers
    int **matrix3 = nullptr;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    matrix3 = new int*[3];
    int hold = 0;
    int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        matrix3[i] = new int[3];

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

         matrix3[i][iii] = hold;
         iii++;
         ii = 0;
         hold = 0;
        }

    }
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

void print(int** holder)
{
  int count = 0;
  
  for(int i = 0; i < 3; i++)
    {
      for(int ii = 0; ii < 3; ii++)
      {
          std::cout << holder[i][ii] << " ";
          count ++;
          
        if(count%3 == 0)
        {
          std::cout << '\n';
        }
            
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        delete [] holder[i];
    }
    
    delete [] holder;
    
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
    int **add = addMatrix(matrix1,matrix2);
    
    print(add);
    
    int **sub = subMatrix(matrix1,matrix2);
    
    print(sub);
    
    int **mult = multMatrix(matrix1,matrix2);
    
    print(mult);
 
    return 0;
}