#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    string name;
    int age;
    double mark;
public:
    Student() {              //
        name = "Default man";//
        age = 69;            //Constructor
        mark = 6.9;          //
    }                        //

    void Writer() {                                                                     //
        ofstream outFile("StudentFile", ios::binary);                                   //
        if (!outFile) {                                                                 //
            cerr << "Error while openning file.\n";                                     //
        }                                                                               //
        outFile.write(reinterpret_cast<const char*>(&age), sizeof(age));                //
        outFile.write(reinterpret_cast<const char*>(&mark), sizeof(mark));              //Binary writer
                                                                                        //
        size_t messageSize = name.size();                                               //
        outFile.write(reinterpret_cast<const char*>(&messageSize), sizeof(messageSize));//
        outFile.write(name.c_str(), messageSize);                                       //
        outFile.close();                                                                //
    }                                                                                   //

    void Reader() {                                                                     //
        ifstream inFile("StudentFile", ios::binary);                                    //
        if (!inFile) {                                                                  //
            cerr << "Error while readding.\n";                                          //
        }                                                                               //
                                                                                        //
        int readAge;                                                                    //
        double readMark;                                                                //
        size_t readMessageSize;                                                         //
        string readName;                                                                //
                                                                                        //
        inFile.read(reinterpret_cast<char*>(&readAge), sizeof(readAge));                //
        inFile.read(reinterpret_cast<char*>(&readMark), sizeof(readMark));              //Binary reader
                                                                                        //
        inFile.read(reinterpret_cast<char*>(&readMessageSize), sizeof(readMessageSize));//
        readName.resize(readMessageSize);                                               //
        inFile.read(&readName[0], readMessageSize);                                     //
                                                                                        //
        inFile.close();                                                                 //
                                                                                        //
                                                                                        //
        cout << "Info from file:\n";                                                    //
        cout << "Name: " << readName << "\n";                                           //
        cout << "Age: " << readAge << "\n";                                             //
        cout << "Mark: " << readMark << "\n";                                           //
    }                                                                                   //
};

int main()
{
    Student st;//Cla
    st.Writer();
    st.Reader();//Output
}