#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Person {
    int ID;
    string Name;
    string Sex;
    double Ne, Ni, Te, Ti, Se, Si, Fe, Fi;
    string Type;
    string Nick;
    double distance;
};

vector<Person> people;

void read_csv(int row_n) 
{ 
    fstream fin; 
    fin.open("COMO.csv", ios::in); 

    if (!fin.is_open()) {
        cout << "Failed to open the file.\n";
        return;
    }

    int currentRow = 0;
    string line, word; 

    getline(fin, line);

    while (getline(fin, line)) { 
        currentRow++; 
        if (currentRow > row_n + 1) {
            break;
        }

        stringstream s(line); 
        vector<string> row; 

        while (getline(s, word, ',')) { 
            row.push_back(word); 
        } 

        Person p;
        p.ID = stoi(row[0]);
        p.Name = row[1];
        p.Sex = row[2];
        p.Ne = stod(row[3]);
        p.Ni = stod(row[4]);
        p.Te = stod(row[5]);
        p.Ti = stod(row[6]);
        p.Se = stod(row[7]);
        p.Si = stod(row[8]);
        p.Fe = stod(row[9]);
        p.Fi = stod(row[10]);
        p.Type = row[11];
        p.Nick = row[12];

        people.push_back(p);
    } 

    fin.close();

}

double calculateDistance(const Person& p1, const Person& p2) {
    return sqrt(pow(p1.Ne - p2.Ne, 2) + pow(p1.Ni - p2.Ni, 2) + 
                pow(p1.Te - p2.Te, 2) + pow(p1.Ti - p2.Ti, 2) +
                pow(p1.Se - p2.Se, 2) + pow(p1.Si - p2.Si, 2) +
                pow(p1.Fe - p2.Fe, 2) + pow(p1.Fi - p2.Fi, 2));
}

void nearest(vector<Person>& people, int k, const Person& testPerson) {
    for (auto& person : people) {
        person.distance = calculateDistance(person, testPerson);
    }

    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.distance < b.distance;
    });

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Person test;
    cin >> test.Ne >> test.Ni >> test.Te >> test.Ti >> test.Se >> test.Si >>test.Fe >> test.Fi;

    read_csv(30);
    nearest(people, 30, test);

    for (const auto& person : people) {
        printf("ID: %d\t| Type: %s\t| Name %s  ->  Distance: %lf\n", person.ID, person.Type.c_str(), person.Name.c_str(), person.distance);
    }

    return 0;
}

//  Test case
//  33.4 28.4 32 38 33 30 33 25 [Tonnam]
//  27 36.2 33 37 27 30 27 20 [Pin]
//  32 32 27 36 29 31 28 23 [Yong]
