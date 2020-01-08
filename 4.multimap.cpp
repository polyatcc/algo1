#include <iostream>
#include <vector>
    #include <string>
    #include <list>
    #include <iterator>

    using namespace std;

    struct hash_struct{
        string key;
        vector <list <string> > hash_value;
        int k;
    };

    vector <int> pow(20);


    const  int p1 = 101;
    const  int p2 = 601;


    int hashi(string &x){
        int h = 0;
        for (int i = 0; i < x.size(); ++i){
            h = abs((h + (int(x[i]) * pow[i]) % p1) % p1);
        }
        return h;
    }

    int hashi2(string &x){
        int h = 0;
        for (int i = 0; i < x.size(); ++i){
            h = abs((h + (int(x[i]) * pow[i]) % p2) % p2);
        }
        return h;
    }

    int main() {
        freopen("multimap.in", "r", stdin);
        freopen("multimap.out", "w", stdout);

        ios_base::sync_with_stdio(0);
        cin.tie(NULL); cout.tie(NULL);

        string s, x, y;
        hash_struct temp;
        int hvalueF, hvalueS;

        pow[0] = 1;
        for (int i = 1; i < 20; ++i){
            pow[i] = pow[i - 1] * 3571;
        }

        vector <list<hash_struct>> a(101);

        while (cin >> s){
            cin >> x;
            hvalueF = hashi(x);
            if (s == "put"){
                cin >> y;
                hvalueS = hashi2(y);
                bool kolk = false;
                for (auto itk = a[hvalueF].begin(); itk != a[hvalueF].end(); ++itk){
                    if ((*itk).key == x){
                        bool kolv = false;
                        for (auto itv = (*itk).hash_value[hvalueS].begin(); itv != (*itk).hash_value[hvalueS].end(); ++itv){
                            if ((*itv) == y){
                                kolv = true; break;
                            }
                        }
                        if (!kolv){
                            (*itk).hash_value[hvalueS].push_back(y);
                            ++(*itk).k;
                        }
                        kolk = true; break;
                    }
                }
                if (!kolk){
                    a[hvalueF].push_back({x, vector <list <string> > (601), 1});
                    a[hvalueF].back().hash_value[hvalueS].push_back(y);
                }
            }
            else if (s == "get"){
                bool kol = false;
                for (auto itk = a[hvalueF].begin(); itk != a[hvalueF].end(); ++itk){
                    if ((*itk).key == x){
                        cout << (*itk).k << ' ';
                        for (int i = 0; i < p2; ++i){
                            copy((*itk).hash_value[i].begin(), (*itk).hash_value[i].end(), ostream_iterator<string>(cout," "));
                        }
                        cout << '\n';
                        kol = true;
                        break;
                    }
                }
                if (!kol){
                    cout << 0 << endl;
                }
            }
            else if (s == "delete"){
                cin >> y;
                hvalueS = hashi2(y);
                for (auto itk = a[hvalueF].begin(); itk != a[hvalueF].end(); ++itk){
                    if ((*itk).key == x){
                        for (auto itv = (*itk).hash_value[hvalueS].begin(); itv != (*itk).hash_value[hvalueS].end(); ++itv){
                            if (*itv == y){
                                itv = (*itk).hash_value[hvalueS].erase(itv);
                                --(*itk).k;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            else if (s == "deleteall"){
                for (auto itk = a[hvalueF].begin(); itk != a[hvalueF].end(); ++itk){
                    if ((*itk).key == x){
                        itk = a[hvalueF].erase(itk);
                        break;
                    }
                }
            }
        }
        return 0;
}
