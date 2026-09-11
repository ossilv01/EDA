// Oscar Silva Urbina

#include <iostream>
#include <iomanip>
#include <fstream>

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {

int resolver(int datos) {

    //entradas validas de archivo
    int d; 
    d = datos * 2;
    return d;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int t;
    std::cin >> t;

    //fin de entrada
    if (!std::cin)
        return false;

    //operar y escribir solucion
    int sol = resolver(t);
    std::cout << sol <<std::endl;
    return true;

}

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