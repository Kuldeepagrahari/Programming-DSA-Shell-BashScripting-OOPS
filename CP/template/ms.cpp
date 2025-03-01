#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findPatchSequence(const string& patch, const string& design) {
    vector<int> sequence;
    int patchLength = patch.length();
    int designLength = design.length();
    
    for (int i = 0; i <= designLength - patchLength; ++i) {
        bool match = true;
        for (int j = 0; j < patchLength; ++j) {
            if (design[i + j] != patch[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            sequence.push_back(i);
            i += patchLength - 1; // Skip ahead to avoid overlapping
        }
    }
    
    if (sequence.empty()) {
        sequence.push_back(-1);
    }
    
    return sequence;
}

int main() {
    string patch, design;
    cin >> patch >> design;
    
    vector<int> sequence = findPatchSequence(patch, design);
    
    for (int i = 0; i < sequence.size(); ++i) {
        cout << sequence[i];
        if (i < sequence.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}