#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int **mat = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        mat[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            cout << "for pos" << i << ',' << j << " : ";
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            cout <<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < rows/2; i++)
    {
        for (int j = 0; j < cols/2; j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
        cout<<endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            cout <<mat[i][j]<<" ";
        }
        cout<<endl;
    }

}