/*
Oscar Silva Urbina
EDA63
Coste:
El coste es de O(n) siendo n el numero de nodos, pues se visita cada uno de los nodos del arbol una vez
y se realizan operaciones de coste constante O(1) sobre ellos. 
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


struct Resultado {
    int enanos; //tamaño grupo
    string lider; //lider actual del grupo
};


//funcion que calcula el nodo de union entre enanos
Resultado unirGrupos(Resultado const& izq, Resultado const& dcha) {
    //si uno de los grupos desaparece, sobrevive el otro
    if(izq.enanos == 0) return dcha;
    if (dcha.enanos == 0) return izq;

    Resultado res;
    //nuevo gruupo resultado de union enanos ambos grupos
    res.enanos = izq.enanos + dcha.enanos;

    //Decision de lider = el grupo más numerosos
    if (izq.enanos > dcha.enanos)
        res.lider = izq.lider;
    else if (dcha.enanos > izq.enanos)
        res.lider = dcha.lider;
    else
        //si emapatan, es el menor alfabeticamente
        res.lider = min(izq.lider, dcha.lider);

    return res;
}

// función que resuelve el problema y justificación del coste
Resultado viaje(bintree<string> const& arbol) {

    //Casos base vacio

    if (arbol.empty()) {
        return { 0, " " };
    }

    //Caso base nodo hoja, 1 solo enano
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 1, arbol.root() };
    }

 
    Resultado izq = viaje(arbol.left());
    Resultado der = viaje(arbol.right());

    //Nodo de unin
    Resultado res = unirGrupos(izq, der);

    // si hay orcos, los enanos pierden lamitad
    if (arbol.root() == "Orcos") {

        res.enanos /= 2;
        //si no queda ningun enano el grupo desaparece
        if (res.enanos == 0)
            return { 0, "" };
    }

    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de datos de entrada
    bintree<string> a = leerArbol(string("."));

    // Llamada a la función
    Resultado viaje_final= viaje(a);
    // Escritura del resultado
    //caso base ningun enano
    if (viaje_final.enanos == 0) {
       cout << "Ninguno" << endl;
    }
    else {
        cout << viaje_final.lider << " " << viaje_final.enanos << endl;
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