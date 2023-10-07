#ifndef _SimplePath_H_
#define _SimplePath_H_

#include <cstring>
#include <cstdlib>

#define DefaultDelim "\\"

class SimplePath
{
public:
	SimplePath();
	SimplePath(const char * _delim);
	SimplePath(const char * _delim, char * _path);
	~SimplePath();

	const char* delim;

	char * Path;
	char** List;
	int Length;

	char* GetLast();
	char* GetLast(const char* _path);
	char* GetRoot();
	char* GetRoot(const char* _path);
	void Split(const char* _path, char** &_array, int & _length);

private:
	char* CreateCopy(const char* _txt);
};

#endif