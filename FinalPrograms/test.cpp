#include <iostream>

//idea for an array of pointers http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function

int** subMatrix(int matrix1[3][3], int matrix2[3][3])
{
    // Creaate a pointer that will evently point to an array of pointers
    int **matrix3 = nullptr;
    // Set an array of 3 integer pointers, so each will point to what would be a row in the matrix
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
    
    return matrix3;
}

int** addMatrix(int matrix1[3][3], int matrix2[3][3])
{
    // Creaate a pointer that will point to an array of pointers
    int **matrix3 = nullptr;
    // Set an array of 3 integer pointers, so each will point to what would be a row in the matrix
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
    
    return matrix3;
}

void print(int **array)
{
 //print out the arrays that the pointer is pointing to 
 // for example when i is zero we are looking at the array being pointed at by pointer one and printing each value in that array
 for(int i = 0; i < 3; i++)
 {
    int count = 0;
    for(int ii = 0; ii < 3; ii++)
    {
        std::cout << array[i][ii] << " ";
        count ++;
        if(count%3 == 0)
        {
            std::cout << '\n';
        }
            
        }
    }   
}

void deallocate(int **array)
{
    // Delete everything in each row, as in deallocate the memory
    for(int i = 0; i < 3; i++)
    {
        delete [] array[i];
    }
    
    //Once all the arrays being pointed to have been deleted we need to delete the array of the pointers
    delete [] array;  
}

int main()
{
    int matrix1[3][3]
    {
        {90,100,119},
        {20,18,13},
        {10,12,14}
    };
    
    int matrix2[3][3]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    
    // As the return is the address of a pointer pointing at an array of pointers this must be a pointer to them pointers 
    int **add = addMatrix(matrix1,matrix2);
    
    int **sub = subMatrix(matrix1,matrix2);
    
    print(add);
    
    std::cout << std::endl;
    
    print(sub);
    
    deallocate(add);
    
    add = nullptr;
    
    deallocate(sub);
    
    sub = nullptr;
    
    return 0;
}