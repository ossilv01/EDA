// Oscar Silva Urbina
//Coste O(log n) 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
bool resolver(const vector <int> &sec, int num, int ini, int fin) {
    int n = fin - ini; 
    //caso base 
    if (n == 0) return false; 
    if (n == 1) return sec[ini] == num;

    int mitad = (ini + fin) / 2; 

    //caso elemento encontrado en mitad. Solo revisa por si da SI
    if (sec[mitad] == num) return true;

    //Vector Ordenado Rotado. AL MENOS 1 de las 2 mitades estará correctamente ORDENADA
    //Ej: (22, 2, 4 ,8) 
    // Mitad Izq: MAL    Mitad Dcha: BIEN
    //Comparamos inicio y mitad: 1º Comprobante
    //Revisamos si valor buscado esta dentro de ese rango, si no es asi, es que esta en el lado DCHO

    // Lado izq bien ordenado. Lado dcho rotado
    if (sec[ini] <= sec[mitad]) {
        if (num >= sec[ini] && num < sec[mitad]) {
            return resolver(sec, num, ini, mitad);
        }
        else return resolver(sec, num, mitad+1, fin);
    }
    else {
    // Lado dcho bien ordenado. Lado izq rotado
        if (num > sec[mitad] && num <= sec[fin - 1]) {
            return resolver(sec, num, mitad+1, fin);
        }
        else return resolver(sec, num, ini, mitad);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n;
    if (n == -1)
        return false;
    vector <int> sec(n);
    int num;
    cin >> num; 
    for (int& a : sec) cin >> a;   
    // escribir sol
    cout << (resolver(sec, num, 0, n)? "SI": "NO") << "\n";
    return true;

}

////num es menor que todos los numeros de la derecha
//if ((num < sec[mitad] && num < sec[fin-1]) 
////num es mayor que todos los numeros de la derecha
//    || (num > sec[mitad] && num > sec[fin -1]) 
////num esta en el rango de la izq? 
//     || (num < sec[mitad] && num > sec[ini]))
//    return resolver(sec, num, ini, mitad);
//else return resolver(sec, num, mitad, fin);

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
