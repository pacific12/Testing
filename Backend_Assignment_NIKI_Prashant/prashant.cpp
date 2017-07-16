#include <cstdio>
#include <iostream>

#define MOD 1000000007

using namespace std;

void bit_string(long long int P[2][2], long long int M[2][2]);
 
void power_string(long long int P[2][2], long long int n);


void power_string(long long int P[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power_string(P, n/2);
  bit_string(P, P);
  if (n%2 != 0)
     bit_string(P, M);
}

void bit_string(long long int P[2][2], long long int M[2][2])
{
  long long int x =  ((P[0][0]*M[0][0])%MOD + (P[0][1]*M[1][0])%MOD)%MOD;
  long long int y =  ((P[0][0]*M[0][1])%MOD + (P[0][1]*M[1][1])%MOD)%MOD;
  long long int z =  ((P[1][0]*M[0][0])%MOD + (P[1][1]*M[1][0])%MOD)%MOD;
  long long int w =  ((P[1][0]*M[0][1])%MOD + (P[1][1]*M[1][1])%MOD)%MOD;
 
  P[0][0] = x;
  P[0][1] = y;
  P[1][0] = z;
  P[1][1] = w;
}


long long int modolus(long long int n)
{
  long long int P[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  power_string(P, n-2);
  return (P[0][0]*3+P[0][1]*2)%MOD;
}

int main()
{
	freopen("input.txt","r",stdin);
	long long int test_case;
	cin >> test_case;
	while(test_case--)
	{
		long long int num;
		cin >> num;
		cout << modolus(num) << endl;
	}
	return 0;
}
