#include <iostream>
#include <stdexcept>
using namespace std;

// ------------------------------------------------------------
// CLASE BASE ABSTRACTA: Figura
// Define la interfaz común para todas las figuras.
// ------------------------------------------------------------
class Figura {
public:
    virtual double area() const = 0;   // método virtual puro
    virtual ~Figura() = default;       // destructor virtual necesario
};

// ------------------------------------------------------------
// CLASE DERIVADA: Circulo (es una Figura)
// ------------------------------------------------------------
class Circulo : public Figura {
    double r;   // radio
public:
    Circulo(double x) {
        r = x;
        // Lanza excepción si el radio es negativo (contrato de la clase)
        if (r < 0) throw invalid_argument("radio negativo");
    }
    double area() const override {
        return 3.14159 * r * r;
    }
};

int main() {
    try {
        // Upcast: puntero de Figura apunta a un objeto Circulo
        Figura* f = new Circulo(2.0);
        cout << f->area() << endl;   // polimorfismo en acción
        delete f;                    // liberar memoria (importante)
    } catch (const exception& e) {   // captura cualquier excepción estándar
        cout << e.what() << endl;
    }
    return 0;
}