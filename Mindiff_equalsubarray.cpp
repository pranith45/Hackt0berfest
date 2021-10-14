//----------Minimum absolute difference between 2 non contiguous equal subarrays------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void solve(int ele, int currSum, int index, int maxe, int *arr, int &answer, int sum, int n)
{
    if (ele == maxe)
    {
        int ssum = sum - currSum;
        if (abs(currSum - ssum) < answer)
            answer = abs(currSum - ssum);
        return;
    }
    if (index >= n)
    {
        return;
    }
    solve(ele + 1, currSum + arr[index], index + 1, maxe, arr, answer, sum, n);
    solve(ele, currSum, index + 1, maxe, arr, answer, sum, n);
}
int FindMinimumDifference(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int answer = INT_MAX;
    solve(0, 0, 0, n / 2, arr, answer, sum, n);
    return answer;
}
int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }
    cout << FindMinimumDifference(arr, n);
    return 0;
}
