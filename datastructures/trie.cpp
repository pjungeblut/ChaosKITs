struct node {
	node *(e)[26];
	int c = 0;
	node() { for(int i = 0; i < 26; i++) e[i] = NULL; }	
};

void insert(node *root, string *txt, int s) {
	if(s >= txt->length()) root->c++;
	else {
		int idx = (int)((*txt).at(s) - 'a');
		if(root->e[idx] == NULL) {
			root->e[idx] = new node();
		}
		insert(root->e[idx], txt, s+1);
	}
}

int contains(node *root, string *txt, int s) {
	if(s >= txt->length()) return root->c;
	int idx = (int)((*txt).at(s) - 'a');
	if(root->e[idx] != NULL) {
			return contains(root->e[idx], txt, s+1);
	} else return 0;
}
