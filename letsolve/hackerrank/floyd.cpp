#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<vector<int>> dp(401, vector<int>(401, 1000000000));

void naiveFloyd(vector<int> f, vector<int> t, vector<int> w){
  int n = f.size();

  for(int i = 1; i <= n; i++){
    dp[f[i- 1]][f[i- 1]] = 0; 
    dp[t[i- 1]][t[i- 1]] = 0;
    dp[f[i- 1]][t[i - 1]] = w[i-1];
   }

  for(int i = 1 ; i <= 400; i++){
    for(int j = 1; j <= 400; j++){
      for(int k = 1; k <= 400; k++){
        dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
      }
    }
  }
};


int main()
{
    int road_nodes;
    int road_edges;

    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);

    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    naiveFloyd(road_from, road_to, road_weight);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        cout << (dp[x][y] == 1000000000 ? -1 : dp[x][y])<< "\n";
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
