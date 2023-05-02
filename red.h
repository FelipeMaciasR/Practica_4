#ifndef RED_H
#define RED_H
#include <string>
#include <map>
#include "enrutador.h"

class Red
{
    map<string, map<string, int>> enrutadores;
public:
    Red();
    void AgregarEnrutador(Enrutador enrutador);
    void EliminarEnrutador(string nombreEnrutador);
    void mostrarMapa();
    map<string, map<string, int> > getEnrutadores() const;
    void setEnrutadores(const map<string, map<string, int> > &newEnrutadores);
};

#endif // RED_H
