/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Marcus Hoertz <marcus.hoertz@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program to show understanding on exceptions, vectors, and recursion
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;
int subtraction (int x, int y)
{
    if(y>x)
    {
        throw 0;
    }
    if (y==x)
    {
        throw 1;
    }
    if (x-y>10)
    {
        throw 2;
    }
    
    return x-y;
}


template<typename T>
void change(T& x, T& y)
{
    y=x;
}

int gcd(int a, int b)
{
	if (a < 0)
	{
		a -= 2 * a;
	}
	if (b < 0)
	{
		b -= 2 * b;
	}
	//base case
	if (a == 0) return b;
	if (b == 0) return a;
	if (a > b) return gcd(a - b, b);

	return gcd(a, b - a);
}

int fib(int n)
{
	if (n < 0)
	{
		throw "negative input";
	}
	if (n == 1) return 1;
	if (n == 2) return 1;
	return fib(n - 2) + fib(n - 1);
}

int fib_iter(int n)
{
	if (n<0)
	{
		throw "negaitve input";
	}
	int q=0;
	for(int i=1; i<=n; i++)
	{
		for (j=1; j<i; j++)
		{
			q+=j;
		}
	}
	return q;
}

int pow(int a, int b)
{
	if (b < 0)
	{
		throw "negative input";
	}
	//base case
	if (b == 0) return 1;
	//base case
	return a*pow(a, b - 1);
}

int pow(int a, int b)
{
	if (b<0)
	{
		throw "negative input";
	}
	if (b==0) return 1;
	int q=a;
	for (int i=0; i<b; i++)
	{
	 q*=a;	
	}
	return q;
}

int tri(int n)
{
	if (n <= 0)
	{
		throw "invalid input";
	}
	//base case
	if (n == 1)return 1;
	//recursive case
	return n + tri(n - 1);
}

int tri_iter(int n)
{
	if (n<=0)
	{
		throw "invalid input";
	}
	return (n+1)*n/2;
}

string int_to_roman(int n)
{
	if (n <= 0)
	{
		throw "invalid input";
	}
	if (n >= 4000)
	{
		throw "invalid input";
	}
	int numbers[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string numerals[13] = { "I","IV","IX","XL","L","XC","C","CD","D","CM","M" };

	//base case
	for (int i = 12; i >= 0; i--)
	{
		if (n == numbers[i])
		{
			return numerals[i];
			
		}
	}

	//recursive case
	for (int i = 12; i >= 0; i--)
	{
		if (n > numbers[i])
		{
			return numerals[i] + int_to_roman(n - numbers[i]);

		}
	}
}

string int_to_roman_iter(int n)
{
	if (n <= 0)
	{
		throw "invalid input";
	}
	if (n >= 4000)
	{
		throw "invalid input";
	}
	int numbers[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string numerals[13] = { "I","IV","IX","XL","L","XC","C","CD","D","CM","M" };
	string numerals_total;
	//base case
	for (int i = 12; i >= 0; i--)
	{
		if (n >= numbers[i])
		{
			n-=numbers[i];
			string numerals_total+=numerals[i];
		}
	}
	return numerals_total;
}
// int to words is unfinished, unsure of how to fix an issue with multiple hundreds/thousands/millions being output
string int_to_words(int n)
{
	if (n > 1000000000 || n < -1000000000)
	{
		throw "out of bounds";
	}
	int amount[31] = { 0,1,2,3,4,5,6,7,8,9,10,
					11,12,13,14,15,16,17,18,19,
					20,30,40,50,60,70,80,90,100,
					1000,1000000000 };
		string words[31] = { "zero ", "one ", "two ", "three ", "four ",
							"five ", "six ", "seven ", "eight ", "nine ",
							"ten ", "eleven ", "twelve ", "thirteen ","fourteen "
							"fifteen ","sixteen ", "seventeen ", "eighteen ", "nineteen ","twenty ",
							"thirty ","fourty ","fifty ","sixty ","seventy ","eighty ","ninety ",
							"hundred ","thousand ","million " };
		//base case
		if (n < 0)
		{
			return "negative " +int_to_words(-n);
		}
		for (int i = 30; i >= 0; i++)
		{
			return words[i];
		}
		for (int i = 30; i >= 0; i++)
		{
			return words[i] + int_to_words(n - i);
		}
		//for(int j=1; j<n/words[i];j++)
		
}
int main()
{
    int g;
    int h;
    cout<< "Please input two integers" <<endl;
    cin>>g>>h;
	try
	{
		subtraction (g,h);
	}
	catch (int i)
	{
	    if( i==0)
	    {
		cout << "ERROR: answer will be negative." << '\n';
	    }
	    if (i==1)
	    {
	        cout<< "ERROR: answer will be zero."<< '\n';
	    }
	    if (i==2)
	    {
	        cout<< "ERROR: answer is greater than 10."<< '\n';
	    }
	    
	}
	cout<<subtraction(g,h)<<endl;
	double a= 1.9, b= 2.7;
	change(a,b);
	cout<<a<<' '<< b<<endl;
	int q=1, r=3;
	change(q,r);
	cout<<q<<' '<< r<<endl;
	char w='a',v='b';
	change(w,v);
	cout<<w<<' '<< v<<endl;
	string cat="cat", dog="dog";
	change(cat,dog);
	cout << cat << ' '<< dog<< endl;
	vector<int> drag ={3,2,1};
	int af=0;
	while (af<10000)
	{
	   drag.push_back(af);
	   cout<<drag[af]<<endl;
	   af++;
	}
	set<int> trask = { 0,1,28,2,87,43 };
	for (int db = 0; db < 120; db++)
	{
		trask.insert(db);
		cout << trask[db] << endl;
	}
	cout<<gcd(3, 2);
	cout << fib(27);
	cout << pow(2, 3);
	cout << tri(6);
	return 0;
}
