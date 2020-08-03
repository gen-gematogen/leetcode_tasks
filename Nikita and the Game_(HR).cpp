#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// 0 4 1 0 1 1 0 1
// 0 1 2 3 4 5 6 7

/*
 * Complete the arraySplitting function below.
 */
int split(vector<int>& sufSum, int l, int r){
    if (l >= r || (sufSum[r - 1] + sufSum[l - 1]) % 2) return 0;

    for (int i = l; i < r; ++i){
        if (2 * sufSum[i] == sufSum[r - 1] + sufSum[l - 1]) return 1 + max(split(sufSum, l, i + 1), split(sufSum, i + 1, r));
    }

    return 0;
}

int arraySplitting(vector<int> arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; ++i){
        if (arr[i]) break;
        if (i == n - 1) return n - 1;
    }

    vector<int> sufSum(n + 1);
    sufSum[1] = arr[0];

    for (int i = 2; i <= n; ++i){
        sufSum[i] = sufSum[i - 1] + arr[i - 1];
    }

    return split(sufSum, 1, n + 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = arraySplitting(arr);

        fout << result << "\n";
    }

    fout.close();

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
