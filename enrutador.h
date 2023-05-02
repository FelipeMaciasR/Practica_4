#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <string>
#include <map>

using namespace std;

class Enrutador
{
    string nombre;
    map<string, int> TabladeEnrutamiento;

public:
    Enrutador(string Nombre);
    void AgrEnlace(string enrutador, int costo);
    void ElimEnlace(string enrutador);
    void ModCosto(string enrutador, int nuevocosto);
    void MostrarTabla();

    string getNombre() const;
    void setNombre(const string &newNombre);
    map<string, int> getTabladeEnrutamiento() const;
    void setTabladeEnrutamiento(const map<string, int> &newTabladeEnrutamiento);
};

#endif // ENRUTADOR_H
