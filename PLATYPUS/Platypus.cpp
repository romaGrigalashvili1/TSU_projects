#include<iostream>
#include<random>
using namespace std;
#include "Platypus.h"



Platypus::Platypus()
	:alive(false)
{
	cout << "Platypus Constructed" << endl;
}

Platypus::Platypus(char initGender, float initWeight,short initAge, char initName) 
{

	if ((initGender == 'M' || initGender == 'F' || initGender == 'm' || initGender == 'f')
		&& initWeight >= 0
		&& initAge >= 0) {

		weight = initWeight;
		age = initAge;
		name = initName;
		gender = initGender;
		alive = 1;
		mutant = 0;

		cout << name << " Platypus Constructed" << endl;
		cout << "Gender: " << gender << endl;
		cout << "Weight: " << weight << endl;
		cout << "Age: " << age << " months" << endl;

		if (alive == 1) {
			cout << "Alive: YES " << endl;
		}
		else {
			cout << "Alive: NO " << endl;
		}

		if (mutant == 0) {

			cout << "Mutant: YES " << endl;

		}
		else {

			cout << "Mutant: NO " << endl;
		}
	}
	else {
		cout << "\t\t\tPlatypus is invalid " << endl;
	}

}

//გეთერები //GETERS
float Platypus::get_Weight()const {

	return weight;

}
short Platypus::get_Age()const {

	return age;

}
char Platypus::get_Name()const {

	return name;

}
char Platypus::get_Gender()const {

	return gender;

}
bool Platypus::get_Alive()const {

	return alive;
}
bool Platypus::get_Mutant()const {

	return mutant;
}


//სეტერები //SETERS
void Platypus::set_Weight(float newWeight) {

	weight = newWeight;

}
void Platypus::set_Age(short newAge) {

	age = newAge;
}
void Platypus::set_Gender(char newGender) {

	gender = newGender;
}
void Platypus::set_Name(char newName) {

	name = newName;
}
void Platypus::set_Alive(bool newAlive) {

	alive = newAlive;
}
void Platypus::set_Mutant(bool newMutant) {

	mutant = newMutant;
}

//დაბეჭვდის ფუნქციის იმპლემენტაცია
void Platypus::print(ostream &out)const {

	out << "Name: " << name << endl;
	out << "Gender: " << gender << endl;
	out << "Age: " << age <<" months"<< endl;
	out << "Weight: " << weight << endl;
	

	if (alive == 1) {
		out << "Alive: YES " << endl;
	}
	else{
		out << "Alive: NO " << endl;
	}

	if (mutant == 0) {
		
		out << "Mutant: YES " << endl;

	}
	else {

		out << "Mutant: NO " << endl;
	}
}

/*მასში უნდა იყოს გათვალისწინებული 2% შანსი იმისა რომ ობიექტი შესაძლოა გახდეს მუტანტი.
ყოველ-ჯერზე  age_me  ფუნქციის გამოძახებისას ობიექტს აქვს  შანსი რომ მოკვდეს და ეს შანსი ტოლია 10-ჯერ იხვნისკარტის წონისა,
ანუ 5 კგ იხვნისკარტას აქვს 50% შანსი რომ მოკვდეს. 10 და მეტ კილოიანი იხნისკარტას სიკვდილის ალბათობა 100%-ია. */
void Platypus::age_me() {
	if (alive == 0) {
		cout << "The Platypus is already dead! " << endl;
		return;
	}
	cout << "aged platypus " << endl;
	int chance; 
	int weight_percent; 
	int death_rand;

	age += 1;//ასაკი ყოველ გამოძახებაზე იზრდება

//2% შანსი იმისა რომ ობიექტი შესაძლოა გახდეს მუტანტი.
//10 და მეტ კილოიანი იხნისკარტას სიკვდილის ალბათობა 100%-ია.
	chance = (rand() % 100) + 1;
	if (chance == 2) {
		mutant = 1;
		cout << "Platypus has mutanted! " << endl;
	}
	if (weight >= 10) {
		cout << "The aged platypus has died! " << endl;
		alive = 0;
		return;
	}
// შანსი იმისა რომ იხვნისკარტა მოვდეს ტოლია 10-ჯერ იხვნისკარტის წონისა.
	weight_percent = weight * 10;
//რანდომული ციფრი 1-100 შუალედიდან
	death_rand = (rand() % 100) + 1;
//თუ  მოკვდება
	if (death_rand <= weight_percent) {
		alive = 0;
		cout << "The aged platypus has died" << endl;
	}
}
/* ფუნქცია  fight-  გამარჯვებულს გამოავლენს ძალების შეფარდებიდან ( "fight ratio") გამომდინარე 
	(calling_platypus წონა /other_platypus წონა) * 50. აიღება შემთხვევითი რიცხვი 1 დან 100-მდე.
	თუ ძალთა შეფარდება მეტია ამ შემთხვევით რიცხვზე  calling_platypus - იმარჯვებს, თუ არადა გამარჯვებულია მეორე.*/
void Platypus::fight(Platypus & p2) {
	if (alive == 0) {
		cout << "Your Platypus isn't Alive to Fight " << endl;
		return;
	}
	if (p2.get_Alive() == 0) {
		cout << "The Platypus you want to Fight is already Dead! " << endl;
	}

	cout << "The 2 Platypuses Engage in Combat!" << endl;

	//( "fight ratio") გამომდინარე (calling_platypus წონა /other_platypus წონა) * 50.
	float p2_weight = p2.get_Weight();
	float fight_ratio = (weight / p2_weight) * 50;
	/*აიღება შემთხვევითი რიცხვი 1 დან 100-მდე.
	თუ ძალთა შეფარდება მეტია ამ შემთხვევით რიცხვზე  calling_platypus - იმარჯვებს,
	თუ არადა გამარჯვებულია მეორე.*/
	int chance = (rand() % 100) + 1;
	if (chance < fight_ratio) {
		p2.Make_Dead();
		cout << "The 2nd Platypus was killed " << endl;
	}
	else{
		alive = 0;
		cout << "The calling platypus has died in battle" << endl;
	}
	
}

/* ფუნქცია eat ზრდის იხვნისკარტას წონას რამდომად მისი მიმდინარე წონის 0.1% - 5.0% -ით. */
void Platypus::eat() {
	if (alive == 0) {
		cout << "A Dead Platypus cann't eat..." << endl;
		return;
	}
	//რანდომულად 1-50 შუალედში
	float chance = (rand() % 5) + 1;
	chance = chance / 100;
	weight = (weight*chance) + weight;
	cout << "New weight is : " << weight << endl;

}

/* ფუნქცია  hatch(ახალშობილი) რომელიც ანიჭებს ახალდაბადებულ პლატიპუსს
	შემდეგ პარამეტრებს alive=true, mutant=false, და age=0. სქესი  'm' ან 'f' ერთნაირი ალბათობით.
	წონა რანდომად 0.1 დან - 1.0 კგ. სახელი მომხმარებელს თავად შეუძლია განუსაზღვროს
	ან შესაძლებელია სახელი იყოს რაიმე შემთხვევითად განსაზღვრული სიმბოლო (character chosen randomly).*/
void Platypus::hatch() {

	char newName;
	char newGender;
	//სქესი  'm' ან 'f' ერთნაირი ალბათობით.
	int chance = (rand() % 2);
	if (chance == 0) {
		newGender = 'M';
	}
	else {
		newGender = 'F';
	}
	cout << "New Platypus Gender is : " << newGender << endl;
	cout << "chose name (1st initial only): " << endl;
	cin >> newName;

	//წონა რანდომად 0.1 დან - 1.0 კგ
	float newWeight = ((rand() % 100) + 1) / 100;
	Platypus newP(newGender, newWeight, 0, newName);
	cout << "New Platypus has been created " << endl;
}


void Platypus::Make_Dead() {
	alive = 0;
}

//ოპერატორების გადატვირთვა
ostream & operator<<(ostream & out, const Platypus & p)
{
	p.print(out);
	return out;
}
