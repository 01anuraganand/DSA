#include <iostream>
using namespace std;

//Struct Point
struct Point{
	int x, y;
};

//Struct Pair global declaration
struct Pair{
	int first, second;
} pir; // pair act as global variable

// Sturct Complex Number
struct ComplexNum{
	int real, img;
};

//Array of sturct
struct People{
	char fname[50];
	char lname[50];
	int age;
	char gender;
};

//Nested Structure
struct Education{
	char degree[10];
	int batch;
	char institute[50];
};
struct Student{
	char fname[50];
	char lname[50];
	int age;
	char gender;
	Education edu;
};

// Demonstration of sizeof
struct structDemo{
	int pincode;
	long long number;
};

// Stuct with Pointers on Sturct Demo


int main()
{
	Point p;
	p.x = 5; p.y = 6;
	cout<<p.x << " "<<p.y<<endl;
	Pair dict = {18, 19};
	cout<<dict.first << "  "<<dict.second<<endl;

	//global struct demonstration
	pir.first = 200;pir.second = 201;
	cout<<pir.first << "  "<<pir.second<<endl;

	//Complex Number
	ComplexNum nums1 = {5, 8};
	ComplexNum nums2 = {2, 2};
	ComplexNum nums3 = {nums1.real + nums2.real, nums1.img + nums2.img};
	cout<<nums3.real << " "<<"i"<<nums3.img<<endl;

	//Array of Sturct
	int N = 3;
	People person[N];
	for(int i = 0; i<N; i++)
		cin>> person[i].fname >> person[i].lname >> person[i].age >> person[i].gender;

	for(int i = 0; i<N; i++)
		cout<<person[i].fname << " "<< person[i].lname << " "<<person[i].age << " "<<person[i].gender<<endl;

	cout<<endl;
	// Insertion Sort on Array Struct (People) on age
	for(int i = 1; i<N; i++)
	{
		int j = i;
		while(j > 0 && person[j-1].age > person[j].age) 
		{
			swap(person[i], person[j-1]);
			j--;
		}
	}

	for(int i = 0; i<N; i++)
		cout<<person[i].fname << " "<< person[i].lname << " "<<person[i].age << " "<<person[i].gender<<endl;

	/*-----------------------------------------------------------------------*/
	//Nested Struct
	Education e = {"M.Tech", 2019, "Lovely Professional University"};
	Student s = {"Anurag", "Anand", 22, 'M', e};
	//s.edu comes from the structure of Student taken from struct Education
	cout<<s.fname << " | " << s.lname << " | "<<s.age << " | " << s.gender<< " | "<< s.edu.degree << " | "<<s.edu.batch<< " | "<<s.edu.institute<<endl;

	// IMORTANT things to notice
	cout<<sizeof(ComplexNum)<<endl; // both belong to int so Output : 4 + 4 = 8;
	cout<<sizeof(structDemo)<<endl; // data type is different is now so padding is performed with int data type by 4 byte so Ouptut : 4 (int) + 4(padding) + 8 (long long) = 16

	structDemo st = {221532, 998711089};
	structDemo* ptr = &st;
	cout<<(*ptr).pincode << " "<< (*ptr).number<<endl;
	// or by using -> operator which dereferences pointers implicitly
	cout<<ptr->pincode << "  "<<ptr->number<<endl;

}