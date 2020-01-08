#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int a;
string c;
string s;
stack<int> st;




int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    while(cin >> c) {
        if (c.size() == 2) {
            int b = '0' - c[1];
            st.push(b);
        } else {
            if (c == "+") {
                a = st.top();
                st.pop();
                st.top() += a;
            } else if (c == "-") {
                a = st.top();
                st.pop();
                st.top() -= a;
            } else if (c == "*") {
                    a = st.top();
                    st.pop();
                    st.top() *= a;
            } else {
                st.push(c[0] - '0');
            }
        }

    }
    cout << st.top();
    return 0;
}