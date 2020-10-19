#include <stdio.h>
#include <stdlib.h> 

int select_num(int m_1_l, int m_1_c,int m_2_l,int m_2_c)
{   
    if (m_1_c == m_2_c && m_1_l == m_2_l && m_1_l == m_2_c){
        printf("You can conduct plus and mutiply!");
    }else if (m_1_c == m_2_c && m_1_l == m_2_l){
        printf("You can conduct plus!");
    }else if (m_1_c == m_2_l){
        printf("You can conduct mutiply!");
    }else {
        printf("I am sorry . I don't know what you mean.");
    }

}

int main(void)
{
    int i=0 , j=0 , v = 0 , s = 0 , swit,h,z,x1,x2,x3,stack,tamp;
    char y;
    int result_plus[h][z];
    int result_mutiply[i][j];
    int matrix1_line_number,matrix1_column_number;
    printf("Please input your matrix1 line number:");scanf("%d",&matrix1_line_number);
    printf("Please input your matrix1 column number:");scanf("%d",&matrix1_column_number);
    int matrix1 [matrix1_line_number][matrix1_column_number];

    int matrix2_line_number,matrix2_column_number;
    printf("Please input your matrix2 line number:");scanf("%d",&matrix2_line_number);
    printf("Please input your matrix2 column number:");scanf("%d",&matrix2_column_number);
    int matrix2 [matrix2_line_number][matrix2_column_number];
    
    // Then will choose whether them can calculate or not???
    // Or ues which kinds of methods ????
    // First we should know we can't change their location ! 
    // What we need to do is just to justy Wether ??
    // Now we gonnan to write the plus method, mulitiplicate method 
    select_num(matrix1_line_number,matrix1_column_number,matrix2_line_number,matrix2_column_number);
    printf("Now we will input our element.\n");
    do
    {
        do
        {
            scanf("%d",&matrix1[i][j]);
            j ++;
        } while ((y=getchar()) != '\n');
        i ++;
        j = 0;
    } while (i != matrix1_line_number);
    for (i = 0 ; i < matrix1_line_number ; i ++){
        for (j = 0; j < matrix1_column_number;j ++){
            printf("%4.d",matrix1[i][j]);
        }
        printf("\n");
    }
    i = 0;
    j = 0;
    printf("Next one!!\n");
    do
    {
        do
        {
            scanf("%d",&matrix2[i][j]);
            j ++;
        } while ((y=getchar()) != '\n');
        i ++;
        j = 0;
    } while (i != matrix2_line_number);
    for (i = 0 ; i < matrix2_line_number ; i ++){
        for (j = 0; j < matrix2_column_number;j ++){
            printf("%4.d",matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Plus -------- 1 \n");
    printf("Mutiply -------- 2 \n");
    scanf("%d",&swit);
    switch (swit)
    {
    case 1:
        h = matrix1_line_number;
        z = matrix1_column_number;
        i = 0;
        j = 0;
        for (i = 0; i < h ; i ++){
            for (j = 0; j < z ; j ++){
                    result_plus[i][j] = matrix1[i][j] + matrix2[i][j];
                    printf("%4.d",result_plus[i][j]);
            }
            printf("\n");
        }
        break;
    
    case 2:
        for (x1 = 0 ; x1 < matrix1_line_number; x1 ++){
            for (x2 = 0 ; x2 < matrix2_column_number; x2 ++){
                for (x3 = 0 ; x3 < matrix1_column_number ; x3 ++){
                    stack = matrix1[x1][x3] * matrix2[x3][x2];
                    tamp += stack;
                }
                result_mutiply[x1][x2] = tamp;
                tamp = 0;
                stack = 0;
                printf("%4.d",result_mutiply[x1][x2]);
            }
            printf("\n");
        }
        
        break;
    
    default:
        printf("?????????????????");
    }
    system("pause");
    return 0;
}