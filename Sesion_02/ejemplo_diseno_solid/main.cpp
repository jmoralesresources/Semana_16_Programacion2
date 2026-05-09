#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------
// PRINCIPIOS SOLID APLICADOS:
// - DIP (Inversión de Dependencias): Servicio depende de INotificador (abstracción), no de Email.
// - OCP (Abierto/Cerrado): podemos añadir nuevos notificadores (SMS, Push) sin modificar Servicio.
// - Patrón utilizado: Delegate / Strategy (el comportamiento de notificar se delega en el inyectado).
// ------------------------------------------------------------

// Interfaz (abstracción) para los notificadores
class INotificador {
public:
    virtual void enviar(const string& m) = 0;
    virtual ~INotificador() = default;
};

// Clase de alto nivel (Servicio) que depende de la abstracción
class Servicio {
    INotificador* notif;
public:
    Servicio(INotificador* n) : notif(n) {}
    void notificar(const string& m) { notif->enviar(m); }
};

// Implementación concreta: Email
class Email : public INotificador {
public:
    void enviar(const string& m) override { cout << "[Email] " << m << endl; }
};

int main() {
    Email e;
    Servicio s(&e);
    s.notificar("Cierre de curso");
    return 0;
}