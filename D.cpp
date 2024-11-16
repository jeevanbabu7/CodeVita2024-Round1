#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define all(v) v.begin(),v.end()



using namespace std;


const int mod = 1000000007;

void BFS(map<string, vector<string>> &adj, string &color, map<string, vector<string>> &paths) {
	
	set<string> st;
	queue<vector<string>> q;
	q.push({"source"});
	st.insert("source");
	while(!q.empty()) {
		
		vector<string> path = q.front();
		q.pop();
		if(path.back() == color) {
			paths[color] = path;
			return;
		}
		string lastNode = path.back();
		for(auto node: adj[lastNode]) {
			if(st.find(node) == st.end()) {
			
				st.insert(node);
				vector<string> newPath = path;
				newPath.push_back(node);
				q.push(newPath);
			}
		}
		
	}
	
}


int main(){
	
	int n;
	cin >> n;
	map<string, vector<string>> adj;
	cin.ignore();
	for(int i = 0;i < 2 * n + 1; ++i) {
		string line;
		getline(cin, line);
		if (line.empty()) continue;
	
		stringstream ss(line);
		string a;
		ss >> a;
		
		vector<string> temp;
		string s;
	
		while(ss >> s) {
			temp.push_back(s);
	;
		}
		adj[a] = temp;
	}

	string temp;
	getline(cin, temp);
	getline(cin, temp);
	vector<string> colors;
	stringstream ss(temp);
	
	
	while(ss >> temp) {
		colors.push_back(temp);
	}
	
	// Adj list
	// for(auto it: adj) {
	// 	cout << it.first << endl;
	// 	for(auto item: it.second) {
	// 		cout << item << " ";
	// 	}
	// 	cout << endl << endl;
	// }
	
	
	map<string, vector<string>> paths;
	for(auto color: colors) {
		BFS(adj, color, paths);
	}
	
	// path 	
	// for(auto it: paths) {
	// 	cout << it.first << "	";
	// 	for(auto node: it.second) {
	// 		cout << node << " ";
	// 	}
	// 	cout << endl;
	// }
	
	int total = 0;
	
	set<pair<string, string>> st;
	for(auto color: colors) {
		vector<string> path = paths[color];
		int size = path.size();
		for(int i = 0;i + 1 < size; ++i) {
			if(st.find({path[i], path[i + 1]}) == st.end()) {
				
				for(auto it: adj[path[i]]) {
					if(st.find({path[i], it}) != st.end()) {
						st.erase({path[i], it});
					}
				}
				st.insert({path[i], path[i + 1]});
				total++;
			}
		}
	}
	
	cout << total << endl;
	
	return 0;
}
