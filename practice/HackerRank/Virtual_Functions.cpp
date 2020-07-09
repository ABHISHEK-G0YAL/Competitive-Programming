// https://www.hackerrank.com/challenges/virtual-functions/problem
// Accepted


class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata() {
        cin >> name >> age;
    }
    virtual void putdata() {
        cout << name << " " << age << endl;
    }
};
class Professor : public Person {
    static int curr_id;
    int id, publications;
    void getdata() {
        cin >> name >> age >> publications;
        id = ++curr_id;
    }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << id << endl;
    }
};
class Student : public Person {
    static int curr_id;
    int id, marks[6];
    void getdata() {
        cin >> name >> age;
        cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
        id = ++curr_id;
    }
    void putdata() {
        cout << name << " " << age << " ";
        cout << marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5];
        cout << " " << id << endl;
    }
};
int Professor::curr_id;
int Student::curr_id;
