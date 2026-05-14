#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class TresEnRaya {
    private:
        char tablero[9];
        string jugador1, jugador2;
        char simboloActual;

    public:
        TresEnRaya(string nombre1, string nombre2) {
            jugador1 = nombre1;
            jugador2 = nombre2;
            simboloActual = 'X';
                for (int i = 0; i < 9; i++) {
                tablero[i] = '1' + i;
            }
        }

    void mostrarTablero() {
            cout << endl;
            cout << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
            cout << "---------" << endl;
            cout << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
            cout << "---------" << endl;
            cout << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
            cout << endl;
        }
        
    bool colocarFicha(int posicion) {
            if (posicion < 1 || posicion > 9) {
                cout << "posicion invalida, intenta de nuevo" << endl;
                return false;
            }
            if (tablero[posicion - 1] == 'X' || tablero[posicion - 1] == 'O') {
                cout << "esa casilla ya esta ocupada" << endl;
                return false;
            }
            tablero[posicion - 1] = simboloActual;
        return true;
    }
        char verificarGanador() {
        // filas
            if (tablero[0] == tablero[1] && tablero[1] == tablero[2]) return tablero[0];
            if (tablero[3] == tablero[4] && tablero[4] == tablero[5]) return tablero[3];
            if (tablero[6] == tablero[7] && tablero[7] == tablero[8]) return tablero[6];
        // columnas
            if (tablero[0] == tablero[3] && tablero[3] == tablero[6]) return tablero[0];
            if (tablero[1] == tablero[4] && tablero[4] == tablero[7]) return tablero[1];
            if (tablero[2] == tablero[5] && tablero[5] == tablero[8]) return tablero[2];
        // diagonales
            if (tablero[0] == tablero[4] && tablero[4] == tablero[8]) return tablero[0];
            if (tablero[2] == tablero[4] && tablero[4] == tablero[6]) return tablero[2];
            
        return ' ';
    }
    
        bool tableroLleno() {
            int count = 0;
                for (int i = 0; i < 9; i++) {
                    if (tablero[i] == 'X' || tablero[i] == 'O') {
                    count++;
                }
            }
                    if (count == 9) return true;
            return false;
        }   
        
        void reiniciar() {
                for (int i = 0; i < 9; i++) {
                    tablero[i] = '1' + i;
            }
         simboloActual = 'X';
        }
        
        void cambiarTurno() {
            if (simboloActual == 'X') {
                simboloActual = 'O';
            } else {
             simboloActual = 'X';
            }
        }
        
        char getSimbolo() { return simboloActual; }
        void setSimbolo(char s) { simboloActual = s; }
        
            string getNombreActual() {
                if (simboloActual == 'X') return jugador1;
                return jugador2;
            }
            
        string getJugador1() { return jugador1; }
        string getJugador2() { return jugador2; }
};

        void actualizarPuntaje(int* ptrPuntaje) {
        *ptrPuntaje = *ptrPuntaje + 1;
    }

    int main() {
            srand(time(0));
            
            string nombre1, nombre2;
                int puntaje1 = 0;
                int puntaje2 = 0;
                int* ptr1 = &puntaje1;
                int* ptr2 = &puntaje2;
                
                cout << "=== TRES EN RAYA ===" << endl;
                cout << "Jugador 1: ";
                cin >> nombre1;
                cout << "Jugador 2: ";
                cin >> nombre2;
                
            TresEnRaya juego(nombre1, nombre2);
            
            int opcion = 0;
                while (opcion != 3) {
                cout << "1. Jugar   2. Ver puntajes   3. Salir" << endl;
                cout << "Opcion: ";
                cin >> opcion;
                
                if (opcion == 1) {
                juego.reiniciar();
                
                    int r = rand() % 2;
                    if (r == 0) {
                        juego.setSimbolo('X');
                        cout << "Empieza " << nombre1 << " (X)" << endl;
                    } else {
                            juego.setSimbolo('O');
                        cout << "Empieza " << nombre2 << " (O)" << endl;
                }
                
                    char ganador = ' ';
                    while (ganador == ' ' && !juego.tableroLleno()) {
                        juego.mostrarTablero();
                        int pos;
                cout << juego.getNombreActual() << " elige posicion (1-9): ";
                cin >> pos;

                    bool resultado = juego.colocarFicha(pos);
                        if (resultado == true) {
                            ganador = juego.verificarGanador();
                        if (ganador == ' ') {
                            juego.cambiarTurno();
                        }
                    }
                }
                
                juego.mostrarTablero();
                
                if (ganador == 'X') {
                    cout << nombre1 << " gano!!" << endl;
                        actualizarPuntaje(ptr1);
                    } else if (ganador == 'O') {
                    cout << nombre2 << " gano!!" << endl;
                        actualizarPuntaje(ptr2);
                    } else {
                cout << "empate!" << endl;
            }
            
        cout << "Puntajes -> " << nombre1 << ": " << puntaje1 << "  " << nombre2 << ": " << puntaje2 << endl;
        
                    } else if (opcion == 2) {
                        cout << nombre1 << ": " << puntaje1 << endl;
                        cout << nombre2 << ": " << puntaje2 << endl;
                        
                    } else if (opcion == 3) {
                        cout << "chao!" << endl;
                        
                } else {
                    cout << "esa opcion no existe" << endl;
            }
        }
        
        return 0;
}
