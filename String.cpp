#include"String.h"

namespace my_string
{
	//���� �޲�
	char* string:: reserve()
	{
		_capacity = _capacity == 0 ? 4: 2 * _capacity;
		char* ret = new char[_capacity];
		strcpy(ret, _str);
		return ret;
	}
	//���� �в�
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
	//���� ����Ϊ�����ַ���
	string::string(const char* str)
	{
		int len=strlen(str);
		_str=this->reserve(len+1);//��/0����
		_size = len;
		strcpy(_str, str);
	}
	//��������
	string::string(const string& s)
	{
		_str = (*this).reserve(s._size);
		strcpy(_str, s._str);
		(*this)._size = s._size;
	}

	//������
	char* string:: begin()
	{
		return _str;
	}
	char* string::end()
	{
		return _str + _size;
	}

	//β��
	void string:: push_back(const char &c)//β���ַ�
	{
		if (_size + 1 >= _capacity)
		{
			_str = (*this).reserve();
		}
		strcat(_str, &c);
		_size++;
	}
	void string:: push_back(const char* s)//β���ַ���
	{
		int len=strlen(s);
		if (_size + len > _capacity)
		{
			_str = reserve(2 * _capacity);
		}
		
		strcpy(_str + _size, s);
		_size += len;
		
	}
	//βɾ
	void string::pop_back()
	{
		assert(_size > 0);
		_size--;
		_str[_size] = 0;
	}

	//�ض�λ�ò���
	void string:: insert(size_t pos ,const char&c)//�����ַ�
	{
		assert(pos <= _size);
		assert(_size >= 0);
		if (_size+1 >= _capacity)
		{
			(*this).reserve();
		}
		int end = _size;  //����
		//����Ų��һλ
		for (end = _size; end >= (int)pos; end--)//��pos������ʱ��Ҳ����ͷ��ʱ��end��pos���бȽ�ʱ�����end��ʽת����size_t���ͣ��޷������Σ���end�������С���㣬����Ҫ��posǿ��ת����int
		{
			_str[end+1 ] = _str[end];
		}
		_str[end+1] = c;
		_size++;
	}
	void string:: insert(size_t pos ,const char* s)//�����ַ���
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

	//ɾ��
	void string:: erase()
	{	
		_str[0] = 0;
		_size = 0;
	}

	//��������
	char* string:: str()const
	{
		return _str;
	}


	//Ԫ�ظ���
	int string:: size()
	{
		return _size;
	}

	size_t string:: find(size_t pos,const char& c)//�����ַ�
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

	size_t string::find(size_t pos, const char* s)//�����ַ���
	{
		assert(pos <= _size);
		if (strstr(_str, s) == nullptr)
			return -1;
		else
			return strstr(_str, s) - _str;
		return -1;
	}

	//���������
		//[]
	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}

	//+=
	string& string:: operator+=(const char c)//���ַ�
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

	//ȫ��ɾ��
	void string:: clear()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	string&string:: operator+=(const string& s)//���ַ���
	{
		insert(_size, s._str);
		
		return *this;
	}


	//append ׷���ַ���
	void string:: append(const char* s)
	{
		insert(_size, s);
	}

	//�������ַ���
	string string:: substr(size_t pos , size_t len)
	{
		char* retstr= new char[len];
		strncpy(retstr, _str + pos, len);
		string ret(retstr);
		return ret;
	}


	
	
}
//������
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

//����ȡ
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

