# include <iostream>
#include <fstream>


int main() {
	std::ifstream in("in.txt");
	if (!in.is_open()) {
		std::cout << "Can't open file";
		system("pause");
		return 0;
	}
	int n, mas0;
	in >> n;
	int* mas1 = new int[n];
	for (int i = 0; i < n; ++i) {
		in >> mas1[i];
	}
	int m;
	in >> m;
	int* mas2 = new int [m];
	for (int i = 0; i < m; ++i) {
		in >> mas2[i];
	}
	in.close();
	mas0 = mas1[0];
	for (int i = 0; i < (n - 1); ++i) {
		mas1[i] = mas1[i + 1];
	}
	mas1[n - 1] = mas0;
	mas0 = mas2[m - 1];
	for (int i = (m - 1); i > 0; --i) {
		mas2[i] = mas2[i - 1];
	}
	mas2[0] = mas0;
	std::ofstream out("out.txt");
	out << m << std::endl;
	int k = 0;
	while (k < m) {
		out << mas2[k] << ' ';
		++k;
	}
	out << std::endl << n << std::endl;
	k = 0;
	while (k < n) {
		out << mas1[k] << ' ';
		++k;
	}
	out.close();
	delete[] mas1;
	delete[] mas2;
	return 0;
	}

