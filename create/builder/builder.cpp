#include <iostream>
using namespace std;

class abstract_thing{
public:
	virtual void modifier() = 0;
	virtual void first_thing() = 0;
	virtual void second_thing() = 0;
	virtual void third_thing() = 0;
};

class eat_thing : public abstract_thing {
public:
	void modifier() {
		cout << "----------------------------------------------" <<endl;
	}
	void first_thing() {
		cout<< "wash your hands" <<endl;
	}
	void second_thing() {
		cout << "eat the food" <<endl;
	}
	void third_thing() {
		cout << "clean your mouth" <<endl;
	}
};
class sleep_thing : public abstract_thing {
public:
	void modifier() {
		cout << "----------------------------------------------" <<endl;
	}
	void first_thing() {
		cout<< "take off your clothes" <<endl;
	}
	void second_thing() {
		cout << "goto the bed" <<endl;
	}
	void third_thing() {
		cout << "close your eyes" <<endl;
	}
};

class drink_thing : public abstract_thing {
public:
	void modifier() {
		cout << "----------------------------------------------" <<endl;
	}
	void first_thing() {
		cout<< "lift your drink-cup" <<endl;
	}
	void second_thing() {
	}
	void third_thing() {
		cout << "drink water by your mouth" <<endl;
	}
};

class thing_builder {
private:
	class abstract_thing *pat;
public:
	thing_builder(class abstract_thing *at) {
		this->pat = at;
	}
	void construct(){
		/* we need ensure that this logic is fixed at least, otherwise
		 * it will touch here more times, more tips we can make abstract_thing
		 * big but not too little, example for drink_thing.
		 * */
		this->pat->modifier();
		this->pat->first_thing();
		this->pat->second_thing();
		this->pat->third_thing();
	}
	void set_abstract_thing(class abstract_thing *at) {
		this->pat = at;
	}
};

int main()
{
	class sleep_thing *pst = new sleep_thing();
	class eat_thing *pet = new eat_thing();
	class drink_thing *pdt = new drink_thing();
	class thing_builder *ptb = new thing_builder(pst);
	ptb->construct();
	ptb->set_abstract_thing(pet);
	ptb->construct();
	ptb->set_abstract_thing(pdt);
	ptb->construct();
	delete pst;
	delete pet;
	delete pdt;
	delete ptb;

}
