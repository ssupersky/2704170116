#include"math.h"
#include"vector"
using std::vector;
class NaturalNumber {
public:
	NaturalNumber(unsigned long int n = 0) :num(n) {}
	unsigned long int GreatestCommonDivisor(NaturalNumber&nn);
	unsigned long int LeaseCommonMultiple(NaturalNumber&nn);
	int GetFactors(vector<unsigned long int >&factors);
	unsigned long int GetNumber() { return num; }
private:
	unsigned long int EUCLID(NaturalNumber&n);
	unsigned long int num;

};
unsigned long int NaturalNumber::EUCLID(NaturalNumber&nn)
{
	unsigned long int m = num;
	unsigned long int n = nn.num;
	unsigned long int r = m%n;
	while (r != 0) {
		m = n; n = r; r = m%n;
	}
	return n;
}
unsigned long int NaturalNumber::GreatestCommonDivisor(NaturalNumber & nn)
{
	return EUCLID(nn);
}
unsigned long int NaturalNumber::LeaseCommonMultiple(NaturalNumber & nn)
{
	unsigned long int temp = EUCLID(nn);
	return num * nn.GetNumber() / temp;
}
int NaturalNumber::GetFactors(vector<unsigned long int >&factors)
{
	int t = 0;
	int m = sqrt((double)num);
	vector<unsigned long int>bigfactors;
	for (unsigned long int i = 1; i<m; i++)
	{
		if (0 == num%i) {
			t += 2; factors.push_back(i);
			bigfactors.push_back(num / i);
		}
	}

	if (m*m == num) { t++; factors.push_back(m); }
	vector<unsigned long int>::iterator it = bigfactors.end();
	if (bigfactors.size()) do
	{
		it--;
		factors.push_back(*it);
	} while (it != bigfactors.begin());
	return t;
}
void main()
{
	NaturalNumber p(1);
	int xx = p.GreatestCommonDivisor(NaturalNumber(120));
	int yy = p.LeaseCommonMultiple(NaturalNumber(120));
	vector<unsigned long int>f;
	int t = p.GetFactors(f);
}


