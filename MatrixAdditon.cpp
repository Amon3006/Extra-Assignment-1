#include<iostream>
using namespace std;

/*5. Write a menu driven C++ program to add, subtract and multiply 
given two matrices defined in class.
 Modify your program using operator overloading method.*/

class Matrix {
    private:
    int rows;
    int cols;
    int** data;

    public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns for the first matrix: ";
    cin >> rows >> cols;
    Matrix matrix1(rows, cols);
    matrix1.input();

    cout << "Enter number of rows and columns for the second matrix: ";
    cin >> rows >> cols;
    Matrix matrix2(rows, cols);
    matrix2.input();

    Matrix sum = matrix1 + matrix2;
    Matrix difference = matrix1 - matrix2;
    Matrix product = matrix1 * matrix2;

    cout << "Sum of the matrices:" << endl;
    sum.display();

    cout << "Difference of the matrices:" << endl;
    difference.display();

    cout << "Product of the matrices:" << endl;
    product.display();

    return 0;
}