#include <QString>
#include <QTextStream>

QTextStream cout(stdout);
QTextStream cin(stdin);

int main() {
    QString s1("This "), s2("is a "), s3("string");
    s1 += s2;
    QString s4 = s1 + s3;
    cout << s4 << endl;
    cout << "The length of that string is " << s4.length() << endl;
    cout << "Enter a sentence with a whitespace: " << endl;
    s2 = cin.readLine();
    cout << "Here is your sentence: \n" << s2 << endl;
    cout << "The length of your sentence is: " << s2.length() << endl;
    return 0;
}
