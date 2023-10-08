#ifndef _SimplePath_H_
#define _SimplePath_H_

#include <cstring>
#include <cstdlib>

#define DEF_DENIM '\\'

class SimplePath
{
public:
	SimplePath();
	SimplePath(char _delim);
	SimplePath(char _delim, char * _path);
	~SimplePath();

	char delim;

	char* Path;
	char** List;
	int Length;
	
	
	char* GetLast();
	char* GetLast(char* _path);
	char* GetRoot();
	char* GetRoot(char* _path);
	
	void Split(char* _path, char** &_array, int & _length);
	
	char* GetParent();
	char* GetParent(char* _path);
	char* GetParent(char* _path, int index);
	
	char* GetParentPath(char* _path);
	

private:
	char* CreateCopy(char* _txt);
	void TrimDelim(char* _path);
};

#endif