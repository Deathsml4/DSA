#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	map<int, string> mp_name;
	map<int, string> mp_class;
	map<int, string>::iterator it;
	string s;
	while (getline(cin, s, '(')) {
	    //cout << s << endl;
		if (s == "Insert") {
		    //cout << "In insert\n";
			char x;
			int id;
			string name, _class;
			cin >> id >> x;
			getline(cin, name, ',');
			getline(cin, _class, ')');
			mp_name.insert(pair<int, string> (id, name));
			mp_class.insert(pair<int, string> (id, _class));
		}
		if (s == "Infor") {
		    //cout << "In infor\n";
		    char x;
		    int id;
		    cin >> id >> x;
			if (mp_class.find(id) != mp_class.end() && mp_name.find(id) != mp_name.end()) {
			    cout << mp_name[id] << "," << mp_class[id] <<endl;
			}
			else cout << "NA,NA\n";
		}
		if (s == "Delete") {
			//cout << "In delete\n";
			int k;
			cin >> k;
			if (mp_class.find(k) != mp_class.end() && mp_name.find(k) != mp_name.end()) {
			    mp_class.erase(k);
			    mp_name.erase(k);
			}
		}
		s = "";
		getline(cin, s);
	}
	return 0;
}
