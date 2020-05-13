#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    using namespace std;
    ostringstream strbuf;

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "An in-memory stream" << endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    outf.open("mydata");
    outf << strval;
    outf.close();

    cout << "Read data from the file - watch for errors. " << endl;
    string newstr;
    ifstream inf;
    inf.open("mydata");
    if (inf) {
        int luck2;
        inf >> newstr >> luck2;
        if (lucky != luck2) {
            cerr << "Error! wrong" << newstr << luck2 << endl;
        } else cout << newstr << "OK" << endl;
        float pi2;
        inf >> newstr >> pi2;
        if (pi2 != pi) {
            cerr << "ERROR! Wrong" << newstr << pi2 << endl;
        } else cout << newstr << " OK " << endl;

        double e2;
        inf >> newstr >> e2;
        if (e2 != e) {
            cerr << "ERROR! Wrong" << newstr << e2 << endl;
        } else cout << newstr << " OK " << endl;
        inf.close();
    }

    cout << "Read from file line-by-line" << endl;
    inf.open("mydata");
    if (inf) {
        while(not inf.eof()) {
            getline(inf, newstr);
            cout << newstr << endl;
        }
        inf.close();
    }

//    ostringstream outstringstream;
//    string line;
//    do {
//        cin >> line;
//        outstringstream << line << endl;
//    } while (line != "z");

    ofstream outfilestream;
    outfilestream.open("mytextdata");
    string line;
    do {
        getline(cin, line);
        outfilestream << line + '\n';
    } while (line != "z");
//    outfilestream << outstringstream.str();
    outfilestream.close();

    ifstream inputfilestream;
    inputfilestream.open("mytextdata");
    string lineout;
    if (inputfilestream) {
        while (not inputfilestream.eof()) {
            getline(inputfilestream, lineout);
            cout << lineout << endl;
        }
    }

    return 0;
}
