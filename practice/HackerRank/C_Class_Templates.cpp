// https://www.hackerrank.com/challenges/c-class-templates/problem


#define concatenate add
#define cin ios_base::sync_with_stdio(false);cin.tie(NULL);cin
template <typename T>
class AddElements {
    T element1;
public:
    AddElements (T arg) : element1(arg){
    }
    T add(T element2) {
        return element1 + element2;
    }
};
