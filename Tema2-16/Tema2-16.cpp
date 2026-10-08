//Oscar Silva Urbina
//Coste: O(log n) donde n es es el numero de elementos de los vectores
// Utilizamos al estrategia divide y vencerás donde se divide el problema
// en mitades, las cuales mediante el uso de condiciones if, se restringe la busqueda a solo una de ellas,
//descartando totalmente la otra mitad. Realizando unicamente una unica llamada recursiva sobre la mitad conservada
//En resumen: Los ifs de casos base y los que restringe la busqueda tienen coste O(1)
// Luego el tamaño de problema pasa a n/2, tantas veces cuanto se pueda, es decir Log2(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct resultado {
    bool encontrado;
    int ini;
    int fin; 
};

resultado re(const vector <int>& secA, const vector <int>& secD, int ini, int fin) {
    int mitad = (ini + fin) / 2;
    int n = fin - ini;

    //Caso base un elemento en ambos vectores
    if (n == 1) {
        //si lo son, return true
        if (secA[ini] == secD[ini]) return { true, ini };
        //CASO CORTE MÁS A LA DERECHA: ascendente sigue siendo menor incluso al final del vector
        else if (secA[mitad] < secD[mitad]) return { false, fin - 1, fin };

        //Caso corte a la izquierda (-1, 0). Ascendente ya era mayor que la descendente desde el 0
        else if (secA[mitad] > secD[mitad]) return { false, ini-1, ini };
    }

    //Caso estudio justo mitad se cruzan
    if (secA[mitad] == secD[mitad]) return { true, mitad};

    //si elemento ascendente es mayor que el descendente. Buscamos izquierda
    if (secA[mitad] > secD[mitad]) {
        return re(secA, secD, ini, mitad);
    }
    //Si no buscamos, eso significa que ascendente es menor que descendente y entonces buscamos por la derecha
    else {
        return re(secA, secD, mitad, fin);
    }

};



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
    resultado solucion = re(secAsc, secDesc, 0, n);
    if (solucion.encontrado) {
        cout << "SI" << " " << solucion.ini << endl;
    }
    else cout << "NO" << " " << solucion.ini << " " << solucion.fin << endl;

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