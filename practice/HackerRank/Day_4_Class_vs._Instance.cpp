// https://www.hackerrank.com/challenges/30-class-vs-instance/problem

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if(initialAge<0)
        {
            cout<<"Age is not valid, setting age to 0."<<endl;
            age=0;
        }
        else
            age=initialAge;

    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age<13)
            cout<<"You are young."<<endl;
        else if(age>17)
            cout<<"You are old."<<endl;
        else
            cout<<"You are a teenager."<<endl;
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        ++age;

    }