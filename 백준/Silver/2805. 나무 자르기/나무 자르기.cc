#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N, M;
vector <long long> V;

long long parameter_search(long long r) {
	long long left = 0;
	long long right = r;
	long long max = 0;
	while (left <= right) {
		long long mid = (left + right)/2;

		long long sum = 0;
		for (int i = 0; i < N; i++)
			if (V[i] > mid)
				sum += V[i] - mid;

		if (sum < M)
			right = mid - 1;
		else {
			if (mid > max)
				max = mid;
			left = mid + 1;
		}
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		cout.tie(NULL);
	cin >> N >> M;
	V.resize(N);
	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
		if (max < V[i])
			max = V[i];
	}
	cout << parameter_search(max);
}