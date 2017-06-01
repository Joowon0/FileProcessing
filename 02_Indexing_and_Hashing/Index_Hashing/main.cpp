#include<fstream>
#include<iostream>
#include<bitset>
#include"HashTable.h"
using namespace std;

int main()
{
	
	ifstream ifs("sampleData.csv",ios::in);
	string data;
	char buffer[1024];
	HashTable tlb;
	vector<Student> students;
	ifs.getline(buffer, 1024);
	int num = atoi(buffer);

	const vector<int>& tb = tlb.getTable();
	
	for(int i=0;i<num;++i){
		ifs.getline(buffer, 1024);
		char* buff = buffer;
		Student stu;
		int next=0;
		char *data;
		
		data = strtok(buff, ",");
		next = strlen(data);
		int j = MyStrCpy(stu.name, data);
		
		cout << stu.name;
		buff = buff + next+1;

		data = strtok(buff, ",");
		stu.studentID=atoi(data);
		next = strlen(data);
		buff = buff + next+1;

		data = strtok(buff, ",");
		stu.score = atof(data);
		next = strlen(data);
		buff = buff + next + 1;

		data = strtok(buff, ",");
		stu.advisorID=atoi(data);		

		students.push_back(stu);
		tlb.insert(students[i]);
	}
	
	ifs.close();
	cout << "==================================================" << endl;
	tlb.printBuckets();
	cout << "##################################################" << endl;
}
