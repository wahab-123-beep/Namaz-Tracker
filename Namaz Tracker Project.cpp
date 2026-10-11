#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Motivation {
public:
    string getQuote(string status) {
        if (status == "read")
            return "MashaAllah! Allah is pleased with you.";
        else if (status == "skip")
            return "Don't forget to pray! Allah is waiting.";
        else if (status == "qaza")
            return "Namaz done. Next time, make it on time.";
        else
            return "Status unknown, but keep trying.";
    }
};

class PrayerRecord {
    string date;
    string fajr, zuhar, asr, maghrib, isha;
    int readCount, skipCount, qazaCount;

    void updateCounts(string status) {
        if (status == "read") readCount++;
        else if (status == "qaza") qazaCount++;
        else skipCount++;
    }

public:
    PrayerRecord() {
        date = "";
        fajr = zuhar = asr = maghrib = isha = "";
        readCount = skipCount = qazaCount = 0;
    }

    void setRecord() {
        cout << "Enter Date (dd-mm-yyyy): ";
        getline(cin, date);

        cout << "Enter Fajr status (read/skip/qaza): ";
        getline(cin, fajr);
        updateCounts(fajr);

        cout << "Enter Zuhar status (read/skip/qaza): ";
        getline(cin, zuhar);
        updateCounts(zuhar);

        cout << "Enter Asr status (read/skip/qaza): ";
        getline(cin, asr);
        updateCounts(asr);

        cout << "Enter Maghrib status (read/skip/qaza): ";
        getline(cin, maghrib);
        updateCounts(maghrib);

        cout << "Enter Isha status (read/skip/qaza): ";
        getline(cin, isha);
        updateCounts(isha);
    }

    void showRecord() {
        cout << endl;
        cout << "Date: " << date << endl;
        cout << "Fajr: " << fajr << endl;
        cout << "Zuhar: " << zuhar << endl;
        cout << "Asr: " << asr << endl;
        cout << "Maghrib: " << maghrib << endl;
        cout << "Isha: " << isha << endl;
        cout << "Total - Read: " << readCount << ", Qaza: " << qazaCount << ", Skipped: " << skipCount << endl;
    }

    void saveRecord() {
        ofstream file("namaz.txt", ios::app);
        if (file.is_open()) {
            file << date << endl;
            file << "fajr = " << fajr << endl;
            file << "zuhar = " << zuhar << endl;
            file << "asr = " << asr << endl;
            file << "maghrib = " << maghrib << endl;
            file << "isha = " << isha << endl;
            file << endl;
            file.close();
        }
        else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    string getFajr() const { return fajr; }
    string getZuhar() const { return zuhar; }
    string getAsr() const { return asr; }
    string getMaghrib() const { return maghrib; }
    string getIsha() const { return isha; }
};

class User {
public:
    virtual void interact() = 0;
    virtual ~User() {}
};

class RegularUser : public User {
public:
    void interact() {
        char choice;
        do {
            PrayerRecord pr;
            pr.setRecord();

            Motivation m;

            cout << endl;
            cout << "Motivational Quotes for each prayer:" << endl;
            cout << "Fajr: " << m.getQuote(pr.getFajr()) << endl;
            cout << "Zuhar: " << m.getQuote(pr.getZuhar()) << endl;
            cout << "Asr: " << m.getQuote(pr.getAsr()) << endl;
            cout << "Maghrib: " << m.getQuote(pr.getMaghrib()) << endl;
            cout << "Isha: " << m.getQuote(pr.getIsha()) << endl;

            pr.showRecord();
            pr.saveRecord();

            cout << endl << "Do you want to enter another record? (y/n): ";
            cin >> choice;
            cin.ignore();
        } while (choice == 'y' || choice == 'Y');
    }
};

class Admin : public User {
public:
    void interact() {
        cout << "--- All Namaz Records ---" << endl;
        ifstream file("namaz.txt");
        string line;
        if (!file) {
            cout << "No records found." << endl;
            return;
        }
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

void resetFile() {
    ofstream file("namaz.txt", ios::trunc);
    file.close();
    cout << "File content cleared successfully!" << endl;
}

int main() {
    int role;
    cout << "Login as: 1. Regular User  2. Admin  3. Reset File" << endl;
    cout << "Choose: ";
    cin >> role;
    cin.ignore();

    if (role == 3) {
        resetFile();
    }
    else {
        User* u;
        if (role == 1)
            u = new RegularUser();
        else
            u = new Admin();

        u->interact();
        delete u;
    }

    return 0;
}
