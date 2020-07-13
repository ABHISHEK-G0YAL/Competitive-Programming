// https://www.hackerrank.com/challenges/box-it/problem



class Box {
    long long l,b,h;
    public:
    Box() {
        l=0; b=0; h=0;
    }
    Box(int L,int B,int H) {
        l=L; b=B; h=H;
    }
    Box(Box &a) {
        l=a.getLength(); b=a.getBreadth(); h=a.getHeight();
    }
    int getLength() {
        return l;
    }
    int getBreadth () {
        return b;
    }
    int getHeight () {
        return h;
    }
    long long CalculateVolume() {
        return l*b*h;
    }
    bool operator<(Box& a) {
        if(l<=a.getLength()) {
            if(l<a.getLength()) return true;
            else if(b<=a.getBreadth()) {
                if(b<a.getBreadth()) return true;
                else if(h<a.getHeight()) return true;
                return false;
            }
        }
        return false;
    }
};

ostream &operator<<(ostream &out, Box &a) {
    out<<a.getLength()<<" "<<a.getBreadth()<<" "<<a.getHeight();
    return out;
}
