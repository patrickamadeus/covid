//UNTUK INISIASI, COPY, DAN CETAK, mengimplementasi sendiri

#include <stdio.h> 
#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <math.h>
using namespace std;
 

//INISIALISASI LINKED LIST
typedef struct _node{
	int data;
	struct _node *next;
} node;

int main(){
	int n;
	//menetapkan jumlah node linked list
	cout<<"Jumlah node linked list: ";
	cin>>n;
	
	//membuat pointer untuk head dan current
	node *head = NULL;
	node *current;
	
	//membuat linked list sebanyak n
	for (int i=0;i<n;i++){
		if (head==NULL){
			//keadaan awal current dan head sama, lalu kita mengalokasikan memori dengan function malloc
			head = current = (node*)malloc(sizeof(node));
			//assign value head menjadi i
			head->data = i;
		}
		else{
			//kita membuat kotak dan menyambungkan nextnya current 
			
			//node *nodebaru = (node*)malloc(sizeof(node))
			//current->next = nodebaru
			
			//dapat disingkat:
			current->next = (node*)malloc(sizeof(node));
			current = current->next;
			current->data = i;
			
		}
	}
	//COPY LINKED LIST
	//inisiasi pointer baru
	node *newHead = NULL;
	node *newCurrent;
	current = head;
	//looping sesuai n
	for (int i=0;i<n;i++){
		//head
		if (newHead==NULL){
			//mengalokasikan memori untuk newHead
			newHead = newCurrent = (node*)malloc(sizeof(node));
			//mengcopy data dari current ke data newHead
			newHead->data = current->data; 
			//memindahkan current ke next
			current = current->next;
		}
		else{
			//mengalokasikan memori untuk next
			newCurrent->next = (node*)malloc(sizeof(node));
			//memindahkan newCurrent ke next
			newCurrent = newCurrent->next; 
			//data current dicopy ke newCurrent
			newCurrent->data = current->data;
			//memindahkan current ke next
			current = current->next;
		}
	}
	
	//CETAK LINKED LIST
	current = head;
	for (int i=0;i<n;i++){
		cout<<current->data<<"\n";
		current = current->next;
	}
}

