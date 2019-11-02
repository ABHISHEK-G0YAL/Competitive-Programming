#define DEBUG
#ifdef DEBUG
    #define debug(args...) Debugger(), args
    class Debugger {
    public:
        Debugger() {
            cout << "DEBUG : ";
        }
        template<typename T>
        Debugger& operator , (const T& i) {
            cerr << i << "  ";
            return *this;
        }
        ~Debugger() {
            cerr << endl;
        }
    };
#else
    #define debug(args...)
#endif