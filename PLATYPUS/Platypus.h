using namespace std;

class Platypus
{
	float weight = 0;
	short age = 0;
	char name = '\0';
	char gender = '\0';
	bool alive = 0;
	bool mutant = 0;

public:

	Platypus();//უპარამეტრო კონსტრუქტორი (default constructor) რომელიც ქმნის მკვდარ იხვნისკარტას.

	Platypus(char initGender, float initWeight, short initAge, char initName);/*
	პარამეტრიანი კონსტრუქტორი რომელსაც გადასცემთ მნიშვნელობებს,
	იმისათვის რომ განსაზღვროთ ობიექტის gender, weight, age, და name ცვლადების მნიშვნელობები, */

	//გეთერები რომლებიც აბრუნებენ საჭირო ინფორმაციას
	float get_Weight()const;
	short get_Age()const;
	char get_Name()const;
	char get_Gender()const;
	bool get_Alive()const;
	bool get_Mutant()const;

	//სეტერები რომლებიც ანიჭებენ საჭირო ინფორმაციას ობიექტებს
	void set_Age(short newAge);
	void set_Name(char newName);
	void set_Gender(char newGender);
	void set_Weight(float newWeight);
	void set_Alive(bool newAlive);
	void set_Mutant(bool newMutant);
	void Make_Dead();


	//ბეჭვდის ფუნქცია რომელსაც გამოაქვს ინფორმაცია იხვნისკარტაზე
	void print(ostream &out) const;

	/*	ფუნქცია age_me რომელიც არაფერს აბრუნებს,მაგრამ ცვლის ობიექტის ასაკს.
	მასში უნდა იყოს გათვალისწინებული 2% შანსი იმისა რომ ობიექტი შესაძლოა გახდეს მუტანტი.
	ყოველ-ჯერზე  age_me  ფუნქციის გამოძახებისას ობიექტს აქვს  შანსი რომ მოკვდეს და ეს შანსი ტოლია 10-ჯერ იხვნისკარტის წონისა,
	ანუ 5 კგ იხვნისკარტას აქვს 50% შანსი რომ მოკვდეს. 10 და მეტ კილოიანი იხნისკარტას სიკვდილის ალბათობა 100%-ია. */
	void age_me();

	/* ფუნქცია  fight- რომელიც პარამეტრად იღებს სხვა პლატიპუსს.
	რომელიც ახდენს იმ იხვნისკარტას შებრძოლებას რომელზეც ხდება ფუნქციის გამოძახება (calling_platypus ) მეორესთან 
	რომელიც პარამეტრად გადაეცემა (other_platypus). გამარჯვებული ვლინდება ძალების შეფარდებიდან ( "fight ratio") გამომდინარე 
	(calling_platypus წონა /other_platypus წონა) * 50. აიღება შემთხვევითი რიცხვი 1 დან 100-მდე.
	თუ ძალთა შეფარდება მეტია ამ შემთხვევით რიცხვზე  calling_platypus - იმარჯვებს, თუ არადა გამარჯვებულია მეორე.*/
	void fight(Platypus & p2);

	/* ფუნქცია eat ზრდის იხვნისკარტას წონას რამდომად მისი მიმდინარე წონის 0.1% - 5.0% -ით. */
	void eat();

	/* ფუნქცია  hatch(ახალშობილი) რომელიც ანიჭებს ახალდაბადებულ პლატიპუსს
	შემდეგ პარამეტრებს alive=true, mutant=false, და age=0. სქესი  'm' ან 'f' ერთნაირი ალბათობით.
	წონა რანდომად 0.1 დან - 1.0 კგ. სახელი მომხმარებელს თავად შეუძლია განუსაზღვროს 
	ან შესაძლებელია სახელი იყოს რაიმე შემთხვევითად განსაზღვრული სიმბოლო (character chosen randomly).*/
	void hatch();

};

ostream & operator << (ostream & out, const Platypus & p);
