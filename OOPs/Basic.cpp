#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
    // Properties
private:
    int health;

public:
    char level;
    char *name;
    static int timeToComplete;

    Hero() // Default
    {
        cout << " Simple constructor is called " << endl;
        name = new char[100];
    }

    // Parameterized constructor
    Hero(int health)
    {
        // cout << "Second -> " << this << endl;
        this->health = health;
    }
    Hero(int health, char level)
    {
        // cout << "Second -> " << this << endl;
        this->health = health;
        this->level = level;
    }

    // Copy constructor
    Hero(Hero &temp)
    {
        // Deep copy
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << " Copy CONSTRUCTOR called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    // Hero()
    // {
    //     cout << " Constuructor called " << endl;
    // }
    void print()
    {
        cout << endl;
        cout << "[ Name: " << this->name << " ,";
        cout << "Level is : " << this->level << " ,"; // You can drop 'health' only instead of 'this->health' , but for better understanding of which health we are mentioning about
        cout << "Health is : " << this->health << " ]";
        cout << endl;
    }

    int add()
    {
        int sum = health + level;
        return sum;
    }

    int getHealth()
    {
        return health;
    }

    int getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    // Destructor
    ~Hero()
    {
        cout << "Destructor bhai called" << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    cout <<  Hero::timeToComplete;

}
// // statically
// Hero a;

// // Dynamically
// Hero *b = new Hero();
// // Manually desturctor called
// delete b;

// return 0;

// Hero hero1;
// hero1.setHealth(12);
// hero1.setLevel('D');
// char name[8] = "Pranjal";
// hero1.setName(name);

// // hero1.print();

// // Use default copy constructor

// Hero hero2(hero1);
// // hero2.print();
// // Hero hero2 = hero1;

// hero1.name[0] = 'G';
// hero1.print();

// hero2.print();

// hero1 = hero2; //hero2 is copied in hero1
// hero1.print();

// hero2.print();

// Hero Rupesh(70, 'C');
// Rupesh.print();

// // Copy Constructor
// Hero Ayush(Rupesh);
// Ayush.print();
// i.e
//  Ayush.health = Rupesh.health;
//  Ayush.level = Rupesh.level;

// // Obejct created statically
// Hero Priyanshu(10);
// cout << " Address of Priyanshu " << &Priyanshu << endl;
// Priyanshu.getHealth();

// Priyanshu.print();

// // Dynacmically
// Hero *h = new Hero(22, 'B');
// h -> print() ;

// Hero temp(22, 'C');
// temp.print();

// Static allocation
//     Hero a;
//     a.setHealth(80);
//     a.setLevel('B');
//     cout << " Level is " << a.level << endl;
//     cout << " Health is " << a.getHealth() << endl;

//     // Dynamically
//     Hero *b = new Hero;
//     b->setLevel('A');
//     b->setHealth(70);
//     cout << " Level is " << b->level << endl;
//     cout << " Health is " << (*b).getHealth() << endl;

//     // creation of Object
//     Hero Akanksha;

//     // cout << " Health is : " << Akanksha.health << endl;

//     // Getter
//     // cout << "Akanksha health is " << Akanksha.getHealh() << endl;

//     // Setter
//     Akanksha.setHealth(70);

//     // Akanksha.health = 60;
//     Akanksha.level = 'A';

//     cout << " Health is : " << Akanksha.level << endl;
//     cout << " Sum is : " << Akanksha.add() << endl;

//     cout << "Size : " << sizeof(Akanksha) << endl;

//     return 0;
// }
// class Hero{
//     //properties
//     int health;
// };

// int main(){

//     //creation of Object
//     Hero h1;

// cout << "Size : " << sizeof(h1) << endl;

//     return 0;
// }