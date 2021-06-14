/*
Sam Schock
Exam 2 Part D: Polymorphism
Due 5/13/21
*/

#include <iostream>
#include <string>

using namespace std;

class Shape
{
	public:
		Shape(const char& newPrintChar, int newSize);
		char getPrintChar() const { return printChar; };
		int getSize() const { return size; };
		virtual void draw() = 0;
	protected:
		char printChar;
		int size;
};

class Square : public Shape
{
	public:
		Square(const char& newPrintChar, int newSize);
		void draw();
};

class Triangle : public Shape
{
	public:
		Triangle(const char& newPrintChar, int newSize);
		void draw();
};

int main()
{
	Square sqr = Square('O', 8);
	Triangle tri = Triangle('#', 15);
	sqr.draw();
	tri.draw();
	return 0;
}

Shape::Shape(const char& newPrintChar, int newSize) : printChar(newPrintChar), size(newSize) {

}

Square::Square(const char& newPrintChar, int newSize) : Shape(newPrintChar, newSize) {

}

void Square::draw()
{
	int i, j;
	char a = getPrintChar();

	for (i = 0; i < getSize(); i++) //rows
	{
		for (j = 0; j < getSize(); j++) //columns
		{
			if ((i == 0) || (i == (getSize() - 1))) {
				cout << a << " ";
			}
			else {
				if ((j == 0) || (j == (getSize() - 1))) {
					cout << a << " ";
				}
				else {
					cout << "  ";
				}
			}
			if (j == (getSize() - 1)) {
				cout << endl;
			}
		}
	}
}

Triangle::Triangle(const char& newPrintChar, int newSize) : Shape(newPrintChar, newSize) {

}

void Triangle::draw()
{
	int i, j, k, n;
	char a = getPrintChar();
	
	if ((getSize() % 2) == 1) {
		k = n = (getSize() / 2);
	}
	else {
		n = (getSize() / 2);
		k = n - 1;
	}

	for (i = 0; i <= (getSize()/2); i++) //rows
	{
		for (j = 0; j < getSize(); j++) //columns
		{
			if ((j == (k - i) || j == (n + i))) {
				cout << a;
			}
			else if (i == n) {
				cout << a;
			}
			else {
				cout << " ";
			}
			if (j == (getSize() - 1)) {
				cout << endl;
			}
		}
	}
}