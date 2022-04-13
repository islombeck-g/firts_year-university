#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double result(string str_1) {
    string mini_res = "";
    for (int i = 0; i < str_1.length(); i++) {
        if (str_1[i] == '(') {
            int kol_skobok = 1;
            string inf_v_skobkax;
            i++;
            while (true) {
                if (str_1[i] == '(')
                    kol_skobok++;
                else if (str_1[i] == ')') {
                    kol_skobok--;
                    if (kol_skobok == 0) {
                        i++;
                        break;
                    }

                }
                inf_v_skobkax += str_1[i];
                i++;
            }
            mini_res += to_string(result(inf_v_skobkax));
        }
        mini_res += str_1[i];
    }
    
    for (int i = 0; i < mini_res.length(); i++) {
        if (mini_res[i] == '+') {
            double a = result(mini_res.substr(0, i));
            double b = result(mini_res.substr(i + 1, mini_res.length()));
            return a + b;
        }
        else if (mini_res[i] == '-') {
            double a = result(mini_res.substr(0, i));
            double b = result(mini_res.substr(i + 1, mini_res.length()));
            return a - b;
        }
    }
    for (int i = 0; i < mini_res.length(); i++) {

        if (mini_res[i] == '*') {
            double a = result(mini_res.substr(0, i));
            double b = result(mini_res.substr(i + 1, mini_res.length()));
            return a * b;

        }
        else if (mini_res[i] == '/') {
            double a = result(mini_res.substr(0, i));
            double b = result(mini_res.substr(i + 1, mini_res.length()));
            return a / b;
        }
        else if (mini_res[i] == '^') {
            double a = result(mini_res.substr(0, i));
            double b = result(mini_res.substr(i + 1, mini_res.length()));
            return pow(a, b);
        }
       
    }

    return stod(mini_res);
}

int main(){
    string str, str_1;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            str_1 += str[i];
    cout << result(str_1);
    return 0;
}
