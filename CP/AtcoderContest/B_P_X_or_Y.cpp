#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    vector<vector<pair<int, int>>> outcomes(6, vector<pair<int, int>>(6));
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            outcomes[i][j] = {i + 1, j + 1};
        }
    }
    int sumAtleastX = 0, difAtLeastY = 0;
    int both = 0;
   
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(outcomes[i][j].first + outcomes[i][j].second >= x) {
                sumAtleastX++;
            }
            if(abs(outcomes[i][j].first - outcomes[i][j].second) >= y) {
                difAtLeastY++;
            }
            if(outcomes[i][j].first + outcomes[i][j].second >= x && abs(outcomes[i][j].first - outcomes[i][j].second) >= y) {
                both++;
            }
        }
    }
    double intersection = double(both) / 36.0;
    double prob1 = double(sumAtleastX) / 36.0;
    double prob2 = double(difAtLeastY) / 36.0;
    cout << fixed << setprecision(18) << prob1 + prob2 - intersection << endl;
    
}