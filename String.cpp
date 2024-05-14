#include"String.h"

namespace my_string
{
	//扩容 无参
	char* string:: reserve()
	{
		_capacity = _capacity == 0 ? 4: 2 * _capacity;
		char* ret = new char[_capacity];
		strcpy(ret, _str);
		return ret;
	}
	//扩容 有参
	char* string::reserve(int len)
	{
		if (_capacity < len)
		{
			_capacity = len;
			char* ret = new char[_capacity];
			if(_str!=nullptr)
			strcpy(ret, _str);
			return ret;
		}
		else
			return _str;
	}
	//构造 参数为常量字符串
	string::string(const char* str)
	{
		int len=strlen(str);
		_str=this->reserve(len+1);//把/0算上
		_size = len;
		strcpy(_str, str);
	}
	//拷贝构造
	string::string(const string& s)
	{
		_str = (*this).reserve(s._size);
		strcpy(_str, s._str);
		(*this)._size = s._size;
	}

	//迭代器
	char* string:: begin()
	{
		return _str;
	}
	char* string::end()
	{
		return _str + _size;
	}

	//尾插
	void string:: push_back(const char &c)//尾插字符
	{
		if (_size + 1 >= _capacity)
		{
			_str = (*this).reserve();
		}
		strcat(_str, &c);
		_size++;
	}
	void string:: push_back(const char* s)//尾插字符串
	{
		int len=strlen(s);
		if (_size + len > _capacity)
		{
			_str = reserve(2 * _capacity);
		}
		
		strcpy(_str + _size, s);
		_size += len;
		
	}
	//尾删
	void string::pop_back()
	{
		assert(_size > 0);
		_size--;
		_str[_size] = 0;
	}

	//特定位置插入
	void string:: insert(size_t pos ,const char&c)//插入字符
	{
		assert(pos <= _size);
		assert(_size >= 0);
		if (_size+1 >= _capacity)
		{
			(*this).reserve();
		}
		int end = _size;  //遍历
		//往后挪动一位
		for (end = _size; end >= (int)pos; end--)//当pos等于零时（也就是头插时）end和pos进行比较时，会把end隐式转换成size_t类型（无符号整形），end不会减到小于零，所以要把pos强制转换成int
		{
			_str[end+1 ] = _str[end];
		}
		_str[end+1] = c;
		_size++;
	}
	void string:: insert(size_t pos ,const char* s)//插入字符串
	{
		assert(_size > 0);
		assert(pos <=_size);
		int len = strlen(s);
		if (_size + len > _capacity)
		{
			(*this).reserve();
		}
		int end = _size;
		for (end = _size; end >= (int)pos; end--)
		{
			_str[end + len] = _str[end];
		}
		int i = 0;
		for (i = 0; i < len; i++)
		{
			_str[end +1+ i] = s[i];
		}
		_size += len;
	}

	//删除
	void string:: erase()
	{	
		_str[0] = 0;
		_size = 0;
	}

	//返回自身
	char* string:: str()const
	{
		return _str;
	}


	//元素个数
	int string:: size()
	{
		return _size;
	}

	size_t string:: find(size_t pos,const char& c)//查找字符
	{
		assert(pos <= _size);
		int i = 0;
		for (i = pos; i < _size; i++)
		{
			if (_str[i] == c)
				return i;

		}
		return -1;
	}

	size_t string::find(size_t pos, const char* s)//查找字符串
	{
		assert(pos <= _size);
		if (strstr(_str, s) == nullptr)
			return -1;
		else
			return strstr(_str, s) - _str;
		return -1;
	}

	//运算符重载
		//[]
	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}

	//+=
	string& string:: operator+=(const char c)//加字符
	{
		insert(_size, c);
		
		return *this;
	}

	//<
	bool string:: operator<(const string& s)
	{
		if (strcmp(_str, s._str) < 0)
			return 1;
		else
			return 0;
	}

	//>
	bool string:: operator>(const string& s)
	{ 
		if (strcmp(_str, s._str) > 0)
			return 1;
		else
			return 0;
	}

	//=
	bool string:: operator==(const string& s)
	{
		if (!((*this) > s)&&!((*this)<s))
			return 1;
		else
			return 0;
	}

	//>=
	bool string:: operator>=(const string& s)
	{
		if ((*this) > s || (*this) == s)
			return 1;
		else
			return 0;
	}

	//<=
	bool string:: operator<=(const string& s)
	{
		if ((*this) < s || (*this) == s)
			return 1;
		else
			return 0;
	}

	//!=
	bool string:: operator!=(const string& s)
	{
		if (!((*this) == s))
			return 1;
		else
			return 0;
	}

	//全部删除
	void string:: clear()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	string&string:: operator+=(const string& s)//加字符串
	{
		insert(_size, s._str);
		
		return *this;
	}


	//append 追加字符串
	void string:: append(const char* s)
	{
		insert(_size, s);
	}

	//返回子字符串
	string string:: substr(size_t pos , size_t len)
	{
		char* retstr= new char[len];
		strncpy(retstr, _str + pos, len);
		string ret(retstr);
		return ret;
	}


	
	
}
//流插入
ostream& operator<<(ostream& out,my_string:: string& s)
{
	int i = 0;
	int len = s.size();
	for (i = 0; i < len; i++)
	{
		out << s[i];
	}
	return out;
}

//流提取
istream& operator>>(istream& in, my_string::string& s)
{
	s.erase();
	char c = in.get();
	while (c != ' ' && c != '\n')
	{
		s += c;
		c = in.get();
	}
	//in >> *(s.str());
	return in;
}

