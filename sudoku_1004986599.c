
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}
int solved(int sudoku[9][9])
{
   for(int i=0; i<9; i++)
   {
       for(int j=0; j<9; j++)
       {
           if(sudoku[i][j]==0)
           {
               return 1;
           }
       }
   }
   return 0;
}

int sameSquare(int row, int col, int num, int sudoku[9][9])
{
    /*
        0  1  2   3  4  5   6  7  8
        ---------------------------
    0 | 5  3  0 | 0  7  0 | 0  0  0
    1 | 6  0  0 | 1  9  5 | 0  0  0
    2 | 0  9  8 | 0  0  0 | 0  6  0
        ---------------------------
    3 | 8  0  0 | 0  6  0 | 0  0  3
    4 | 4  0  0 | 8  0  3 | 0  0  1
    5 | 7  0  0 | 0  2  0 | 0  0  6
        ---------------------------
    6 | 0  6  0 | 0  0  0 | 2  8  0
    7 | 0  0  0 | 4  1  9 | 0  0  5
    8 | 0  0  0 | 0  8  0 | 0  7  9
         ---------------------------
    */


    row = (row/3)*3;
    col = (col/3)*3;
    for(int i=row; i<row+3; i++)
    {
        for(int j=col; j<col+3; j++)
        {
            if(sudoku[i][j]==num)
            {
                return 1;    //found
            }
        }

    }
    return 0;

}
int sameCol(int row, int col, int num, int sudoku[9][9])
{
    for(int i=0; i<9; i++)
    {
        if(sudoku[row][i]==num)
        {
            return 1;    //found
        }
    }
    return 0;
}
int sameRow(int row, int col, int num, int sudoku[9][9])
{
    for(int i=0; i<9; i++)
    {
        if(sudoku[i][col]==num)
        {
            return 1;    //found
        }
    }
    return 0;
}
int helper_sudoku(int sudoku[9][9], int row, int col)
{
    int num = 1;

    if(col==9)
    {
        return 1;
    }
    if(sudoku[row][col]!=0)
    {
        if(row<8)
        {
            if(helper_sudoku(sudoku, row+1, col)==1)
                return 1;
        }
        else
        {

            if(helper_sudoku(sudoku, 0, col+1)==1)
                return 1;
        }
        return 0;
    }
    if(sudoku[row][col]==0)
    {
        while(num<10)
        {
            if(sameSquare(row, col, num, sudoku)==0 && sameCol(row, col, num, sudoku)==0 && sameRow(row, col, num, sudoku)==0)
            {
                sudoku[row][col]=num;
                if(row<8)
                {
                    if(helper_sudoku(sudoku, row+1, col)==1)
                        return 1;
                }
                else
                {

                    if(helper_sudoku(sudoku, 0, col+1)==1)
                        return 1;
                }

            }
            num++;
        }
        sudoku[row][col]=0;
        return 0;
    }
    return 0;
}
void solve_sudoku(int sudoku[9][9], int depth)
{
    int row=0;
    int col=0;
    helper_sudoku(sudoku, row, col);
    return;
}

#ifndef __testing

int main()
{
   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
         // int Sudoku[9][9]={{0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
         //        {0, 0, 0, 0, 0, 0, 0, 0, 0}};


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);

  solve_sudoku(Sudoku,0);

  printf("Solution is:\n");
  print_sudoku(Sudoku);

}

#endif
