#include <iostream>

using namespace std;
void Input(int **array, int MatrixSize){
    bool TrueFalse;
    int n;
    cout << "Type the N number: ";
    cin >> n;

    for(int i(0); i<MatrixSize; i++){
        for (int j(0); j<MatrixSize; j++){
            TrueFalse = (rand() % 100) < 90;
            if(TrueFalse == 0){
                cout << "Element [" << i << "][" << j << "]=";
                cin >> array[i][j];
            }
            else
                array[i][j] = n;
        }
    }
}
void Print(int **array, int MatrixSize){
    for(int i(0); i<MatrixSize; i++){
        for (int j(0); j<MatrixSize; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void Mult(int **array1, int **array2, int **array3, int MatrixSize){
    for(int i(0); i<MatrixSize; i++){
        for (int j(0); j<MatrixSize; j++){
            array3[i][j]=(array1[i][j])*(array2[i][j]);
        }
    }
}
void menu(){
    cout << "-----------------" << endl;
    cout << "1-Input" << endl;
    cout << "2-Multiply" << endl;
    cout << "0-Exit" << endl;
    cout << "-----------------" << endl;
    cout << endl;
}

int main()
{
    int **array1, **array2, **array3;
    int MatrixSize;
    int button;
    bool hasMatrix=0;

    menu();

    while(1){
        cin >> button;
        switch (button){
            case 1:{
                cout << "Input the size of the matrix: ";
                cin >> MatrixSize;

                cout << "Matrix 1: " << endl;
                array1=new int*[MatrixSize];
                for(int i(0); i<MatrixSize; i++){array1[i]=new int[MatrixSize];}
                Input(array1, MatrixSize);

                cout << "Matrix 2: " << endl;
                array2=new int*[MatrixSize];
                for(int i(0); i<MatrixSize; i++){array2[i]=new int[MatrixSize];}
                Input(array2, MatrixSize);
                cout << "Press the next button: " << endl;

                hasMatrix=1;
                break;
            }
            case 2:{
                if(hasMatrix==1){
                    array3=new int*[MatrixSize];
                    for(int i(0); i<MatrixSize; i++){array3[i]=new int[MatrixSize];}

                    Mult(array1, array2, array3, MatrixSize);
                    cout << "The result is: " << endl;
                    Print(array3, MatrixSize);

                    for (int i(0); i<MatrixSize; i++)
                        delete [] array3[i];
                    delete [] array3;
                }
                else
                    cout << "Enter the matrix first!" << endl;
                break;
            }
            case 0:{
                exit(1);
            }
        }
    }
}
