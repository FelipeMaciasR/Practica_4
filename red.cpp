#include "red.h"
#include "enrutador.h"
#include <iostream>
using namespace std;


map<string, map<string, int> > Red::getEnrutadores() const
{
    return enrutadores;
}

void Red::setEnrutadores(const map<string, map<string, int> > &newEnrutadores)
{
    enrutadores = newEnrutadores;
}

Red::Red()
{

}

void Red::AgregarEnrutador(Enrutador enrutador) {
    enrutadores.insert(make_pair(enrutador.getNombre(), enrutador.getTabladeEnrutamiento()));
    cout << "El enrutador " << enrutador.getNombre() << " ha sido agregado a la red." << endl;
}

void Red::EliminarEnrutador(string nombreEnrutador){
    enrutadores.erase(nombreEnrutador);
}

void Red::mostrarMapa() {
    cout << "Mapa de enrutadores:" << endl;
    for (auto const& [nombre, tablaDeEnrutamiento] : enrutadores) {
        cout << "Nombre del enrutador: " << nombre << endl;
        cout << "Tabla de enrutamiento:" << endl;
        for (auto const& [enrutador, costo] : tablaDeEnrutamiento) {
            cout << enrutador << ": " << costo << endl;
        }
        cout << endl;
    }
}
