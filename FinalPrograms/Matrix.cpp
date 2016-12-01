#include <iostream>

//idea for an array of pointers http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function

int** addMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    //std::cout << matrix1[1][1] << " " << matrix2[1][1] << std::endl;
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
        //std::cout << "Working" << std::endl;
        //hold = 0;
        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {
            //if (count == 1) 
            //{
                //hold = matrix1[i+3][ii+3] + matrix2[i+3][ii+3];
                //matrix3[i+3][ii+3] = hold;
            //}
            //else if(count == 2)
            //{
                //hold = matrix1[i+6][ii+6] + matrix2[i+6][ii+6];
                //matrix3[i+6][ii+6] = hold; 
            //}
            //std::cout << "I is " << i << "II is " << ii << std::endl; 
            hold = matrix1[i][ii] + matrix2[i][ii];
            //std::cout <<  "Hold "<< matrix1[i][ii] + matrix2[i][ii] <<  std::endl;
            matrix3[i][ii] = hold;
            //std::cout << matrix1[i][ii] << " " << matrix2[i][ii] << " " << matrix3[i][ii] <<'\n';
            
        }
        count++;
    }
    
    //int *matrixptr = &matrix3
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

int** subMatrix(const int matrix1[3][3], const int matrix2[3][3])
{
    //std::cout << matrix1[1][1] << " " << matrix2[1][1] << std::endl;
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
        //std::cout << "Working" << std::endl;
        //hold = 0;
        //fill out the row with relevant data
        for(int ii = 0; ii < 3; ii++)
        {
            //if (count == 1) 
            //{
                //hold = matrix1[i+3][ii+3] + matrix2[i+3][ii+3];
                //matrix3[i+3][ii+3] = hold;
            //}
            //else if(count == 2)
            //{
                //hold = matrix1[i+6][ii+6] + matrix2[i+6][ii+6];
                //matrix3[i+6][ii+6] = hold; 
            //}
            //std::cout << "I is " << i << "II is " << ii << std::endl; 
            hold = matrix1[i][ii] - matrix2[i][ii];
            //std::cout <<  "Hold "<< matrix1[i][ii] + matrix2[i][ii] <<  std::endl;
            matrix3[i][ii] = hold;
            //std::cout << matrix1[i][ii] << " " << matrix2[i][ii] << " " << matrix3[i][ii] <<'\n';
            
        }
        count++;
    }
    
    //int *matrixptr = &matrix3
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix3;
}

int** multMatrix(const int matrix1[3][3], const int matrix2[3][3])
{

    // Creaate a pointer that will point to an array of pointers
    int **matrix4 = nullptr;
    // Set an array of 3 integer pointers, so each will point to a row in the matrix
    matrix4 = new int*[3];
    int hold = 0;
    int count = 0;
    
    for(int i = 0; i < 3; i++)
    {
        // create an array of size three i.e. 3 columns that will be pointed at by an array at by the pointer indicated by the array 
        matrix4[i] = new int[3];

        int iii = 0;
        int ii = 0;
        
        while(iii < 3)
        {
         //std::cout << "III IS: "<< iii << std::endl;
         
          while(ii < 3)
          {
            //std::cout << "III IS: "<< iii << std::endl;
            int calc = matrix1[i][ii] * matrix2[ii][iii];
            //std::cout << calc << std::endl;
            hold += calc;
            //std::cout << matrix1[i][ii] << " * " << matrix2[ii][iii] << " = "<< matrix1[i][ii] * matrix2[ii][iii] <<'\n';
            ii++;
          }
         //std::cout << "I IS: "<< i << std::endl;
         
         //std::cout <<  "Hold " <<  hold << std::endl;
         iii++;
         ii = 0;
         matrix4[i][iii-1] = hold;
         //std::cout <<  matrix4[i][iii-1] << std::endl; 
         hold = 0;
        }

    }
    
    //int *matrixptr = &matrix3
    
    //return the pointer to the array of pointers thus a pointer to a pointer 
    return matrix4;
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
       {1,2,3},
       {4,5,6},
       {7,8,9}
    };
    
    int matrix2[3][3]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    //std::cout << matrix2[2][1] << std::endl;
    
    //int height = sizeof(matrix1)/sizeof(matrix1[0]);
    //int width = sizeof(matrix1[0])/sizeof(int);
    
    // As the return is the address of a pointer pointing at an array of pointers this must be a pointer to them pointers 
    int **add = addMatrix(matrix1,matrix2);
    
    print(add);
    
    // int count = 0;
    
    // //std::cout << "pos " << add[2][2] << std::endl;
    // //print out the arrays that the pointer is pointing to 
    // // for example when i is zero we are looking at the array being pointed at by pointer one and printing each value in that array
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int ii = 0; ii < 3; ii++)
    //     {
    //         std::cout << add[i][ii] << " ";
    //         count ++;
    //         if(count%3 == 0)
    //         {
    //             std::cout << '\n';
    //         }
            
    //     }
    // }
    
    // for(int i = 0; i < 3; i++)
    // {
    //     delete [] add[i];
    // }
    
    // delete [] add;
    
    //std::cout << std::endl;
    
    int **sub = subMatrix(matrix1,matrix2);
    
    print(sub);
    
    // count = 0;
    
    // //std::cout << "pos " << add[2][2] << std::endl;
    // //print out the arrays that the pointer is pointing to 
    // // for example when i is zero we are looking at the array being pointed at by pointer one and printing each value in that array
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int ii = 0; ii < 3; ii++)
    //     {
    //         std::cout << sub[i][ii] << " ";
    //         count ++;
    //         if(count%3 == 0)
    //         {
    //             std::cout << '\n';
    //         }
            
    //     }
    // }
    
    // for(int i = 0; i < 3; i++)
    // {
    //     delete [] sub[i];
    // }
    
    // delete [] sub;
    
        
   // std::cout << std::endl;
    
    int **mult = multMatrix(matrix1,matrix2);
    
    print(mult);
    
    // count = 0;
    
    // //std::cout << "pos " << add[2][2] << std::endl;
    // //print out the arrays that the pointer is pointing to 
    // // for example when i is zero we are looking at the array being pointed at by pointer one and printing each value in that array
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int ii = 0; ii < 3; ii++)
    //     {
    //         std::cout << mult[i][ii] << " ";
    //         count ++;
    //         if(count%3 == 0)
    //         {
    //             std::cout << '\n';
    //         }
            
    //     }
    // }
    
    // for(int i = 0; i < 3; i++)
    // {
    //     delete [] mult[i];
    // }
    
    // delete [] mult;
    
    
    
    return 0;
}