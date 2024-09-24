#include <bits/stdc++.h>
using namespace std;

int n, arr[20][20];
vector<int> s;
vector<int> temp;
int res = 987654321;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) s.push_back(i);
    for(int i = 0; i < n/2; i++) temp.push_back(0);
    for(int i = 0; i < n/2; i++) temp.push_back(1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    do{
        vector<int> morning;
        vector<int> evening;
        for(int i = 0; i < s.size(); i++){
            if(temp[i] == 1) morning.push_back(s[i]);
            if(temp[i] == 0) evening.push_back(s[i]);
        }

        // cout << "morning: ";
        // for(auto x : morning) cout << x << " ";
        // cout << "\nevening: ";
        // for(auto x : evening) cout << x << " ";
        // cout << "\n";
        // 여기까진 맞음

        int morning_sum = 0, evening_sum = 0;
        for(int i = 0; i < morning.size(); i++){
            for(int j = i + 1; j < morning.size(); j++){
                morning_sum += arr[morning[i] - 1][morning[j] - 1];
                morning_sum += arr[morning[j] - 1][morning[i] - 1];
            }
        }
        for(int i = 0; i < evening.size(); i++){
            for(int j = i + 1; j < evening.size(); j++){
                evening_sum += arr[evening[i] - 1][evening[j] - 1];
                evening_sum += arr[evening[j] - 1][evening[i] - 1];
            }
        }
        // cout << "morning_sum: " << morning_sum << "\n";
        // cout << "evening_sum: " << evening_sum << "\n";

        int diff = abs(morning_sum - evening_sum);
        if(res > diff) res = diff; 
    } while(next_permutation(temp.begin(), temp.end()));

    cout << res << "\n";
    return 0;
}