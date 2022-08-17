/*BOJ 1543 문서 검색 - 2021.09.25 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	string target;

	getline(cin, name);
	getline(cin, target);

	int nameLen = name.length();
	int targetLen = target.length();
	int count = 0;

	//name = "abb abb";
	//cout << name.substr(1, 3);
	/*cout << name.substr(1, 3);
	cout << "============\n";*/

	int i;
	string temp;

	for (i = 0; i < nameLen; i++) {
		temp = "";
		if (name[i] == target[0]) {
			temp = temp + target[0];
			//cout << i<<" : "<< temp << '\n';
			for (int j = i + 1; j <= i + targetLen-1; j++) {
				if (name[j] == target[j - i]) {
					temp += name[j];
					//cout << temp << "\n";
				}
				else {
					temp = ""; 
					//cout << temp << "\n"; 
					break;
				}
			}
			if (temp == target) { temp = ""; count++; i += targetLen - 1; }
		}
	}
	cout << count;
}