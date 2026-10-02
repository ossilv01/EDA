//Oscar Silva Urbina
//Coste: O(log n) por el if condicional que restringe la busqueda a la mitad del contenido
//de ambos vectores

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
using namespace std;


// función que resuelve el problema y justificación del coste
 pair <bool, int> re(vector <int>& secA, vector <int>& secD, int ini, int fin) {
    int mitad = (ini + fin) / 2;
    int n = fin - ini; 

    //Caso base un elemento en ambos vectores
    if (n == 1) {
        //si lo son, return true
        if (secA[ini] == secD[ini]) return { true, secA[ini] };
        //si no false
        else return { false, secA[ini] };
    }

    //Caso estudio justo mitad se cruzan
    if (secA[mitad] == secD[mitad]) return { true, secA[ini]};

    //si elemento ascendente es mayor que el descendente. Buscamos izquierda
    if (secA[mitad] > secD[mitad]) {
        return re(secA, secD, ini, mitad);
    }
    //Si no buscamos en la derecha
    else {
        return re(secA, secD, mitad, fin);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> secAsc(n), secDesc(n);
    for (int& e : secAsc) cin >> e;
    for (int& e : secDesc) cin >> e;

    // Llamada a la función/Solucinon
    auto resultado = re(secAsc, secDesc, 0, n);
    std::cout << (resultado.first ? "SI" : "NO") << " " << resultado.second;
    cout << endl; 
    //cout << re(secAsc, secDesc, 0, n).first << " " << re(secAsc, secDesc, 0, n).second;
    //cout << endl; 

    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}