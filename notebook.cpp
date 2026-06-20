//3.4
#if 0
#include 
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string a, b;
	cin >> a >> b;
	if (a == b)
		cout
	else
		coutb ? a : b)//这样更简洁
		return 0;
}
3.6
#include<string>
#include<iostream>
int main() 
{
	std::string s = "Hello, World!";
	for (char &c : s) //这里应该是引用 c = 'X';
	{
	 std::cout << s << std::endl; return 0;
	}
}
#endif

//3.20
#if 0
#include <iostream>
#include<vector>
using std::vector;
int main()
{
	vector<int> a;
	int input;
	while (std::cin >> input)
	{
		a.push_back(input);
	}
	if (a.size() == 0)
			return 0;

	
	for (decltype(a.size()) i = 0; i < a.size() - 1; i += 2)
	{
		int result = 0;
		result = a[i] + a[i + 1];
		std::cout << result << std::endl;
	}
	if (a.size() % 2 != 0)
		std::cout << a[(a.size() - 1)] << std::endl;
	return 0;
}
#endif
#if 0
#include <iostream>
#include<vector>
using std::vector;
int main()
{
	vector<int> a;
	int input;
	while (std::cin >> input)
	{
		a.push_back(input);
		std::cout << "continue input?" << std::endl<< "Y or N" << std::endl;
		char l;
		std::cin >> l;
		if (l != 'Y' && l != 'y')
			break;

	}

		if (a.size() == 0)
			return 0;

	
	for (decltype(a.size()) i = 0; i < a.size()/2; i++)
	{
		int result = 0;
		result = a[i] + a[a.size()-1-i];
		std::cout << result << std::endl;
	}
	if (a.size() % 2 != 0)
		std::cout << a[(a.size() - 1)/2] << std::endl;
	return 0;
}
#endif
//3.24
#if 0
#include <iostream>
#include <vector>
using std::vector;
int main()
{
	vector <int> a;
	int input;
	while (std::cin >> input)
		a.push_back(input);
	if (a.end() == a.begin())
		return 0;
	for (auto i = a.begin(); i < a.end() - 1; i += 2)
		std::cout << *i + *(i + 1) << std::endl;
	if ((a.end() - a.begin()) % 2 != 0)
		std::cout << *(a.begin() + a.size() - 1) << std::endl;
	return 0;
}
#endif 
//3.43
#if 0
#include<iterator>
#include<iostream>
using std::begin;
using std::end;
void main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	/*
	for (int(* p)[4] = ia; p < end(ia); p++)
		for (int* q = *p; q < end(*p); q++)
			std::cout << *q;
	std::cout << std::endl;
	*/
	for (int(&p)[4] : ia)
		for (int q : p)
			std::cout << q;
	std::cout << std::endl;

	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++)
			std::cout << ia[i][j];
	std::cout << std::endl;


#endif
#if 0
	//5.5
#include<iostream>
#include<vector>
	using std::string;
	using std::vector;
	void main()
	{
		const vector<string> s = { "F","D","C","B","A","A++" };
		int grade;
		string letgrade;
		while (std::cin >> grade)
		{
			(grade < 60 ? letgrade = s[0] : (letgrade = s[grade / 10 - 5], (grade != 100 ? (grade % 10 > 3 ? (grade % 10 > 7 ? letgrade += "+" : "") : letgrade += "-") : "")));
			std::cout << letgrade << std::endl;
		}

	}
#endif
#if 0
	//5.17
#include<vector>
	using std::vector;
#include<iostream>
	int main()
	{
		vector<int> a{};
		vector<int> b{};
		int input;
		while (std::cin >> input)
			a.push_back(input);
		std::cin.clear(); // 清状态位，让 cin 恢复良好
		std::cin.ignore();// 如果之前按了 Ctrl+Z/Ctrl+D，还需要 ignore 吃掉流里的残留// 忽略一个字符，如换行符
		while (std::cin >> input)
			b.push_back(input);
		vector<int> t{};
		if (a.size() > b.size())
		{
			t = a;
			a = b;
			b = t;
		}
		if (t.empty())
		{
			for (decltype(a.size())i = 0; i != a.size(); i++)
			{
				if (a[i] != b[i])
				{
					std::cout << "a not in b" << std::endl;
					return 0;
				}

			}
			std::cout << "a in b" << std::endl;
		}
		else
		{ 
			for (decltype(a.size())i = 0; i != a.size(); i++)
			{
				if (a[i] != b[i])
				{
					std::cout << "b not in a" << std::endl;
					return 0;
				}
			}
			std::cout << "b in a" << std::endl;
		}
	}
#endif
	//5.17 最优解
#if 0
#include<vector>
	using std::vector;
#include<iostream>
	int  Input(vector <int>& p)
	{
		int x;
		while (std::cin >> x)
			p.push_back(x);
		return 0;
	}

	bool compare(auto shorter, auto longer, auto count)
	{
		for (vector<int>::size_type i = 0; i != count; i++)
		{
			if (*(shorter + i) != *(longer + i))
				return false;
		}
		return true;
	}
	int main()
	{
		vector<int> a;
		vector<int> b;
		Input(a);
		std::cin.clear();
		std::cin.ignore();
		Input(b);
		auto pa = a.begin();
		auto pb = b.begin();
		if (a.size() > b.size())
			std::cout << (compare(pb, pa, b.size()) ? "b in a" : "b not in a");
		else
			std::cout << (compare(pa, pb, a.size()) ? "a in b" : "a not in b");
	}
#endif
#if 0
	//大成之作 2026 6 7
#include<iostream>
#include<stdexcept>
	class Sales_item
	{
	public:
		int isbn;
		int number;
		int price;
		int total;
	};
	std::istream& operator >>(std::istream& p1, Sales_item& p2)
	{
		p1 >> p2.isbn >> p2.number >> p2.price;
		return p1;
	}
	Sales_item operator+(Sales_item& p1, Sales_item& p2)
	{
		int total_number = p1.number + p2.number;
		Sales_item p3 = Sales_item(p1.isbn, total_number, p1.price, total_number * p1.price);
		return p3;

	}
	std::ostream& operator <<(std::ostream& p1, const Sales_item& p2)//这里const是为了接收临时对象p3 const 代表不能修改，
		//修改一个临死对象本身是没有意义的 真正的原因是防止引用悬垂
	{
		p1 << p2.isbn << p2.number << p2.price << p2.total;
		return p1;
	}
	void main()
	{
		Sales_item item1, item2;
		while (std::cin >> item1 >> item2)
		{
			try
			{
				if (item1.isbn != item2.isbn)
					throw std::runtime_error("You must input same book");
				std::cout << (item1 + item2);
			}
			catch (std::runtime_error e)
			{
				std::cout << e.what() << std::endl;
				std::cout << "continue" << std::endl << "Y or N";
				char  c;
				std::cin >> c;
				if (c == 'N')
					break;
			}
		}

	}
	//6.25
#include <string>
#include<iostream>
	using std::string;
	int main(int argc, char* array[])
	{
		for (size_t i = 0; i != argc; i++)
		{
			while (*array[i] != '\0')
				std::cout << *(array[i]++);

		}
		std::cout << std::endl;
	}

	//P265
#include <string>
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;
	public:
		Entity(const std::string& name)
			: m_Name(name), m_Age(-1) {}

		Entity(int age)
			: m_Name("Unknown"), m_Age(age) {}
	};
	void PrintEntity(const Entity& entity)
	{

	}

	int main()
	{
		PrintEntity(22);
		PrintEntity("Cherno");   //PrintEntity(std::string("Cherno"))  或 PrintEntity(Enity("Cherno"))

		Entity a("Cherno");
		Entity b = "Cherno";     //同上
		Entity b = 22;

	}


#include <string>
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;
	public:
		explicit Entity(const std::string& name)//禁用string到Entity隐式转换
			: m_Name(name), m_Age(-1) {}
	};
	void PrintEntity(const Entity& entity)
	{

	}

	int main()
	{

		PrintEntity(std::string("Cherno"));  // PrintEntity(Entity("Cherno"));

		Entity a("Cherno");
		Entity b = "Cherno";     //同上


	}

#endif
	//7.43
#if 0
	class Nodefault
	{
		int i;
	public:
		Nodefault(int a) { i = a; }

	};
	class C
	{
		Nodefault c;
	public:
		C() :c(0) {}
	};
	void main()
	{

	}

	//88页
#include <vector>
#include <string>
	using std::string;
	using std::vector;
	class Player
	{
		int a{ 1 };

		int a = 1;
		int a = (1);
		int a = { 1 };
	};
	void main()
	{
		//
		string s("abc");
		string s{ "abc" };

		string s = "abc";
		string s = ("abc");
		string s = { "abc" };
		//
		vector<int> a(10);//有十个元素，全部默认初始化为0；//如果使用圆括号，则要数字开头，表示数量
		vector<int> a(10, 1);//与uuu有十个元素，默认初始化为1；//数字开头
		vector<int> a{ 1,2,3 };
		vector<int> a = { 1,2 ,3 };



	}
#endif

	