//Encryption-Decryption Sample Library
// [32, 126] Available Range
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
const int MAX = 126;
const int MIN = 32;
const int RANGE = MAX - MIN; // Range = MaxValue - MinValue 
const std::string KEY = "abc";
//Each key outputs a different encrypted message

std::string EncryptFile(std::string const& f);
//
void NewEncryptedValues(std::vector <char> & u, std::vector <int> const& v);
//
void ShowNewCode(std::vector <char> const& u);
//
void DecryptVigenereFile(std::string const & f, std::string & d);
//

int main() {
	std::string fileName, text, plaintext;
	std::cin >> fileName;

	text = EncryptFile(fileName);
	DecryptVigenereFile(text, plaintext);
	std::cout << plaintext << '\n';
	system("pause");

	return 0;
}

void DecryptVigenereFile(std::string const & f, std::string & d) {
	std::vector <int> v;
	int keySize = KEY.size();

	d = f;
	for (int i = 0; i < f.size(); ++i) {
		v.push_back(KEY[i % keySize] % RANGE);
	}

	for (int i = 0; i < f.size(); ++i) {
		d[i] = d[i] - v[i];
		if (d[i] < MIN)
		{
			d[i] = MAX - (MIN - d[i]);
		}
	}
}



std::string EncryptFile(std::string const& f) {
	std::ifstream file;
	std::string aux2 = "";
	int i = 0, keySize = KEY.size();
	char aux;
	std::vector <int> v;
	std::vector <char> u;
	file.open(f);
	if (!file.is_open())
	{
		std::cout << "No se pudo abrir el archivo \n";
	}
	else
	{
		file.get(aux);
		while (!file.eof())
		{
			u.push_back(aux);
			v.push_back(KEY[i % keySize] % RANGE);
			file.get(aux);
			++i;
		}
		NewEncryptedValues(u, v);
		ShowNewCode(u);
		for (int i = 0; i < u.size(); ++i) {
			aux2 += u[i];
		}
		file.close();
	}
	return aux2;
}

void NewEncryptedValues(std::vector <char> & u, std::vector <int> const& v) {
	int newCode;
	for (int i = 0; i < v.size(); ++i)
	{
		newCode = u[i] + v[i];
		if (newCode > MAX)
		{
			newCode = MIN + newCode % MAX;
		}
		u[i] = char(newCode);
	}
}

void ShowNewCode(std::vector <char> const& u) {
	for (int i = 0; i < u.size(); ++i)
	{
		std::cout << u[i];
	}
	std::cout << '\n';
}
