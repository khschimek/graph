#include <iostream>
#include <fstream>

using namespace std;

string placement(int horizontal, int vertical) {
    char horizontalLetters[26] = ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I');
}

void newChart() {

}

void oldChart() {
    int horizontal;
    int vertical;
    string fileName;
    cout << "What chart do you want to use? ";
    cin >> fileName;
    ifstream fin(fileName);
    fin >> horizontal;
    fin >> vertical;
    string chart[horizontal*vertical];
    string chartNames[horizontal*vertical];
    int chartPlacement = 0;
    string nextSpot;
    for(int i=1; i<=horizontal; i++) {
        for(int t=1; t<=vertical; t++) {
            string spot = placement(horizontal, vertical);
            chartNames[chartPlacement] = spot;
            fin >> nextSpot;
            chart[chartPlacement] = nextSpot;
            chartPlacement+=1;
        }
    }
}

int main() {
    string oldnew;
    while(true) {
        string choice;
        cout << "Are you making a new chart or using an old chart? [new] [old] ";
        cin >> choice;
        if(choice == "new") {
            oldnew = "new";
            break;
        }
        else if(choice == "old") {
            oldnew = "old";
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    if(oldnew == "new") {
        newChart();
    }
    else {
        oldChart();
    }
    return 0;
}
