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

    int opcion = 0,num,costo;
    vector<Enrutador> Enrutadores;
    vector<string> ruta;
    string nombre, nombre2;
    Red red;

    do {
        cout << "Menu" << endl;
        cout << "1. Agregar/Eliminar nodos" << endl;
        cout << "2. Agregar/Eliminar/Cambiar conexiones" << endl;
        cout << "3. Valor minimo de ruta" << endl;
        cout << "4. Ruta a tomar" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout<<"Desea agregar(1) o eliminar(2) nodos"<<endl;
                cin>>num;
                if(num==1){
                   cout<<"Ingrese el nombre del nodo"<<endl;
                   cin>>nombre;
                   Enrutadores.push_back(Enrutador(nombre));
                }
                else if(num==2){
                    cout<<"Ingrese el nombre del nodo"<<endl;
                    cin>>nombre;

                    for (auto nod : Enrutadores) {
                        map<string,int> tabla = nod.getTabladeEnrutamiento(); // crear una copia mutable de la tabla
                        for (auto it = tabla.begin(); it != tabla.end(); it++ ) {
                            if (it->first == nombre) {
                                it = tabla.erase(it); // eliminar y actualizar el iterador
                                break;
                            }
                        }
                        nod.setTabladeEnrutamiento(tabla); // actualizar la tabla del enrutador
                    }

                    for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                        if (it->getNombre()==nombre) {

                            Enrutadores.erase(it);
                            break;
                        }
                    }



                }

                else{
                    cout<<"Opcion invalida"<<endl;
                }

                break;
            case 2:
                cout<<"Desea agregar(1), eliminar(2) o cambiar(3) enlaces"<<endl;
                cin>>num;
                if(num==1){
                   cout<<"Ingrese el nombre del nodo origen"<<endl;
                   cin>>nombre;
                   cout<<"Ingrese el nombre del nodo destino"<<endl;
                   cin>>nombre2;
                   cout<<"Ingrese el valor del enlace"<<endl;
                   cin>>costo;

                   for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                       if (it->getNombre()==nombre) {
                           it->AgrEnlace(nombre2,costo);
                       }
                       else if (it->getNombre()==nombre2) {
                           it->AgrEnlace(nombre,costo);
                       }
                   }

                }
                else if(num==2){
                    cout<<"Ingrese el nombre del nodo origen"<<endl;
                    cin>>nombre;
                    cout<<"Ingrese el nombre del nodo destino"<<endl;
                    cin>>nombre2;

                    for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                        if (it->getNombre()==nombre) {
                            it->ElimEnlace(nombre2);
                        }
                        else if (it->getNombre()==nombre2) {
                            it->ElimEnlace(nombre);
                        }
                    }



                }
                else if(num==3){
                    cout<<"Ingrese el nombre del nodo origen"<<endl;
                    cin>>nombre;
                    cout<<"Ingrese el nombre del nodo destino"<<endl;
                    cin>>nombre2;
                    cout<<"Ingrese el nuevo valor del enlace"<<endl;
                    cin>>costo;
                    for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                        if (it->getNombre()==nombre) {
                            it->ModCosto(nombre2,costo);
                        }
                        else if (it->getNombre()==nombre2) {
                            it->ModCosto(nombre,costo);
                        }
                    }

                }
                else{
                    cout<<"Opcion invalida"<<endl;
                }
                break;
            case 3: 
                red.getEnrutadores().clear();
                for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                    red.AgregarEnrutador(*it);
                }
                red.mostrarMapa();
                cout<<"Ingrese el nombre del nodo origen"<<endl;
                cin>>nombre;
                cout<<"Ingrese el nombre del nodo destino"<<endl;
                cin>>nombre2;
                cout<<"El menor valor es: "<<menorValor(nombre,nombre2,red.getEnrutadores())<<endl;


                break;
            case 4:
                red.getEnrutadores().clear();
                for (auto it = Enrutadores.begin(); it != Enrutadores.end(); ++it) {
                    red.AgregarEnrutador(*it);
                }
                red.mostrarMapa();
                cout<<"Ingrese el nombre del nodo origen"<<endl;
                cin>>nombre;
                cout<<"Ingrese el nombre del nodo destino"<<endl;
                cin>>nombre2;
                cout<<"La ruta a tomar es: "<<endl;
                ruta = menorRuta(nombre,nombre2,red.getEnrutadores());
                for (int i = 0; i < ruta.size(); i++) {
                    cout << ruta[i];
                    if (i != ruta.size() - 1) {
                        cout << " -> ";
                    }

                }
                    break;
            case 5:
                cout << "Fin del programa" << endl;

                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while(opcion != 5);
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
