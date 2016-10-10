// Zerlegt s anhand aller Zeichen in delim.
vector<string> split(string &s, string delim) {
	vector<string> result; char *token;
	token = strtok((char*)s.c_str(), (char*)delim.c_str());
	while (token != NULL) {
		result.push_back(string(token));
		token = strtok(NULL, (char*)delim.c_str());
	}
	return result;
}
