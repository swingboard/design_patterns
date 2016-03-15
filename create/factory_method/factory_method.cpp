#include <iostream>
using namespace std;

class tranval_destination {
public:
	virtual void get_tranval_points() = 0;
};

class tranval_factory {
public:
	virtual class tranval_destination * tranval_line() = 0;
};

class td_shanghai : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Shanghai!" <<endl;
	}
};
class td_beijing : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Beijing!" <<endl;
	}
};

class tf_shanghai : public tranval_factory {
private:
	class tranval_destination* ptd = NULL;
public:
	class tranval_destination * tranval_line() {
		if (this->ptd == NULL)
			this->ptd = new td_shanghai();
		return this->ptd;
	}
	~tf_shanghai()
	{
		if (this->ptd)
			delete(this->ptd);
	}
};
class tf_beijing : public tranval_factory {
private:
	class tranval_destination* ptd = NULL;
public:
	class tranval_destination * tranval_line() {
		if (this->ptd == NULL)
			this->ptd = new td_beijing();
		return this->ptd;
	}
	~tf_beijing()
	{
		if (this->ptd)
			delete(this->ptd);
	}
};

class tranval_agency {
private:
	int tranval_type;
	class tranval_factory *ptf;
public:
	void get_tranval_line() {
		/* logic process here, just using the based class will be OK,
		 * as their derived class have the same method as based class.
		 * */
		if (this->tranval_type == 1) {
			this->ptf = new tf_shanghai();
			this->ptf->tranval_line()->get_tranval_points();
		} else if (this->tranval_type == 2) {
			this->ptf = new tf_beijing();
			this->ptf->tranval_line()->get_tranval_points();
		}
	}
	tranval_agency(int type) {
		tranval_type = type;
	}
	~tranval_agency()
	{
		if (this->ptf) {
			delete(this->ptf->tranval_line());
			delete(this->ptf);
		}
	}
};
int main()
{
	class tranval_agency *pctl_1 = new class tranval_agency(1);
	pctl_1->get_tranval_line();
	class tranval_agency *pctl_2 = new class tranval_agency(2);
	pctl_2->get_tranval_line();
	delete(pctl_1);
	delete(pctl_2);
}
