//                          Курс.Объектно - ориентированное программирование на C++.
//                     Модуль 1. Введение в объектно - ориентированное программирование.
//                                            Домашнее задание №2.
//                                                 Задание 1.
// Создайте приложение "Телефонная книга".
// Необходимо хранить данные об абоненте :
//   -Фамилия;
//   -Имя;
//   -Отчество;
//   -домашний телефон;
//   -рабочий телефон;
//   -мобильный телефон;
//   -дополнительная информация о контакте.
// внутри соответствующего класса.
// Наполните класс переменными - членами, функциями - членами, конструкторами, 
// inline - функциями - членами, используйте инициализаторы, реализуйте деструктор.
// Обязательно необходимо выделять динамически память под ФИО. 
// Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, 
// искать абонентов по ФИО, искать абонентов по телефону, показывать всех абонентов, сохранять информацию в файл и загружать из файла.
#include <iostream>
#include <Windows.h>
#define COL0 3
#define COL1 20
#define COL2 20
#define COL3 20
#define COL4 16
#define COL5 16
#define COL6 16
#define COL7 20
#define INBUFFER 500
#define OUTBUFFER 500
using namespace std;
class Phonebook
{
public:
	struct Data // структура данных
	{
		char* dom;
		char* work;
		char* mobil;
		char* name;
		char* otch;
		char* fam;
		char* info;
		Phonebook *next;
	} record;
	Phonebook()  // конструктор
	{
		record.dom = new char[15];
		record.work = new char[15];
		record.mobil = new char[15];
		record.fam = new char[100];
		record.name = new char[100];
		record.otch = new char[100];
		record.info = new char[100];
	}
	~Phonebook() // деструктор
	{
		delete[] record.dom;
		record.dom = NULL;
		delete[] record.work;
		record.work = NULL;
		delete[] record.mobil;
		record.mobil = NULL;
		delete[] record.fam;
		record.fam = NULL;
		delete[] record.name;
		record.name = NULL;
		delete[] record.otch;
		record.otch = NULL;
		delete[] record.info;
		record.info = NULL;
	}
	//функции печати
	void printHead()      // функция печати заголовка
	{
		cout << "============================================================================================================================================\n";
		cout << "| № |      Фамилия       |         Имя        |      Отчество      |Домашний телефон|Рабочий  телефон|Мобильн. телефон|     Информация     |\n";
		cout << "============================================================================================================================================\n";
	}
	void beginStrOne(char *buffer, int column, int sum, int &sume) {
		for (int i = 0; i < (column - sum) / 2; i++) {
			strcat(buffer, " ");
		}
		sume = ((column - sum) / 2) + sum;
	}
	void endStrOne(char *buffer, int column, int &sume) {
		for (int i = 0; i < column - sume; i++) {
			strcat(buffer, " ");
		}
		strcat(buffer, "|");
	}
	void beginPrintOne(int column, int sum, int &sume)   // функция печати пробелов до данных
	{
		for (int i = 0; i < (column - sum) / 2; i++) {
			cout << " ";
		}
		sume = ((column - sum) / 2) + sum;
	}
	void endPrintOne(int column, int sume)               // функция печати пробелов после данных
	{
		for (int i = 0; i < column - sume; i++)
			cout << " ";
		cout << "|";
	}
	void creatOneStr(Phonebook *r, int n, char *buff)
	{
		char number[6];
		int sum0 = 0;
		int sum1 = strlen(r->record.fam);
		int sum2 = strlen(r->record.name);
		int sum3 = strlen(r->record.otch);
		int sum4 = strlen(r->record.dom);
		int sum5 = strlen(r->record.work);
		int sum6 = strlen(r->record.mobil);
		int sum7 = strlen(r->record.info);
		int sum0e = 0, sum1e = 0, sum2e = 0, sum3e = 0, sum4e = 0, sum5e = 0, sum6e = 0, sum7e = 0;
		//запись в строку порядкового номера абонента
		for (int i = n + 1; i > 0;) { i /= 10; sum0++; }
		strcat(buff, "|");
		beginStrOne(buff, COL0, sum0, sum0e);
		itoa(n + 1, number, 6);
		strcat(buff, number);
		endStrOne(buff, COL0, sum0e);
		//запись в строку фамилии
		beginStrOne(buff, COL1, sum1, sum1e);
		strcat(buff, r->record.fam);
		endStrOne(buff, COL1, sum1e);
		//запись в строку имени
		beginStrOne(buff, COL2, sum2, sum2e);
		strcat(buff, r->record.name);
		endStrOne(buff, COL2, sum2e);
		//запись в строку отчества
		beginStrOne(buff, COL3, sum3, sum3e);
		strcat(buff, r->record.otch);
		endStrOne(buff, COL3, sum3e);
		//запись в строку домашнего телефона
		beginStrOne(buff, COL4, sum4, sum4e);
		strcat(buff, r->record.dom);
		endStrOne(buff, COL4, sum4e);
		//запись в строку рабочего телефона
		beginStrOne(buff, COL5, sum5, sum5e);
		strcat(buff, r->record.work);
		endStrOne(buff, COL5, sum5e);
		//запись в строку мобильного телефона
		beginStrOne(buff, COL6, sum6, sum6e);
		strcat(buff, r->record.mobil);
		endStrOne(buff, COL6, sum6e);
		//запись в строку информации
		beginStrOne(buff, COL7, sum7, sum7e);
		strcat(buff, r->record.info);
		endStrOne(buff, COL7, sum7e);
		strcat(buff, "\n");
	}
	void printOne(Phonebook *r, int n)               // функция печати одной структуры (абонента) 
	{
		int sum0 = 0;
		int sum1 = strlen(r->record.fam);
		int sum2 = strlen(r->record.name);
		int sum3 = strlen(r->record.otch);
		int sum4 = strlen(r->record.dom);
		int sum5 = strlen(r->record.work);
		int sum6 = strlen(r->record.mobil);
		int sum7 = strlen(r->record.info);
		int sum0e = 0, sum1e = 0, sum2e = 0, sum3e = 0, sum4e = 0, sum5e = 0, sum6e = 0, sum7e = 0;
		//вывод порядкового номера абонента
		for (int i = n + 1; i > 0;) { i /= 10; sum0++; }
		cout << "|";
		beginPrintOne(COL0, sum0, sum0e);
		cout << n + 1;
		endPrintOne(COL0, sum0e);
		//вывод фамилии
		beginPrintOne(COL1, sum1, sum1e);
		cout << r->record.fam;
		endPrintOne(COL1, sum1e);
		//вывод имени
		beginPrintOne(COL2, sum2, sum2e);
		cout << r->record.name;
		endPrintOne(COL2, sum2e);
		//вывод отчества
		beginPrintOne(COL3, sum3, sum3e);
		cout << r->record.otch;
		endPrintOne(COL3, sum3e);
		//вывод домашнего телефона
		beginPrintOne(COL4, sum4, sum4e);
		cout << r->record.dom;
		endPrintOne(COL4, sum4e);
		//вывод рабочего телефона
		beginPrintOne(COL5, sum5, sum5e);
		cout << r->record.work;
		endPrintOne(COL5, sum5e);
		//вывод мобильного телефона
		beginPrintOne(COL6, sum6, sum6e);
		cout << r->record.mobil;
		endPrintOne(COL6, sum6e);
		//вывод информации
		beginPrintOne(COL7, sum7, sum7e);
		cout << r->record.info;
		endPrintOne(COL7, sum7e);
		cout << "\n";
	}
	void print(Phonebook **mas, int kol)            // функция просмотра исходного массива
	{
		printHead();
		for (int i = 0; i < kol; i++) {
			printOne(mas[i], i);
		}
		cout << "============================================================================================================================================\n";
	}
	void clear(Phonebook *&head) {               // освобождение памяти под списком
		while (head != NULL) {
			Phonebook *tmp = head;
			head = head->record.next;
			delete tmp;
		}
	}
	void creatArray(Phonebook *head, Phonebook **&mas, int kol) {// создание массива указателей на элементы списка
		mas = new Phonebook*[kol];                               // выделяем память под массив указателей
		int i = kol-1;
		while (head != NULL) {
			mas[i] = head;
			i--;
			head = head->record.next;
		}
		clear(head);                                            // очищаем список
	}
	void initManual(Phonebook *&head, int &kol)                 // функция ручного ввода данных 
	{
		Phonebook *elem = new Phonebook;
		cout << "Введите данные абонента № " << kol + 1 << ":\n";
		cout << "Фамилия: ";
		cin >> elem->record.fam;
		cout << "Имя: ";
		cin >> elem->record.name;
		cout << "Отчество: ";
		cin >> elem->record.otch;
		cout << "Домашний телефон: ";
		cin >> elem->record.dom;
		cout << "Рабочий телефон: ";
		cin >> elem->record.work;
		cout << "Мобильный телефон: ";
		cin >> elem->record.mobil;
		cout << "Дополнительная информация: ";
		cin >> elem->record.info;
		elem->record.next = head;
		head = elem;
		kol++;
	}
	void readData(FILE *in, Phonebook *&head, Phonebook **&mas, int &kol) {          // чтение данных из файла в список
		char filename[128];
		cout << "Введите имя файла для чтения: ";
		cin >> filename;
		if (fopen_s(&in, filename, "r") != 0) {
			cout << "Не удалось открыть файл " << filename << " для чтения\n";
			system("pause");
			return;
		}
		char buffer[INBUFFER];
		buffer[0] = 0;
		int n = 0;
		while (fgets(buffer, INBUFFER, in) != NULL) {
			n++;
		}
		buffer[0] = 0;
		kol = n-4;
		fseek(in, 0L, SEEK_SET);
		for (int i = 0; fgets(buffer, INBUFFER, in) != NULL; i++) {
			if (i > 2 && i<n-1) {
				Phonebook *tmp = new Phonebook;
				char *word, *next;
				word = strtok_s(buffer, "| ", &next);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.fam, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.name, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.otch, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.dom, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.work, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.mobil, word);
				word = strtok_s(NULL, "| ", &next);
				strcpy(tmp->record.info, word);
				tmp->record.next = head;
				head = tmp;
			}
			buffer[0] = 0;
		}
		head->creatArray(head, mas, kol);
		if (fclose(in) != 0)
		{
			cout << "Ошибка закрытия файла для чтения\n";
			system("pause");
			exit(2);
		}
		cout << "Данные успешно загружены из файла " << filename << "\n";
	}
	void writeData(FILE *out, Phonebook **mas, int kol) { // функция записи в файл
		char buffer[OUTBUFFER];
		char filename[128];
		cout << "Введите имя файла для записи: ";
		cin >> filename;
		if (fopen_s(&out, filename, "w") != 0) {
			cout << "Не удалось открыть файл " << filename << " для записи\n";
			system("pause");
			exit(4);
		}
		fputs("============================================================================================================================================\n", out);
		fputs("| № |      Фамилия       |         Имя        |      Отчество      |Домашний телефон|Рабочий  телефон|Мобильн. телефон|     Информация     |\n", out);
		fputs("============================================================================================================================================\n", out);
		buffer[0] = 0;
		for (int i = 0; i < kol; i++) {
			creatOneStr(mas[i], i, buffer);
			fputs(buffer, out);
			buffer[0] = 0;
		}
		fputs("============================================================================================================================================\n", out);
		if (fclose(out) != 0)
		{
			cout << "Не удалось закрыть файл " << filename << " после записи\n";
			system("pause");
			exit(4);
		}
		cout << "Данные успешно сохранены в файле " << filename << "\n";
	}
	void del(Phonebook **&mas, int &kol) {                  // функция удаления записи 
		int pos;
		do {
			cout << "\nВведите порядковый номер абонента для удаления: ";
			while (cin.get() != '\n');
			cin >> pos;
			if (pos <= 0 || pos > kol)
				cout << "Неверно! Повторите ввод!\n";
		} while (pos <= 0 || pos > kol);
		--kol;
		Phonebook**ptr = new Phonebook*[kol];               // создание массива указателей на записи
		int n = 0;
		for (int i = 0; i < pos - 1; i++, n++) {            // переписываем указатели до позиции в новый массив указателей
			ptr[n] = mas[i];
		}
		for (int i = pos; i < kol + 1; i++, n++) {          // пропускаем удаляемую позицию и переписываем указатели после позиции
			ptr[n] = mas[i];
		}
		delete[] mas;                                       // удаляем старый массив указателей на указатели
		mas = ptr;                                          // переназначаем старый массив указателей на новый
		cout << "Запись № " << pos << " удалена!\n";
	}
	void search(Phonebook **mas, int kol) {
		cout << "\nПоиск по фамилии, имени и отчеству абонента\n";
		char fam[100];
		char name[100];
		char otch[100];
		cout << "Введите фамилию: ";
		cin >> fam;
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите отчество: ";
		cin >> otch;
		int n = 0;
		for (int i = 0; i < kol; i++) {
			if (strcmp(mas[i]->record.fam, fam) == 0&& strcmp(mas[i]->record.name, name) == 0 && strcmp(mas[i]->record.otch, otch) == 0) {
				n++;                          // если нашли то считаем
				if (n < 2) {                  // если первый раз то печатаем заголовок
					printHead();
				}
				printOne(mas[i], i);
			}
		}
		if (n) cout << "============================================================================================================================================\n";
		if (n == 0) cout << "Абонент "<< fam << " " << name << " " << otch <<" не найден!\n";
	}
};
void quit() {                                         // функция выхода
	cout << "Завершение работы!\n";
	system("pause");
	exit(0);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol = 0, vyb = 0;
	FILE *in, *out;
	Phonebook **mas;
	Phonebook *head = NULL;
	cout << "Необходимо ввести данные.\n";
	while (vyb < 1 || vyb>2) {
		cout << "Выберите способ ввода:\n";
		cout << "1 - ручной ввод;\n";
		cout << "2 - ввод из файла;\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		switch (vyb)
		{
		// ручной ввод
		case 1:
			short n;
			do {
				system("cls");
				head->initManual(head, kol);
				cout << "\nСоздать нового абонента?\n1 - да\n0 - нет\nВаш выбор: ";
				cin >> n;
			} while (n);
			head->creatArray(head, mas, kol);              // создание массива указателей на элементы списка
			break;
		// ввод из файла
		case 2:
			head->readData(in, head, mas, kol);
			system("pause");
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - добавить абонента\n";
		cout << "2 - удалить абонента\n";
		cout << "3 - поиск по фамилии, имени, отчеству\n";
		cout << "4 - показать всех абонентов\n";
		cout << "5 - сохранить информацию в файл\n";
		cout << "6 - загрузить информацию из файла\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			head->initManual(head, kol);
			head->creatArray(head, mas, kol);
			system("pause");
			break;
		case 2:
			head->print(mas, kol);
			head->del(mas, kol);
			system("pause");
			break;
		case 3:
			head->search(mas, kol);
			system("pause");
			break;
		case 4:
			head->print(mas, kol);
			system("pause");
			break;
		case 5:
			head->writeData(out, mas, kol);
			system("pause");
			break;
		case 6:
			head->readData(in, head, mas, kol);
			system("pause");
			break;
		case 0:
			delete[]mas;
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	return 0;
}
