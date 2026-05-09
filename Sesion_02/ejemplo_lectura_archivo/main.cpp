#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ------------------------------------------------------------
// Función auxiliar para crear el archivo de ejemplo si no existe
// ------------------------------------------------------------
void crearArchivoSiNoExiste() {
    ifstream prueba("datos.txt");
    if (prueba) {
        prueba.close();
        return;  // ya existe, no hacer nada
    }
    // El archivo no existe, lo creamos con contenido de ejemplo
    ofstream crear("datos.txt");
    if (crear) {
        crear << "Esta es la linea 1 del archivo de ejemplo.\n";
        crear << "Linea 2: persiste despues de la ejecucion.\n";
        crear.close();
        cout << "[Info] Archivo datos.txt creado automáticamente con contenido de ejemplo.\n";
    } else {
        cerr << "[Error] No se pudo crear el archivo datos.txt\n";
    }
}

int main() {
    // Aseguramos que el archivo existe antes de ejecutar el código original
    crearArchivoSiNoExiste();

    // ============================================================
    ifstream f("datos.txt");
    if (!f) {
        cout << "Error abriendo archivo.\n";
        return 1;
    }
    string linea;
    while (getline(f, linea))
        cout << linea << endl;
    f.close();
    // ============================================================

    return 0;
}