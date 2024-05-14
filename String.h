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
		char* reserve();//扩容
		char* reserve(int len);//扩容
		
		string(const char*str);//构造
		string(const string & s );//拷贝构造
		
		//迭代器
		typedef char* iterator;
		iterator begin();
		iterator end();

		//尾插
		void push_back(const char& c);//尾插字符
		void push_back(const char*s);//尾插字符串

		//尾删
		void pop_back();

		//特定位置插入
		void insert(size_t pos ,const char &c);//插入字符
		void insert(size_t pos ,const char*s);//插入字符串

		//删除
		void erase();

		//返回自身
		char* str()const;

		//元素个数
		int size();

		//查找元素
		size_t find(size_t pos,const char &c);//查找字符
		size_t find(size_t pos,const char*s );//查找字符串

		//运算符重载
		//[]
		char& operator[](size_t pos);
		
		//+=
		string& operator+=(const char c);//加字符
		string &operator+=(const string& s);//加字符串

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

		//全部删除
		void clear();

		//append 追加字符串
		void append(const char* s);

		//返回子字符串
		string substr(size_t pos = 0, size_t len = npos);

		

	};

}

//流插入
ostream& operator<<(ostream& out,  my_string:: string& s);

//流提取
istream& operator>>(istream& in, my_string::string& s);
