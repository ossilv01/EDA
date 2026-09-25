// Oscar Silva Urbina 
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std; 


int RecComplementario (int dato){
    //Condición base para detenerse:
    if (dato>=0 && dato<=9) {
        return 9-dato;
     }
     int aux = dato % 10;
     aux = 9 - aux;
     dato = dato / 10;
     return (RecComplementario(dato)*10)+aux;   
     
}


int InversoREC(int dato, int numfinal) {
    if (dato >= 0 && dato <= 9) {
        return numfinal * 10 + (9-dato); 
    }
    else {
        int aux1 = dato % 10; 
        numfinal = numfinal * 10 + (9-aux1);
        dato = dato / 10; 
        return InversoREC(dato, numfinal);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num; 

    int c = RecComplementario(num);
    int d = InversoREC(num, 0);
    // escribir sol
    cout << c << " " << d << endl; 


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