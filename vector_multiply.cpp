#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void matrix_product() {
	int matrix1_rownum = 200;
	int matrix1_colnum = 5000;
	int matrix1_size = matrix1_colnum * matrix1_rownum;
    float* vector1 = (float*)calloc(matrix1_size,sizeof(float));
    for (int i=0; i<matrix1_size; ++i){
        vector1[i] = 0.01;
    }
 
    int matrix2_rownum = 5000;
    int matrix2_colnum = 200;
    int matrix2_size = matrix2_rownum * matrix2_colnum;
    float* vector2 = (float*)calloc(matrix2_size,sizeof(float));
    for (int i=0; i<matrix2_size; ++i){
        vector2[i] = 0.02;
    }
    
    int matrix3_size=matrix1_rownum * matrix2_colnum;
    float* vector3 = (float*)calloc(matrix3_size, sizeof(float));

    for(int row1 = 0; row1 < matrix1_rownum; ++row1){
        for(int col2 = 0; col2 < matrix2_colnum; ++col2){
            for(int col1 = 0; col1 < matrix1_colnum; ++col1){
                vector3[row1*matrix2_colnum+col2] += vector1[row1*matrix1_colnum+col1] * vector2[col1*matrix2_colnum+col2];
            }
        }
    }
}

void fill() {
	int vect_size = 100000000;
    vector<float> vector(vect_size, 0.01);
}

void vector_matrix_product() {
	int matrix1_rownum = 200;
	int matrix1_colnum = 5000;
	int matrix1_size = matrix1_colnum * matrix1_rownum;
    vector<float> vector1(matrix1_size, 0.01);
 
    int matrix2_rownum = 5000;
    int matrix2_colnum = 200;
    int matrix2_size = matrix2_rownum * matrix2_colnum;
    vector<float> vector2(matrix2_size, 0.02);
    
    int matrix3_size=matrix1_rownum * matrix2_colnum;
    vector<float> vector3(matrix3_size);

    for(int row1 = 0; row1 < matrix1_rownum; ++row1){
        for(int col2 = 0; col2 < matrix2_colnum; ++col2){
            for(int col1 = 0; col1 < matrix1_colnum; ++col1){
                vector3[row1*matrix2_colnum+col2] += vector1[row1*matrix1_colnum+col1] * vector2[col1*matrix2_colnum+col2];
            }
        }
    }
}

int main(int argc, char **argv)
{
    clock_t s = clock();

    matrix_product();

    clock_t e = clock();
    cout << double(e - s) / CLOCKS_PER_SEC << endl;
    return 0;
}
