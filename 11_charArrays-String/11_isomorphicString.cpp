
// solved it but fcked up que

#include <iostream>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t)
{

    int hash[256] = {0};
    int isMapped[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {

        if (hash[s[i]] == 0)
        {

            if (isMapped[t[i]] != 0)
            {
                // is mapped true
                cout << t[i] << "ismapped" << endl;

                if (hash[s[i]] != t[i])
                {
                    cout << "but new mapping is not same " << s[i] << "and "
                         << t[i] << endl;
                    return false;
                }
            }
            // still not mapped

            hash[s[i]] = (int)t[i];
            isMapped[t[i]] = 1;

            cout << s[i] << "mapped with" << (int)t[i] << endl;
        }
        else
        {
            if (hash[s[i]] != t[i])
            {
                cout << "but new mapping is not same " << s[i] << "and "
                     << t[i] << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{

    string s = "badc";
    string t = "baba";

    cout << isIsomorphic(s, t);

    return 0;
}