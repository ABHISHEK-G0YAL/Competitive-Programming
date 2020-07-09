// https://www.hackerrank.com/challenges/attending-workshops/problem
// Accepted



//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int endTime;
    int startTime;
    int duration;
};
struct Available_Workshops {
    int n;
    Workshop* a;
};
//Implement the functions initialize and CalculateMaxWorkshops
bool operator<(Workshop& a, Workshop& b) {
    return a.endTime < b.endTime;
}
Available_Workshops* initialize(int* start_time, int* duration, int n) {
    Available_Workshops* ptr = new Available_Workshops;
    ptr->n = n;
    ptr->a = new Workshop[n];
    for(int i = 0; i < n; i++) {
        ptr->a[i].startTime = start_time[i];
        ptr->a[i].duration = duration[i];
        ptr->a[i].endTime = start_time[i] + duration[i];
    } return ptr;
}
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->a, ptr->a + ptr->n);
    int m = 1;
    int endTime = ptr->a[0].endTime;
    for(int i = 1; i < ptr->n; i++) {
        if(ptr->a[i].startTime >= endTime) {
            m += 1;
            endTime = ptr->a[i].endTime;
        }
    }
    return m;
}
