#pragma once
const int BLOCK_SIZE = 4096;

struct Student {
	char name[20];
	unsigned studentID;
	float score;
	unsigned advisorID;
};
struct Professor {
	char name[20];
	unsigned ProfID;
	int Salary;
};