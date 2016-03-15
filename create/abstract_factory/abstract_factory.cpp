#include <iostream>
using namespace std;

class tranval_destination {
public:
	virtual void get_tranval_points() = 0;
};

class tranval_factory {
public:
	virtual class tranval_destination * tranval_line_1() = 0;
	virtual class tranval_destination * tranval_line_2() = 0;
};

class td_shanghai : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Shanghai!" <<endl;
	}
};
class td_suzhou : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Suzhou!" <<endl;
	}
};
class td_beijing : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Beijing!" <<endl;
	}
};

class td_tianjin : public tranval_destination {
public:
	void get_tranval_points() {
		cout << "Wellcomm to Tianjin!" <<endl;
	}
};

class tf_huadong : public tranval_factory {
private:
	class tranval_destination* ptd1 = NULL;
	class tranval_destination* ptd2 = NULL;
public:
	class tranval_destination * tranval_line_1() {
		if (this->ptd1 == NULL)
			this->ptd1 = new td_shanghai();
		return this->ptd1;
	}
	class tranval_destination * tranval_line_2() {
		if (this->ptd2 == NULL)
			this->ptd2 = new td_suzhou();
		return this->ptd2;
	}
	~tf_huadong()
	{
		if (this->ptd1)
			delete(this->ptd1);
		if (this->ptd2)
			delete(this->ptd2);

	}
};
class tf_huabei : public tranval_factory {
private:
	class tranval_destination* ptd1 = NULL;
	class tranval_destination* ptd2 = NULL;
public:
	class tranval_destination * tranval_line_1() {
		if (this->ptd1 == NULL)
			this->ptd1 = new td_beijing();
		return this->ptd1;
	}
	class tranval_destination * tranval_line_2() {
		if (this->ptd2 == NULL)
			this->ptd2 = new td_beijing();
		return this->ptd2;
	}
	~tf_huabei()
	{
		if (this->ptd1)
			delete(this->ptd1);
		if (this->ptd2)
			delete(this->ptd2);
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
			this->ptf = new tf_huadong();
			this->ptf->tranval_line_1()->get_tranval_points();
			this->ptf->tranval_line_2()->get_tranval_points();
		} else if (this->tranval_type == 2) {
			this->ptf = new tf_huabei();
			this->ptf->tranval_line_1()->get_tranval_points();
			this->ptf->tranval_line_2()->get_tranval_points();
		}
	}
	tranval_agency(int type) {
		tranval_type = type;
	}
	~tranval_agency()
	{
		if (this->ptf) {
			delete(this->ptf->tranval_line_1());
			delete(this->ptf->tranval_line_2());
			delete(this->ptf);
		}
	}
};
int main()
{
	class tranval_agency *pctl_1 = new class tranval_agency(1);
	pctl_1->get_tranval_line();
	cout << "------------------------------------------" <<endl;
	class tranval_agency *pctl_2 = new class tranval_agency(2);
	pctl_2->get_tranval_line();
	delete(pctl_1);
	delete(pctl_2);
}
