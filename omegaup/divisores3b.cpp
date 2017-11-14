#include <stdio.h>
#include <math.h>
#define DEBUG 0	
#include <vector>
#include <bitset>
using namespace std;


typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<1000100> bs;
vi primes;

void sieve(ll upperbound) {
// create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1;
// add 1 to include upperbound
	bs.set();
// set all bits to 1
	bs[0] = bs[1] = 0;
// except index 0 and 1
	ll i = 2;

	//for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) 
	{
// cross out multiples of i starting from i * i!
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
// add this prime to the list of primes
	} 

	for (ll i = 3; i <= _sieve_size; i+=2) 
		if (bs[i]) {
// cross out multiples of i starting from i * i!
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
				primes.push_back((int)i);
// add this prime to the list of primes
	} 
}

unsigned long long  sumDiv(unsigned long long  N) {
	unsigned long long  PF_idx = 0, PF = primes[PF_idx], ans = 1;
// start from ans = 1
	while (PF * PF <= N) {
		unsigned long long  power = 0;
		while (N % PF == 0) { N /= PF; power++; }
		ans *= ((unsigned long long )pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((unsigned long long )pow((double)N, 2.0) - 1) / (N - 1); // last
	return ans;
}


int main(){
	sieve(1000100);
	unsigned long long int s;
	scanf("%llu", &s);
	printf("%llu\n", sumDiv(s)-s );

	return 0;
}