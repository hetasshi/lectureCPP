#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // 1) создаём вектор 1, -1, 2, -2 … 10, -10
    vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        v.push_back(-i);
    }

    cout << "исходный: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // 2) перемешиваем случайно
    random_shuffle(v.begin(), v.end());

    // 3) сдвиг на 3 влево
    rotate(v.begin(), v.begin() + 3, v.end());

    // 4) ещё сдвиг на 5
    rotate(v.begin(), v.begin() + 5, v.end());

    cout << "после сдвигов: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // 5) 55 чисел фибоначчи
    vector<int> fib(55);
    fib[0] = fib[1] = 1;
    for (size_t i = 2; i < fib.size(); ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    // 6) меняем первые 20 элементов
    swap_ranges(v.begin(), v.begin() + 20, fib.begin());

    // 7) сортируем и убираем дубли
    sort(fib.begin(), fib.end());
    fib.erase(unique(fib.begin(), fib.end()), fib.end());

    // 8) берём чётные из v
    vector<int> even;
    copy_if(v.begin(), v.end(), back_inserter(even),
            [](int x) { return x % 2 == 0; });

    // вывод
    cout << "первый: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "фибоначчи: ";
    copy(fib.begin(), fib.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "чётные: ";
    copy(even.begin(), even.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    return 0;
}
