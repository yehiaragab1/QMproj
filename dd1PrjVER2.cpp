#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


void sortString(string& str)
{

	sort(str.begin(), str.end());
	
}


bool checkAlphabet(string func,int &count,int &division,string &g) {

	division = 1;
	count = 0;
	g="";
	bool found=0;
	
	for (int i = 0; i < func.size(); i++) {
		if (func[i] == '+') {
			division += 1;
		}
		if ((!(func[i] >= 'a' && func[i] <= 'z')) && func[i] != '!' && func[i] != '+' && func[i] != '*') {
			return 1;
		}
		else if (func[func.size() - 1] == '!' || func[func.size() - 1] == '+' || func[func.size() - 1] == '*')
			return 1;
		else if (func[i] >= 'a' && func[i] <= 'z') {
			for (int j = 0; j < g.size(); j++) {
				if (func[i] == g[j]) {
					found = 1;
				}
				
			}
			if (found == 0) {
				g += func[i];
				count++;
			}
		}
		found = 0;
	}
	
	
	sortString(g);
	return 0;

}

void matchVec(string alp, vector<vector<bool>> f, map< char, vector<bool>> &K) {

	for (int x = 0; x < alp.size(); x++) {	
				K.insert({ alp[x] ,f[x]});	
	}
}

vector<vector<bool>>  crvector(int count) {

	int can=1;
	

	
	int n = count;
	int m = pow(2, count);

	
	
	vector<vector<bool>> V(n,vector<bool>(m));
	/*float arr[4];
	arr[0] = 6.28;
	arr[1] = 2.50;
	arr[2] = 9.73;
	arr[3] = 4.364;
	std::vector<float*> vec = std::vector<float*>();
	vec.push_back(arr);
	float* ptr = vec.front();
	for (int i = 0; i < 3; i++)
		printf("%g\n", ptr[i]);*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; )

		{

			for (int k = 0; k < pow(2, n-1-i); k++) {

				if (can % 2 != 0) {

					V[i][j] = 0;
					if (j < m)
						j++;
				}

				else {
					V[i][j] = 1;

					if (j <m)
						j++;
				}
			}

			can++;

			
		}
		can = 1;
		
	}
	
		
	return V;
}

void divideString(string func, string* &produc,int division) {

	produc = new string[division];
	
	int c = 0;
	for (int i = 0; i < func.size(); i++) {

		if (func[i] != '+') {
			produc[c] += func[i];
		}
		else {
			c++;
		}

	}




}

vector<bool> getTruth( map<  char, vector<bool>> km,int count,string* div,int numbdiv,int &numbT, vector<int> &mint) {

	int n = count;
	int m = pow(2, count);

	 numbT = 0;



	bool sum=1;

	bool sol=0;
	
	vector<bool> answ(m);
		
	
		for (int j = 0; j < m; j++) {


			for (int sec = 0; sec < numbdiv; sec++) {

				for (int i = 0; i < div[sec].size(); i++) {


					if (div[sec][i] == '!') {
						++i;
						auto it2 = km.find(div[sec][i]);



						sum *= !it2->second[j];
					}
					else if(div[sec][i] != '*') {
					
						auto it2 = km.find(div[sec][i]);



						sum *= it2->second[j];

					
					
					}
				}
				sol += sum;
				sum = 1;
			}

			if (sol == 1) {
				numbT += 1;
			}
			answ[j] = sol;

			

			 sol = 0;
		}
	
		

		for (int i = 0; i < answ.size();i++) {
			if (answ[i] == 1)
				mint.push_back(i);
		}


	return answ;

}

/*vector<vector<int>> getFomule(string eq, vector<vector<int>> V) {
	//A*B*!C+A
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < c; i++) {

			if (i == 0)
				cas = cas * V[i][j];
			else {
				if (c == '+')
					sum = a + b;
				else
				{
					if (c == '-')
						sum = a - b;
					else
					{
						if (c == '*')
							sum = a * b;
						else
							sum = 0;
					}
				}
			}


		}
	}

}*/

void pos(vector<bool> tru, map<char, vector<bool>> mp, int count, int numbT,string alp) {
	int m = pow(2, count);
	int k = numbT;
	string pos = "(";

	for (int i = 0; i < m; i++) {
		if (tru[i] == 1) {
			for (auto it = mp.begin(); it != mp.end(); ++it) {
				if (it->second[i] == 1) {
					pos += "!";
					pos += it->first;
					if (i != m &&alp[count-1]!=it->first)
						pos += "+";

					
				}
				else {
					
					pos += it->first;
					if (i != m && alp[count - 1] != it->first)
						pos += "+";
				}
				
			}
			numbT -= 1;
			if (numbT > 0)
				pos += ") * (";
		}
	}
	pos += ")";
	cout << endl << "Product of sums:";
	cout << endl << pos;

}

void sop(vector<bool> tru,map<char,vector<bool>> mp,int count,int numbT) {
	int m = pow(2, count);
	int k = numbT;
	string sop="";

	for (int i = 0; i < m; i++) {
		if (tru[i] == 1) {

			for (auto it = mp.begin(); it != mp.end(); ++it) {
				if (it->second[i] == 1) {
					sop += it->first;
					
				}
				else {
					sop += "!";
						sop+=it->first;
					
				}
			}
			numbT -= 1;
			if (numbT > 0)
				sop += " + ";
		}
	}
	cout << endl << "Sum of Products:";
	cout << endl << sop;

}


void comp(string& k, int c) {
	do {
		k.insert(0, "0");
	} while (k.size() != c);
}
void bin(unsigned n, string& k, int c)
{
	/* step 1 */
	if (n > 1)
		bin(n / 2, k, c);

	/* step 2 */
	k += to_string(n % 2);


}

vector<string> getstr(vector<int> k) {

	vector<string> s;
	for (int i = 0; i < k.size(); i++) {
		s.push_back(to_string(k[i]));
	}
	return s;
}

bool combin(string x1, string x2, string& sol) {
	int c = 0;
	for (int i = 0; i < x1.size(); i++) {
		if (x1[i] != x2[i]) {
			c++;
			x1[i] = '-';
		}
	}
	if (c == 1) {
		sol = x1;
		return 1;
	}
	else
		return 0;
}
bool checkLike(string x1, string x2) {
	sortString(x1);
	sortString(x2);
	for (int i = 0; i < x1.size(); i++) {
		
		if (x1[i] != x2[i]) {
			return 1;
		}
	}
	return 0;
}

int countCommas(string x1) {
	int c = 0;
	for (int i = 0; i < x1.size();i++) {
		if (x1[i] == ',')
			c++;
	}
	return c;
}
bool stringCheck(string x1, string x2) {
	int ck = 0;
	for (int i = 0; i < x1.size(); i++) {
		for (int j = 0; j < x2.size(); j++) {
			if (x1[i] != ','&&x2[j]!=',' && x1[i] == x2[j]) {
				ck++;
			}
		}
	}
	if (ck >= x1.size()- countCommas(x1)) {
		return 1;
	}
	else
		return 0;
}

void getAlp(string alph,string bin,string &sol) {
	 sol = "";
	for (int i = 0; i < bin.size(); i++) {
		if (bin[i] == '0') {
			sol += '!';
			sol += alph[i];
		}
		else if (bin[i] == '1') {
			sol += alph[i];
		}
	}
	

}

void getBol(string k,int si, vector<bool> &v) {
	
	v.resize(si);
	
	vector<string> vst;
	vst.resize(k.size());
	int j = 0;
	int c = 0;
	int d = 0;
	for (int i = 0; i < k.size(); i++) {
		
		 if (k[i] == ',') {
			
			 vst[c] = k.substr(i-d, d);
			 c++;
			 d = 0;
		 }
		 else if (k[i+1] == NULL) {
			 vst[c] = k.substr(i - d, d+1);
			 c++;
			 d = 0;
		}
		 else {
			 d++;
		 }
		

			 
		
	}

	vst.shrink_to_fit();
	for (int i = 0; i < vst.size(); i++) {
		if(vst[i]!="")
		v[stoi(vst[i])] = 1;
	}

}

void covChart(string alph,map<string,vector<bool>> &sol,map<string,string> PI) {

	int siz = pow(2, alph.size());
	vector<bool >v;
	v.resize(siz);
	string sv = "";
	
	for (auto it = PI.begin(); it != PI.end(); ++it) {

		getBol(it->first, siz, v);
		getAlp(alph, it->second,sv);
		sol.insert(make_pair(sv,v));
	}

	
	/*for (auto it2 = sol.begin(); it2 != sol.end(); ++it2) {
		cout << it2->first <<"  " << endl;
		for (int i = 0; i < siz; i++) {
			cout << it2->second[i] << endl;
		}
	}*/

}
void PI(map<string, string> IT, vector<int> mint, int count,string alph, map<string, vector<bool>> &mp3) {

	
	string str;
	string binr;
	

	vector<string> k;
	k.resize(mint.size());
		k=getstr(mint);
	
		
	for (int i = 0; i < mint.size(); i++) {
		bin(mint[i], binr, count);

		if (binr.size() != count)
			comp(binr, count);

		
		//vbin.push_back(s);

	
		
		IT.insert(make_pair(k[i],binr));
			
		binr = "";

	}

	cout << endl;

	map<string, string> IT2;
	IT2 = IT;
	map<string, string> sol;
	string d = "";
	string mi = "";
	int option = 0;
	int com = 0;
	int check = 0;
	map<string, string> flag;
	do {
		for (auto it = IT.cbegin(); it != IT.cend(); ++it) {
			for (auto it2 = IT2.cbegin(); it2 != IT2.cend(); ++it2) {

				if (combin(it->second, it2->second, d)) {

					mi += it->first;
					mi += ',';
					mi += it2->first;
					if (!sol.empty()) {

						for (auto it3 = sol.cbegin(); it3 != sol.cend(); ++it3) {
							if (checkLike(mi, it3->first)) {
								
								if (check == sol.size() - 1) {
									sol.insert(make_pair(mi, d));
									com++;
								}

									
									check += 1;
								
							}
						}
						check = 0;
					}
					else {
						sol.insert(make_pair(mi, d));
						com++;
					}
					mi = "";
					d = "";
					
				}

			}

		}
		if (com == 0) {
			option = 1;
		}
		else {

			string * z= new string[IT.size()];
			string* z2 = new string[sol.size()];
			if(!sol.empty()){
				int i1 = 0, i2 = 0;
				for (auto it = IT.begin(); it != IT.end(); ++it) {
				
					z[i1] = it->first;
					i1++;
				}
				for (auto it2 = sol.begin(); it2 != sol.end(); ++it2) {

					z2[i2] = it2->first;
					i2++;
				}
				int ck = 0;
				for (int i = 0; i <i1; i++) {
					for (int j = 0; j <i2; j++) {
						if (stringCheck(z[i], z2[j])) {
							ck += 1;
						}
						if (ck > 0)
							j = i2;
					}
					if (ck > 0) {
						ck = 0;
					}
					else {

						auto it3 = IT.find(z[i]);
						flag.insert(make_pair(it3->first,it3->second));
						ck = 0;
					}

				}

			}
			IT.clear();
			IT = sol;
			IT2.clear();
			IT2 = sol;
			sol.clear();

		}
		com = 0;


	} while (option != 1);
	cout << endl;
	for (auto it4 = flag.begin(); it4 != flag.end(); ++it4) {
		IT.insert(make_pair(it4->first,it4->second));
	}
	cout << "Minterms of PI" << "          " << "Binary Representation" << endl;
	for (auto it = IT.begin(); it != IT.end(); ++it) {
		cout << it->first << "                       " << it->second << endl;
	}
	
	covChart(alph, mp3, IT);
}

void EPI(int numbAlph, map <string, vector<bool>> PI) {  //function takes the number of unique letters, and the coverage table of PIs


	int m = pow(2, numbAlph);
	int sum = 0;
	vector<int> min_EPI; // vector of minterms that only have 1 coverage
	vector< pair <string, vector<bool>> > EPI; //vector of EPIs , stored as a pair of their product and coverage table row

	for (int i = 0; i < m; i++) { // checks to see if a column (minterm) only has a total of 1 true value, and saves that index as a min_EPI
		for (auto itr = PI.begin(); itr != PI.end(); itr++) {
			if (itr->second[i])
				sum++;
		}

		if (sum == 1) {
			min_EPI.push_back(i);
		}
		sum = 0;
	}

	for (int i = 0; i < min_EPI.size(); i++) { //finds the PI that is true at the index of the minterm EPI, and assigns
									// that PI to the EPI vector, and removes it from the PI map


		for (auto itr = PI.begin(); itr != PI.end(); itr++) {

			if (itr->second[min_EPI[i]]) {
				EPI.push_back(*itr);
				
			}
		}

	}

	//Printing of the PI and EPI

	cout << "The EPIs are: ";

	for (int i = 0; i < EPI.size(); i++) {
		cout << EPI[i].first << " ";
	}

	cout << endl;

	vector <bool> minterms(m, true);


	for (int i = 0; i < EPI.size(); i++) {
		for (int j = 0; j < m; j++) {
			if (EPI[i].second[j] == 1)
				minterms[j] = 0;
		}
	}


	cout << "The minterms not covered by EPIs are: ";

	for (int i = 0; i < minterms.size(); i++) {
		if (minterms[i])
			cout << i << " ";
	}


	cout << endl;
}



int main() {
	int k,numbdiv,numbT;
	vector<int> mint;
	string* sol;
	string alp;
	map<  char, vector<bool>> K;
	string a = "a*b+c";
	if (!checkAlphabet(a, k, numbdiv, alp)) {
		vector<vector<bool>> V;
		vector<bool> tru(pow(2, k));

		V = crvector(k);
		matchVec(alp, V, K);

		divideString(a, sol, numbdiv);

		tru = getTruth(K, k, sol, numbdiv, numbT, mint);
		cout << "Truth Table:" << endl;
		for (int i = 0; i < pow(2, k); i++) {
			cout << tru[i] << "  ";
		}

		sop(tru, K, k, numbT);
		pos(tru, K, k, numbT,alp);

		map<string, string> mpk;
		map<string, vector<bool>> mp3;
		PI(mpk, mint, k, alp, mp3);
		EPI(k, mp3);
	}
	else
		cout << "Input Error " << endl;
}