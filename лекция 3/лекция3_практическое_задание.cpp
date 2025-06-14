#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

bool triple(int a, int b)            // проверка x3
{
    return a * 3 == b || b * 3 == a;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // читаем исходные числа
    std::vector<int> v;
    std::ifstream fin("numbers.txt");
    int x;
    while (fin >> x) v.push_back(x);

    // 1) сколько раз встречается заданное число
    int target;
    std::cout << "введите число: ";
    std::cin >> target;
    std::cout << "встречается "
        << std::count(v.begin(), v.end(), target)
        << " раз(а)\n";

    // 2) сколько раз встречается число, чей корень равен введённому
    int root;
    std::cout << "введите корень: ";
    std::cin >> root;
    int sq = root * root;
    std::cout << "число " << sq << " встречается "
        << std::count(v.begin(), v.end(), sq)
        << " раз(а)\n";

    // 3) первая пара равных и пары x3
    auto eq = std::adjacent_find(v.begin(), v.end());
    if (eq != v.end())
        std::cout << "первая пара равных: " << *eq << ' ' << *(eq + 1) << '\n';
    else
        std::cout << "равных рядом нет\n";

    for (std::size_t i = 0; i + 1 < v.size(); ++i)
        if (triple(v[i], v[i + 1]))
            std::cout << "пара x3: " << v[i] << ' ' << v[i + 1]
            << " (позиция " << i << ")\n";

    // 4) возводим в квадрат и пишем в файл
    std::vector<int> squared;
    std::transform(v.begin(), v.end(), std::back_inserter(squared),
        [](int val) { return val * val; });
    std::ofstream fout("squared.txt");
    std::copy(squared.begin(), squared.end(),
        std::ostream_iterator<int>(fout, " "));

    // 5) проверяем подпоследовательность
    std::size_t m;
    std::cout << "длина подпоследовательности: ";
    if (!(std::cin >> m)) return 0;
    std::vector<int> sub(m);
    std::cout << "введите элементы: ";
    for (auto& e : sub) std::cin >> e;

    if (std::search(v.begin(), v.end(), sub.begin(), sub.end()) != v.end())
        std::cout << "подпоследовательность найдена\n";
    else
        std::cout << "такой подпоследовательности нет\n";

    return 0;
}
