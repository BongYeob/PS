#include <iostream>	//17609
#include <string>
#include <stack>

using namespace std;

int check(string str) {		//회문 체크

	bool answer = true;	//회문
	bool answer1 = false;	//유사회문
	int start = -1;
	int finish = str.size();
	int temp_start, temp_finish;

	bool start1 = false;
	bool finish1 = false;


	for (int i = 0; i < str.size() / 2; i++) {
		start += 1;
		finish -= 1;

		if (str[start] != str[finish]) {
			answer = false;

			if (str[start + 1] == str[finish]) {

				temp_start = start;
				temp_finish = finish + 1;
				bool start2 = true;
				int asdf = (temp_finish - 1 - temp_start) / 2;

				for (int j = 0; j < asdf; j++) {
						
					temp_start += 1;
					temp_finish -= 1;

					if (str[temp_start] != str[temp_finish])
						start2 = false;
				}

				if (start2 == true)
					start1 = true;
			}

			if (str[start] == str[finish - 1]) {

				temp_start = start - 1;
				temp_finish = finish;
				bool finish2 = true;
				int asdf =  (temp_finish - 1 - temp_start) / 2;

				for (int j = 0; j < asdf; j++) {
					temp_start += 1;
					temp_finish -= 1;

					if (str[temp_start] != str[temp_finish])
						finish2 = false;
				}

				if (finish2 == true)
					finish1 = true;
			}

			if (start1 == true || finish1 == true)
				answer1 = true;
			break;
		}
	}

	if (answer == true)
		return 0;
	else {
		if (answer1 == true)
			return 1; 
		else
			return 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		cout<<check(str)<<"\n";
	}
}