#include <iostream>

using namespace std;

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int A[][100], int B[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[][100], int B[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void scalarMultiply(int matrix[][100], int scalar, int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void matrixMultiply(int A[][100], int B[][100], int result[][100], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[100][100], B[100][100], result[100][100];
    int rowsA, colsA, rowsB, colsB, choice, scalar;
    bool exit = false;

    cout << "Masukkan jumlah baris matriks A: ";
    cin >> rowsA;
    cout << "Masukkan jumlah kolom matriks A: ";
    cin >> colsA;

    cout << "Masukkan elemen matriks A:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Masukkan jumlah baris matriks B: ";
    cin >> rowsB;
    cout << "Masukkan jumlah kolom matriks B: ";
    cin >> colsB;

    cout << "Masukkan elemen matriks B:" << endl;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    while (!exit) {
        cout << "Pilih operasi yang ingin Anda lakukan:" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian Skalar" << endl;
        cout << "4. Perkalian Matriks" << endl;
        cout << "5. Keluar" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrix(A, B, result, rowsA, colsA);
                    cout << "Hasil penjumlahan matriks A dan B adalah:" << endl;
                    printMatrix(result, rowsA, colsA);
                } else {
                    cout << "Matriks A dan B harus memiliki ukuran yang sama untuk penjumlahan." << endl;
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrix(A, B, result, rowsA, colsA);
                    cout << "Hasil pengurangan matriks A dan B adalah:" << endl;
                    printMatrix(result, rowsA, colsA);
                } else {
                    cout << "Matriks A dan B harus memiliki ukuran yang sama untuk pengurangan." << endl;
                }
                break;

            case 3:
                cout << "Masukkan nilai skalar: ";
                cin >> scalar;
                scalarMultiply(A, scalar, result, rowsA, colsA);
                cout << "Hasil perkalian skalar matriks A adalah:" << endl;
                printMatrix(result, rowsA, colsA);
                break;

            case 4:
                if (colsA == rowsB) {
                    matrixMultiply(A, B, result, rowsA, colsA, colsB);
                    cout << "Hasil perkalian matriks A dan B adalah:" << endl;
                    printMatrix(result, rowsA, colsB);
                } else {
                    cout << "Jumlah kolom matriks A harus sama dengan jumlah baris matriks B untuk perkalian matriks." << endl;
                }
                break;

            case 5:
                exit = true;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
