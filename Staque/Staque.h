#pragma once
#ifndef __Staque__
#define __Staque__


#include <iostream>
#include <new>
#include <assert.h>

using namespace std;
typedef int StaqueElement;

class Staque
{
private:
	friend class Staque;
	unsigned int sizeStaque = 0; //სტაქუეს ზომა
	unsigned int oddN = 0; //ლუწი რიცხვები
	unsigned int evenN = 0; //კენტი რიცხვები

	 /*** Node კლასი ***/
	class Node
	{
		friend class Staque;
		StaqueElement data;
		int rank;
		Node* next;
		Node* back;
		//--- Node-ის კონსტრუქტორი
		Node(StaqueElement value, int rank, Node* linkNext = 0, Node* linkBack = 0)
			
			: data(value), rank(rank), next(linkNext), back(linkBack)
		{}
		//ვცვლით ელემენტის Link
		void ChangeLink(Node* linkNext, Node* linkBack)
		{
			next = linkNext;
			back = linkBack;
		}
		friend ostream& operator<<(ostream& out, Node& node) {
			out << node.data;
		}
	};

	typedef Node* NodePointer;

	/***** Data წევრები *****/
	NodePointer FirstPtr;
	NodePointer LastPtr;
	//წინა მხრიდან აღების ფუნქცია
	NodePointer& Begin();
	//უკანა მხრიდან აღების ფუნქცია
	NodePointer& End();

public:
	/***** ფუნქციის წევრები *****/
	/***** კონსტრუქტორი *****/
	Staque();
	/***** დესტრუქტორი *****/
	~Staque();

	//ამატებს ახალ ელემენტს სტაქუეში
	void push(const StaqueElement& value);

	//ნახულობს ცარიელია თუ არა სტაქუე
	bool empty() const;
	//ბეჭდავს ყველა ელემენტს
	void display(ostream& out = cout) const;
	//ბეჭდავს შებრუნებულ სტაქუეს ყველა ელემენტს
	void rdisplay(ostream& out = cout) const;
	//შლის ელემენტს ლუწსაც და კენტსაც
	void pop(int evenN, int oddN);
	//შლის ზოგიერთ ელემენტს
	void pop(const int& number);

	//გადატვირთვის ოპერაცია
	int& operator[](const int& index);
	//ასუფთავებს სტაქუეს
	void clear();
	//იღებს სტაქუეს ზომა
	int size() const;


};

//კონსტრუქტორი
Staque::Staque()
	: LastPtr(0), FirstPtr(0)
{}
//დესტრუქტორი
Staque::~Staque() {
	if (!empty()) {
		clear();
	}
}
//---შეტანის ოპერაციის განსაძღვრა 
void Staque::push(const StaqueElement& value)
{
	sizeStaque++;

	//თუ ცარიელია?
	if (empty()) {
		FirstPtr = new Staque::Node(value, sizeStaque, 0, 0);
		LastPtr = FirstPtr;
	}
	else if (sizeStaque == 2) {
		//თუ ლუწია?
		if (value % 2 == 0) {
			FirstPtr = new Staque::Node(value, sizeStaque, FirstPtr, 0);
			LastPtr->ChangeLink(0, FirstPtr);
		}
		//თუ კენტია?
		else {
			LastPtr = new Staque::Node(value, sizeStaque, 0, FirstPtr);
			FirstPtr->ChangeLink(LastPtr, 0);
		}
	}
	else {
		//თუ ლუწია?
		if (value % 2 == 0) {
			FirstPtr = new Staque::Node(value, sizeStaque, FirstPtr);
			FirstPtr->next->ChangeLink(FirstPtr->next->next, FirstPtr);
		}
		//თუ კენტია?
		else {
			LastPtr = new Staque::Node(value, sizeStaque, 0, LastPtr);
			LastPtr->back->ChangeLink(LastPtr, LastPtr->back->back);
		}

	}

	//თუ ლუწია?
	if (value % 2 == 0) {
		evenN++;
	}
	//თუ კენტია?
	else {
		oddN++;
	}
}
//--- განსაზრვრა ეკრანზე ბეჭვდის ოპერაციის
void Staque::display(ostream& out) const
{
	for (NodePointer ptr = FirstPtr; ptr != 0; ptr = ptr->next) {
		out << ptr->data << " ";
		//out << ptr->rank << endl;
	}
	out << endl;
}
//--- განსაზღვრა შებრუნებული სტაქუეს ბეჭვდის ფუნქციის
void Staque::rdisplay(ostream& out) const
{
	for (NodePointer ptr = LastPtr; ptr != 0; ptr = ptr->back) {
		out << ptr->data << " ";
	}
}
//--- Definition of empty()
bool Staque::empty() const
{
	return FirstPtr == 0;
}
//--- Definition of pop with two parametr()
void Staque::pop(int evenN, int oddN) {
	//If try delete all elements
	if (evenN + oddN == sizeStaque) {
		clear();
	}
	else {
		
		bool Condition = !empty() && evenN <= this->evenN && oddN <= this->oddN && evenN >= 0 && oddN >= 0 && evenN + oddN < sizeStaque;
		assert(Condition);
	
		this->evenN -= evenN;
		this->oddN -= oddN;
		this->sizeStaque -= evenN + oddN;
		NodePointer ptr;
		if (evenN > 0 && oddN > 0)
			//LIFO
			while (true) {

				//If Front Element rank more than Back
				if (FirstPtr->rank > LastPtr->rank && evenN > 0) {
					//Delete First Element
					evenN--;
					ptr = FirstPtr->next;
					ptr->ChangeLink(ptr->next, 0);
					
					//clog << "Deleted FirstPtr with " << FirstPtr->data << endl;
					delete FirstPtr;
					FirstPtr = ptr;
				}
				//If Front Element rank more than Back
				else if (FirstPtr->rank < LastPtr->rank && oddN > 0) {
					//Delete Last Element
					oddN--;
					ptr = LastPtr->back;
					ptr->ChangeLink(0, ptr->back);
					
					//clog << "Deleted LastPtr with " << LastPtr->data << endl;
					delete LastPtr;
					LastPtr = ptr;
				}

				else {
					bool ConditionLIFO = evenN == 0 && oddN == 0; 
					assert(ConditionLIFO);
					break;
				}
			}
	}
}
//--- Definition of pop with one parametr()
void Staque::pop(const int& number) {

	if (number == sizeStaque) {
		clear();
	}
	else {
		bool Condition = number > 0 && number <= sizeStaque;
		assert(Condition);
		this->sizeStaque = evenN + oddN;
		NodePointer ptr;
		for (int i = 0; i < number; i++) {
			//If Front Element rank more than Back
			if (FirstPtr->rank > LastPtr->rank && evenN > 0) {
				//Delete First Element
				evenN--;
				ptr = FirstPtr->next;
				ptr->ChangeLink(ptr->next, 0);
				
				//clog << "Deleted FirstPtr with " << FirstPtr->data << endl;
				delete FirstPtr;
				FirstPtr = ptr;
			}
			//If Front Element rank more than Back
			else if (FirstPtr->rank < LastPtr->rank && oddN > 0) {
				//Delete Last Element
				oddN--;
				ptr = LastPtr->back;
				ptr->ChangeLink(0, ptr->back);
				
				//clog << "Deleted LastPtr with " << LastPtr->data << endl;
				delete LastPtr;
				LastPtr = ptr;
			}
			else {
				bool ConditionLIFO = evenN == 0 && oddN == 0; //If Function not End Success
				assert(ConditionLIFO);
				break;
			}
		}
	}
}

//Index operator Reload
int& Staque::operator[](const int& index) {
	bool ConditionRange = !empty() && index >= 0 && index <= size();
	assert(ConditionRange);
	NodePointer ptr = FirstPtr;
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr->data;
}
//Delete All elements
void Staque::clear() {
	bool StaqueEmpty = !empty();
	assert(StaqueEmpty);
	NodePointer ptr = FirstPtr;
	while (ptr != 0) {
		ptr = FirstPtr->next;
		delete FirstPtr;
		FirstPtr = ptr;
	}
	LastPtr = 0;
	FirstPtr = 0;

}
int Staque::size() const {
	return sizeStaque;
}

#endif