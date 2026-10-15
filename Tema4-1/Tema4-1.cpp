// Oscar Silva Urbina
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"
#include <string>
#include <cmath>
using namespace std; 

// función que resuelve el problema
//version int
//int resolver(int num) {
//    Set<int>s;
//    s.add(num);
//    if (s.contains(1)) {
//        return 1;
//    }
//    
//    num = 
//
//
//    resolver(num);
//}

//Version string
string resolver(string num) {
    Set<string>s;
    
    //ver si ya esta contenido
    if (s.contains("1")) {
        return num + "1";
    }

    //ver si se repite numero, si asi es numero infeliz
    if (s.contains(num)) {
        return num + "0";
    }

    s.add(num);

    vector <int> cifras; 
    for (char c : num) {
        if (isdigit(c)) {
            int cifra = c - '0';
            cifras.push_back(cifra);
        }
    }
    int aux = 0; 
    for (int i = 0; i < cifras.size(); i++) {
        cifras[i] = pow(cifras[i], 2);
        aux += cifras[i];
    }
    num = to_string(aux);
    return resolver(num);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    //int num;
    //cin >> num;
    //version string
    string num;
    cin >> num;
    if (!std::cin)
        return false;

    cout << resolver(num) << endl;
    //Set(int n) s = resolver(datos);
    // escribir sol
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}