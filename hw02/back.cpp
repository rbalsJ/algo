#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;

    cin >> n;
    cin.clear();

    while (n != 0)
    {
        stack<char> st;
        string s_word;
        string t_word;

        cin >> s_word;

        cin.clear();

        cin >> t_word;

        for (int i = 0; i < s_word.size(); i++)
        {
            st.push(s_word[i]);
        }

        int temp = (t_word.size() - 1);

        string answer;

        while (1)
        {
            if (st.top() == t_word[temp])
            {
                answer += st.top();
                temp--;
            }
            else
            {
                st.pop();
            }

            if (temp < 0 || st.size() <= 0) break;
            else st.pop();

            if (st.size() <= 0) break;
        }

        reverse(answer.begin(), answer.end());

        if (answer == t_word) cout << "YES" << endl;
        else cout << "NO" << endl;

        n--;
    }

    return 0;
}