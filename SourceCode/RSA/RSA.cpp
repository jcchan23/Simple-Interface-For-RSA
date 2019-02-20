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

/* 创建一个大素数，其位数为输入的比特数 */
mpz_class RSA::CreatePrimes(int bits)
{
	/* 随机产生一个输入长度的大整数 */
	gmp_randclass s(gmp_randinit_default);
	s.seed(rand());
	mpz_class numbers(bits);
	mpz_class Integer = s.get_z_bits(numbers);

	/* GMP库自带的素数生成函数 */
	mpz_class primes;
	mpz_nextprime(primes.get_mpz_t(), Integer.get_mpz_t());
	return primes;
}

void RSA::InitialNumbers(int InputBits)
{
	/* 生成素数因子p和q */
	Factor_p = CreatePrimes(InputBits / 2);
	Factor_q = CreatePrimes(InputBits / 2);
	/* 计算大整数n以及相应的欧拉函数 */
	BigInteger_n = Factor_p * Factor_q;
	Euler_Function = (Factor_p - 1)*(Factor_q - 1);

	/* 求加密指数e */
	mpz_class gcd, e;
	while (gcd != 1)
	{
		/* 随机产生一个0 < e < φ(n)的数字 */
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

	/* 计算对应的解密指数d,d*e+temp*Euler=gcd */
	mpz_class d;
	mpz_class temp;
	mpz_gcdext(gcd.get_mpz_t(), d.get_mpz_t(), temp.get_mpz_t(), e.get_mpz_t(), Euler_Function.get_mpz_t());
	Decryption_Index = d;
}