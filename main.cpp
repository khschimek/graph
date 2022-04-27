#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void working(int horizontal, int vertical, string chart[], string chartNames[]);

string placement(int horizontal, int vertical) {
    string horizontalLetters[26] = {"A ", "B ", "C ", "D ", "E ", "F ", "G ", "H ", "I ", "J ", "K ", "L ", "M ", "N ", "O ", "P ", "Q ", "R ", "S ", "T ", "U ", "V ", "W ", "X ", "Y ", "Z "};
    string verticalNumbers[26] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
    string placementName = horizontalLetters[horizontal-1] + verticalNumbers[vertical-1];
    return placementName;
}

string basicToMath(string basic) {
    char part;
    int placement = 0;
    string parts[100];
    for(int i=0; i<basic.length(); i++) {
        part = basic[i];
        if(part == ' ') {
            placement += 1;
            continue;
        }
        else if(part == '#') {
            i<basic.length();
            continue;
        }
        else {
            parts[placement] += part;
        }
    }
    if(parts[2] == "+") {
        int number = stoi(parts[0]) + stoi(parts[1]);
        parts[0] = to_string(number);
    }
    else if(parts[2] == "-") {
        int number = stoi(parts[0]) - stoi(parts[1]);
        parts[0] = to_string(number);
    }
    else if(parts[2] == "*") {
        int number = stoi(parts[0]) * stoi(parts[1]);
        parts[0] = to_string(number);
    }
    else if(parts[2] == "/") {
        int number = stoi(parts[0]) / stoi(parts[1]);
        parts[0] = to_string(number);
    }
    return parts[0];
}

void mathDisplay(int horizontal, int vertical, string chart[], string chartNames[]) {
    string basic;
    int countDown = 0;
    int countDownPlus = 1;
    while(countDown<horizontal*vertical) {
        basic = chart[countDown];
        cout << basicToMath(basic) << " ";
        if(countDownPlus%horizontal==0) {
            cout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
    working(horizontal, vertical, chart, chartNames);
}

void basicDisplay(int horizontal, int vertical, string chart[], string chartNames[]) {
    int countDown = 0;
    int countDownPlus = 1;
    while(countDown<horizontal*vertical) {
        cout << chart[countDown] << " ";
        if(countDownPlus%horizontal==0) {
            cout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
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
    while(countDown<horizontal*vertical) {
        cout << chartNames[countDown] << " ";
        if(countDownPlus%horizontal==0) {
            cout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
    int spot = 0;
    string choice1;
    string choice2;
    string choice3;
    while(true) {
        cout << "What spot do you want to modify? ";
        string truefalse = "false";
        cin >> choice1 >> choice2;
        choice3 = choice1 + " " + choice2;
        for(spot=0; spot<=horizontal*vertical; spot++) {
            if(chartNames[spot]==choice3) {
                truefalse = "true";
                break;
            }
        }
        if(truefalse=="true") {
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    cout << choice3 << " is: "  << chart[spot] << endl;
    string newInput;
    cout << "End the line with: # " << endl;
    cout << "If you want to make a phrase, use _ instead of spaces" << endl;
    cout << "If you want to make a math formula, do: A B + " << endl;
    cout << "What do you want " << choice3 << " to be? ";
    string fake;
    getline(cin, fake);
    getline(cin, newInput);
    chart[spot]=newInput;
    cout << choice3 << " is now: " << newInput << endl;
    working(horizontal, vertical, chart, chartNames);
}

void finishChart(int horizontal, int vertical, string chart[], string chartNames[]) {
    string filename;
    cout << "What do you want the file to be named? (Name it the same thing as the old file if you want to replace it) ";
    cin >> filename;
    ofstream fout(filename);
    fout << horizontal << " " << vertical << endl;
    string basic;
    int countDown = 0;
    int countDownPlus = 1;
    while(countDown<horizontal*vertical) {
        basic = chart[countDown];
        fout << basicToMath(basic) << " ";
        if(countDownPlus%horizontal==0) {
            fout << endl;
        }
        countDownPlus+=1;
        countDown+=1;
    }
}

void working(int horizontal, int vertical, string chart[], string chartNames[]) {
    string displaymodifyfinish;
    while(true) {
        string input;
        cout << "What do you want to do? [display] [modify] [finish] ";
        cin >> input;
        if(input == "display") {
            displaymodifyfinish = "display";
            break;
        }
        else if(input == "modify") {
            displaymodifyfinish = "modify";
            break;
        }
        else if(input == "finish") {
            displaymodifyfinish = "finish";
            break;
        }
        cout << "Incorrect Input" << endl;
    }
    if(displaymodifyfinish == "display") {
        displayChart(horizontal, vertical, chart, chartNames);
    }
    else if(displaymodifyfinish == "modify") {
        modifyChart(horizontal, vertical, chart, chartNames);
    }
    else {
        finishChart(horizontal, vertical, chart, chartNames);
    }
}

void newChart() {
    int horizontal;
    int vertical;
    cout << "How many spaces horizontal do you want the graph to be? [1-26] ";
    cin >> horizontal;
    cout << "How many spaces vertical do you want the graph to be? [1-26] ";
    cin >> vertical;
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
