#include"RSA.h"
#include<ctime>

RSA::RSA()
{
}

RSA::~RSA()
{
}

string RSA::Cal(string text, string key, string BigInteger)
{
	mpz_class result_text;
	mpz_class text_convert(text);
	mpz_class key_convert(key);
	mpz_class Integer_convert(BigInteger);
	mpz_powm(result_text.get_mpz_t(), text_convert.get_mpz_t(), key_convert.get_mpz_t(), Integer_convert.get_mpz_t());
	return result_text.get_str();
}

mpz_class RSA::get_Decryption()
{
	return Decryption_Index;
}

mpz_class RSA::get_Factor()
{
	return Factor_p;
}

/* ����һ������������λ��Ϊ����ı����� */
mpz_class RSA::CreatePrimes(int bits)
{
	/* �������һ�����볤�ȵĴ����� */
	gmp_randclass s(gmp_randinit_default);
	s.seed(rand());
	mpz_class numbers(bits);
	mpz_class Integer = s.get_z_bits(numbers);

	/* GMP���Դ����������ɺ��� */
	mpz_class primes;
	mpz_nextprime(primes.get_mpz_t(), Integer.get_mpz_t());
	return primes;
}

void RSA::InitialNumbers(int InputBits)
{
	/* ������������p��q */
	Factor_p = CreatePrimes(InputBits / 2);
	Factor_q = CreatePrimes(InputBits / 2);
	/* ���������n�Լ���Ӧ��ŷ������ */
	BigInteger_n = Factor_p * Factor_q;
	Euler_Function = (Factor_p - 1)*(Factor_q - 1);

	/* �����ָ��e */
	mpz_class gcd, e;
	while (gcd != 1)
	{
		/* �������һ��0 < e < ��(n)������ */
		gmp_randclass s(gmp_randinit_default);
		s.seed(rand());
		e = s.get_z_range(Euler_Function);
		if (e <= 1) { continue; }
		else
		{
			mpz_gcd(gcd.get_mpz_t(), e.get_mpz_t(), Euler_Function.get_mpz_t());
		}
	}
	Encryption_Index = e;

	/* �����Ӧ�Ľ���ָ��d,d*e+temp*Euler=gcd */
	mpz_class d;
	mpz_class temp;
	mpz_gcdext(gcd.get_mpz_t(), d.get_mpz_t(), temp.get_mpz_t(), e.get_mpz_t(), Euler_Function.get_mpz_t());
	Decryption_Index = d;
}