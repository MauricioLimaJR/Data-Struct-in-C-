#include <iostream>
#include "queue.h"
using namespace std;
Queue::Queue(int value){
	capacity = value;
	data = new float[value];
	first = 0;
	last = -1;
	amount = 0;
}

void Queue::enqueue(int element){
	if(!q_full()){
		if(last == capacity-1)
		last = -1;
		data[++last] = element;
		amount++;
	}
	else{
		cout << "The Queue is full!" << endl;
	}
}

int Queue::dequeue(){
	if(!q_empty()){
		int target = data[first];
		if(first == capacity-1)
		first = -1;
		first++; amount--;
		return target;
	}
	else{
		cout << "The Queue is empty!" << endl;
	}
}

void Queue::peek(){
	if(!q_empty()){
		int i, ct;
		for(ct=0, i=first; ct < amount; ct++){
			cout << data[i++] << endl;
			if(i == capacity)
			i = 0;
		}
	}
	else{
		cout << "The Queue is empty!" << endl;
	}
}

void Queue::inverse(){
	Queue rowA(q_size()-1);
	Queue rowB(q_size()-2);
	int i,j;
	//Left just the last element in thr original queue
	for(i = 0, j = q_size()-1; i < j; i++){
		rowA.enqueue(dequeue());
	}

	/* Repeat the same process above betwen rowA and rowB
	adding to the original queue the last element from
	rowA and after recovering the first elements from
	rowB. This process happen until the queue rowA be
	empty.
	*/

	while(!rowA.q_empty() || !rowB.q_empty()){
		for(i=0, j=rowA.q_size()-1; i < j; i++){
			rowB.enqueue(rowA.dequeue());
		}
		enqueue(rowA.dequeue());
		for(i=0, j=rowB.q_size(); i < j; i++){
			rowA.enqueue(rowB.dequeue());
		}
	}
	peek();
}

bool Queue::q_empty(){
	return amount == 0;
}

bool Queue::q_full(){
	return amount == capacity;
}

int Queue::q_size(){
	return amount;
}