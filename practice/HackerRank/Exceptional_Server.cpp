// https://www.hackerrank.com/challenges/exceptional-server/problem
// Accepted


        try {
            cout << Server::compute(A, B) << endl;
        }
        catch(bad_alloc &ex) {
            cout << "Not enough memory" << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Other Exception" << endl;
        }
