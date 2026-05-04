#include<iostream>
#include<vector>
#include "TSubstance.h"
#include "TCup.h"
using namespace std;


int main()
{
	cout << "Hello World!\n";

	TCup kubek1;
	kubek1.add(substancje[0], 100);
	kubek1.add(substancje[1], 50);
	kubek1.add("woda", 30);
	kubek1.add("kwas", 1);
	kubek1.add("krew", 1000);
	kubek1.add("mleko", 20);
	kubek1.show();
	

}
