// b.a(s2w2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
    bool chek_zero (vector<int>& mas);
    void del_to_two(vector<int>& mas);
    bool chek_bigger(vector<int>& mas, vector<int>& mas_1);
    void minus(vector<int>& mas, vector<int>& mas_1);
    bool chek_to_one(vector<int>& mas);
};

bool biiig::chek_to_one(vector<int>& mas) {
    for (int i = 0; i < s - 1; i++) 
        if (mas[i] != 0)return false;
    if (mas[s - 1] == 1)return true;
    else return false;
}
void biiig::minus(vector<int>& mas, vector<int>& mas_1) {
    int one_zero = 0;
    for (int i = s - 1; i != -1; i--) {
        mas[i] -= one_zero;
        if (mas[i] < mas_1[i]) {
            mas[i] += 10;
            one_zero = 1;
        }
        else if (mas[i] > mas_1[i]||mas[i]==mas_1[i])
            one_zero = 0;
        mas[i] -= mas_1[i];
    }
}

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
        
        
        while (true) {
          
            if (chek_bigger(mas, mas_1) == true) {
                minus(mas, mas_1);
                if (chek_zero(mas) == true) {
                    cout << setw(3) << position << ".<" << str << "> <" << str_1 << "> <";
                    int t = 0;
                    while (mas_1[t] == 0)t++;
                    for (int i = t; i < s; i++)cout << mas_1[i]; cout << ">" << endl;
                    position++;
                    break;
                }
                int k = 1;
                while (mas[s-1] % 2 == 0) {
                    del_to_two(mas);
                    k *= 2;
                }
                
                if (chek_to_one(mas) == true) {
                    cout << setw(3) << position << ".<" << str << "> <" << str_1 << "> <" << 1 << ">" << endl;
                    position++;
                    break;
                }   
            }                
            else {
                minus(mas_1, mas);
                if (chek_zero(mas_1) == true) {
                    cout << setw(3) << position << ".<" << str << "> <" << str_1 << "> <";
                    int t = 0;
                    while (mas[t] == 0)t++;
                    for (int i = t; i < s; i++)cout << mas[i]; cout << ">" << endl;
                    position++;
                    break;
                }
                int k = 1;
                while (mas_1[s - 1] % 2 == 0) {
                    del_to_two(mas_1);
                    k *= 2;
                }
                if (chek_to_one(mas_1) == true) {
                    cout << setw(3) << position << ".<" << str << "> <" << str_1 << "> <" << 1 << ">" << endl;
                    position++;
                    break;
                }
            } 
        } 
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
void biiig::del_to_two(vector<int>& mas) {
    int ten = 0;
    for (int i = 0; i < s; i++) {
        mas[i] = ten * 10 + mas[i];
        if (mas[i] < 2 && mas[i] != 0) {
            mas[i] = 0;
            ten = 1;
        }
        else if (mas[i] % 2 == 0) {
            mas[i] /= 2;
            ten = 0;
        }
        else {

            int kol = 0;
            while (mas[i] > 2) {
                mas[i] -= 2;
                kol++;
            }
            mas[i] = kol;
            ten = 1;
        }
    }
}
bool biiig::chek_zero(vector<int>& mas) {

    for (int i = 0; i < s; i++)
        if (mas[i] != 0)
            return false;

    return true;
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
