
#include"Employee.h"
#include"Chaining.h"
#include"Linear.h"
using namespace std;






void main()
{
	
	Employee e("Mina", 30 ,10000 ,4);
	Employee e1("Fawzy ", 45, 5000, 8);
	Employee e2("Yara ",19 ,2000 ,0);
	Employee e3("Mariam ",32 ,8000 ,2);
	Employee e4("Ayman" ,33 ,4000 ,8);
	Employee e5("Roshdy" ,28 ,9000 ,3);
	Employee e6("Aya", 26 ,6000, 3);
	Employee e7("Abdallah", 29, 7000, 4);
	Employee e8("Fatema" ,24 ,3000, 1);

	Linear_Hashing lh;
	Chain_Hashing ch;
	ch.insert(e);
	ch.insert(e1);
	ch.insert(e2);
	ch.insert(e3);
	ch.insert(e4);
	ch.insert(e5);
	ch.insert(e6);
	ch.insert(e7);
	ch.insert(e8);
	ch.remove(e3);
	ch.remove(e2);
	ch.print();
	cout << endl<<"Collision Rate: " << ch.collision_rate()<<" Collisions\n\n";
	lh.insert(e);
	lh.insert(e1);
	lh.insert(e2);
	lh.insert(e3);
	lh.insert(e4);
	lh.insert(e5);
	lh.insert(e6);
	lh.insert(e7);
	lh.insert(e8);
	lh.remove(e3);
	lh.remove(e2);

	lh.print();
	cout << endl << "Collision Rate: " << lh.coll_rate() << " Collisions\n\n";
	



	


}