#include <iostream>
using namespace std;
void pointersIntro()
{
	int a, b;
	printf("%p  %p \n", &a, &b);
	printf("\n%lld  %lld \n", &a, &b);
	cout<<&a<< "   "<<&b<<endl;
}

void pointesrsAddressAsign()
{
	int a;
	int* b = &a; // address of var : a gets stored in b, not in *b
	cout<<&a << "   "<<b<< " " <<&b<<endl;
	cout<<a << "   " <<*b <<endl; // *b is dereferencing operator
	a = 5;
	cout<<*(&a)<<"  " <<&a<<endl;
	a++;	// only value gets changed but pointer remains the same
	cout<<a << " " << &a<<endl; 
}

void pointerManupulation()
{
	int a = 0;
	int* b = &a;
	cout<<b<<endl; //prints address
	cout<<*b<<endl; // prints value present at memory location referenced i.e - &a -> a
	*b = 5;
	cout<<b<< "   " << *b<<endl;
	cout<<a<<endl;
	cout<<"--------------------------"<<endl;
	int x = 89;
	int* y = &x;
	int* z = y;

	cout<<x << "   "<<&x<<endl;
	cout<<*y << "   "<<y<<endl;
	*z = 90;
	cout<<x << "  "<< *y << "  "<< *z<<endl;
}

void pointerAirthematic()
{
	int a = 5;
	int* b = &a;
	cout<<&a << "    "<<b<< "   "<< &b<<endl;
	b++; //increasing the pointer's address not its value
	cout<<&a << "    "<<b<<"   "<<&b<<endl;
	*b++; // due to increament of address of b in above line the value at prev address's of b's values does not get changes.
	cout<<&a << "    "<<b<<"   "<<&b<<endl;
	cout<<a<<endl; //Output: 5 instead of 6;
	cout<<"----------------------------"<<endl;
	int x, y, z;
	int* p1 = &x;
	int* p2 = &y;
	int* p3 = &z;
	cout<<p1 << "   " <<p2<<"   "<< p2 - p1<<endl;
	x = 98;
	cout<<*p1<<endl;
	if(p1 > p2)  //relational operator is also possible on pointers
		cout<<"greater."<<endl;
}

void pointerAirthematic2()
{
	// arr datatype is *int
	long long int arr[5] = {1, 2, 3, 4, 5};  // by default array is defined as constant pointer ->long long int const arr[7] = {...}
	for(int i = 0; i<5; i++)
		cout<<arr[i] <<"   "<< &arr[i]<<endl;
	cout<<"----------------------------------"<<endl;
	for(long long int* ptr = &arr[0]; ptr != NULL ; ptr++)
	{
		cout<<*ptr<<endl;
		if(*ptr == arr[4]) break;
	}
	cout<<"----------------------------------"<<endl;
	long long int *p1 = arr;
	long long int *p2 = &arr[4];
	cout<<"Total number of elements in array:"<<p2 - p1 + 1<<endl;

	cout<<*p1<< " "<<*p1+1<< " " << *p1+2 <<"  "<<endl;
	p1++; //increament the pointers by 1 
	cout<<*p1<< " "<<*p1 - 1<<endl;
	for(int i = 0; i<5; i++)
		cout<<*(arr+i)<< " "; // *(arr+i) = arr[i]
}

void pointerTopointers()
{
	int a = 10;
	int* p = &a;
	//int* q = &p; 
	/*
		error as it will not hold the pointer of 'int*' as it can 
		only hold the pointers of 'int' only . instead use double indirection pointers.
	*/

	int *q = p;
	cout<<q<<"   "<<*q<<endl;

	int** j = &p; // store the address of pointer p of(int*) which was not possible with int
	cout<<j<<"   "<<*j<< "  "<< **j<<endl<<endl;


	cout<<"-----------Important --------------"<<endl;
	int k = 70;
	int* l = &k;
	int** m = &l;
	cout<<k <<"  " <<&k << "  "<< l <<"  "<< &l <<endl; // &l = m, *m = l
	cout<<m << "  "<< *m << "  "<<**m <<endl;

}
void arrayPointers()
{
	// int* pointer[3] = {1, 2, 3}; wrong initialization
	int* pointers[3]; // pointers data type is int**
	int x = 1, y = 2, z = 3;
	pointers[0] = &x;
	pointers[1] = &y;
	pointers[2] = &z;

	cout<<"Address of pointers to pointers:"<<pointers<<endl;
	cout<<"Address of pointers to  pointer:"<<&pointers[0]<<endl;
	cout<<"Address of first pointer : "<<*pointers<<endl;

	for(int i= 0; i<3; i++)
		cout<<pointers[i] <<"   "<< *pointers[i]<<endl;

	cout<<"Size of int*:"<<sizeof(int*)<<endl;
	for(int i = 0; i<3; i++)
	{
		printf("%lld  : ", pointers[i]);
	}
	cout<<endl;
	cout<< &x << "	"<< &y << "		"<< &z <<endl;
	for(int i = 0; i<3; i++)
	{
		cout<<*(pointers + i)<< "	"; // prints address of x, y, z
	}
	cout<<endl;

	for(int i = 0; i<3; i++)
	{
		cout<<**(pointers + i)<< "	";
	}
}

void arrayPointers2()
{
	cout<<"Notice the value printed by p"<<endl;
	int arr[3] = {1, 2, 3};
	int* p = arr;

	for(int i = 0; i<3; i++)
		cout<<p[i]<< " "; //implicitly  p[i] = *(arr+ i) or *(p+i)
}

void array2D()
{
	int arr2D[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			cout<<&arr2D[i][j]<< " ";
		}
		cout<<endl;
	}

	for(int i = 0; i<3; i++)
	{
		int* col0 = &arr2D[i][0];
		for(int j = 0; j<3; j++)
		{
			cout<<*(col0 + j)<< " ";
		}
		cout<<endl;
	}

	// When 2D array is declared, the pointers of all elements are in contigous fashion so, 
	int* ptr = &arr2D[0][0];
	for(int i = 0; i<9; i++)
	{
		cout<<*(ptr+i)<< " ";
	}
	cout<<endl;
	for(int i = 0; i<9; i++)
	{
		cout<<ptr[i]<< " ";
	}
	cout<<endl;
}
void array2D2()
{
	/*
	Concept : ptrArr is type of 'int*', x[] -> x represents the first pointer
	x[0] ->represented as *(x + 0), 
	In same way pointer[i][j] is treated as (pointer[i] ->'int*') -> *(pointer[i] + j)

	*/
	int* ptrArr[3];
	int x[] = {1, 2, 3};
	int y[] = {4, 5, 6};
	int z[] = {7, 8, 9};

	ptrArr[0] = x;
	ptrArr[1] = y;
	ptrArr[2] = z;

	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
			cout<<ptrArr[i][j] << " ";
		cout<<endl;
	}
	cout<<endl;
	
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
			cout<<*(*(ptrArr + i) + j)<< " "; // or *(pointer[i] + j)
		cout<<endl;
	}
}

void stringPointers()
{
	char str[10] = "Anurag";
	for(int i = 0; str[i] != '\0'; i++)
		cout<<*(str + i)<< " ";

	cout<<endl;
	char char2D[2][6] = {{'A', 'n', 'u', 'r', 'a', 'g'}, "Anand"};
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j < 6; j++)
			cout<<*(char2D[i] + j);

		cout<<"-"<<endl;
	}

}
int main()
{
	pointersIntro();
	pointesrsAddressAsign();
	pointerManupulation();
	pointerAirthematic();
	pointerAirthematic2();
	pointerTopointers();
	arrayPointers();
	arrayPointers2();
	array2D();
	array2D2();
	stringPointers();
}