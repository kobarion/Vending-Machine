#include <iostream>
#include <string>

using namespace std;

int main(){

	string msg;
	int j = 0;
	string line[3];
	cout << "Input message: ";
	getline(cin, msg);

	for (int i = 0; i < msg.length(); i += 20) {
	    line[j] = msg.substr(i, 20);
	    j++;
	}

	for (int k = 0; k < 3; k++){
		cout << line[k] << endl;
	}

}
	