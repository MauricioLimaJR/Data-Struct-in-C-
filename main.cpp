#include <iostream>
#include "queue.h"
using namespace std;
int main(){
	int n, i, input;
	cin >> n;
	Queue row(n);

	for(i=0; i < n; i++){
		cin >> input;
		row.enqueue(input);
	}

	row.peek();
	cout << "\nNow, the inverse queue: \n" << endl;
	row.inverse();
	cout << "Removing the first element" << endl;
	cout << row.dequeue() << endl;
	cout << "After removed: " << endl;
	row.peek();
	cout << "Removing all elements" << endl;

	for(i=0; i < n-1; i++){
		row.dequeue();
	}

	row.peek();
	cout << "Please, rewitre other values: " << endl;

	for(i=0; i < n; i++){
		cin >> input;
		row.enqueue(input);
	}
	
	row.peek();
	return 0;
}