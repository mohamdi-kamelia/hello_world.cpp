#include <iostream>
#include <cstring> 

void MySortString(const char* arr[], int size) {
    for (int i = 1; i < size; ++i) {
        const char* key = arr[i];
        int j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const char* arr[] = { "kamelia", "Mounir", "Maysa", "banane", "kiwi" };
    int size = sizeof(arr) / sizeof(arr[0]);

    MySortString(arr, size);

    std::cout << "Tableau trie : " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
