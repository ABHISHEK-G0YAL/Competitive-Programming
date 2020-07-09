// https://www.hackerrank.com/challenges/classes-objects/problem
// Accepted



class Student {
    int exam_1,exam_2,exam_3,exam_4,exam_5;
    public:
    void input() {
        cin>>exam_1>>exam_2>>exam_3>>exam_4>>exam_5;
    }
    int calculateTotalScore() {
        return exam_1+exam_2+exam_3+exam_4+exam_5;
    }
};

