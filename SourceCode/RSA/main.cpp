#include<iostream>
#include"RSA.h"
using namespace std;
int main()
{
	/* 输入加密位数 */
	int InputBits;
	cout << "请输入加密的位数(推荐输入1024或者2048)：";
	cin >> InputBits;
	RSA test;
	test.InitialNumbers(InputBits);

	/* 输入加密的数字字符串 */
	cout << endl;
	string m;
	cout << "请输入待加密的字符串(仅数字):";
	cin >> m;

	/* 加密过程 */
	cout << endl;
	cout << "明文为：" << m << endl;
	cout << endl;
	string c = test.Cal(m, test.Encryption_Index.get_str(),test.BigInteger_n.get_str());
	cout << "密文为：" << c << endl;

	/* 获取解密指数 */
	cout << endl;
	mpz_class private_key = test.get_Decryption();
	string text = test.Cal(c, private_key.get_str(),test.BigInteger_n.get_str());
	cout << "解密明文为：" << text << endl;

	/* 验证加密解密是否成功 */
	cout << endl;
	if (text == m) { cout << "解密正确!" << endl; }
	else { cout << "解密失败!" << endl; }
	cout << endl;

	/* 公钥和私钥 */
	cout << endl;
	cout << "公钥为：(" << test.BigInteger_n.get_str() << "," << test.Encryption_Index.get_str() << ")" << endl;
	cout << endl;
	cout << "私钥为：(" << test.get_Decryption() << ")" << endl;
	cout << endl;

	system("pause");
	return 0;
}