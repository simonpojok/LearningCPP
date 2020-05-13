#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream cout(stdout);
QTextStream cerr(stderr);
QTextStream cin(stdin);

int main() {

    QFile qFile("mydata");
    qFile.open(QIODevice::WriteOnly);
    QTextStream outStream(&qFile);
    QString line;
    do {
        line = cout.readLine();
        if (line != "z") outStream << line << endl;
    } while (line != "z");
    qFile.close();
    bool res = qFile.open(QIODevice::ReadOnly);
    if (res) {
        QTextStream readStream(&qFile);
        while (not readStream.atEnd()) {
            cout << readStream.readLine() << endl;
        }
    }
    qFile.close();


}
