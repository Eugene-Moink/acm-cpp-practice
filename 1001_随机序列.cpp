#include<bits/stdc++.h>
using namespace std;
int calculateRange(vector<int>& arr)
{
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 0; i < arr.size();i++)
    {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    return max_val - min_val;
}

double calculateVariance(vector<int>& arr)
{
    double sum = 0;
    double temp = 0;
    for (int i = 0; i < arr.size();i++)
    {
        sum += arr[i];
    }

    double avg = sum / arr.size();
    for (int j = 0; j < arr.size();j++)
    {
        temp += (arr[j] - avg)*(arr[j] - avg);
    }

    double result = temp / arr.size();
    return result;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int num_size;
        cin >> num_size;
        vector<int> number;
        for (int j = 0; j < num_size;j++)
        {
            int num;
            cin >> num;
            number.push_back(num);
        }
        long long range = calculateRange(number);
        double result = calculateVariance(number);
        cout << range << " " << fixed << setprecision(3) 
        << result << endl;
    }

    return 0;
}