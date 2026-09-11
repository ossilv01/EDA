//GDV - Oscar Silva Urbina
#include <iostream>

int main()
{
    bool p = false;
    while (!p) {
        int n; 
        std::cin >> n; 
        if (n == 0) p = true;
        else {
            n = n * 2; 
            std::cout << n << std::endl; 
        }
    }
    return 0; 
}

