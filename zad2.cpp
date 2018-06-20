#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Book
{
private:
	string author;
	string title;
	int year;
	int ID;

public:
	Book(string a, string t, int y, int i)
	{
		author = a;
		title = t;
		year = y;
		ID = i;
	}

	string getauthor()
	{
		return author;
	}

	string gettitle()
	{
		return title;
	}

	int getyear()
	{
		return year;
	}
	int getID()
	{
		return ID;
	}

	bool borrowed(int a)
	{

	}

	void findauthor(vector<string> myvector, string author)
	{
		for (vector<string>::iterator it = myvector.begin(); it != myvector.end(); it++)
			cout << *it << endl;

		int pos = std::find(myvector.begin(), myvector.end(), author) - myvector.begin();

		if (pos < myvector.size())
		{
			std::cout << author << " " << title << " " << ID << endl;
		}
		else
		{
			std::cout << " not found" << endl << endl;
		}

	}

	void findtitle(vector<string> myvector, string title)
	{
		for (vector<string>::iterator it = myvector.begin(); it != myvector.end(); it++)
			cout << *it << endl;

		int pos = std::find(myvector.begin(), myvector.end(), title) - myvector.begin();

		if (pos < myvector.size())
		{
			std::cout << author << " " << title << " " << ID << endl;
		}
		else
		{
			std::cout << " not found" << endl << endl;
		}

	}

};

class Reader
{
private:
	string name;
	int nr;
	int ID;

public:
	Reader(string n, int r, int i)
	{
		name = n;
		nr = r;
		ID = i;

	}

	string getname()
	{
		return name;
	}

	int getnr()
	{
		return nr;
	}
	int getID()
	{
		return ID;
	}


};



class Librarian
{
private:

	string name;
	string login;
	string password;
	int id;

public:
	Librarian();
	Librarian(string n, string l, string p, int i)
	{
		name = n;
		login = l;
		password = p;
		id = i;
	}
	string getname()
	{
		return name;
	}

	string getlogin()
	{
		return login;
	}

	string getpassword()
	{
		return password;
	}

	int getid()
	{
		return id;
	}

	void log()
	{
		string a;
		string b;
		cin >> a;
		cin >> b;
		cout << "enter login: " << endl;
		cout << "enter password: " << endl;
		if (a == login && b == password)
		{
			cout << "logged: " << name << " " << "id: " << id;
		}

		else
		{
			cout << "wrong login or password" << endl;
		}
	}

};

class Files
{
public:
	void saveworkers()
	{
		ofstream write;
		write.open("librarian.txt");

		if (write.is_open())
		{
			write << "Jan Kowalski" << " ";
			write << "kowal" << " ";
			write << 1 << endl;
			write << "Kacper Nowak" << " ";
			write << "nowakk" << " ";
			write << 2 << endl;
			write << "Basia Bodzion" << " ";
			write << "boo1" << " ";
			write << 3 << endl;

			write.close();
		}
	}

	void fillvectorworker(vector<Librarian> &myvector)
	{
		string name, login, password;
		int id;
		ifstream read;
		read.open("librarian.txt");
		string line;

		for (int i = 0; i < 20; i++)
		{
			cin >> name;
			cin >> login;
			cin >> password;
			cin >> id;
		}

		Librarian librarian(name, login, password, id);    //tutorial na youtube Vectors of Objects
		myvector.push_back(librarian);

		/*if (read.is_open())
		{
		for (int i = 0; i < 9; i++)
		{
		getline(read, line);
		myvector.push_back(line);
		cout << myvector[i] << endl;
		}
		*/

	}

	void savereaders()
	{
		ofstream write;
		write.open("reader.txt");

		if (write.is_open())
		{
			write << "Pan Kleks" << " ";
			write << 2345 << " ";
			write << 11 << endl;
			write << "Albert Einstein" << " ";
			write << 2344 << " ";
			write << 22 << endl;
			write << "Tom Hanks" << " ";
			write << 2444 << " ";
			write << 33 << endl;

			write.close();
		}
	}

	void fillvectorreader(vector<Reader> &myvector)
	{
		string name;
		int nr;
		int ID;
		ifstream read;
		read.open("reader.txt");
		string line;

		for (int i = 0; i < 20; i++)
		{
			cin >> name;
			cin >> nr;
			cin >> ID;
		}

		Reader reader(name, nr, ID);
		myvector.push_back(reader);
	}

	void savebooks()
	{
		ofstream write;
		write.open("books.txt");

		if (write.is_open())
		{
			write << "J.K.Rowling" << " ";
			write << "Harry Potter" << " ";
			write << 1998 << " ";
			write << 11 << endl;
			write << "J.R.R.Tolkien" << " ";
			write << "Lord of the rings" << " ";
			write << 1968 << " ";
			write << 22 << endl;
			write << "George Orwell" << " ";
			write << "1984" << " ";
			write << 1978 << " ";
			write << 33 << endl;
			write << "Charles Bukowski" << " ";
			write << "Poems" << " ";
			write << 1987 << " ";
			write << 44 << endl;
			write << "Andrzej Sapkowski" << " ";
			write << "Wiedzmi" << " ";
			write << 1999 << " ";
			write << 55 << endl;

			write.close();
		}
	}
	void fillvectorbook(vector<Book> &myvector)
	{
		string author;
		string title;
		int year;
		int ID;
		ifstream read;
		read.open("books.txt");
		string line;

		for (int i = 0; i < 20; i++)
		{
			cin >> author;
			cin >> title;
			cin >> year;
			cin >> ID;
		}

		Book book(author, title, year, ID);
		myvector.push_back(book);
	}
};



int main()
{
	vector<string> myvector;
	string login;
	string password;

	Librarian library;
	library.log();
