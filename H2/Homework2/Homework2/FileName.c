#include <stdio.h>
#define  MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;
typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows; // 행의 개수
    int cols; // 열의 개수
    int terms; // 항의 개수
} SparseMatrix;

SparseMatrix x1 = { {{1,1,5},{2,2,9}}, 3, 3, 2 };//(1, 1)에 5 위치, (2, 2)에 9 위치(나머지는 전부 0)
SparseMatrix y1 = { {{0,0,5},{2,2,9}}, 3, 3, 2 };

SparseMatrix x2 = { {{0,0,1},{0,1,2},{0,2,3},{1,0,1},{1,1,2},{1,2,3},{2,0,1},{2,1,2},{2,2,3}}, 3, 3, 9 };
SparseMatrix y2 = { {{0,0,1},{0,1,1},{0,2,1},{1,0,1},{1,1,1},{1,2,1},{2,0,1},{2,1,1},{2,2,1}}, 3, 3, 9 };

SparseMatrix x3 = { {{0,0,7},{0,2,2},{1,2,3},{2,0,7}}, 3, 3, 4 };
SparseMatrix y3 = { {{0,1,5},{0,2,8},{1,2,4},{2,0,4},{2,2,1}}, 3, 3, 5 };


//희소 행렬을 일반 행렬로 변환하는 함수
void sparseToDense(SparseMatrix sparse, int dense[][MAX_TERMS]) {
    for (int i = 0; i < sparse.rows; i++) {
        for (int j = 0; j < sparse.cols; j++) {
            dense[i][j] = 0; // 일단 모든 요소를 0으로 초기화
        }
    }

    for (int i = 0; i < sparse.terms; i++) {
        dense[sparse.data[i].row][sparse.data[i].col] = sparse.data[i].value;
    }
}


//행렬들을 곱해주는 함수
void matrixMultiply(int a[][MAX_TERMS], int b[][MAX_TERMS], int result[][MAX_TERMS], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}



//행렬을 출력하는 함수
void printMatrix(int mat[][MAX_TERMS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}


int main() {
    int result[MAX_TERMS][MAX_TERMS];

    // x1와 y1의 희소 행렬을 일반 행렬로 변환
    int dense_x1[3][3];
    int dense_y1[3][3];
    sparseToDense(x1, dense_x1);
    printf("x1: \n");
    printMatrix(dense_x1, x1.rows, x1.cols);
    printf("\n");
    sparseToDense(y1, dense_y1);
    printf("y1: \n");
    printMatrix(dense_y1, y1.rows, y1.cols);
    printf("\n");

    // 두 행렬을 곱하고 결과를 출력
    matrixMultiply(dense_x1, dense_y1, result, x1.rows, x1.cols, y1.cols);
    printf("x1 * y1 결과:\n");
    printMatrix(result, x1.rows, y1.cols);

    // x2와 y2의 희소 행렬을 일반 행렬로 변환
    int dense_x2[3][3];
    int dense_y2[3][3];
    sparseToDense(x2, dense_x2);
    printf("x2: \n");
    printMatrix(dense_x2, x2.rows, x2.cols);
    sparseToDense(y2, dense_y2);
    printf("y2: \n");
    printMatrix(dense_y2, y2.rows, y2.cols);


    // 두 행렬을 곱하고 결과를 출력
    matrixMultiply(dense_x2, dense_y2, result, x2.rows, x2.cols, y2.cols);
    printf("\nx2 * y2 결과:\n");
    printMatrix(result, x2.rows, y2.cols);

    // x3와 y3의 희소 행렬을 일반 행렬로 변환
    int dense_x3[3][3];
    int dense_y3[3][3];
    sparseToDense(x3, dense_x3);
    printf("x3: \n");
    printMatrix(dense_x3, x3.rows, x3.cols);
    sparseToDense(y3, dense_y3);
    printf("y3: \n");
    printMatrix(dense_y3, y3.rows, y3.cols);

    // 두 행렬을 곱하고 결과를 출력
    matrixMultiply(dense_x3, dense_y3, result, x3.rows, x3.cols, y3.cols);
    printf("\nx3 * y3 결과:\n");
    printMatrix(result, x3.rows, y3.cols);

    return 0;
}