#include <bits/stdc++.h>

using namespace std;

string toString(int n)
{
    string ans = "";
    while (n > 0)
    {
        ans = char(n % 10 + '0') + ans;
        n /= 10;
    }
    if (ans.length() == 1)
    {
        ans = "0" + ans;
    }
    return ans;
}
int compare(string a, string b)
{
    while (a.size() < b.size())
        a = '0' + a;

    while (a.size() > b.size())
        b = '0' + b;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return (a[i] > b[i]) ? 1 : -1;
    return 0;
}

string generateString(string s)
{
    string ans = "", temp;
    for (int i = 0; i <= 9; i++)
    {
        temp = char(i + '0') + ans;
        if (compare(temp, s) > 0)
            return (ans == "") ? "-1" : ans;
        ans = temp;
    }
    return ans;
}

string decString(string s, int index)
{
    for (int i = index; i < s.size(); i++)
        s[i]--;
    return s;
}

string solve(string s)
{
    string p = generateString(s);
    if (p == "-1")
        return p;
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = p[i] - '0' + 1; j <= 9 && (j < p[i - 1] - '0' || (i == 0)); j++)
        {
            string temp = p;
            temp[i] = (j + '0');
            if (compare(temp, s) > 0)
                break;
            p = temp;
        }
    }
}

int main()
{
    ofstream finput, foutput;

    srand(time(NULL));

    long long n, minN = 2;
    for (int TC = 1; TC <= 10; TC++)
    {
        finput.open("../testcase/tc" + toString(TC) + "/input.txt");
        foutput.open("../testcase/tc" + toString(TC) + "/output.txt");
        cout << toString(TC) << endl;

        n = minN;
        string s = "";
        s = s + char(rand() % 9 + '1');
        for (int i = 0; i < n; i++)
            s = s + char(rand() % 10 + '0');

        finput << s << endl;
        finput.close();

        foutput << solve(s);
        foutput.close();
        minN += 1;
        if (minN > 100)
        {
            minN = 100;
        }
    }
}