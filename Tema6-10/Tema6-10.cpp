/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
//Ayuda:
#include <algorithm>
using namespace std;


struct Resultado {
    int enanos;
    string lider;
};
// función que resuelve el problema y justificación del coste

Resultado viaje(bintree<string> const& arbol) {

    //Casos base:
    //Vacio:

    if (arbol.empty()) {
        return { 0, " " };
    }

    //Nodo hoja (aldea de enanos)
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 1, arbol.root() };
    }

    //Procesamiento PostOrden Resolver recursivamente


    //1.Unión caminos/grupos enanos
    //asignación


    //2. Evento del nodo actual
        //Division entera y grupo desaparece


}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de datos de entrada
    bintree<string> a = leerArbol(string("."));

    // Llamada a la función
    Resultado viaje_final= viaje(a);
    // Escritura del resultado

    if (viaje_final.enanos == 0) {
       cout << "Ninguno\n";
    }
    else {
        cout << viaje_final.lider << " " << viaje_final.enanos << "\n";
    }
    

}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}