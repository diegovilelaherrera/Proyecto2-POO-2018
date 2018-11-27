#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include "sudoku.h"

using namespace std;


int main() {
    srand(time(NULL));
    int n;
    cout << "Seleccione el tamaño del tablero de sudoku (2 o 3)" << '\n';
    cin >> n;

    Sudoku *sudoku = new Sudoku(n);

    sudoku->mostrarMenu();
    sudoku->printTablero();

    while(true){
        sudoku->game();
    }

    delete sudoku;
}
