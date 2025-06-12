#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Функция для генерации первых n чисел Фибоначчи
vector<int> generateFibonacci(int n) {
    vector<int> fib;
    if (n >= 1) fib.push_back(0);
    if (n >= 2) fib.push_back(1);
    
    for (int i = 2; i < n; ++i) {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    return fib;
}

int main() {
    // 1. Создать контейнер состоящий из 1–1, 2-2, 3-3 …10-10
    vector<int> container1;
    for (int i = 1; i <= 10; ++i) {
        container1.push_back(i);
        container1.push_back(i);
    }
    
    cout << "1. Исходный контейнер: ";
    for (int num : container1) cout << num << " ";
    cout << endl;

    // 2. Перераспределить его произвольным образом
    random_shuffle(container1.begin(), container1.end());
    cout << "2. После перераспределения: ";
    for (int num : container1) cout << num << " ";
    cout << endl;

    // 3. Сдвинуть влево на 3 позиции
    rotate(container1.begin(), container1.begin() + 3, container1.end());
    cout << "3. После сдвига влево на 3: ";
    for (int num : container1) cout << num << " ";
    cout << endl;

    // 4. Сдвинуть по кругу на 5 позиций
    rotate(container1.begin(), container1.begin() + (container1.size() - 5 % container1.size()), container1.end());
    cout << "4. После кругового сдвига на 5: ";
    for (int num : container1) cout << num << " ";
    cout << endl;

    // 5. Создать контейнер состоящий из 55 первых чисел Фибоначчи
    vector<int> container2 = generateFibonacci(55);
    cout << "5. Первые 10 чисел Фибоначчи из второго контейнера: ";
    for (int i = 0; i < 10; ++i) cout << container2[i] << " ";
    cout << endl;

    // 6. Поменять местами первые 20 членов двух контейнеров
    for (int i = 0; i < 20; ++i) {
        swap(container1[i], container2[i]);
    }
    cout << "6. После обмена первых 20 элементов:" << endl;
    cout << "   Контейнер 1: ";
    for (int i = 0; i < 10; ++i) cout << container1[i] << " ";
    cout << endl;
    cout << "   Контейнер 2: ";
    for (int i = 0; i < 10; ++i) cout << container2[i] << " ";
    cout << endl;

    // 7. Отсортировать второй контейнер, удалить подряд идущие одинаковые элементы
    sort(container2.begin(), container2.end());
    auto last = unique(container2.begin(), container2.end());
    container2.erase(last, container2.end());
    cout << "7. После сортировки и удаления дубликатов во втором контейнере: ";
    for (int i = 0; i < 10; ++i) cout << container2[i] << " ";
    cout << endl;

    // 8. Скопировать из первого контейнера только четные элементы
    vector<int> even_elements;
    copy_if(container1.begin(), container1.end(), back_inserter(even_elements), 
             [](int x) { return x % 2 == 0; });
    cout << "8. Четные элементы из первого контейнера: ";
    for (int num : even_elements) cout << num << " ";
    cout << endl;

    return 0;
}
