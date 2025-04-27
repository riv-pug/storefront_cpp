#pragma once
#ifndef  DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>

#include "Product.h"

using namespace std;

class DataBaseManager
{

	private:
		string filePATH;
	public:
		DataBaseManager();
		DataBaseManager(string);

		string getFileName();
		void writeRecord(Product);
		void readRecord();
};

#endif DATA_H