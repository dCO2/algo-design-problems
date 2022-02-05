#include <bits/stdc++.h>
using namespace std;

int N, M, P, Q;

map<int, int> user_follows;
map<int, int> story_follows;
map<int, int> story_creator;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i=1;i<=N;i++){
		cin >> story_creator[i];
	}

	cin >> P >> Q;

	for (int i=1;i<=P;i++){
		int a, b; cin >> a >> b;
		user_follows[a] = b;
	}

	for (int i=1;i<=Q;i++){
		int a, b; cin >> a >> b;
		story_follows[a] = b;
	}

    for(int i=1; i<=M; i++){
        vector<pair<int, int>> scores;

        for(int k=1; k<=N; k++){
            int a, b, score;

            if(story_creator[k] == i){
                score = -1;
            }else{
                for(int j=1; j<=M; j++){

                    if(i == j) a = 0;
                    else if(user_follows[i] == j) a = 3;
                    else if(story_creator[story_follows[i]] == j) a = 2;
                    else if(story_follows[i] == story_follows[j]) a = 1;
                    else a = 0;

                    if(story_creator[k] == j) b = 2;
                    else if(story_follows[j] == k) b = 1;
                    else b = 0;

                    score += a*b;
                }
            }
            scores.emplace_back(-score, k);
        }

		for (int k=0;k<N;k++) cout << scores[k].first << ' ';
		cout << '\n';

		cout << '\n';

    	sort(scores.begin(), scores.end());
		for (int k=0;k<3;k++) cout << scores[k].second << ' ';
		cout << '\n';
    }
}