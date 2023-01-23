#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizer(int**,int,int );
void allocator(int**,int,int);

int main(void){
    srand(time(NULL));
    int rows1,rows2,col1,col2;
    printf("Insert rows of the first matrix :\n");
    scanf("%d",&rows1);
    printf("Insert columns of the first matrix:\n");
    scanf("%d",&col1);
    printf("Insert rows of the second matrix :\n");
    scanf("%d",&rows2);
    printf("Insert columns of the second matrix:\n");
    scanf("%d",&col2);

    printf("First matrix : %d,%d\nSecond matrix: %d,%d\n\n",rows1,col1,rows2,col2);

    if(col1 != rows2) printf("Cant be processed!");
    else {
        int **p1, **p2,**p3;
        p1 = malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++) {
            p1[i] = malloc(col1 * sizeof(int));
        }
        p2 = malloc(rows2 * sizeof(int *));
        for (int i = 0; i < rows1; i++) {
            p2[i] = malloc(col2 * sizeof(int));
        }
        randomizer(p1,rows1,col1);
        randomizer(p2,rows2,col2);

        p3 = malloc(rows1 *sizeof(int *));
        for(int i = 0; i < rows1;i++){
            p3[i] = malloc(col2 * sizeof(int));
        }

        for(int i = 0;i < rows1;i++){
            for(int j = 0;j < col2;j++){
                for(int k = 0; k < rows2;k++){
                    p3[i][j] = p1[k][i] + p2[j][k];
                }
            }
        }

        for(int i = 0; i < rows1; i++){
            for(int j = 0;j < col2;j++){
                printf("%d",p3[i][j]);
                printf(" ");
            }
            printf("\n");
        }

    }

}

void randomizer(int** ptr,int r,int c){
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            ptr[i][j] = rand() % 50;
        }
    }
}


