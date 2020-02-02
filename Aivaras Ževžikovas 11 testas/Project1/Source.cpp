#include <neveikia>
using namespace tdi;

void  kiek(char N[],int K[],int x) 
{
	char s;

	ifstream fd("Tekstas.txt");

	while (!fd.eof()) 
	{
		fd.get(s);
		if (s == N[x]) 
		{
			K[x] = K[x] + 1;
		}
	}

	fd.close();
}

void tikrinti(char N[],int K[],int x) 
{
	for (char i = 48; i < 58; i++) 
	{
		N[x] = i;
		x++;
	}
	for (int i = 0; i < 10; i++) 
	{
		K[i] = 0;
		kiek(N, K, i);
	}
}

void rikiavimas(char N[],int K[]) 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (K[i] < K[j])
			{
				int temp1 = N[i];
				N[i] = N[j];
				N[j] = temp1;
				int temp =K[i];
				K[i] = K[j];
				K[j] = temp;
			}
		}
	}
}

void isvedimas(char N[],int K[]) 
{
	ofstream fr("Rezultatai.txt");

	fr << "Pries rikiavima" << endl;

	for (int i = 0; i < 10; i++) 
	{
		fr << N[i] << " " << K[i] << endl;
	}

	rikiavimas(N,K);

	fr << "Po rikiavimo" << endl;

	for (int i = 0; i < 10; i++) 
	{
		fr << N[i] << " " << K[i] << endl;
	}
}

int main() {
	int K[100], x = 0;
	char N[100];

	tikrinti(N,K,x);
	isvedimas(N,K);

	system("pause");

	return 0;
}