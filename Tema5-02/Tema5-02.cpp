// Oscar Silva Urbina
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
//
//Conclusiones:
//Si se realiza de manera abstracta, es decir solo accediendo a dicho tipo de dato mediante 
// los propios metodos que tiene definidos.EN STACK Y QUEUE va a ser realmente dificil
//
//Lo ideal seria entonces usar algoritmos de ordenación o ver alguna forma de ordenarlo
// .En el primer intento con mi QUEUE utilice un algoritmo bubble sort, lo cual funciona, 
// pero claramente es ineficiente con un coste O(n ^ 2).Otra alternativa seria un MergeSort,
// aplicando recursion(algoritmos de ordenacion recursivos), pero eso seria 
// demasiado trabajoso para el problema sencillo dado.
//
//Asi que como definitiva, lo que hice fue utilizar la libreria algorithm 
// para poder utilizar el sort() con un vector auxiliar
//Luego tras tenerlo de vuelta en orden, seria pasarle el contenido de este
// al queue resultado que devolveremos en la funcion

using namespace std;
// función que resuelve el problema
queue <int> resolver(queue <int> datos) {
  
    vector <int> result;

    //caso base
    if (datos.empty()) return datos;

    while (!datos.empty()) {
        result.push_back(datos.front());
        datos.pop();
    }

    sort(result.begin(), result.end());

    queue<int> resultado;
    for (int a : result) {
        resultado.push(a);
    }
    return resultado;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n; 
    //caso especial 0
    if (n == 0)
        return false;

    queue<int> cola;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem; 
        cola.push(elem);
    }
    //cout de datos
    //while (!cola.empty()) {
    //    cout << cola.front() << " ";
    //    cola.pop();
    //}
    //cout << endl; 

    // escribir solucion: 
    queue <int> sol = resolver(cola);
    //imprimir solucion:

    while (!sol.empty()) {
        cout << sol.front() << " ";
        sol.pop();
    }
    cout << endl;

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

//Basura:  TIME LIMIT

    ////algoritmo bubble sort: 
    //int n = datos.size();
    //for (int i = 0; i < n; i++) {

    //    int a = datos.front();
    //    datos.pop();
    //    for (int j = 0; j < n - 1; j++) {
    //        int b = datos.front();
    //        datos.pop();
    //        if (a > b) {
    //            datos.push(b);
    //        }
    //        else {
    //            datos.push(a);
    //            a = b;
    //        }

    //        /* if (datos.size() == 1) {
    //             int c = datos.front();
    //             if (c < a) {
    //                 resultado.push(c);
    //                 datos.pop();
    //             }
    //             else {
    //                 resultado.push(a);
    //                 datos.pop();
    //                 a = c;
    //             }
    //         }*/
    //    }
    //    datos.push(a);
    //}

    //return datos;