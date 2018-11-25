//                          ����.�������� - ��������������� ���������������� �� C++.
//                     ������ 1. �������� � �������� - ��������������� ����������������.
//                                            �������� ������� �2.
//                                                 ������� 1.
// �������� ���������� "���������� �����".
// ���������� ������� ������ �� �������� :
//   -�������;
//   -���;
//   -��������;
//   -�������� �������;
//   -������� �������;
//   -��������� �������;
//   -�������������� ���������� � ��������.
// ������ ���������������� ������.
// ��������� ����� ����������� - �������, ��������� - �������, ��������������, 
// inline - ��������� - �������, ����������� ��������������, ���������� ����������.
// ����������� ���������� �������� ����������� ������ ��� ���. 
// ������������ ������������ ����������� ��������� ����� ���������, ������� ���������, 
// ������ ��������� �� ���, ������ ��������� �� ��������, ���������� ���� ���������, ��������� ���������� � ���� � ��������� �� �����.
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
	struct Data // ��������� ������
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
	Phonebook()  // �����������
	{
		record.dom = new char[15];
		record.work = new char[15];
		record.mobil = new char[15];
		record.fam = new char[100];
		record.name = new char[100];
		record.otch = new char[100];
		record.info = new char[100];
	}
	~Phonebook() // ����������
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
	//������� ������
	void printHead()      // ������� ������ ���������
	{
		cout << "============================================================================================================================================\n";
		cout << "| � |      �������       |         ���        |      ��������      |�������� �������|�������  �������|�������. �������|     ����������     |\n";
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
	void beginPrintOne(int column, int sum, int &sume)   // ������� ������ �������� �� ������
	{
		for (int i = 0; i < (column - sum) / 2; i++) {
			cout << " ";
		}
		sume = ((column - sum) / 2) + sum;
	}
	void endPrintOne(int column, int sume)               // ������� ������ �������� ����� ������
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
		//������ � ������ ����������� ������ ��������
		for (int i = n + 1; i > 0;) { i /= 10; sum0++; }
		strcat(buff, "|");
		beginStrOne(buff, COL0, sum0, sum0e);
		itoa(n + 1, number, 6);
		strcat(buff, number);
		endStrOne(buff, COL0, sum0e);
		//������ � ������ �������
		beginStrOne(buff, COL1, sum1, sum1e);
		strcat(buff, r->record.fam);
		endStrOne(buff, COL1, sum1e);
		//������ � ������ �����
		beginStrOne(buff, COL2, sum2, sum2e);
		strcat(buff, r->record.name);
		endStrOne(buff, COL2, sum2e);
		//������ � ������ ��������
		beginStrOne(buff, COL3, sum3, sum3e);
		strcat(buff, r->record.otch);
		endStrOne(buff, COL3, sum3e);
		//������ � ������ ��������� ��������
		beginStrOne(buff, COL4, sum4, sum4e);
		strcat(buff, r->record.dom);
		endStrOne(buff, COL4, sum4e);
		//������ � ������ �������� ��������
		beginStrOne(buff, COL5, sum5, sum5e);
		strcat(buff, r->record.work);
		endStrOne(buff, COL5, sum5e);
		//������ � ������ ���������� ��������
		beginStrOne(buff, COL6, sum6, sum6e);
		strcat(buff, r->record.mobil);
		endStrOne(buff, COL6, sum6e);
		//������ � ������ ����������
		beginStrOne(buff, COL7, sum7, sum7e);
		strcat(buff, r->record.info);
		endStrOne(buff, COL7, sum7e);
		strcat(buff, "\n");
	}
	void printOne(Phonebook *r, int n)               // ������� ������ ����� ��������� (��������) 
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
		//����� ����������� ������ ��������
		for (int i = n + 1; i > 0;) { i /= 10; sum0++; }
		cout << "|";
		beginPrintOne(COL0, sum0, sum0e);
		cout << n + 1;
		endPrintOne(COL0, sum0e);
		//����� �������
		beginPrintOne(COL1, sum1, sum1e);
		cout << r->record.fam;
		endPrintOne(COL1, sum1e);
		//����� �����
		beginPrintOne(COL2, sum2, sum2e);
		cout << r->record.name;
		endPrintOne(COL2, sum2e);
		//����� ��������
		beginPrintOne(COL3, sum3, sum3e);
		cout << r->record.otch;
		endPrintOne(COL3, sum3e);
		//����� ��������� ��������
		beginPrintOne(COL4, sum4, sum4e);
		cout << r->record.dom;
		endPrintOne(COL4, sum4e);
		//����� �������� ��������
		beginPrintOne(COL5, sum5, sum5e);
		cout << r->record.work;
		endPrintOne(COL5, sum5e);
		//����� ���������� ��������
		beginPrintOne(COL6, sum6, sum6e);
		cout << r->record.mobil;
		endPrintOne(COL6, sum6e);
		//����� ����������
		beginPrintOne(COL7, sum7, sum7e);
		cout << r->record.info;
		endPrintOne(COL7, sum7e);
		cout << "\n";
	}
	void print(Phonebook **mas, int kol)            // ������� ��������� ��������� �������
	{
		printHead();
		for (int i = 0; i < kol; i++) {
			printOne(mas[i], i);
		}
		cout << "============================================================================================================================================\n";
	}
	void clear(Phonebook *&head) {               // ������������ ������ ��� �������
		while (head != NULL) {
			Phonebook *tmp = head;
			head = head->record.next;
			delete tmp;
		}
	}
	void creatArray(Phonebook *head, Phonebook **&mas, int kol) {// �������� ������� ���������� �� �������� ������
		mas = new Phonebook*[kol];                               // �������� ������ ��� ������ ����������
		int i = kol-1;
		while (head != NULL) {
			mas[i] = head;
			i--;
			head = head->record.next;
		}
		clear(head);                                            // ������� ������
	}
	void initManual(Phonebook *&head, int &kol)                 // ������� ������� ����� ������ 
	{
		Phonebook *elem = new Phonebook;
		cout << "������� ������ �������� � " << kol + 1 << ":\n";
		cout << "�������: ";
		cin >> elem->record.fam;
		cout << "���: ";
		cin >> elem->record.name;
		cout << "��������: ";
		cin >> elem->record.otch;
		cout << "�������� �������: ";
		cin >> elem->record.dom;
		cout << "������� �������: ";
		cin >> elem->record.work;
		cout << "��������� �������: ";
		cin >> elem->record.mobil;
		cout << "�������������� ����������: ";
		cin >> elem->record.info;
		elem->record.next = head;
		head = elem;
		kol++;
	}
	void readData(FILE *in, Phonebook *&head, Phonebook **&mas, int &kol) {          // ������ ������ �� ����� � ������
		char filename[128];
		cout << "������� ��� ����� ��� ������: ";
		cin >> filename;
		if (fopen_s(&in, filename, "r") != 0) {
			cout << "�� ������� ������� ���� " << filename << " ��� ������\n";
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
			cout << "������ �������� ����� ��� ������\n";
			system("pause");
			exit(2);
		}
		cout << "������ ������� ��������� �� ����� " << filename << "\n";
	}
	void writeData(FILE *out, Phonebook **mas, int kol) { // ������� ������ � ����
		char buffer[OUTBUFFER];
		char filename[128];
		cout << "������� ��� ����� ��� ������: ";
		cin >> filename;
		if (fopen_s(&out, filename, "w") != 0) {
			cout << "�� ������� ������� ���� " << filename << " ��� ������\n";
			system("pause");
			exit(4);
		}
		fputs("============================================================================================================================================\n", out);
		fputs("| � |      �������       |         ���        |      ��������      |�������� �������|�������  �������|�������. �������|     ����������     |\n", out);
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
			cout << "�� ������� ������� ���� " << filename << " ����� ������\n";
			system("pause");
			exit(4);
		}
		cout << "������ ������� ��������� � ����� " << filename << "\n";
	}
	void del(Phonebook **&mas, int &kol) {                  // ������� �������� ������ 
		int pos;
		do {
			cout << "\n������� ���������� ����� �������� ��� ��������: ";
			while (cin.get() != '\n');
			cin >> pos;
			if (pos <= 0 || pos > kol)
				cout << "�������! ��������� ����!\n";
		} while (pos <= 0 || pos > kol);
		--kol;
		Phonebook**ptr = new Phonebook*[kol];               // �������� ������� ���������� �� ������
		int n = 0;
		for (int i = 0; i < pos - 1; i++, n++) {            // ������������ ��������� �� ������� � ����� ������ ����������
			ptr[n] = mas[i];
		}
		for (int i = pos; i < kol + 1; i++, n++) {          // ���������� ��������� ������� � ������������ ��������� ����� �������
			ptr[n] = mas[i];
		}
		delete[] mas;                                       // ������� ������ ������ ���������� �� ���������
		mas = ptr;                                          // ������������� ������ ������ ���������� �� �����
		cout << "������ � " << pos << " �������!\n";
	}
	void search(Phonebook **mas, int kol) {
		cout << "\n����� �� �������, ����� � �������� ��������\n";
		char fam[100];
		char name[100];
		char otch[100];
		cout << "������� �������: ";
		cin >> fam;
		cout << "������� ���: ";
		cin >> name;
		cout << "������� ��������: ";
		cin >> otch;
		int n = 0;
		for (int i = 0; i < kol; i++) {
			if (strcmp(mas[i]->record.fam, fam) == 0&& strcmp(mas[i]->record.name, name) == 0 && strcmp(mas[i]->record.otch, otch) == 0) {
				n++;                          // ���� ����� �� �������
				if (n < 2) {                  // ���� ������ ��� �� �������� ���������
					printHead();
				}
				printOne(mas[i], i);
			}
		}
		if (n) cout << "============================================================================================================================================\n";
		if (n == 0) cout << "������� "<< fam << " " << name << " " << otch <<" �� ������!\n";
	}
};
void quit() {                                         // ������� ������
	cout << "���������� ������!\n";
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
	cout << "���������� ������ ������.\n";
	while (vyb < 1 || vyb>2) {
		cout << "�������� ������ �����:\n";
		cout << "1 - ������ ����;\n";
		cout << "2 - ���� �� �����;\n";
		cout << "��� �����: ";
		cin >> vyb;
		switch (vyb)
		{
		// ������ ����
		case 1:
			short n;
			do {
				system("cls");
				head->initManual(head, kol);
				cout << "\n������� ������ ��������?\n1 - ��\n0 - ���\n��� �����: ";
				cin >> n;
			} while (n);
			head->creatArray(head, mas, kol);              // �������� ������� ���������� �� �������� ������
			break;
		// ���� �� �����
		case 2:
			head->readData(in, head, mas, kol);
			system("pause");
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - �������� ��������\n";
		cout << "2 - ������� ��������\n";
		cout << "3 - ����� �� �������, �����, ��������\n";
		cout << "4 - �������� ���� ���������\n";
		cout << "5 - ��������� ���������� � ����\n";
		cout << "6 - ��������� ���������� �� �����\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
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
			cout << "�������! ��������� ����!\n";
		}
	}
	return 0;
}
