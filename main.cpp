// lab5.2
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Empty {};

class Error {
	string message;
public:
	Error(string message) : message(message) {}
	string What() { return message; }
};

class E : public exception {
	string message;
public:
	E(string message) : message(message) {}
	string What() { return message; }
};

int WholePart1(int a, int b) {
	if (b==0) throw 1;
	return a/b;
}

int WholePart2(int a, int b) throw() {
	if (b == 0) throw 1.0;
	return a/b;
}

int WholePart3(int a, int b) throw(char) {
	if (b==0) throw '1';
	return a/b;
}

int WholePart4(int a, int b) throw(Empty){
	if (b==0) throw Empty();
	return a/b;
}

int WholePart5(int a, int b) throw(Error) {
	if (b==0) throw Error("Division by zero! ");
	return a/b;
}

int WholePart6(int a, int b) throw(int) {
	if (b==0) throw E("Division by zero!");
	return a/b;
}

void unexpected() {
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void terminate() {
	cout << "unknown error! - terminate" << endl;
	abort();
}
	
int main() {
	set_unexpected(unexpected);
	set_terminate(terminate);
	int a, b;
	cout << "a = ? "; cin >> a;
	cout << "b = ? "; cin >> b;
	// try {
		// cout << WholePart1(a,b) << endl;
		// cout << WholePart2(a,b) << endl;
		// cout << WholePart3(a,b) << endl;
		// cout << WholePart4(a,b) << endl;
		// cout << WholePart5(a,b) << endl;
		cout << WholePart6(a, b) << endl;
	// }
	// catch (int) {
	// 	cout << "catch (int) <= WholePart1()" << endl;
	// }
	// catch (double) {
	// 	cout << "catch (double) <= WholePart2()" << endl;
	// }
	// catch (char) {
	// 	cout << "catch (char) <= WholePart3()" << endl;
	// }
	// catch (Empty) {
	// 	cout << "catch (Empty) <= WholePart4()" << endl;
	// }
	// catch (Error e) {
	// 	cout << "catch (Error) <= WholePart5() :" << endl;
	// 	cout << e.What() << endl;
	// }
	// catch (bad_exception) {
	// 	cout << "catch (bad_exception)" << endl;
	// }
	// catch (exception) {
	// 	cout << "catch (exception) <= WholePart6() :" << endl;
	// }
	// catch (E e) {
	// 	 cout << "catch (E) <= WholePart6() :" << endl;
	// 	cout << e.What() << endl;
	// }
	system("pause");

	return 0;
}
