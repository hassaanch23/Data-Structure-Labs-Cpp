#include<iostream>
using namespace std;

class Polynomial {
	int TotalTerms; //Total terms in a Polynomial
	int* coeff; //To save array of coefficient
	int* exp; //To save array of exponents

public:
	Polynomial() {
		TotalTerms = 0;
		coeff = nullptr; exp = nullptr;
	}
	Polynomial(int a, int b[], int c[]) {
		TotalTerms = a;
		coeff = new int[a];
		exp = new int[a];
		for (int i = 0; i < a; i++) {
			coeff[i] = b[i];
			exp[i] = c[i];
		}
	}

	Polynomial(const Polynomial& obj) {
		TotalTerms = obj.TotalTerms;
		coeff = new int[TotalTerms];
		exp = new int[TotalTerms];

		for (int i = 0; i < TotalTerms; i++)
		{
			coeff[i] = obj.coeff[i];
			exp[i] = obj.exp[i];
		}
	}

	friend ostream& operator <<(ostream& out, const Polynomial& p1) {
		for (int i = 0; i < p1.TotalTerms; i++) {
			if (p1.exp[i] != 0) {
				if (p1.coeff[i] == 1) {
					out << "x^" << p1.exp[i];
				}
				else {
					out << p1.coeff[i] << "x^" << p1.exp[i];
				}
				if (i != p1.TotalTerms - 1) {
					out << " + ";
				}
			}
			else
				out << p1.coeff[i];
		}
		return out;
	}

	bool operator !() {
		for (int i = 0; i < TotalTerms; i++) {
			if (coeff[i] != 0 || exp[i] != 0)
				return false;
		}
		return true;
	}

	bool operator !=(const Polynomial& p1) {
		for (int i = 0; i < p1.TotalTerms; i++) {
			if (coeff[i] == p1.coeff[i] && exp[i] == p1.exp[i]) {
				return false;
			}
		}return true;
	}
	Polynomial operator++() {
		for (int i = 0; i < TotalTerms; i++) {
			++coeff[i];
		}
		return *this;
	}
	Polynomial operator ++(int) {
		Polynomial p1(TotalTerms, coeff, exp);
		for (int i = 0; i < TotalTerms; i++) {
			coeff[i]++;
		}
		return p1;
	}

	Polynomial operator +(const Polynomial& p1) {
		int TotalTerms1 = TotalTerms + p1.TotalTerms;
		int* coeff1 = new int[TotalTerms1]; int* exp1 = new int[TotalTerms1];
		int i = 0, j = 0, k = 0;
		while (j < TotalTerms && k < p1.TotalTerms) {
			if (exp[j] == p1.exp[k]) {
				coeff1[i] = coeff[j] + p1.coeff[k];
				exp1[i] = exp[j];
				i++, j++; k++;
			}
			else if (exp[j] > p1.exp[k]) {
				coeff1[i] = coeff[j];
				exp1[i] = exp[j];
				i++, j++;
			}
			else if (exp[j] < p1.exp[k]) {
				coeff1[i] = p1.coeff[k];
				exp1[i] = p1.exp[k];
				i++, k++;
			}
		}
		while (j < TotalTerms) {
			coeff1[i] = coeff[j];
			exp1[i] = exp[j];
			i++; j++;
		}
		while (k < p1.TotalTerms) {
			coeff1[i] = p1.coeff[k];
			exp1[i] = p1.exp[k];
			i++; k++;
		}
		Polynomial Output(TotalTerms1 - 1, coeff1, exp1);

		delete[] coeff1; delete[] exp1;

		return Output;
	}

	friend Polynomial operator+(int const constant, const Polynomial& obj) {
		Polynomial result(obj);
		for (int i = 0; i < result.TotalTerms; i++) {
			if (result.exp[i] == 0) {
				result.coeff[i] += constant;
			}
		}
		return result;
	}

	/*~Polynomial() {
		delete[] coeff;
		delete[] exp;
	}*/
};

int main() {


	int coeff_P1[] = { 1,2,5 };  //Coefficients for Polynomial P1
	int exp_P1[] = { 4, 2, 0 };  //Exponents for Polynomial P1

	int coeff_P2[] = { 4,3 };    //Coefficients for Polynomial P2
	int exp_P2[] = { 6,2 };     //Exponents for Polynomial P2

	Polynomial P1(3, coeff_P1, exp_P1); //Creates P1 with 3 terms (P1 = 1x ^ 4 + 2x ^ 2 + 5x ^ 0 )
	Polynomial P2(2, coeff_P2, exp_P2); //Creates P2 with 2 terms (P2 = 4x ^ 6 + 3x ^ 2)

	cout << "P1 = " << P1 << endl;   //Prints P1 = x^4 + 2x^2 + 5
	cout << "P2 = " << P2 << endl; //Prints P2 = 4x^6 + 3x^2
	if (!P1)
		cout << "P1 is zero" << endl; //if polynomial has only 1 term and its coeff and exp are zero. i.e. if p1 = 0.
	if (P1 != P2)
		cout << "P1 is Not Equal to P2" << endl;
	Polynomial P3 = P1 + P2;        //Adds P1 and P2 and saves result in P3.You may consume extra space for resultant Polynomial in Add function
	cout << "P3 = " << P3 << endl; //Prints P3 = 4�^6+�^4+5�^2+5
	cout << ++P1 << endl;  //adds 1 in all the coefficients.
	cout << P1 << endl;
	cout << P1++ << endl; //adds 1 in all the coefficients.
	cout << P1 << endl;
	P3 = 2 + P1; //Assume P1 already has a constant term, add 2 in it.
	cout << "P3 = " << P3 << endl;
}
