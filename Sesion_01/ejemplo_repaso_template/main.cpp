#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Definición mínima de la clase Figura
// ------------------------------------------------------------
class Figura {
public:
    virtual double area() const = 0;
    virtual ~Figura() = default;
};

// implementación concreta solo para la demostración
class Circulo : public Figura {
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double area() const override { return 3.14159 * radio * radio; }
};

template<typename T>
T maximo(T a, T b) { return a > b ? a : b; }
vector<unique_ptr<Figura>> figuras;
// ------------------------------------------------------------

int main() {
    // --- Ejemplo de uso de la función template maximo ---
    cout << "Maximo de 10 y 20: " << maximo(10, 20) << endl;
    cout << "Maximo de 3.14 y 2.71: " << maximo(3.14, 2.71) << endl;
    cout << "Maximo de 'perro' y 'gato': " << maximo(string("perro"), string("gato")) << endl;

    // --- Ejemplo de uso del vector de unique_ptr a Figura ---
    figuras.push_back(make_unique<Circulo>(5.0));
    figuras.push_back(make_unique<Circulo>(2.0));

    cout << "\nAreas de las figuras almacenadas:" << endl;
    for (const auto& ptr : figuras) {
        cout << " - " << ptr->area() << endl;
    }

    return 0;
}