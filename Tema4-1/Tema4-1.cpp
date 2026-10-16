// Oscar Silva Urbina
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "Set.h"
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
string resolver_rec(string num, Set<string>& s, vector <string> v) {
    v.push_back(num);
    //ver si ya esta contenido
    if (s.contains("1")) {
        string resultado = "";
        for (int i = 0; i < v.size(); i++) {
            resultado += v[i] + (i == v.size() - 1 ? " 1" : " ");
        }
        return resultado;
    }

    //ver si se repite numero, si asi es numero infeliz
    if (s.contains(num)) {
        string resultado = "";
        for (int i = 0; i < v.size(); i++) {
            resultado += v[i] + " ";
        }
        return resultado + "0";
    }

    s.add(num);

    //separar cifras y elevar al cuadrado
    int aux = 0;
    for (char c : num) {
        if (isdigit(c)) {
            int cifra = c - '0';
            aux += pow(cifra, 2);
        }
    }
    num = to_string(aux);
    return resolver_rec(num,s,v);
}

string esFeliz(string num) {
    Set<string>s;
    vector<string> pasos;
    return resolver_rec(num, s, pasos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    //version string
    string num;
    cin >> num;
    if (!std::cin)
        return false;

    cout << esFeliz(num) << endl;
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