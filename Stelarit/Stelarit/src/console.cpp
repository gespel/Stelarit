#include "console.h"

using namespace std;

void Console::pause() {
	while((getchar()) != '\n');
	cout << endl << "==================================" << endl;
	cout << "==== Press a key to continue! ====" << endl;
	cout << "==================================" << endl;
	system("stty raw");
	getchar();
	system("stty cooked");
}
