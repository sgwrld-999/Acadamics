#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> minAndMax(vector<int>& ipVec, int sizeOfIpVec) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < sizeOfIpVec; i++) {
            mini = min(mini, ipVec[i]);
            maxi = max(maxi, ipVec[i]);
        }
        pair<int, int> tempPr(mini, maxi);
        return tempPr;
    }

    map<int, int> countFrequency(pair<int, int>& pr, vector<int>& ipVec) {
        map<int, int> mp;
        for (int i = pr.first; i <= pr.second; i++) {
            mp[i] = 0;
        }
        for (int i = 0; i < ipVec.size(); i++) {
            mp[ipVec[i]]++;
        }
        int sum = mp[pr.first];
        for (int i = pr.first + 1; i <= pr.second; i++) {
            mp[i] += mp[i - 1];
        }
        return mp;
    }
    /*
    Stable sorting :
    In this we'll iterate from backside of the array to maintain the relative order of 
    the number.
    */
    /*Stable sorting :*/
    vector<int> finalStep(map<int, int>& mp, vector<int>& ipVec) {
        int j = ipVec.size() - 1; 
        vector<int> res(j + 1, 0);
        while (j >= 0) {
            res[mp[ipVec[j]]] = ipVec[j];
            mp[ipVec[j]]--;
            j--;
        }
        return res;
    }
    /*Unstable sorting :*/
    vector<int> finalStep(map<int, int>& mp, vector<int>& ipVec) {
        int j = 0;
        vector<int> res(j + 1, 0);
        while (j < ipVec.size()) {
            res[mp[ipVec[j]]] = ipVec[j];
            mp[ipVec[j]]--;
            j++;
        }
        return res;
    }
    void printingTheArray(vector<int>& ipVec) {
        cout << "Print the array: ";
        for (int i = 0; i < ipVec.size(); i++) {
            cout << ipVec[i];
            if (i < ipVec.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cout << "Enter the size of an array: ";
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    Solution obj;
    pair<int, int> minAndMaxPr = obj.minAndMax(ipVec, sizeOfIpVec);
    map<int, int> hashMap = obj.countFrequency(minAndMaxPr, ipVec);
    vector<int> res = obj.finalStep(hashMap, ipVec);
    obj.printingTheArray(res);
    return 0;
}
