#include "ColorSwap.h"
#include "ScoresFile.h"

//returs decrypted record
FileRecord ScoresFile::readRecord(int recordIndex)
{
	FileRecord record;
	std::wstring scoreBuffer;

	file.open("Content/data.dat", std::ios::in);
	file.seekg(0);
	for (int i = 0; i <= recordIndex; i++) 
	{
		//save score from file to buffer, decrypt it and save to record
		std::getline(file, scoreBuffer);
		scoreBuffer = crypt(scoreBuffer);
		record.score = stoi(scoreBuffer);

		//save nickname and date from file and decrypt it
		std::getline(file, record.nickname);
		std::getline(file, record.date);

		record.nickname = crypt(record.nickname);
		record.date = crypt(record.date);
	}
	file.close();

	return record;;
}

//encrypt and save record to file
void ScoresFile::save(FileRecord records[3])
{
	file.open("Content/data.dat", std::ios::out);
	file.seekg(0);
	for (int i = 0; i < 3; i++)
	{
		file << crypt(std::to_wstring(records[i].score)) << std::endl;
		file << crypt(records[i].nickname) << std::endl;
		file << crypt(records[i].date) << std::endl;
	}
	file.close();
}

ScoresFile::ScoresFile()
{
	//open or create .dat file
	file.open("Content/data.dat");
	if (!file.is_open())
	{
		file.open("Content/data.dat", std::ios::out);
		for (int i = 0; i < 3; i++)
		{
			file << L"c" << std::endl;
			file << L"~~~" << std::endl;
			file << L"~~~" << std::endl;
		}
	}
	file.close();
}

ScoresFile::~ScoresFile()
{
}

//XOR wstring cipher for file read/write
std::wstring ScoresFile::crypt(std::wstring str)
{
	std::wstring result = str;
	for (int i = 0; i < result.size(); i++) result[i] = str[i] ^ 83;
	return result;
}