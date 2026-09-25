// Oscar Silva Urbina 
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std; 

//metodo complementario
//int recomplementario(int dato) {
//    int pos = 1; 
//    int numfinal = 0; 
//   
//    while (dato/10 != 0) {
//        int aux = dato % 10;
//        aux = 9 - aux;
//        numfinal += aux * pos;
//        pos = pos * 10;
//        dato = dato / 10;
//    }
//
//
//   /* while (dato/10 != 0) {
//        int aux = dato % 10;
//        aux = 9 - aux;
//        aux = aux * pow(10, nexpo);
//        nexpo++;
//        numfinal += aux;
//        dato = dato / 10;
//    }
//    if (dato <= 9 || dato >= 0) {
//        int aux = 9 - dato;
//        aux = aux * pow(10, nexpo);
//        numfinal += aux;
//    }*/
//    return numfinal;
//}

int RecComplementario (int dato){
    //Condición base para detenerse:
    if (dato>=0 && dato<=9) {
        return 9-dato;
     }
     int aux = dato % 10;
     aux = 9 - aux;
     return (RecComplementario(dato/10)*10)+aux;   
     
}

// int CoplementarioREC(int datos) {
//     //Rango limitado por enunciado
//    if (datos <0 || datos > 1000000000) return datos; 
//    return RecComplementario(datos); 
//}


int InversoREC(int dato, int numfinal) {
    if (dato >= 0 && dato <= 9) {
        return numfinal * 10 + dato; 
    }
    else {
        int aux1 = dato % 10; 
        numfinal = numfinal * 10 + aux1;
        dato = dato / 10; 
        return InversoREC(dato, numfinal);
    }
}

int RecInverso(int dato) {
    return InversoREC(dato, 0);
}

//metodo (inverso) 
//int reinverso(int dato) {
//    int numfinal = 0;
//    int aux =0; 
//    while (dato != 0) {
//        aux = dato % 10;
//        numfinal = (numfinal * 10) + aux;
//        dato = dato / 10;
//    }
//
//    return numfinal;
//}

// función que resuelve el problema
int resolver(int &datos) {
    int c = RecComplementario(datos);
    int d = RecInverso(c);
    //int a = recomplementario(datos);
    //int b = reinverso(a);
    cout << c << " " << d << " " << /*"Original:" << a << " " << b <<*/ endl;
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