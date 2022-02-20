#include "MatrixMultiplication.h"
#define MIN(a,b) ((a) < (b) ? (a) : (b))

void matrixMult1(const std::vector<std::vector<int> >& a, const std::vector<std::vector<int> >& b, std::vector<std::vector<int> >& result, const int n) {
    /* jki */
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            int r = b[k][j];
            for(int i = 0; i < n; i++) {
                result[i][j] += a[i][k] * r;
            }
        }
    }
}

void matrixMult2(const std::vector<std::vector<int> >& a, const std::vector<std::vector<int> >& b, std::vector<std::vector<int> >& result, const int n) {
    /* ijk */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = 0;
            for(int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void matrixMult3(const std::vector<std::vector<int> >& a, const std::vector<std::vector<int> >& b, std::vector<std::vector<int> >& result, const int n){
    /* ikj */
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            int r = a[i][k];
            for(int j = 0; j < n; j++) {
                result[i][j] += r * b[k][j];
            }
        }
    }
}

void blockingMatrixMult(const std::vector<std::vector<int> >& a, const std::vector<std::vector<int> >& b, std::vector<std::vector<int> >& result, const int n, const int block_size) {
    int min_outer;
    int sum;
    int min_inner;

    for(int kk = 0; kk < n; kk += block_size) {
        for(int jj = 0; jj < n; jj += block_size) {
            for(int i = 0; i < n; i++) {
                min_outer = MIN(jj + block_size - 1, n - 1);
                for(int j = jj; j <= min_outer; j++) {
                    sum = 0; 
                    min_inner = MIN(kk + block_size - 1, n - 1);
                    for(int k = kk; k <= min_inner; k++) {
                        sum += a[i][k] * b[k][j];
                    }
                    result[i][j] += sum;
                }
            }
        }
    }
}
