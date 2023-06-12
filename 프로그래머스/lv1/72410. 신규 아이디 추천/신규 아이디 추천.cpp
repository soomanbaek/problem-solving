#include<iostream>

using namespace std;

string solution(string new_id) {
	//1단계
	for (auto &s : new_id) {
		if ('A' <= s && s <= 'Z') {
			s += abs('a' - 'A');
		}
	}

	//2단계
	for (string::iterator it = new_id.begin(); it < new_id.end(); it++) {
		if (('0'<=*it&&*it<='9')||('a' <= *it && *it <= 'z') || *it == '-' || *it == '_' || *it == '.')
			continue;
		new_id.erase(it--);
	}

	//3단계
	bool flag = false;
	for (string::iterator it = new_id.begin(); it < new_id.end(); it++) {
		if (*it == '.') {
			if (flag)
				new_id.erase(it--);
			else
				flag = true;
		}
		else
			flag = false;
	}

	//4단계
	while (*new_id.begin() == '.') {
		new_id.erase(new_id.begin());
	}
	while (*(new_id.end()-1) == '.')
		new_id.erase(new_id.end()-1);

	//5단계
	if (new_id.empty())
		new_id += 'a';
	
	if (new_id.size() > 15) {
		new_id = new_id.substr(0, 15);
		
		//6단계
		while (*(new_id.end() - 1) == '.')
			new_id.erase(new_id.end() - 1);
	}

	//7단계
	while(new_id.size() < 3)
		new_id += *(new_id.end()-1);

	return new_id;
}