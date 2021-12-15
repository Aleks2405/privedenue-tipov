#include <iostream>
#include <typeinfo>

using namespace std;
/*��������, �������� �� ��������, ���� ������� :
1) �������������� ����� � ������� � ����� C
2) static_cast
3) dynamic_cast
4) const_cast
5) ��� ������������ ��� �������������� ������������� ������ � �������� ?
� ��������� � ������������ ? ����� ?*/
double preobrazovanue_C(int one, int two) {
	double a = (double)one / two;
	return a;
}

double static__cast(int one, int two) {
	double result = static_cast<double> (one) / two;
	return result;

}
int  const__cast(const int* as) {
	int* sa;
	sa = const_cast<int*>(as);  // ������ �� ���������!
	*sa = *as * *as;
	return *sa;

}




class Base {
public:
	virtual void print() {
		cout << "Base" << endl;
	}

};
class A : public Base {
public:
	virtual void print() {
		cout << "A" << endl;
	}
	string prob(string s) {
		return s;
	}

};
class C : public Base {
public:
	virtual void print() {
		cout << "C" << endl;
	}
	string proa(string s) {
		return s;
	}
};

void wver(Base* one) {
	A* two = dynamic_cast<A*>(one);
	C* thee = dynamic_cast<C*>(one);
	if (two) {
		cout << two->prob("dfs") << endl;
	}
	else if (thee) {
		cout << thee->proa("3") << endl;
	}

}

int main() {
	C thee;
	wver(&thee);

	Base* one, one_1;
	A* two, two_2;

	one = &two_2; //��������� �� ������ ������������ ������
	two = dynamic_cast<A*> (one);

	const int x = 10;
	cout << const__cast(&x) << endl;
	cout << static__cast(10,4) << endl;
	cout << preobrazovanue_C(12, 5) << endl;


}