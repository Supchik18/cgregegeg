#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

// Функция для переворота слова задом наперед
string a(string word) {
    reverse(word.begin(), word.end());
    return word;
}

// Функция для удаления гласных букв из слова
string b(string word) {
    string vowels = "aeiouAEIOU";
    word.erase(remove_if(word.begin(), word.end(), [&](char c) {
        return vowels.find(c) != string::npos;
        }), word.end());
    return word;
}

// Функция для удаления согласных букв из слова
string C(string word) {
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(remove_if(word.begin(), word.end(), [&](char c) {
        return consonants.find(c) != string::npos;
        }), word.end());
    return word;
}

// Функция для перемешивания букв в слове
string d(string word) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(word.begin(), word.end(), default_random_engine(seed));
    return word;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    cout << "Выберите действие:" << endl;
    cout << "1. Вывести слово задом наперед" << endl;
    cout << "2. Вывести слово без гласных" << endl;
    cout << "3. Вывести слово без согласных" << endl;
    cout << "4. Рандомно раскидать буквы заданного слова" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Результат: " << a(word) << endl;
        break;
    case 2:
        cout << "Результат: " << b(word) << endl;
        break;
    case 3:
        cout << "Результат: " << C(word) << endl;
        break;
    case 4:
        cout << "Результат: " << d(word) << endl;
        break;
    default:
        cout << "Некорректный выбор!" << endl;
        break;
    }

    return 0;
}