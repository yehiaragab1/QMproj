#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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

vector<bool> getTruth( map<  char, vector<bool>> km,int count,string* div,int numbdiv,int &numbT) {

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

void posndsop(vector<bool> tru,map<char,vector<bool>> mp,int count,int numbT) {
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
				sop += ' + ';
		}
	}

	cout << endl << sop;

}

int main() {
	int k,numbdiv,numbT;
	string* sol;
	string alp;
	map<  char, vector<bool>> K;
	string a = "!d+!a*!b*c+b*c";
	checkAlphabet(a,k, numbdiv,alp);
	vector<vector<bool>> V;
	vector<bool> tru(pow(2, k));
	
	V=crvector(k);
	matchVec(alp, V, K);

	divideString(a,sol, numbdiv);
	tru=getTruth(K, k, sol, numbdiv,numbT);

	for (int i = 0; i < pow(2, k); i++) {
		cout<<tru[i]<<"  ";
	}
	posndsop(tru, K,k, numbT);
	
	
}