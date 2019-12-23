#define _CRT_SECURE_NO_WARNINGS 0
#define MAXN 25000
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <time.h>
using namespace std;

typedef struct Node {
	char sign1 = '+';//��һ���������ķ���
	char ctr1[MAXN] = { '\0' };//��һ���������ַ���(����)
	int itr1[MAXN] = { 0 };//��һ���������ַ���ת��Ϊ������(����)
	int Lenctr1;//��һ���������ĳ���

	char sign2 = '+';//�ڶ����������ķ���
	char ctr2[MAXN] = { '\0' };//�ڶ����������ַ���(����)
	int itr2[MAXN] = { 0 };//�ڶ����������ַ���ת��Ϊ������(����)
	int Lenctr2;//�ڶ����������ĳ���

	char signresult = '+';//�������������ķ���
	char cresult[MAXN] = { '\0' };//���������õ��Ĵ������ṹ�ַ���(����)
	int iresult[MAXN] = { 0 };//�����������(����)
	int Lencresult;//�������
}Node;

void page__title(char* menu_item) {
	printf("\n\t* * * * * * * * * ���������� * * * * * * * * * *");
	printf("\n\n\t * *          -������-%s-������-          * *\n\n", menu_item);
	printf("\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("* *�����������������ݣ�\n\n");
}
void page_title() {
	printf("\n\t* * * * * * * * * * ���������� * * * * * * * * * *\n\n");
	cout << "\t   1.����-�ӷ�-����           2.����-����-����" << endl << endl;
	cout << "\t   3.����-�˷�-����                          " << endl;
	printf("\n\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	cout << "* *������������е�������ţ�";
}

void Addition(Node& K) {//�ӷ�����
	clock_t startTime, endTime;
	startTime = clock();
	if (K.Lenctr1 < K.Lenctr2) {
		swap(K.sign1, K.sign2);
		swap(K.ctr1, K.ctr2);
		swap(K.Lenctr1, K.Lenctr2);
	}
	else {
		if (strcmp(K.ctr1, K.ctr2) < 0 && K.Lenctr1 == K.Lenctr2) {
			swap(K.sign1, K.sign2);
			swap(K.ctr1, K.ctr2);
		}
	}
	for (int i = K.Lenctr1 - 1, j = 0;i >= 0;i--, j++) {//��ctr1�ַ�������ת��Ϊ��������
		K.itr1[j] = K.ctr1[i] - '0';
	}
	for (int i = K.Lenctr2 - 1, j = 0;i >= 0;i--, j++) {//��ctr2�ַ�������ת��Ϊ��������
		K.itr2[j] = K.ctr2[i] - '0';
	}
	K.Lencresult = K.Lenctr1;
	for (int i = 0;i < K.Lencresult;i++) {
		K.iresult[i] = K.itr1[i] + K.itr2[i];//���мӷ�����
	}
	for (int i = 0;i < K.Lencresult;i++) {//�ж��Ƿ��λ
		if (K.iresult[i] >= 10) {
			K.iresult[i] %= 10;
			K.iresult[i + 1]++;
		}
	}
	int k = 0;//�ж�K.iresult���һ������Ԫ�ز�Ϊ0���±�
	for (int i = 0;i <= K.Lencresult;i++) {
		if (K.iresult[i] != 0) k = i;
	}
	for (int i = k, j = 0;i >= 0;i--) {//����������ת��Ϊ�ַ�������
		K.cresult[j++] = K.iresult[i] + '0';
	}
	K.Lencresult = k + 1;
	K.signresult = K.sign1;
	cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
	cout << K.signresult;
	for (int i = 0;i <= k;i++) {//������
		cout << K.cresult[i];
	}
	cout << endl << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl << endl;
}

void Subtraction(Node& K) {//��������
	clock_t startTime, endTime;
	startTime = clock();
	if (K.Lenctr1 < K.Lenctr2) {
		swap(K.sign1, K.sign2);
		swap(K.ctr1, K.ctr2);
		swap(K.Lenctr1, K.Lenctr2);
		if (K.sign1 == '-') K.sign1 = '+';
		else K.sign1 = '-';
	}
	else {
		if (strcmp(K.ctr1, K.ctr2) < 0 && K.Lenctr1 == K.Lenctr2) {
			swap(K.sign1, K.sign2);
			swap(K.ctr1, K.ctr2);
		}
	}
	for (int i = K.Lenctr1 - 1, j = 0;i >= 0;i--, j++) {//��ctr1�ַ�������ת��Ϊ��������
		K.itr1[j] = K.ctr1[i] - '0';
	}
	for (int i = K.Lenctr2 - 1, j = 0;i >= 0;i--, j++) {//��ctr2�ַ�������ת��Ϊ��������
		K.itr2[j] = K.ctr2[i] - '0';
	}
	K.Lencresult = K.Lenctr1;
	for (int i = 0;i < K.Lencresult;i++) {
		K.iresult[i] = K.itr1[i] - K.itr2[i];//���м�������
	}
	for (int i = 0;i < K.Lencresult;i++) {//�ж��Ƿ���λ
		if (K.iresult[i] < 0) {
			K.iresult[i] += 10;
			K.iresult[i + 1]--;
		}
	}
	int k = 0;//�ж�K.iresult���һ������Ԫ�ز�Ϊ0���±�
	for (int i = 0;i <= K.Lencresult;i++) {
		if (K.iresult[i] != 0) k = i;
	}
	for (int i = k, j = 0;i >= 0;i--) {//����������ת��Ϊ�ַ�������
		K.cresult[j++] = K.iresult[i] + '0';
	}
	K.Lencresult = k + 1;
	if (k != 0) {
		if (K.Lenctr1 >= K.Lenctr2) {
			K.signresult = K.sign1;
		}
		else {
			K.signresult = K.sign2;
		}
	}
	else {
		K.signresult = '+';
	}
	cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
	cout << K.signresult;
	for (int i = 0;i <= k;i++) {//������
		cout << K.cresult[i];
	}
	cout << endl << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl << endl;
}

void Multiple(Node& K) {//�����˷�
	clock_t startTime, endTime;
	startTime = clock();
	if (K.Lenctr1 < K.Lenctr2) {
		swap(K.sign1, K.sign2);
		swap(K.ctr1, K.ctr2);
		swap(K.Lenctr1, K.Lenctr2);
	}
	else {
		if (strcmp(K.ctr1, K.ctr2) < 0 && K.Lenctr1 == K.Lenctr2) {
			swap(K.sign1, K.sign2);
			swap(K.ctr1, K.ctr2);
		}
	}
	for (int i = K.Lenctr1 - 1, j = 0;i >= 0;i--, j++) {//��ctr1�ַ�������ת��Ϊ��������
		K.itr1[j] = K.ctr1[i] - '0';
	}
	for (int i = K.Lenctr2 - 1, j = 0;i >= 0;i--, j++) {//��ctr2�ַ�������ת��Ϊ��������
		K.itr2[j] = K.ctr2[i] - '0';
	}
	K.Lencresult = K.Lenctr1 * K.Lenctr1;
	for (int i = 0;i < K.Lenctr1;i++) {
		for (int j = 0;j < K.Lenctr2;j++) {
			K.iresult[i + j] += K.itr1[i] * K.itr2[j];
		}
	}
	for (int i = 0;i <= K.Lencresult;i++) {//�ж��Ƿ��λ
		if (K.iresult[i] >= 10) {//�ж�����Ԫ���Ƿ����10
			K.iresult[i + 1] += K.iresult[i] / 10;//�������10�������10��λ
			K.iresult[i] %= 10;
		}
	}
	int k = 0;//�жϽ�����������һ����Ϊ0������Ԫ�ص��±�
	for (int i = 0;i <= K.Lencresult;i++) {
		if (K.iresult[i] != 0) k = i;
	}
	for (int i = k, j = 0;i >= 0;i--) {//����������ת��Ϊ�ַ�������
		K.cresult[j++] = K.iresult[i] + '0';
	}
	K.Lencresult = k + 1;
	switch (K.sign1) {//�ж���������������
	case '-':
		if (K.sign2 == '-') K.signresult = '+';
		else K.signresult = '-';
		break;
	case '+':
		if (K.sign2 == '-') K.signresult = K.sign2;
		else K.signresult = K.sign1;
		break;
	default:
		if (K.sign2 == '-') K.signresult = K.sign2;
		else K.signresult = '+';
	}
	cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
	cout << K.signresult;
	for (int i = 0;i <= k;i++) {//������
		cout << K.cresult[i];
	}
	cout << endl << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl << endl;
}

void Charscanf(Node& K) {//��������
	char str1[MAXN], str2[MAXN];
	scanf("%s %s", str1, str2);//����һ�����ݸ���str1,���ڶ������ݸ���str2
	int Lenstr1 = strlen(str1), Lenstr2 = strlen(str2);
	if (str1[0] != '-' && str1[0] != '+') {
		strcpy(K.ctr1, str1);
	}
	else {
		K.sign1 = str1[0];
		for (int i = 1, j = 0;i < Lenstr1;i++) {
			K.ctr1[j++] = str1[i];
		}
	}
	if (str2[0] != '-' && str2[0] != '+') {
		strcpy(K.ctr2, str2);
	}
	else {
		K.sign2 = str2[0];
		for (int i = 1, j = 0;i < Lenstr2;i++) {
			K.ctr2[j++] = str2[i];
		}
	}
	K.Lenctr1 = strlen(K.ctr1), K.Lenctr2 = strlen(K.ctr2);
}

int main() {
	Node K;//����һ�����
	system("color F0");
al:char ch;
	page_title();
	cin >> ch;
	switch (ch) {//ѡ������㷨
	case '1':system("cls");page__title("�ӷ�");Charscanf(K);
		switch (K.sign1) {
		case '-':
			if (K.sign2 == '-') Addition(K);
			else Subtraction(K);
			break;
		case '+':
			if (K.sign2 == '-') Subtraction(K);
			else Addition(K);
			break;
		default:
			if (K.sign2 == '-') Subtraction(K);
			else Addition(K);
		}
		break;
	case '2':system("cls");page__title("����");Charscanf(K);
		switch (K.sign1) {
		case '-':
			if (K.sign2 == '-') Subtraction(K);
			else Addition(K);
			break;
		case '+':
			if (K.sign2 == '-') Addition(K);
			else Subtraction(K);
			break;
		default:
			if (K.sign2 == '-') Addition(K);
			else Subtraction(K);
		}
		break;
	case '3':system("cls");page__title("�˷�");Charscanf(K);Multiple(K);break;
	default:
		cout << "\n***��ʽ�������������룡����\n" << endl;
		Sleep(1500);
		system("cls");
		goto al;
	}
	return 0;
}

