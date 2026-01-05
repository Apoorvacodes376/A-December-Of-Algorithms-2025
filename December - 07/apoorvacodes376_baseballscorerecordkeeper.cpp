#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& operations) {
    vector<int> record;
    for (string op : operations) {
        if (op == "+") {
            int n = record.size();
            record.push_back(record[n-1] + record[n-2]);
        } else if (op == "D") {
            record.push_back(2 * record.back());
        } else if (op == "C") {
            record.pop_back();
        } else {
            record.push_back(stoi(op)); // convert string to int
        }
    }
    int total = 0;
    for (int score : record) total += score;
    return total;
}

int main() {
    int n;
    cin >> n; // number of operations
    vector<string> operations(n);
    for (int i = 0; i < n; i++) {
        cin >> operations[i];
    }
    cout << calPoints(operations) << endl;
    return 0;
}
