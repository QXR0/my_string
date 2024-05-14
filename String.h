#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
#define npos -1
using namespace std;

namespace my_string
{
	class string
	{
	private:
		char* _str=nullptr;
		int _size=0;
		int _capacity=0;
	public:
		char* reserve();//����
		char* reserve(int len);//����
		
		string(const char*str);//����
		string(const string & s );//��������
		
		//������
		typedef char* iterator;
		iterator begin();
		iterator end();

		//β��
		void push_back(const char& c);//β���ַ�
		void push_back(const char*s);//β���ַ���

		//βɾ
		void pop_back();

		//�ض�λ�ò���
		void insert(size_t pos ,const char &c);//�����ַ�
		void insert(size_t pos ,const char*s);//�����ַ���

		//ɾ��
		void erase();

		//��������
		char* str()const;

		//Ԫ�ظ���
		int size();

		//����Ԫ��
		size_t find(size_t pos,const char &c);//�����ַ�
		size_t find(size_t pos,const char*s );//�����ַ���

		//���������
		//[]
		char& operator[](size_t pos);
		
		//+=
		string& operator+=(const char c);//���ַ�
		string &operator+=(const string& s);//���ַ���

		//<
		bool operator<(const string &s);

		//>
		bool operator>(const string& s);

		//==
		bool operator==(const string& s);

		//>=
		bool operator>=(const string& s);

		//<=
		bool operator<=(const string& s);

		//!=
		bool operator!=(const string& s);

		//ȫ��ɾ��
		void clear();

		//append ׷���ַ���
		void append(const char* s);

		//�������ַ���
		string substr(size_t pos = 0, size_t len = npos);

		

	};

}

//������
ostream& operator<<(ostream& out,  my_string:: string& s);

//����ȡ
istream& operator>>(istream& in, my_string::string& s);
