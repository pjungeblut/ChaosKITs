map<char,int> m; map<int,char> o; 
int num[7] = {1000,500,100,50,10,5,1};

void buildMap() {
	m['M'] = 1000; m['D'] = 500; m['C'] = 100; m['L'] = 50; m['X'] = 10; m['V'] = 5; m['I'] = 1; m[' '] = 0;
	o[1000] = 'M'; o[500] = 'D'; o[100] = 'C'; o[50] = 'L'; o[10] = 'X'; o[5] = 'V'; o[1] = 'I';
} 

int convertToInt(string &s) {
	int res = m[s[0]];
	for(int i = 1; i < s.size(); i++) {
		if(m[s[i-1]] < m[s[i]])
			res -= 2*m[s[i-1]];
		res += m[s[i]];	
	}
	return res;
}

string convertToRoman(int n) {
	string roman = "";
	for(int i = 0; i < 7; i++) {
		while(n >= num[i]) {
			roman += o[num[i]];
			n -= num[i];
		}
	}
	int pos = roman.find("CCCC");
	if(pos != string::npos) roman.replace(pos,4,"CD");
	pos = roman.find("XXXX");
	if(pos != string::npos) roman.replace(pos,4,"XL");
	pos = roman.find("IIII");
	if(pos != string::npos) roman.replace(pos,4,"IV");
	pos = roman.find("DCD");
	if(pos != string::npos) roman.replace(pos,3,"CM");
	pos = roman.find("LXL");
	if(pos != string::npos) roman.replace(pos,3,"XC");
	pos = roman.find("VIV");
	if(pos != string::npos) roman.replace(pos,3,"IX");
	return roman;
}
