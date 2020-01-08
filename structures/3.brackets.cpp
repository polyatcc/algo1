#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<int> h;
int u, m, f;
string s;
stack<char> st;
bool flag;



int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    while (cin >> s) {
        m = s.size();
        while(!st.empty()) {
            st.pop();
        }

        for (int i = 0; i < m; ++i) {
            flag = true;
            if (st.size() == 0) {
                if ((s[i] == ')') || (s[i] == ']')) {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                } else {
                    st.push(s[i]);
                }
            } else {
                if (st.top() == '(') {
                    if (s[i] == ')') {
                        st.pop();
                    } else if ((s[i] == '[') || (s[i] == '(')) {
                        st.push(s[i]);
                    } else if (s[i] == ']') {
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                } else { //  верхний эл-т стека не может быть закрывающейся скобкой, (  уже разобрана, это случай [
                    if (s[i] == ']') {
                        st.pop();
                    } else if ((s[i] == '[') || (s[i] == '(')) {
                        st.push(s[i]);
                    } else if (s[i] == ')') {
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        if ((flag) && (st.size() == 0)) {
            cout << "YES" << endl;
        } else if ((flag) && (st.size() != 0)) {
               cout << "NO" << endl;

        }


    }
    return 0;
}