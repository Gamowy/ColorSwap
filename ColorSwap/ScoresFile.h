#pragma once
#include "ColorSwap.h"

using namespace sf;

//holds records of high scores from data.dat file
struct FileRecord {
	int score = 0;
	std::wstring nickname;
	std::wstring date;
};

class ScoresFile
{
private: 
	std::wfstream file;

public:
	std::wstring crypt(std::wstring str);
	FileRecord readRecord(int recordIndex);
	void save(FileRecord records[3]);
	ScoresFile();
	virtual ~ScoresFile();
};

