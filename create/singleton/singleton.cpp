#include <iostream>
#include <string>
using namespace std;

class singleton{
public:
	/*
	 * it need to be the static method, otherwise it will produce compile error:
	 * "error: cannot call member function ‘singleton* singleton::get_singleton()’ without object"
	 * */
	/*成员函数没有定义为static类型 -> cannot call member function '' without object
	*/
	static class singleton *get_singleton()
	{
		if (!p)
			p = new singleton();
		return p;
	}
	void show_name()
	{
		cout << "my address:0x"<< p << " and my name is "<< p->name <<endl;
	}
	void set_name(string s)
	{
		p->name = s;	
	}
	~singleton()
	{
		delete p;
		p = NULL;
	}
private:
	static class singleton *p;
	string name;
	singleton()
	{
	}
	
};
singleton *singleton::p = NULL;
int main()
{
	singleton *ps = singleton::get_singleton();
	ps->set_name("singleton1");
	ps->show_name();
	ps->set_name("singleton2");
	ps->show_name();
}
