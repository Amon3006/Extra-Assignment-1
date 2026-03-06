#include<iostream>
using namespace std;

class Matrix {
    private:
    int **mat;
    int row;
    int col;

    public:
    Matrix(){
        this->row =1;
        this->col=1;
        mat = new int*[1];
        mat[0] = new int(0);
    }

    Matrix(const int row,int col){
        this->row = row;
        this->col = col;
        mat = new int*[row];
        for (int i = 0; i < row; i++)
            {
                mat[i] = new int[col]();
            } 
        }

    void Accept(){
        for(int i = 0 ; i< row ;i++){
            for (int j = 0; j < col; j++)
            {
                cout<<"Enter element at pos"<<i+1<<','<<j+1<<" : ";
                cin>>mat[i][j];
            }
        }

    }




    void setElement(int i, int j, int num){
        mat[i][j] = num;
    }

    void setCol(int col){
        this->col =col;
    }

    void setRow(int Row){
        this->row =row;
    }

    void transpose(){
        Matrix temp(this->col,this->row);
        for(int i = 0 ; i< row;i++){
            for (int j = 0; j < col; j++)
            {
              temp.setElement(j,i,mat[i][j]);   
            }     
        }

        temp.display();

        
    }

    void display(){
        for(int i = 0 ; i< row ;i++){
            for (int j = 0; j < col; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};



int main(){

    int row,col;

    
    cin>>row;
    cin>>col;

    Matrix m1(row,col);

    m1.Accept();
    m1.display();
    m1.transpose();

}

