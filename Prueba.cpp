/*
#include <iostream>
#include <enrutador.h>
#include <red.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int menorValor(string origen, string destino, map<string, map<string, int>> Enrutadores);
vector<string> menorRuta(string origen, string destino, map<string, map<string, int>> Enrutadores);

int main()
{
    Enrutador enrutadorA("A"), enrutadorB("B"), enrutadorC("C"), enrutadorD("D");
    Red red;
    enrutadorA.AgrEnlace(enrutadorB.getNombre(),1);
    enrutadorA.AgrEnlace(enrutadorC.getNombre(),10);
    enrutadorB.AgrEnlace(enrutadorA.getNombre(),1);
    enrutadorB.AgrEnlace(enrutadorD.getNombre(),12);
    enrutadorC.AgrEnlace(enrutadorA.getNombre(),10);
    enrutadorC.AgrEnlace(enrutadorD.getNombre(),1);
    enrutadorD.AgrEnlace(enrutadorB.getNombre(),12);
    enrutadorD.AgrEnlace(enrutadorC.getNombre(),1);
    red.AgregarEnrutador(enrutadorA);
    red.AgregarEnrutador(enrutadorB);
    red.AgregarEnrutador(enrutadorC);
    red.AgregarEnrutador(enrutadorD);
    red.mostrarMapa();
    cout<<menorValor(enrutadorA.getNombre(),enrutadorD.getNombre(),red.getEnrutadores())<<endl;
    vector<string> ruta = menorRuta(enrutadorA.getNombre(),enrutadorD.getNombre(),red.getEnrutadores());
    for (int i = 0; i < ruta.size(); i++) {
        cout << ruta[i];
        if (i != ruta.size() - 1) {
            cout << " -> ";
        }

    }
    cout<<endl;

    return 0;
}


int menorValor(string origen, string destino, map<string, map<string, int>> Enrutadores) {
    // Creamos una cola de prioridad para almacenar los nodos por visitar
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Creamos un mapa para almacenar el costo mínimo para cada nodo
    map<string, int> costos;

    // Inicializamos todos los costos como infinito excepto el origen, que tiene costo 0
    for (auto const& [nodo, enlaces] : Enrutadores) {
        costos[nodo] = (nodo == origen) ? 0 : INT_MAX;
    }

    // Agregamos el nodo origen a la cola de prioridad
    pq.push(make_pair(0, origen));

    // Mientras haya nodos por visitar
    while (!pq.empty()) {
        // Obtenemos el nodo con el costo mínimo
        string actual = pq.top().second;
        pq.pop();

        // Si ya visitamos el nodo destino, retornamos su costo mínimo
        if (actual == destino) {
            return costos[actual];
        }

        // Para cada nodo adyacente al nodo actual
        for (auto const& [nodo, costo] : Enrutadores[actual]) {
            // Si el costo desde el origen hasta el nodo adyacente a través del nodo actual es menor al costo mínimo anterior
            if (costos[actual] + costo < costos[nodo]) {
                // Actualizamos el costo mínimo del nodo adyacente
                costos[nodo] = costos[actual] + costo;

                // Agregamos el nodo adyacente a la cola de prioridad
                pq.push(make_pair(costos[nodo], nodo));
            }
        }
    }

    // Si no se pudo encontrar un camino desde el origen al destino, retornamos -1
    return -1;
}

vector<string> menorRuta(string origen, string destino, map<string, map<string, int>> Enrutadores) {
    // Inicializamos una cola de prioridad con el nodo origen y su costo 0
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, origen));

    // Inicializamos el mapa de padres para poder reconstruir la ruta después
    map<string, string> Nodos;
    Nodos[origen] = "";

    // Inicializamos los costos de todos los nodos como infinito
    map<string, int> costos;
    for (auto const& [nodo, _] : Enrutadores) {
        costos[nodo] = INT_MAX;
    }

    // La distancia del origen a sí mismo es 0
    costos[origen] = 0;


    // Algoritmo de Dijkstra
    while (!pq.empty()) {
        // Obtenemos el nodo con el costo mínimo
        string actual = pq.top().second;
        pq.pop();

        // Si ya visitamos el nodo destino, retornamos la ruta
        if (actual == destino) {
            vector<string> ruta;
            ruta.push_back(actual);
            while (Nodos[actual] != "") {
                actual = Nodos[actual];
                ruta.insert(ruta.begin(), actual);
            }
            return ruta;
        }

        // Para cada nodo adyacente al nodo actual
        for (auto const& [nodo, costo] : Enrutadores[actual]) {
            // Si el costo desde el origen hasta el nodo adyacente a través del nodo actual es menor al costo mínimo anterior
            if (costos[actual] + costo < costos[nodo]) {
                // Actualizamos el costo mínimo del nodo adyacente y su padre
                costos[nodo] = costos[actual] + costo;
                Nodos[nodo] = actual;

                // Agregamos el nodo adyacente a la cola de prioridad
                pq.push(make_pair(costos[nodo], nodo));
            }
        }
    }
    // Si no se pudo llegar al nodo destino, retornamos una ruta vacía
    return {};
}
*/




