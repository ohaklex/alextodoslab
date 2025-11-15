#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "===== MENU =====\n";
        cout << "1. Clasificar numeros\n";
        cout << "2. Ordenar archivos (pares/impares)\n";
        cout << "3. Ver resultados\n";
        cout << "4. Salir\n";
        cout << "Elige opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            ifstream archivo("datos.txt");

            if (!archivo.is_open()) {
                cout << "ERROR: datos.txt no existe!\n\n";
            } else {
                int n;
                ofstream pares("pares.txt");
                ofstream impares("impares.txt");

                while (archivo >> n) {
                    if (n % 2 == 0) pares << n << endl;
                    else impares << n << endl;
                }

                archivo.close();
                pares.close();
                impares.close();

                cout << "Numeros clasificados en pares.txt e impares.txt\n\n";
            }
        }

        else if (opcion == 2) {
            cout << "\n=== Ordenando archivos ===\n";

            ifstream pares("pares.txt");
            ifstream impares("impares.txt");

            if (!pares.is_open() || !impares.is_open()) {
                cout << "ERROR: Primero debes clasificar numeros!\n\n";
            } else {
                cout << "Archivos verificados. (No hay orden extra)\n\n";
            }
        }

        else if (opcion == 3) {
            cout << "\n=== RESULTADOS ===\n";

            ifstream pares("pares.txt");
            ifstream impares("impares.txt");

            cout << "\n--- pares.txt ---\n";
            if (pares.is_open()) {
                int x;
                while (pares >> x) cout << x << " ";
                pares.close();
            } else cout << "No existe pares.txt";

            cout << "\n\n--- impares.txt ---\n";
            if (impares.is_open()) {
                int x;
                while (impares >> x) cout << x << " ";
                impares.close();
            } else cout << "No existe impares.txt";

            cout << "\n\n";
        }

    } while (opcion != 4);

    return 0;
}
