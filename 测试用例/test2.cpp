#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<io.h>
#include <ctype.h>
using namespace std;
#define MATCH      1
#define NOT_MATCH  0
#define MATCH_CHAR(c1,c2,ignore_case)  ( (c1==c2) || ((ignore_case==1) &&(tolower(c1)==tolower(c2))) )
#define	MAX_PATH_LENGTH			80

void getFiles(string path, vector<string>& files, char* pattern);
int WildCharMatch(char *src, char *pattern, int ignore_case);
void getFileName(char path[], vector<string> files);
void count(fstream &outfile, int *cnt);

struct Command {
	bool _c;
	bool _w;
	bool _l;
	bool _o;
	bool _s;
	Command() {
		_c = false;
		_w = false;
		_l = false;
		_o = false;
		_s = false;
	}
};
