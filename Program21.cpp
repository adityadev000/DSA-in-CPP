#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//P21a -> shift all element by k position
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v(n);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = ((i + k) % n);
        v[x] = nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = v[i];
    }
}

//P21b -> check if array is sorted and rotated
bool checkArrayIsSortesAndRotated(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[((i + 1) % nums.size())])
        {
            count++;
        }
        else if (nums[i] == nums[((i + 1) % nums.size())])
        {
        }
    }
    if (count <= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// P21c -> find array sum 
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;
    int carry = 0, val = 0;
    int i = (n - 1), j = (m - 1);
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        val = sum % 10;

        ans.push_back(val);
        i--;
        j--;
    }

    while (i >= 0)
    {
        ans.push_back(a[i] + carry);

        i--;
        carry = 0;
    }
    while (j >= 0)
    {
        ans.push_back(b[j] + carry);
        j--;
        carry = 0;
    }

    if (carry != 0)
    {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end());
    cout << endl;
    return ans;
}
int main()
{
    // p21a
    vector<int> v = {2, 6, 4, 5};
    rotate(v, 2);
    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << endl;
    }
    // p21b
    vector<int> vv = {4, 5, 6, 1, 2};
    if (checkArrayIsSortesAndRotated(vv))
    {
        cout << "array is sorted and rotated " << endl;
    }
    else
    {
        cout << "array is not sorted and rotated " << endl;
    }

    // p21c
    vector<int> v1 = {2, 9, 4};
    vector<int> v2 = {8, 2, 1};
    vector<int> ans = findArraySum(v1, 3, v2, 3);
    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << "  ";
    }
}
