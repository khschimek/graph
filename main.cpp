#include <iostream>
#include <fstream>

using namespace std;

void working(int horizontal, int vertical, string chart[], string chartNames[]);

string placement(int horizontal, int vertical) {
    string horizontalLetters[26] = {"A ", "B ", "C ", "D ", "E ", "F ", "G ", "H ", "I ", "J ", "K ", "L ", "M ", "N ", "O ", "P ", "Q ", "R ", "S ", "T ", "U ", "V ", "W ", "X ", "Y ", "Z "};
    string verticalNumbers[26] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
    string placementName = horizontalLetters[horizontal-1] + verticalNumbers[vertical-1];
    return placementName;
}

void mathDisplay(int horizontal, int vertical, string chart[], string chartNames[]) {

}

void basicDisplay(int horizontal, int vertical, string chart[], string chartNames[]) {
    int countDown = 0;
    int countDownPlus = 1;
    while(countDown<=horizontal*vertical) {
        cout << chart[countDown] << " ";
        if(countDownPlus%horizontal==0) {
            cout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
    string enter;
    cout << "Press enter to go back.";
    cin >> enter;
    working(horizontal, vertical, chart, chartNames);
}

void displayChart(int horizontal, int vertical, string chart[], string chartNames[]) {
    string mathbasic;
    while(true) {
        string output;
        cout << "How do you want to display your graph? [math] [basic] ";
        cin >> output;
        if(output == "math") {
            mathbasic = "math";
            break;
        }
        else if(output == "basic") {
            mathbasic = "basic";
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    if(mathbasic == "math") {
        mathDisplay(horizontal, vertical, chart, chartNames);
    }
    else {
        basicDisplay(horizontal, vertical, chart, chartNames);
    }
}

void modifyChart(int horizontal, int vertical, string chart[], string chartNames[]) {
   int countDown = 0;
    int countDownPlus = 1;
    while(countDown<=horizontal*vertical) {
        cout << chartNames[countDown] << " ";
        if(countDownPlus%horizontal==0) {
            cout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
    int spot = 0;
    string choice;
    while(true) {
        cout << "What spot do you want to modify? ";
        string truefalse = "false";
        getline(cin, choice);
        for(spot; spot<=horizontal*vertical; spot++) {
            if(chartNames[spot]==choice) {
                truefalse = "true";
                break;
            }
        }
        if(truefalse=="true") {
            cout << "truefalse true" << endl;
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    cout << choice << " is: "  << chart[spot] << endl;
    string newInput;
    cout << "What do you want " << choice << " to be? ";
    cin >> newInput;
    chart[spot]="newInput";
    cout << choice << " is now: " << newInput << endl;
    working(horizontal, vertical, chart, chartNames);
}

void working(int horizontal, int vertical, string chart[], string chartNames[]) {
    string displaymodify;
    while(true) {
        string input;
        cout << "What do you want to do? [display] [modify] ";
        cin >> input;
        if(input == "display") {
            displaymodify = "display";
            break;
        }
        else if(input == "modify") {
            displaymodify = "modify";
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    if(displaymodify == "display") {
        displayChart(horizontal, vertical, chart, chartNames);
    }
    else {
        modifyChart(horizontal, vertical, chart, chartNames);
    }
}

void newChart() {
    cout << "What do you want to name your new chart? ";
    string fileName;
    cin >> fileName;
    ofstream fout(fileName);
    int horizontal;
    int vertical;
    cout << "How many spaces horizontal do you want the graph to be? [1-26] ";
    cin >> horizontal;
    fout << horizontal;
    fout << " ";
    cout << "How many spaces vertical do you want the graph to be? [1-26] ";
    cin >> vertical;
    fout << vertical;
    string chart[horizontal*vertical];
    string chartNames[horizontal*vertical];
    int chartPlacement = 0;
    string nextSpot;
    for(int i=1; i<=horizontal; i++) {
        for(int t=1; t<=vertical; t++) {
            string spot = placement(i, t);
            chartNames[chartPlacement] = spot;
            chart[chartPlacement] = "[BLANK]";
            chartPlacement+=1;
        }
    }
    working(horizontal, vertical, chart, chartNames);
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
            string spot = placement(i, t);
            chartNames[chartPlacement] = spot;
            fin >> nextSpot;
            chart[chartPlacement] = nextSpot;
            chartPlacement+=1;
        }
    }
    working(horizontal, vertical, chart, chartNames);
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
