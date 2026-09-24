// Oscar Silva Urbina 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std; 
//metodo recursivo 1 (complementario) 
int recomplementario(int dato) {
    int nexpo =0; 
    int aux = 0;
    int numfinal = 0; 
   
    while (dato/10 != 0) {
        aux = dato % 10;
        aux = 9 - aux;
        aux = aux * pow(10, nexpo);
        nexpo++;
        numfinal += aux;
        dato = dato / 10;
    }
    if (dato <= 9 || dato >= 0) {
        aux = 9 - dato;
        aux = aux * pow(10, nexpo);
        numfinal += aux;
    }
    return numfinal;
}
//metodo recursivo 2 (inverso) 
int reinverso(int dato) {
    int aux1 = dato; 
    int nexpo = 0; 
    int numfinal = 0;
    while (aux1 / 10 != 0) {
        aux1 = aux1/10; 
        nexpo++;
    }

    while (dato / 10 != 0) {
        aux1 = dato % 10;
        aux1 = aux1 * pow(10, nexpo);
        nexpo--;
        numfinal += aux1;
        dato = dato / 10;
    }
    if (dato <= 9 || dato >= 0) {
        numfinal += dato;
    }
    return numfinal;
}

// función que resuelve el problema
int resolver(int &datos) {
    int a = recomplementario(datos);
    int b = reinverso(a);
    cout << a << " " << b << endl; 
    return 0; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num; 
    //cout << num << endl; 
    resolver(num);
    //int sol = resolver(lol);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}