//GDV - Oscar Silva Urbina
#include <iostream>


int main()
{
    int numero;
    std::cin >> numero;
    if (numero > 0) {
        for (int i = 0; i < numero; i++) {
            int n;
            std::cin >> n;
            n = n * 2;
            std::cout << n << std::endl; 
        }
    }
    return 0;
}
