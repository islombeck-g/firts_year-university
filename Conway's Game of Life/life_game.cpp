#include <iostream>
#include<ctime>
using namespace std;


void zapolnenie(int** mas, const int& a, int** mas2) {
	//cout <<endl<< "Пожалуйста вводите либо 0 либо 1\n"
		//<< "админу лень писать код)))" << endl<<endl;
	int b = a - 1;
	for (int i = 1; i < b; i++) {
		for (int j = 1; j < b; j++) {

			mas[i][j] = rand() % 2;
			
			//cout << "mas[" << i << "][" << j << "] "; cin >> mas[i][j];
		}
	}
	
	for (int i = 0; i < a; i++) {
		mas[i][0] = 0;
		mas[0][i] = 0;
		mas[a - 1][i] = 0;
		mas[i][a - 1] = 0;

		mas2[i][0] = 0;
		mas2[0][i] = 0;
		mas2[a - 1][i] = 0;
		mas2[i][a - 1] = 0;
	}
}

void show(int** mas, const int& a) {
	int b = a - 1;
	for (int i = 1; i < b; i++) {
		for (int j = 1; j < b; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void action(int** mas, const int& a, int** mas2) {
	int b = a - 1;
		for (int i = 1; i < b; i++) {
			for (int j = 1; j < b; j++) {
				int kolsosed = 0;
				if (mas[i - 1][j - 1] == 1)kolsosed++;
				if (mas[i - 1][j] == 1)     kolsosed++;
				if (mas[i - 1][j + 1] == 1) kolsosed++;
				if (mas[i][j - 1] == 1)     kolsosed++;
				if (mas[i][j + 1] == 1)     kolsosed++;
				if (mas[i + 1][j - 1] == 1) kolsosed++;
				if (mas[i + 1][j] == 1)     kolsosed++;
				if (mas[i + 1][j + 1] == 1) kolsosed++;
				
				if (mas[i][j] == 1) {
					if (kolsosed == 0 || kolsosed == 1 || kolsosed > 3) mas2[i][j] = 0;
					else mas2[i][j] = 1;
				}
				else {
					if (kolsosed == 3) mas2[i][j] = 1;
					else mas2[i][j] = 0;
				
				}
			}
		}
}

void copy(int** mas, int** mas2, const int& a) {
	for (int i = 0; i < a; i++) 
		for (int j = 0; j < a; j++) 
			mas[i][j] = mas2[i][j];
}

bool chek(int** mas, const int &a) {
	int b = a - 1;
	bool t = false;
	for (int i = 1; i < b; i++){
		for (int j = 1; j < b; j++) {
			if (mas[i][j] == 1){
				t = true;
				break;
			}
		}
	}
	return t;
}

bool chek2(int** mas, int** mas2, const int& a) {
	int b = a - 1;
	bool t = false;
	for (int i = 1; i < b; i++) {
		for (int j = 1; j < b; j++) {
			if (mas[i][j] != mas2[i][j]) {
				t = true;
				break;
			}
		}
	}
	return t;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	//создание поля
	int a;
	cout << "Введите размер поля" << endl; cin >> a;
	if (a < 2) return 0;
	a = a + 2;
	int** mas;
	int** mas2;
	int** mas3;
	mas  = new int* [a];
	mas2 = new int* [a];
	mas3 = new int* [a];
	for (int i = 0; i < a; i++) mas[i] = new int[a];
	for (int i = 0; i < a; i++) mas2[i] = new int[a];
	for (int i = 0; i < a; i++) mas3[i] = new int[a];

	zapolnenie(mas, a, mas2);				   //заполнение либо рандомным способом либо в ручную
	cout << endl << "результат заполнения" << endl;
	show(mas, a);                            //показывает то что получилось после ввода
	
	int i = 1;
	copy(mas3, mas, a);
	
	do{		//отсчёт поколений
		
		action(mas, a, mas2);		       //исполнение правил игры
		cout << endl << "поколение_" << i << endl;
		show(mas2, a);                   //результат исполнения законов игры
		
		bool t = chek(mas2, a);		    //проверка нахождения выживших
		if (t == false) {			   //если выживших нет, то программа завершает свою работу(спасти уже точно не получится)
			cout <<endl<< "жители погибли раньше времени" << endl;
			break; 
		}

		if (i > 1) {                //проверка на богатырей выпивших зелье бессмертия
			bool y= chek2(mas, mas3, a);

			if (y == false) {           //результат повторяется и смысла дальше считать нет
				cout << endl << "Эти жители оказались умнее, они не умрут никогда!!!" << endl;
				break;
			}
			copy(mas3, mas, a);
		}
		i++;
		copy(mas, mas2, a);				  //копирование полученного результата в первый массив
	}while (a);
	
									   //удаление
	for (int i = 0; i < a; i++) {
		delete[]mas[i];
		delete[]mas2[i];
	}
					
	delete[]mas;
	delete[]mas2;
	return 0;
}
