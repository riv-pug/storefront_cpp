#include "DataBaseManager.h"



DataBaseManager::DataBaseManager() {}
DataBaseManager::DataBaseManager(string filename){
	filePATH = filename;
}

string DataBaseManager::getFileName() {
	return filePATH;

}

void DataBaseManager::writeRecord(Product p) {

	ofstream file(filePATH, ios::binary | ios::app);
	if (file.is_open()) {
		file.write(reinterpret_cast<char*>(&p), sizeof(Product));
		file.close();
		cout << "Writing Product Info to file..." << endl;
	}
}
void DataBaseManager::readRecord() {
	cout << "Reading Product Info from file..." << endl;
	ifstream file(filePATH, ios::binary);
	Product p;
	if (file.is_open()) {
		while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
			p.displayProductDetails();
		
		}
	
		file.close();
	}
	

}
