#include "SimplePath.h"

SimplePath::SimplePath()
{
	delim = DEF_DENIM;
}


SimplePath::SimplePath(char _delim)
{
	delim = _delim;
	Length = 0;
}

SimplePath::SimplePath(char _delim, char* _path)
{
	delim = _delim;
	Path = CreateCopy(_path);
	Split(Path, List, Length);
}

SimplePath::~SimplePath()
{
}

char* SimplePath::CreateCopy(char* _txt)
{
	char* value = (char*)malloc(sizeof(char) * (strlen(_txt) + 1));
	strcpy(value, _txt);

	return value;
}

void SimplePath::TrimDelim(char* _path)
{
	do
	{
		if (strlen(_path) > 0 && _path[strlen(_path) - 1] == delim)
			_path[strlen(_path) - 1] = 0;

	} while (strlen(_path) > 0 && _path[strlen(_path) - 1] == delim);
}

void SimplePath::Split(char* _path, char**& _array, int& _length)
{
	char* str = CreateCopy(_path);
	char* ptrPositonName = NULL;
	char* find = NULL;
	char* prew = NULL;

	TrimDelim(str);

	_array = (char**)malloc(sizeof(char**));

	if (strlen(_path) == 1)
	{
		ptrPositonName = (char*)malloc(sizeof(char) + 2);
		ptrPositonName[0] = delim;
		ptrPositonName[1] = 0;
		_array[0] = ptrPositonName;
		_length = 1;

		return;
	}

	_length = 0;
	find = strchr(str, delim);

	if (find == NULL)
	{
		ptrPositonName = (char*)malloc(sizeof(char) + 2);
		strcpy(ptrPositonName, _path);
		_array[0] = ptrPositonName;
		_length = 1;

		return;
	}

	prew = str;
	while (find != NULL)
	{
		int index = find - prew ;
		find = find + 1;

		if (index > 0)
		{
			_array = (char**)realloc(_array, (_length + 1) * sizeof(char**));
			ptrPositonName = (char*)malloc(sizeof(char) * (index + 2));

			strncpy(ptrPositonName, prew, index);

			ptrPositonName[index] = 0;
			_array[_length] = ptrPositonName;
			_length++;
		}
		else
		{
			ptrPositonName = (char*)malloc(sizeof(char) + 2);
			ptrPositonName[0] = delim;
			ptrPositonName[1] = 0;
			_array[_length] = ptrPositonName;
			_length++;
		}

		prew = find;
		find = strchr(prew, delim);
	}

	if (strlen(prew) > 0)
	{
		_array = (char**)realloc(_array, (_length) * sizeof(char**));
		ptrPositonName = (char*)malloc(sizeof(char) * strlen(prew) + 1);
		strcpy(ptrPositonName, prew);
		_array[_length] = ptrPositonName;
		_length++;
	}

	free(str);
}

char* SimplePath::GetLast()
{
	if(Length > 0)
		return List[Length -1];

	return NULL;
}

char* SimplePath::GetLast(char* _path)
{
	char* str = CreateCopy(_path);
	char* returnValue = NULL;
	char* find = NULL;
	char* last = NULL;

	if (strlen(str) == 1)
	{
		return str;
	}

	TrimDelim(str);

	find = strchr(str, delim);

	while (find != NULL)
	{
		last = find;
		find = strchr(find + 1, delim);
	}

	if (last != NULL)
	{
		if(last[0] == delim)
		{ 
			returnValue = (char*)malloc(sizeof(char) * (strlen(last) + 1));
			strcpy(returnValue, last + 1);
		}
		else
		{
			returnValue = (char*)malloc(sizeof(char) * (strlen(last) + 2));
			strcpy(returnValue, last);
		}
	}
	else
	{
		return str;
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

char* SimplePath::GetRoot(char* _path)
{
	char* str = CreateCopy(_path);
	char* returnValue = NULL;
	char* find = NULL;


	if (strlen(str) == 1)
	{
		return str;
	}

	TrimDelim(str);

	find = strchr(str, delim);

	if (find != NULL)
	{
		int index = find - str;

		if (index == 0)
		{
			returnValue = (char*)malloc(sizeof(char) * 3);
			returnValue[0] = delim;
			returnValue[1] = 0;

			return returnValue;
		}
		else
		{
			returnValue = (char*)malloc(sizeof(char) * (index + 2));

			strncpy(returnValue, str, index);
			returnValue[index] = 0;
		}
	}
	else
	{
		return str;
	}

	free(str);
	
	return returnValue;
}

char* SimplePath::GetParent()
{
	if (Length == 0 || Length == 1)
		return NULL;

	return List[Length-2];
}

char* SimplePath::GetParent(char* _path)
{
	char* str = CreateCopy(_path);
	char* returnValue = NULL;
	char* find = NULL;
	char* last = NULL;

	if (strlen(str) == 1)
	{
		return NULL;
	}

	TrimDelim(str);

	find = strchr(str, delim);

	while (find != NULL)
	{
		last = find;
		find = find + 1;
		find = strchr(find, delim);
	}

	if (last != NULL)
	{
		int index = last - str;
		if (index == 0) index = 1;
		returnValue = (char*)malloc(sizeof(char) * (index + 1));
		if (str[0] == delim)
		{
			strncpy(returnValue, str + 1, index - 1);
			returnValue[index-1] = 0;
		}
		else
		{
			strncpy(returnValue, str, index);
			returnValue[index] = 0;
		}

		
	}

	free(str);

	return returnValue;
}

char* SimplePath::GetParent(char* _path, int index)
{
	char** array = nullptr;
	int length;
	char* returnValue = nullptr;


	Split(_path, array, length);

	if (index >= length)
		return NULL;
	else if (index == 0)
		return (char*)_path;
	

	for (int i = length - 1; i >= 0; i--)
	{
		char* ptr = array[i];

		if (index == length - i - 1)
			returnValue = array[i];
		else
			free(ptr);
	}
	
	return returnValue;;
}

char* SimplePath::GetParentPath(char* _path)
{
	if (strlen(_path) == 1)
		return NULL;

	char* str = CreateCopy(_path);

	TrimDelim(str);

	if (strlen(str) == 1)
		return NULL;

	char* last = GetLast(str);


	int lengthParent = strlen(str) - strlen(last) - 1;
 
	if (lengthParent == 0) lengthParent = 1;

	char * parent = (char*)malloc(sizeof(char) * (lengthParent + 1));

	for (int i = 0; i < lengthParent; i++)
	{
		parent[i] = str[i];
	}

	parent[lengthParent] = 0;

	free(str);

	return parent;
}

char* SimplePath::GetExtensionFromPath(char* _fileName)
{
	return GetExtensionFromPath(GetLast(_fileName));
}

char* SimplePath::GetExtensionFromFileName(char* _path)
{
	char* returnValue = NULL;
	char* str = CreateCopy(_path);

	if (_path == NULL || strlen(_path) == 1)
	{
		return NULL;
	}

	char* find = NULL;
	char* last = NULL;

	TrimDelim(str);

	find = strchr(str, '.');
	last = find;

	while (find != NULL)
	{
		last = find;
		find = strchr(find + 1, '.');
	}

	if (last != NULL)
	{
		if (strlen(last) == 1)
		{
			returnValue = (char*)malloc(sizeof(char) * 2);
			returnValue[0] = 0;
		}
		else
		{
			returnValue = (char*)malloc(sizeof(char) * strlen(last) + 1);
			strcpy(returnValue, last + 1);
		}
	}
	else
	{
		return NULL;
	}

	free(str);

	return returnValue;
}

