#pragma once
class Date {
private:
	int *day = new int;
	int *month = new int;
	int *year = new int;
public:
	Date();
	Date(int d, int m, int y);
	Date(Date* s);
	~Date();
	void Set(int, int, int);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	void Get();
	void Get2();
	int Module(const Date &);
	int GetDay();
	int GetMonth();
	int GetYear();
	void Increase();
	int operator<(const Date&);
	Date operator--();
};
