// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// función que resuelve el problema
bool resolver(string a) {
    //V.2 pila
    stack <char> pila;

    for (char b : a) {
        if (b == '(' || b== '{' || b == '[') {
            pila.push(b);
        }

        else if (b == ')' || b == '}' || b == ']') {
            if (pila.empty()) return false; //si no se ha encontrado antes un simbolo de apertura es que esta sola el simbolo de cerrar
            //pila.push(b);
            char cima = pila.top();
            if (cima == '(' && b == ')') {
                pila.pop();
            }
            else if (cima == '[' && b == ']') {
                pila.pop();
            }
            else if (cima == '{' && b == '}') {
                pila.pop();
            }
            else {
                return false;
            }
        }
    }
    if (pila.size() == 0) return true;
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string a;
    if (!getline(cin,a))
        return false;

    cout << (resolver(a) ? "SI" : "NO") << endl;
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

//Muy mal:

    //vector <char> texto;
    ////v.1
    //char c1 = '(';
    //char c2 = ')';
    //int cont1 = 0;

    //char c3 = '{';
    //char c4 = '}';
    //int cont2 = 0;

    //char c5 = '[';
    //char c6 = ']';
    //int cont3 = 0;

    //for (char b : a) texto.push_back(b);
    ////casos base: 
    //if (texto.size() == 1 || texto.size() == 0) {
    //    return false;
    //}

    //for (int i = 0; i < texto.size(); i++) {   
    //    if (texto[i] == c1 || texto[i] == c2) {
    //        cont1++;
    //    }
    //    else if (texto[i] == c3 || texto[i] == c4) {
    //        cont2++;
    //    }
    //    else if (texto[i] == c5 || texto[i] == c6) {
    //        cont3++;
    //    }
    //}
    //if (cont1 % 2 == 0 && cont2 % 2 == 0 && cont3 % 2 == 0) {
    //    return true;
    //}