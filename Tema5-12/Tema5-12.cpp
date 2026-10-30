//Oscar Silva Urbina
//Coste: O(n) Debido a las busquedas lineales que se realizan hasta encontrar los valores de A y B
//donde pues se observa el peor caso de que recorra de principio a fin. 
//Contamos tambien la accion de reenlazado de nodos, pero que se trata de asignaciones directtas es decir que son de O(1)
//haciendo por ello que el Maximo de todos sea O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void cuela(const T& a, const T& b) {
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
        Nodo* nodoA = this->prim;
        //buscamos A hasta encontrarlo
        while (nodoA != nullptr && nodoA->elem != a) {
            nodoA = nodoA->sig;
        }

        if (nodoA == nullptr) return;
        //buscamos B (despues del primer a) 
        //guardamos posicion de donde esta A (que seria su el nodo previo de B) para B para luego moverlo
        Nodo* prevB = nodoA;
        Nodo* nodoB = nodoA->sig;

        while (nodoB != nullptr && nodoB->elem != b) {
            prevB = nodoB;
            nodoB = prevB->sig;
        }

        // Caso critico de si b no existe despues de A o si ya B estaba despues de A y por tanto no hay que mover nada
        if (nodoB == nullptr || nodoA->sig == nodoB) return;

        //mover a B de sitio: 
        prevB->sig = nodoB->sig;

        //ultimo elemento de la lista
        if (nodoB == this->ult) {
            this->ult = prevB;
        }

        //insercion de  b despues de A
        nodoB->sig = nodoA->sig;
        nodoA->sig = nodoB;

    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1) {
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a, b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return true;
}

//#define DOMJUDGE
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
