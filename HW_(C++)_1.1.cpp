//                          ����.�������� - ��������������� ���������������� �� C++.
//                     ������ 1. �������� � �������� - ��������������� ����������������.
//                                            �������� ������� �1.
//                                                 ������� 1.
// ���������� ����� �����. ���������� ������� ��������� � ����������� � �������� ���������� - ������.
// ���������� ������� - �����:
// -��� ����� ������ � ���������� - �����;
// -��� ���������� �������������� ��������(��������, ���������, ���������, �������).
#include <iostream>
#define N 11
using namespace std;
class fract 
{
	int ch, zn, ch_1, zn_1, ch_2, zn_2, whole;
public:
	fract(int chisl_1, int znam_1, int chisl_2, int znam_2);
	void optim();
	void sum();
	void razn();
	void ymn();
	void del();
	int get_ch()         // ������� ��������� �������� ���������
	{
		return ch;
	}
	int get_zn()         // ������� ��������� �������� �����������
	{
		return zn;
	}
	int get_whole()      // ������� ��������� �������� ������
	{
		return whole;
	}
};
// ����������� (���� ������ � ����������-�����)
fract::fract(int chisl_1, int znam_1, int chisl_2, int znam_2)
{
	ch_1 = chisl_1;
	zn_1 = znam_1;
	ch_2 = chisl_2;
	zn_2 = znam_2;
	whole = 0;
}
// ������� �����������
void fract::optim()
{
	if (ch%zn == 0) 
	{
		whole = ch / zn;
		zn = 0;            // ���������� ���� ��� � ��� ������ ����� �����
	}
	else if ((ch / zn)!=0)
	{
		whole = ch / zn;
		ch %= zn;
		ch = abs(ch);      // ������� ����� � ��������� ���� ������������� ��������
	}
	if (ch < zn) {
		for (int i = 10; i > 1; i--) //���������� ��������� �������� ������ �������� ��������� � �����������
		{	
			if (ch%i == 0 && zn%i == 0)
			{
				ch /= i;
				zn /= i;
				i = 10;
			}
		}
	}
}

// ������� ��������
void fract::sum()
{
	if (zn_1 == zn_2) 
	{
		zn = zn_1;
		ch = ch_1 + ch_2;
	}
	else if (zn_1%zn_2==0) 
	{
		zn = zn_1;
		ch = ch_2*(zn_1/zn_2)+ch_1;
	}
	else if (zn_2%zn_1 == 0) 
	{
		zn = zn_2;
		ch = ch_1 * (zn_2 / zn_1) + ch_2;
	}
	else 
	{
		zn = zn_1*zn_2;
		ch = ch_1 * zn_2 + ch_2 * zn_1;
	}
}

// ������� ���������
void fract::razn()      
{
	if (zn_1 == zn_2) {
		zn = zn_1;
		ch = ch_1 - ch_2;
	}
	else if (zn_1%zn_2 == 0) {
		zn = zn_1;
		ch = ch_2 * (zn_1 / zn_2) - ch_1;
	}
	else if (zn_2%zn_1 == 0) {
		zn = zn_2;
		ch = ch_1 * (zn_2 / zn_1) - ch_2;
	}
	else {
		zn = zn_1 * zn_2;
		ch = ch_1 * zn_2 - ch_2 * zn_1;
	}
}

// ������� ���������
void fract::ymn()
{
	ch = ch_1 * ch_2;
	zn = zn_1 * zn_2;
}

// ������� �������
void fract::del()
{
	ch = ch_1 * zn_2;
	zn = zn_1 * ch_2;
}

// ������� �������� ������ (��������� ��������� � �����������) - ��� ����� ��������������� ����� (�������� 1/2, 2/6 � �.�)
void parsing(char*buffer, int &chisl, int &znam);

// ������� ������
void print(fract f, char*str1, char*str2, char*op, int choice);

int main() 
{
	setlocale(LC_ALL, "rus");
	int ch_1, zn_1, ch_2, zn_2, choice, n=0;
	char str1[N], str2[N], op[4] = {'+', '-', '*', '/'};
	cout << "\t\tC++. ������� 1\n���������� ������ �����\n";
	cout << "������ ����� �����: 1/2, 2/6, 3/4 � �.�.\n";
	do
	{
		n++;
		cout << "\n=======================================\n";
		cout << "\t\t������ �" << n << "             |" << endl;
		cout << "=======================================\n";
		cout << "������� 1 �����: ";
		cin >> str1;
		cout << "������� 2 �����: ";
		cin >> str2;
		parsing(str1, ch_1, zn_1);
		parsing(str2, ch_2, zn_2);
		fract f(ch_1, zn_1, ch_2, zn_2);
		cout << "\n�������� �������������� ��������:\n";
		cout << "1 - ��������:\t" << str1 << " " << op[0] << " " << str2 << endl;
		cout << "2 - ���������:\t" << str1 << " " << op[1] << " " << str2 << endl;
		cout << "3 - ���������:\t" << str1 << " " << op[2] << " " << str2 << endl;
		cout << "4 - �������:\t" << str1 << " " << op[3] << " " << str2 << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			f.sum();
			f.optim();
			print(f, str1, str2, op, choice);
			break;
		case 2:
			f.razn();
			f.optim();
			print(f, str1, str2, op, choice);
			break;
		case 3:
			f.ymn();
			f.optim();
			print(f, str1, str2, op, choice);
			break;
		case 4:
			f.del();
			f.optim();
			print(f, str1, str2, op, choice);
			break;
		default: cout << "������! ������������ ����!\n";
		}
		cout << "������� ���������� ����������?\n1 - ��\n0 - ���\n";
		cout << "��� �����: ";
		cin >> choice;
	} while (choice);
	system("pause");
	return 0;
}

// ������� �������� ������ (��������� ��������� � �����������) - ��� ����� ��������������� ����� (�������� 1/2, 2/6 � �.�)
void parsing(char*buffer, int &chisl, int &znam) 
{
	char *word, *next;
	char tmp[N]; 
	strcpy_s(tmp, buffer);
	word = strtok_s(tmp, "/\n", &next);
	chisl = atoi(word);
	if (*next == '\0')
	{
		znam = 1;
	}
	else
	{
		word = strtok_s(NULL, "\n", &next);
		znam = atoi(word);
	}
}

// ������� ������
void print(fract f, char*str1, char*str2, char*op, int choice)
{
	cout << "\n�����: " << "\t" << str1 << " " << op[choice - 1] << " " << str2 << " = ";
	if (f.get_whole() && f.get_zn())
	{
		cout << f.get_whole() << " " << f.get_ch() << "/" << f.get_zn() << endl;
	}
	else if (f.get_zn() == 0)
	{
		cout << f.get_whole() << endl;
	}
	else
	{
		cout << f.get_ch() << "/" << f.get_zn() << endl;
	}
}
