#include <iostream>
#include<string>
#include<fstream>
#include "Stopwatch.hpp"
#include <iomanip>
#include <vector>

using namespace std;

class biiig {

    string str, str_1;
    ifstream file;
    int position = 1;
    int s;

public:
    biiig();
    ~biiig();
    void calculate();
    bool chek_bigger(vector<int>& mas, vector<int>& mas_1);
    void minus(vector<int>& mas, vector<int>& mas_1);
    bool chek_a_a(vector<int>& mas, vector<int>& mas_1);
};


void biiig::calculate() {

    while (!file.eof()) {
        file >> str;
        file >> str_1;
        s = str.length();

        vector<int>mas(s);
        vector<int>mas_1(s);

        for (int i = 0; i < s; i++)
            mas[i] = str[i] - 48;
        for (int i = 0; i < s; i++)
            mas_1[i] = str_1[i] - 48;

        while (chek_a_a(mas, mas_1) == false) {
            if (chek_bigger(mas, mas_1) == true)
                minus(mas, mas_1);
            else
                minus(mas_1, mas);
        }
        cout << setw(3) << position << ".<" << str << "> <" << str_1 << "> <";
        int t = 0;
        while (mas[t] == 0)t++;
        for (int i = t; i < s; i++)cout << mas[i]; cout << ">" << endl;
        position++;
       
    }
    file.close();
}
bool biiig::chek_bigger(vector<int>& mas, vector<int>& mas_1) {
    for (int i = 0; i < s; i++) {
        if (mas[i] == mas_1[i])continue;
        else if (mas[i] > mas_1[i])
            return true;
        else return false;
    }
    return false;
}
bool biiig::chek_a_a(vector<int>& mas, vector<int>& mas_1) {
    for (int i = 0; i < s; i++)
        if (mas[i] != mas_1[i])
            return false;
    return true;
}
void biiig::minus(vector<int>& mas, vector<int>& mas_1) {
    int one_zero = 0;
    for (int i = s - 1; i != -1; i--) {
        mas[i] -= one_zero;
        if (mas[i] < mas_1[i]) {
            mas[i] += 10;
            one_zero = 1;
        }
        else if (mas[i] > mas_1[i] || mas[i] == mas_1[i])
            one_zero = 0;
        mas[i] -= mas_1[i];
    }
}
biiig::biiig() {
    file.open("test.txt");
    if (!file.is_open()) {
        cout << "error of open file" << endl;
        return;
    }
}
biiig::~biiig() {
    //end
}
int main()
{
    namespace sw = stopwatch;
    sw::Stopwatch my_watch;

    biiig big;
    big.calculate();


    auto duration_ms = my_watch.elapsed();
    std::cout << "time: " << duration_ms << " milliseconds." << std::endl;
}