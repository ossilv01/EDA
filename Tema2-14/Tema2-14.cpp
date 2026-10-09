// Oscar Silva Urbina
//Coste: O(logn)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
int ultimo(vector <int> &sec, int ini, int fin) {
    int n = fin - ini; 
    //Caso base 1 elemento en vector
    if (n == 1) return sec[ini];

    //O una llamada recursiva u otra
    int mitad = (ini + fin) / 2;
    if (sec[mitad] == sec[0] + mitad) {
        //mira derecha
        return ultimo(sec, mitad, fin);
    }
    //mira izquierda
    else return ultimo(sec, ini, mitad);
    
    //Esta genial, pero, habria un problema si hubiese otra supuesta secuencia en el vector
    //Ejemplo: (1,2,24,25,78) Ya que se menciona que empieza de manera ascendente
    //asi que la primera secuencia es la que importa, y de ahi se puede aplicar
    //la logica de que si el valor que tiene no es equivalente al del valor
    // que se supone que tiene que tener por la posicion que es, da igual si es que es uno menos que el anterior
    // no es LA SECUENCIA que estamos contando 

   /* if (pivote - 1 != sec[mitad - 1]) {
        return ultimo(sec, ini, mitad);
       
    }
    else  return ultimo(sec, mitad, fin); */
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n; 
    vector <int> sec(n);
    for (int& a : sec)  cin >> a;
    //for (int b : sec) cout << b << " ";
    //cout << endl; 
    cout << ultimo(sec, 0, n) << endl; 
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