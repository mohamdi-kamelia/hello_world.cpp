#include <iostream>

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Avant lechange :" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    swapValues(x, y);

    std::cout << "Apres l'echange :" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    return 0;
}
