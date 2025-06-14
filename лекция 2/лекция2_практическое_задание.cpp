#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

// запись списка в файл
template<typename T>
void save_list(const std::list<T>& lst, const std::string& file)
{
    std::ofstream fout(file);
    if (!fout) return;
    std::copy(lst.begin(), lst.end(), std::ostream_iterator<T>(fout, " "));
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1) читаем вектор из файла и считаем единицы
    std::vector<int> v;
    std::ifstream fvec("vector.txt");
    int n;
    while (fvec >> n) v.push_back(n);

    int ones = std::count(v.begin(), v.end(), 1);
    std::cout << "число 1 встречается " << ones << " раз(а)\n";

    // 2) копируем в list, пропуская единицы
    std::list<int> lst;
    std::copy_if(v.begin(), v.end(), std::back_inserter(lst),
        [](int x) { return x != 1; });

    // 3) читаем list из файла и кладём в vector в обратном порядке
    std::list<int> lst_file;
    std::ifstream flist("list.txt");
    while (flist >> n) lst_file.push_back(n);
    std::vector<int> vec_rev(lst_file.rbegin(), lst_file.rend());

    // 4) дополняем list данными из консоли и снова перекладываем в vector
    std::cout << "введите числа (конец — ctrl+d): ";
    while (std::cin >> n) lst_file.push_back(n);
    std::vector<int> vec_from_list(lst_file.begin(), lst_file.end());

    // 5) сохраняем list без единиц в файл
    save_list(lst, "list_out.txt");

    return 0;
}
