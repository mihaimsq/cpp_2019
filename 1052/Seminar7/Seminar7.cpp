#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string nume;
	int nr_note;
	int* note;

public:
	Student(string _nume, int _nr_note, int* _note)
	{
		nume = _nume;
		nr_note = _nr_note;
		if (_note)
		{
			note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				note[i] = _note[i];
			}
		}
		else
		{
			note = NULL;
		}
	}

	Student(const Student& s)
	{
		nume = s.nume;
		nr_note = s.nr_note;
		if (s.note)
		{
			note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				note[i] = s.note[i];
			}
		}
		else
		{
			note = NULL;
		}
	}

	~Student()
	{
		if (note)
		{
			delete[] note;
		}
	}

	Student operator=(const Student& s)
	{
		if (note)
		{
			delete[] note;
		}

		nume = s.nume;
		nr_note = s.nr_note;
		if (s.note)
		{
			note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				note[i] = s.note[i];
			}
		}
		else
		{
			note = NULL;
		}

		return *this;
	}

	Student operator++()
	{
		if (note)
		{
			note[0]++;
		}
		return *this;
	}

	Student operator++(int i)
	{
		Student aux = *this;
		if (note)
		{
			note[0]++;
		}
		return aux;
	}

	Student operator+(int value)
	{
		Student aux = *this;
		if (aux.note)
		{
			aux.note[0] += value;
		}
		return aux;
	}

	friend Student operator+(int, Student);
	friend istream& operator>>(istream&, Student&);
};

Student operator+(int value, Student s)
{
	if (s.note)
	{
		s.note[0] += value;
	}
	return s;
}

istream& operator>>(istream& in, Student& s)
{
	in >> s.nume;
	in >> s.nr_note;

	if (s.note)
	{
		delete[] s.note;
	}
	s.note = new int[s.nr_note];
	for (int i = 0; i < s.nr_note; i++)
	{
		in >> s.note[i];
	}

	return in;
}

int main()
{
	int v[] = { 8, 10, 9, 10 };
	Student s1("Gigel", 4, v);

	Student s2(s1);
	Student s3 = s1;
	Student s4("Ion", 4, v);
	s4 = s2;

	Student s5 = ++s1;
	Student s6 = s1++;
	s3 = s2 + 2;
	s4 = 1 + s2;

	cin >> s4;
}