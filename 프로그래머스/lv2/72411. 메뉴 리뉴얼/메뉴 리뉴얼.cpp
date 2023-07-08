#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	set<string> S;

	for (auto co : course) {
		priority_queue<pair<int,string>> PQ;
		map<string, int> M;
		for (auto order : orders) {
			sort(order.begin(),order.end());
			if (order.size() < co)
				continue;
			vector<int> V;
			for (int i = 0; i < order.size(); i++) {
				if (i >= order.size() - co)
					V.push_back(1);
				else
					V.push_back(0);
			}

			do {
				string str = "";
				for (int i = 0; i < V.size(); i++)
					if (V[i])	str += order[i];
				if (M.find(str) != M.end()) {
					M[str] += 1;
					PQ.push({ M[str],str });
				}
				else
					M[str] = 1;
			} while (next_permutation(V.begin(), V.end()));
		}
		int num;
		if (PQ.empty())
			continue;
		if (PQ.top().first > 1)
			num = PQ.top().first;
		else
			continue;
		while (!PQ.empty()) {
			if (PQ.top().first == num) {
				S.insert(PQ.top().second);
				PQ.pop();
			}
			else
				break;
		}
	}
	for (auto s : S)
		answer.push_back(s);
	sort(answer.begin(), answer.end());

	return answer;
}