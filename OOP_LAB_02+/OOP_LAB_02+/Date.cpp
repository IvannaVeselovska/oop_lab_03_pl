#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
using namespace std; 

Date::Date() {
	printf("\nconstructor without parameters\n");
}
Date::~Date() {
	printf("\ndestructor\n");
	delete day;
	delete month;
	delete year;
}
Date::Date(Date*s) {
	printf("\ncopy constructor\n");
	this->day = s->day;
	this->month = s->month;
	this->year = s->year;
}
Date::Date(int d, int m, int y) {
	printf("\nconstructor with parameters\n");
	this->Set(d, m, y);
}
void Date::Set(int d, int m, int y) 
{
	if (d > 0 && m > 0 && d < 32 & m < 13 && y>0)
		if (m == 2)
			if (y % 4 == 0)
				if (d < 30) 
				{
					*this->day = d;
					*this->month = m;
					*this->year = y;
				}
				else throw "\nsomething went wrong";
			else if (d < 29) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else throw "\nsomething went wrong";
		else if (m == 4 || m == 6 || m == 9 || m == 11)
			if (d < 31) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else throw "\nsomething went wrong";
		else {
			*this->day = d;
			*this->month = m;
			*this->year = y;
		}
}
void Date::SetDay(int d) 
{

	if (d > 0 && d < 32) *this->day = d;
}
void Date::SetMonth(int m) 
{

	if (m > 0 && m < 13) *this->month = m;
}
void Date::SetYear(int y) 
{

	if (y > 0) *this->year = y;
}
int Date::GetDay() 
{
	return *this->day;
}
int Date::GetMonth() 
{
	return *this->month;
}
int Date::GetYear()
{
	return *this->year;
}
void Date::Increase() 
{
	if (*this->month == 2)
		if (*this->year % 4 == 0)
			if (*this->day == 29) {
				*this->day = 1;
				(*this->month)++;
			}
			else throw "\nsomething went wrong";
		else if (*this->day == 28) {
			*this->day = 1;
			(*this->month)++;
		}
		else throw "\nsomething went wrong";
	else if (*this->month == 4 || *this->month == 6 || *this->month == 9 || *this->month == 11)
		if (*this->day == 30) {
			*this->day = 1;
			(*this->month)++;
		}
		else throw "\nsomething went wrong";
	else if (*this->day == 31 && *this->month == 12) {
		*this->day = 1;
		*this->month = 1;
		(*this->year)++;
	}
	else if (*this->day == 31) {
		*this->day = 1;
		(*this->month)++;
	}
	else (*this->day)++;
}
int Date::operator<(const Date& a)
{
	if ((this->year - a.year) < 0) {
		return 1;
	}
	if (((this->year - a.year) == 0) && ((this->month - a.month) < 0)) 
	{
		return 1;
	}
	if (((this->year - a.year) == 0) && ((this->month - a.month) == 0)
		&& ((this->day - a.day)<0)) 
	{
		return 1;
	}
	return 0;
}
Date Date::operator--()
{
	if (*this->month == 3)
		if (*this->year % 4 == 0)
			if (*this->day == 1) 
			{
				*this->day = 29;
				(*this->month)--;
			}
		else if (*this->day == 1) 
			{
			*this->day = 28;
			(*this->month)--;
		}
	else if (*this->month == 5 || *this->month == 7 || *this->month == 10 || *this->month == 12)
		if (*this->day == 1) 
		{
			*this->day = 30;
			(*this->month)--;
		}
	else if (*this->day == 1 && *this->month == 1) 
	{
		*this->day = 31;
		*this->month = 12;
		(*this->year)--;
	}
	else if (*this->day == 1) 
		{
		*this->day = 31;
		(*this->month)--;
	}
	else (*this->day)--;
	return this;
}
void Date::Get() 
{
	printf("\n%d/%d/%d", *this->day, *this->month, *this->year);
}
void Date::Get2() 
{
	printf("\n%d-%d-%d", *this->year, *this->month, *this->day);
}
int Date::Module(const Date & now)
{
	int sum=0;
	int y = *this->year - *now.year;
	int m = *this->month - *now.month;
	int d = *this->day - *now.day;
	if (y != 0)
		if (y < 0)
			sum += (-1) * y * 365;
		else sum += y * 365;
	if (m != 0)
		if (m < 0)
			sum += (-1) * y * 30;
		else sum += y * 30;
	if (d != 0)
		if (d < 0)
			sum += (-1) * d;
		else sum += y ;
	return sum;
}