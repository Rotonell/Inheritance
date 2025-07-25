#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS  last_name,  first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//  Constructors

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Hconstructors:\t" << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods:

	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

#define SRUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define SRUDENT_GIVE_PARAMETERS  speciality,  group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating; // успеваемость 
	double attendance; // посещаемость

public:
	const std::string get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double  rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// Constructors:

	Student
	(
		HUMAN_TAKE_PARAMETERS, SRUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructors:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//Methods:

	void info() const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS  speciality, experience

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	// Constructors:

	Teacher
	(
		HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const override
	{
		Human::info();
		cout << speciality << " " << experience << endl;
	}





};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate : public Student
{

	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//constructors

	Graduate(HUMAN_TAKE_PARAMETERS, SRUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, SRUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructors:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//Methods:
	void info()
		const override
	{
		Student::info();
		cout << get_subject() << endl;
	}
};

//#define INHERITANCE
#define POLUMORPHISM


void main() {

	setlocale(LC_ALL, "");

#ifdef INHERITANCE

	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pincman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Teacher teacher("white", "walter", 50, "Chemestry", 25);
	teacher.info();

	Graduate graduate("Schereder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch...");
    graduate.info();

# endif//INHERITANCE

	Human* group[] =
	{
	  new Student ("Pincman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
	  new Teacher("white", "walter", 50, "Chemestry", 25),
	  new Graduate ("Schereder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch..."),
	  new Student ("Vercetty", "Tommy", 22, "Theft", "Vise", 95, 99),
	  new Teacher("Diaz", "Ricardo", 50, "Weapon distribution", 20)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
}
