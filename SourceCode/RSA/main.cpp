#include<iostream>
#include"RSA.h"
using namespace std;
int main()
{
	/* �������λ�� */
	int InputBits;
	cout << "��������ܵ�λ��(�Ƽ�����1024����2048)��";
	cin >> InputBits;
	RSA test;
	test.InitialNumbers(InputBits);

	/* ������ܵ������ַ��� */
	cout << endl;
	string m;
	cout << "����������ܵ��ַ���(������):";
	cin >> m;

	/* ���ܹ��� */
	cout << endl;
	cout << "����Ϊ��" << m << endl;
	cout << endl;
	string c = test.Cal(m, test.Encryption_Index.get_str(),test.BigInteger_n.get_str());
	cout << "����Ϊ��" << c << endl;

	/* ��ȡ����ָ�� */
	cout << endl;
	mpz_class private_key = test.get_Decryption();
	string text = test.Cal(c, private_key.get_str(),test.BigInteger_n.get_str());
	cout << "��������Ϊ��" << text << endl;

	/* ��֤���ܽ����Ƿ�ɹ� */
	cout << endl;
	if (text == m) { cout << "������ȷ!" << endl; }
	else { cout << "����ʧ��!" << endl; }
	cout << endl;

	/* ��Կ��˽Կ */
	cout << endl;
	cout << "��ԿΪ��(" << test.BigInteger_n.get_str() << "," << test.Encryption_Index.get_str() << ")" << endl;
	cout << endl;
	cout << "˽ԿΪ��(" << test.get_Decryption() << ")" << endl;
	cout << endl;

	system("pause");
	return 0;
}