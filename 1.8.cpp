#include <stdio.h>

void add (void *result, void *A, void *B, int n, int m, int is_int);
void mul (void *result, void *A, void *B, int n, int m, int is_int);

int main() {

    int **A = new int*[5];
    int **B = new int*[5];
    int **resultInt = new int*[5];
    for (int i = 0; i < 5; i++) {
        A[i] = new int[5];
        B[i] = new int[5];
        resultInt[i] = new int[5];
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            A[i][j] = i*j;
            B[i][j] = i*j;
        }

    double **C = new double*[5];
    double **D = new double*[5];
    double **resultDouble = new double*[5];
    for (int i = 0; i < 5; i++){
        C[i] = new double[5];
        D[i] = new double[5];
        resultDouble[i] = new double[5];
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            C[i][j] = i*j + 0.001;
            D[i][j] = i*j + 0.001;
        } 

   /* add(resultInt, A, B, 5, 5, 1); 
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int j = 0; j < 5; j++)
        printf ("%d ", resultInt[i][j]);
    }
    printf("\n");

    add(resultDouble, C, D, 5, 5, 0);
    for (int i = 0; i < 5; i++){
        printf ("\n");
        for (int j = 0; j < 5; j++)
        printf ("%f ", resultDouble[i][j]);
    }
    printf("\n");
    return 0;*/ 

    mul(resultInt, A, B, 5, 5, 1);
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int j = 0; j < 5; j++)
            printf ("%d ", resultInt[i][j]);
    }
    printf("\n");

    mul(resultDouble, C, D, 5, 5, 0);
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int j = 0; j < 5; j++)
            printf ("%f ", resultDouble[i][j]);
    }
    printf("\n");

}

void add (void *result, void *A, void *B, int n, int m, int is_int) {
    if (is_int == 1) {
        int **tempA = new int*[n];
        int **tempB = new int*[n];
        int **tempResult = new int*[n];
        for (int i = 0; i < n; i++) { 
            tempA[i] = new int[m];
            tempB[i] = new int[m];
            tempResult[i] = new int[m];
         }
         tempA = (int**)A;
         tempB = (int**)B;
         tempResult = (int**)result;

         for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tempResult[i][j] = tempA[i][j] + tempB[i][j];
    }
    else {
        double **tempA = new double*[n];
        double **tempB = new double*[n];
        double **tempResult = new double*[n];
        for (int i = 0; i < m; i++) {
            tempA[i] = new double[m];
            tempB[i] = new double[m];
            tempResult[i] = new double[m];
         }
         tempA = (double**)A;
         tempB = (double**)B;
         tempResult = (double**)result;

         for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tempResult[i][j] = tempA[i][j] + tempB[i][j];

    }
}

void mul (void *result, void *A, void *B, int n, int m, int is_int) {
        if (is_int == 1) {
        int **tempA = new int*[n];
        int **tempB = new int*[n];
        int **tempResult = new int*[n];
        for (int i = 0; i < n; i++) { 
            tempA[i] = new int[m];
            tempB[i] = new int[m];
            tempResult[i] = new int[m];
         }
         tempA = (int**)A;
         tempB = (int**)B;
         tempResult = (int**)result;

         for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int z = 0; z < m; z++)
                tempResult[i][j] += tempA[i][z] * tempB[z][j];
    }
    else {
        double **tempA = new double*[n];
        double **tempB = new double*[n];
        double **tempResult = new double*[n];
        for (int i = 0; i < m; i++) {
            tempA[i] = new double[m];
            tempB[i] = new double[m];
            tempResult[i] = new double[m];
         }
         tempA = (double**)A;
         tempB = (double**)B;
         tempResult = (double**)result;

         for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int z = 0; z < m; z++)
                tempResult[i][j] += tempA[i][z] * tempB[z][j];

    }

}


