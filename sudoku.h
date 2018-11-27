#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

vector<vector<int>> tresxtres = { {1, 2, 5, 6, 4, 7, 8, 8, 9},
                                  {0, 0, 0, 0, 0, 0, 1, 0, 2},
                                  {0, 7, 0, 9, 0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 2, 0, 1, 0, 3},
                                  {0, 0, 0, 0, 0, 0, 1, 0, 0},
                                  {0, 4, 0, 2, 0, 0, 1, 0, 0},
                                  {3, 0, 0, 0, 0, 0, 1, 0, 0},
                                  {2, 0, 0, 0, 1, 0, 1, 0, 1},
                                  {8, 3, 0, 0, 0, 0, 1, 0, 0} };

vector<vector<int>> dosxdos = { {0, 3, 0, 1},
                                {0, 0, 0, 2},
                                {0, 2, 0, 0},
                                {0, 0, 0, 0} };

class Sudoku{
public:
    Sudoku(int s) : n(s) {
        if(s == 2 || s == 3){
            size = s*s;
            llenarTablero();
        } else{
            cout << "No puede crearse el tablero de ese tamaño." << '\n';
        }
    }

    void mostrarMenu(){
        cout << "--------------------------" << '\n';
        cout << "Sudoku " << size << "x" << size << "\n\n";
    }

    void printTablero(){

        for(int i = 0; i < size; ++i){
            cout << "| ";
            for(int j = 0; j < size; ++j){
                if(tablero[i][j] == 0)
                    cout << "  ";
                else
                    cout << tablero[i][j] << ' ';
                if((j+1) % n == 0)
                    cout << "| ";
            }
            cout << '\n';
            if((i+1) % n == 0) {
                for(int k = 0; k < (size*3)-2; ++k)
                    cout << "-";
                cout << '\n';
            }

        }
    }

    void game(){
        int row, col, v;
        cout << "Ingresa las coordenadas separadas por un espacio donde quieras ingresar un numero: ";
        cin >> row >> col;
        cout << "Ingresa un valor entre 1 y 9: ";
        cin >> v;
        while (v < 0 || v > 9){
            cout << "Ingresa un valor entre 1 y 9: ";
            cin >> v;
        }

        tablero[row][col] = v;
        printTablero();

    }

private:

    vector<vector<int>> tablero;

    int size; // n * n
    int n; // Numero que se ingreso en el constructor

    int getRandom(){
        return (rand() % 9) + 1;
    }

    void llenarTablero(){

        tablero.resize(size, vector<int>(size));

        if (size == 3){
            tablero = tresxtres;
        }else {
            tablero = dosxdos;
        }
    }

};
