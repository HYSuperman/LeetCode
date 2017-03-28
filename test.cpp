#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class Car{

private:
	string name;
	int age;

public:
	Car(string, int);

	string getname() const{return name;}
	int getage() const{return age;}
	void setname(string n){name = n;}
	void setage(int a){age = a;}

};

Car::Car(string n, int a){
	name = n;
	age = a;
}

struct compareCar
{
	bool operator()(const Car& c1, const Car& c2) const{
		if(c1.getname() == c2.getname()){
			return c1.getage() < c2.getage();
		}
		return c1.getname() < c2.getname();
	}
};

struct comp
{
	bool operator()(const pair<string, int>& l1, const pair<string, int>& l2){
		return l1.second < l2.second;
	}
};

void printMap(map<Car, int, compareCar>);
void printSet(set<pair<string, int>, comp>);

int main(){

	Car c1("red", 3);
	Car c2("red", 4);
	Car c3("red", 5);
	Car c4("red", 1);

	map<Car, int, compareCar> carCata;
	set<pair<string, int>, comp> carLog;
	unordered_map<int, int> lookuptable;

	carCata[c1] = 123;
	carCata[c2] = 234;
	carCata[c3] = 345;
	carCata[c4] = 456;

	carLog.insert(make_pair("Enz", 123));
	carLog.insert(make_pair("Zmw", 234));
	carLog.insert(make_pair("Canada", 345));
	carLog.insert(make_pair("Dick", 456));


/*
	carCata.emplace(c1, 123);
	carCata.emplace(c2, 234);
	carCata.emplace(c3, 345);
	carCata.emplace(c4, 456);
*/
	printMap(carCata);
	printSet(carLog);

	cout << INT_MAX << " " << INT_MIN << NULL << endl;

	    std::string s("Somewhere down the road");
    std::istringstream iss(s);

    do
    {
        std::string sub;
        iss >> sub;
        std::cout << "Substring: " << sub << std::endl;
    } while (iss);
}


void printMap(map<Car, int, compareCar> m){
	for (auto& x: m) {
		std::cout << x.first.getname() << ": " << x.first.getage() << '\n';
  	}
}
void printSet(set<pair<string, int>, comp> s){
	for(auto& x: s){
		cout << x.first << ": " << x.second << "\n";
	}
}