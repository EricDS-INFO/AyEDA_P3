#include <iostream>
#define N 3
#define M 3


// this function captures the left cell values
int left (int pos)
{
    if (pos == 0 ){
        pos = M-1;
    }
    else 
        pos--;
 return pos;
}


// this function captures the right cell values
int right (int pos)
{
    if (pos == M - 1) 
        pos = 0; 
    else 
        pos++;
 return pos;
}

// this function captures the up cell values
int up (int pos)
{
    if (pos == 0 )
    {
        pos = N-1;
    }      
    else 
        pos--;     // we decrease one position in y axis.
 return pos;
}

// this function captures the down cell values
int down (int pos)
{
    if (pos == N - 1 ) 
        pos = 0; 
    else 
        pos++;
 return pos;
}

void write (int grid[N][M]);

int main (void) 
{
    int grid[3][3];   
    int num = 0;
    
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    {
        grid[i][j] = num++; 
    }

    write(grid);
    
    return 0;
}



void write (int grid[N][M]) 
{

        if (grid[up(1)][left(1)] == 0)
            std::cout << " x ";
        else
            std::cout << "   ";
        
        if (grid[up(1)][1] == 1)
            std::cout << " x ";
        else
            std::cout << "   ";

        if (grid[up(1)][right(1)] == 2)
            std::cout << " x ";
        else
            std::cout << "   ";

        
        
        std::cout << std::endl;

        
        
        if (grid[1][left(1)] == 3)
            std::cout << " x " ;
        else
            std::cout << "   ";

        if (grid[1][1] == 4)
            std::cout << " x ";
        else
            std::cout << "   ";

        if (grid[1][right(1)] == 5)
            std::cout << " x " ;
        else
            std::cout << "   ";
        


        std::cout << std::endl;



        if (grid[down(1)][left(1)] == 6)
            std::cout << " x " ;
        else
            std::cout << "   ";

        if (grid[down(1)][1] == 7)
            std::cout << " x ";
        else
            std::cout << "   ";

        if (grid[down(1)][right(1)] == 8)
            std::cout << " x " ;
        else
            std::cout << "   ";

        std::cout << std::endl;

        
}
    