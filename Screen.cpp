
#include <iostream>
#include <vector>
#include <string>
using std::string; using std::vector;

class Screen;
class Windows
{

	vector<Screen> screens;	
	
public:
	using pos = vector<Screen>::size_type;
	void clear(pos);

};

class Screen
{
private: 
	friend void Windows::clear(pos index);
private:
	using pos = string::size_type;

	pos height=0, width=0;
	string contents;

public:
	Screen();
	Screen(pos wd, pos ht) :width(wd), height(ht), contents(wd* ht,' ') {}
	Screen(pos wd,pos ht,char c):width(wd),height(ht),contents(wd*ht,c){}
	
	

};
Screen::Screen() = default;

void Windows::clear(pos index)
{
	Screen& s = screens[index];
	s.contents = string(s.width * s.height, ' ');
}

void main()
{
	
}