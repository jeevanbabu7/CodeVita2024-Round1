#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void display(int row, vector<int> &temp, vector<vector<int>> &v, int c) {
	
	for(auto it: temp) {
		int ind = (it - 1) * c;
		for(int k = ind;k < ind + c; ++k) {
			cout << v[row][k] << " ";
		}
	}
	cout << endl;
}

int main() {
    
    int n, r, c;
    cin >> n >> r >> c;
    cin.ignore();
    
    vector<vector<int>> v(r, vector<int>(n * c));
    for (int i = 0; i < r; ++i) {
    	for(int j = 0;j < n * c; ++j) {
    		cin >> v[i][j];
    	}
    }
    cin.ignore(); 

    string l;
    while (getline(cin, l)) {
    	
        if (l.empty()) continue;
        stringstream ss(l);
        vector<int> temp;
        int val;
        while (ss >> val) {
            temp.push_back(val);
        }
        
        for(int i = 0;i < r; ++i) {
        	display(i, temp, v, c);
        }
        
    }

    return 0;
}
