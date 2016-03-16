#include <iostream>
#include <string>
using namespace std;

class mythologic_figure {
protected:
	string weapon;
	string cloth;
	string hair;
	string shoe;
public:
	virtual ~mythologic_figure(){}
	virtual mythologic_figure* clone() = 0;
	//virtual void show() = 0;
};

class sunwukong : public mythologic_figure {
public:
	sunwukong(string weapon, string cloth, string hair, string shoe, string mission){
		this->weapon = weapon;
		this->cloth	= cloth;
		this->hair = hair;
		this->shoe = shoe;
		this->mission = mission;
	}
	~sunwukong(){}
	sunwukong(sunwukong &swk) {
		this->weapon = swk.weapon;
		this->cloth = swk.cloth;
		this->hair = swk.hair;
		this->shoe = swk.shoe;
		this->mission = swk.mission;
	}
	mythologic_figure *clone(){
		return this;
	}
	void show(){
		cout << this->weapon << " + " << this->cloth << " + " << this->hair << " + " << this->shoe << " + " << this->mission <<endl;
	}
private:
	string mission;
};

class erlangshen : public mythologic_figure {
public:
	erlangshen(string weapon, string cloth, string hair, string shoe){
		this->weapon = weapon;
		this->cloth	= cloth;
		this->hair = hair;
		this->shoe = shoe;
	}
	~erlangshen(){}
	erlangshen(erlangshen &swk) {
		this->weapon = swk.weapon;
		this->cloth = swk.cloth;
		this->hair = swk.hair;
		this->shoe = swk.shoe;
	}
	mythologic_figure* clone(){
		return this;
	}
	void show(){
		cout << this->weapon << " + " << this->cloth << " + " << this->hair << " + " << this->shoe <<endl;
	}
};

int main()
{
	class mythologic_figure *pmf;
	class sunwukong *pswk = new sunwukong("jingubang", "pigua", "dingyu", "feixingxie", "xitianqujing");
	class erlangshen *pels = new erlangshen("sanchaji", "pigua", "dingyu", "feixingxie");

	pmf = pswk->clone();
	class sunwukong *pswk_clone = dynamic_cast<sunwukong *>(pmf);
	pswk_clone->show();
	pmf = pels->clone();
	class erlangshen *pels_clone = dynamic_cast<erlangshen *>(pmf);
	pels_clone->show();
	delete pswk;
	delete pels;
}
