#include "SimplePath.h"

SimplePath::SimplePath()
{
	delim = DefaultDelim;
}

SimplePath::SimplePath(const char* _delim)
{
	delim =  CreateCopy(_delim);
	Length = 0;
}

SimplePath::SimplePath(const char* _delim, char* _path)
{
	delim =  CreateCopy(_delim);
	Path = _path;
	Split(Path, List, Length);
}

SimplePath::~SimplePath()
{
}


char* SimplePath::CreateCopy(const char* _txt)
{
	char* value = (char*)malloc(sizeof(char) * (strlen(_txt) + 1));
	strcpy(value, _txt);

	return value;
}

char* SimplePath::GetLast()
{
	if(Length > 0)
		return List[Length -1];

	return NULL;
}

char* SimplePath::GetLast(const char* _path)
{
	char* str = CreateCopy(_path);
	char* find = nullptr;
	char* last = nullptr;
	char* returnValue = nullptr;

	find = strtok(str, delim);

	do
	{
		last = find;
		find = strtok(NULL, delim);

	} while (find != NULL);

	if (last != NULL)
	{
		returnValue = (char*)malloc(sizeof(char) * (strlen(last) + 1));
		strcpy(returnValue, last);
	}

	free(str);

	return returnValue;
}

char* SimplePath::GetRoot()
{
	if(Length > 0)
		return List[0];

	return NULL;
}

char* SimplePath::GetRoot(const char* _path)
{
	char* str = CreateCopy(_path);
	char* find = nullptr;
	char* returnValue = nullptr;

	find = strtok(str, delim);

	if (find != NULL)
	{
		returnValue = (char*)malloc(sizeof(char) * (strlen(find) + 1));
		strcpy(returnValue, find);
	}

	free(str);

	return returnValue;
}

void SimplePath::Split(const char* _path, char** &_array, int & _length)
{
	char* str = CreateCopy(_path);
	char* ptrValuePositon = nullptr;
	char* find = nullptr;

	_length = 0;
	find = strtok(str, delim);
	if (find != NULL)
	{
		_array = (char**)malloc(sizeof(char*));
	}

	while (find != NULL)
	{
		_array = (char**)realloc(_array, (_length + 1) * sizeof(char*));
		ptrValuePositon = (char*)malloc(sizeof(char) * (strlen(find) + 1));

		strcpy(ptrValuePositon, find);
		_array[_length] = ptrValuePositon;

		_length++;
		
		find = strtok(NULL, delim);
	} 
	
	free(str);
}