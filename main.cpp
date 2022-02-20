#include "MatrixMultiplication.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

void printMatrix(vector<vector<int> > matrix, int n) {
    if(n > 3) return; // only print for small matrices
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    // File Read Operation
    ifstream ifs(argv[1]);
    // get the dimensions 
    int n; 
    ifs >> n;
    // initialize vectors 
    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > b(n, vector<int>(n));
    vector<vector<int> > res_initial(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ifs >> a[i][j]; 
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ifs >> b[i][j]; 
        }
    }

    ifs.close();

    // Matrix Mult 1
    vector<vector<int> > res = res_initial;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    matrixMult1(a, b, res, n);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    auto duration_mili = duration_cast<milliseconds>(end - start).count();
    cout << "Time (ms): " << duration_mili << endl;
    printMatrix(res, n);

    // Matrix Mult 2
    res = res_initial;
    start = high_resolution_clock::now();
    matrixMult2(a, b, res, n);
    end = high_resolution_clock::now();
    duration_mili = duration_cast<milliseconds>(end - start).count();
    cout << "Time (ms): " << duration_mili << endl;
    printMatrix(res, n);

    // Matrix Mult 3
    res = res_initial;
    start = high_resolution_clock::now();
    matrixMult3(a, b, res, n);
    end = high_resolution_clock::now();
    duration_mili = duration_cast<milliseconds>(end - start).count();
    cout << "Time (ms): " << duration_mili << endl;
    printMatrix(res, n);

    // Matrix Mult Blocking
    res = res_initial;
    const int block_size = 20;
    start = high_resolution_clock::now();
    blockingMatrixMult(a, b, res, n, block_size);
    end = high_resolution_clock::now();
    duration_mili = duration_cast<milliseconds>(end - start).count();
    cout << "Time (ms): " << duration_mili << endl;
    printMatrix(res, n);

    return 0;
}
