//person
//#if 0
#include <iostream>
#include<string>
using std::string;
using std::istream;
class Person
{
    friend istream& read(istream& cin, Person& p);
    string name;
    string position;
public:
    Person() = default;
    Person(string& name, string& position) :name(name), position(position) {  }
    const string& Name() const
    {
        return name;
    }
    const string& Position() const
    {
        return position;
    }
};
istream& read(istream& cin,  Person& p)
{
    std::cin >> p.name >> p.position;
    return cin;
}
int main()
{
    Person person1;
    return 0;
}
//#endif