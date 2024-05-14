#include"String.h"
int main()
{
	my_string::string s("abcd");
	my_string::string s1("a");
	my_string::string::iterator begin = s.begin();
	/*for (; begin < s.end(); begin++)
	{
		cout << *begin<<' ';
	}*/
	s.push_back("a");
	s.push_back("axxxx");
	s.push_back("a");
	s.push_back('q');
	s.pop_back();
	s.insert(1, "1111");

	cout << s.str()<<endl;	
	//cout << endl << s.find(0, "cdfff");
	my_string::string ret=s.substr(0,5 );
	//cout << ret.str();
	cin >> s;
	cout << s;

	return 0;
}