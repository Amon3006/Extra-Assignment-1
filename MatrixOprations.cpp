#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Matrix {
private:
    int mat[MAX_SIZE][MAX_SIZE];
    int rows, cols;

public:
    Matrix() : rows(0), cols(0) {}

    void getInput() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

        Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Dimensions must be the same for addition\n";
            return Matrix();
        }
        Matrix result;
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Dimensions must be the same for subtraction\n";
            return Matrix();
        }
        Matrix result;
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Error: Columns of first matrix must equal rows of second for multiplication\n";
            return Matrix();
        }
        Matrix result;
        result.rows = rows;
        result.cols = other.cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
}; // End of Matrix class

int main() {
    Matrix m1, m2, m3;
    cout << "Enter details for Matrix 1:\n";
    m1.getInput();
    cout << "Enter details for Matrix 2:\n";
    m2.getInput();

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add matrices\n";
        cout << "2. Subtract matrices\n";
        cout << "3. Multiply matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m3 = m1 + m2;
                cout << "Result of Addition:\n";
                m3.display();
                break;
            case 2:
                m3 = m1 - m2;
                cout << "Result of Subtraction:\n";
                m3.display();
                break;
            case 3:
                m3 = m1 * m2;
                cout << "Result of Multiplication:\n";
                m3.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}