#include "enrutador.h"
#include <iostream>
using namespace std;



string Enrutador::getNombre() const
{
    return nombre;
}

void Enrutador::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

map<string, int> Enrutador::getTabladeEnrutamiento() const
{
    return TabladeEnrutamiento;
}

void Enrutador::setTabladeEnrutamiento(const map<string, int> &newTabladeEnrutamiento)
{
    TabladeEnrutamiento = newTabladeEnrutamiento;
}

Enrutador::Enrutador(string Nombre)
{
    this->nombre=Nombre;
}
void Enrutador::AgrEnlace(string enrutador, int costo){
    TabladeEnrutamiento.insert(pair<string, int>(enrutador, costo));
}
void Enrutador::ElimEnlace(string enrutador){
    TabladeEnrutamiento.erase(enrutador);
}
void Enrutador::ModCosto(string enrutador, int nuevocosto){
    TabladeEnrutamiento.at(enrutador) = nuevocosto;
}
void Enrutador::MostrarTabla(){
    for (auto const& [key, val] : TabladeEnrutamiento) {
        cout << "Destino: " << key << "  Costo: " << val << endl;
    }
}
