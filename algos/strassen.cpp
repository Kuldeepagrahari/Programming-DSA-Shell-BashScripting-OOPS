#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Function to multiply two matrices using Strassen's Algorithm
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    // Base case
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
   
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));
    
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    
  
    vector<vector<int>> P1 = strassenMultiply(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> P2 = strassenMultiply(addMatrices(A21, A22), B11);
    vector<vector<int>> P3 = strassenMultiply(A11, subtractMatrices(B12, B22));
    vector<vector<int>> P4 = strassenMultiply(A22, subtractMatrices(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(addMatrices(A11, A12), B22);
    vector<vector<int>> P6 = strassenMultiply(subtractMatrices(A21, A11), addMatrices(B11, B12));
    vector<vector<int>> P7 = strassenMultiply(subtractMatrices(A12, A22), addMatrices(B21, B22));
    
   
    vector<vector<int>> C11 = subtractMatrices(addMatrices(addMatrices(P1, P4), P7), P5);
    vector<vector<int>> C12 = addMatrices(P3, P5);
    vector<vector<int>> C21 = addMatrices(P2, P4);
    vector<vector<int>> C22 = subtractMatrices(addMatrices(addMatrices(P1, P3), P6), P2);
    
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}


void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
   int n=16;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 10; // Generate random values between 0 and 9
            B[i][j] = rand() % 10;
        }
    }

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;


    vector<vector<int>> C = strassenMultiply(A, B);

    cout << "A * B:" << endl;
    printMatrix(C);

    // time: O(n^log(7))
}
