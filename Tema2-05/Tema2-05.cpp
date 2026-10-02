//Oscar Silva Urbina
//Coste O(n) = Pues se hace un recorrido lineal cada vez que se revisa para ver si hay 
// numeros pares. Nos encontrariamos. Recorrido a N, recorrido a N/2, recorrido a N/4 cada vez que se pueda hacer mas pequeño
//O(n) + O (n/2) + O(n/ 4) + ... = O(n) 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


bool RECcaucasico(vector<int>& v, int ini, int fin, int &cont) {
    int n = fin - ini;

    //caso 1 solo elemento, donde por el enunciado es caúcasico
    if (ini == fin-1)  return true;

    ////solo pueden ser caucasicos aquellos que tengan 2^n tamaño, no impares, no pares como 6,10, no negativos
    //int a = v.size();
    ////comparacion de valor con su anterior con puerta AND
    //if (a < 0 || (a & (a - 1)) != 0) {
    //    return false;
    //}

    //rango de busqueda por segmenetos que actualiza
    int mitad = (ini+fin)/2;

    //Casos Base/Parada
    int contador = 0;
    int contaizq = 0; 
    int contadcha = 0; 

    //Buscamos pares
    for (int i = ini; i < fin; i++) {
        if (v[i] % 2 == 0 && i >= mitad) contadcha++;
        else if (v[i] % 2 == 0 && i < mitad) contaizq++;
    }
    //por si el vector esta totalmente lleno de elementos impares
   /* contador = contaizq + contadcha; 
    if (contador == 0) {
        return false; 
    }*/

    //Comprobacion recursiva
    bool izq = RECcaucasico(v, ini, mitad, contaizq);
    bool dcha = RECcaucasico(v, mitad, fin, contadcha);
    if (izq && dcha) {
        int sol = contaizq - contadcha;
        //valor absoluto
        if (sol < 0) sol = sol * -1;
        //condición caucasica
        if (sol > 2) return false;
        else return true;
    }
    else return false;
}

bool caucasico(vector<int>& v) {
    int contador;
    return RECcaucasico(v, 0, v.size(), contador);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    //imprimir datos
    //for (int a : sec) cout << a << " ";
    //cout << endl;

    //resultado
    cout << (caucasico(sec) ? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}