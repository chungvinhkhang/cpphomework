/**
* 0. Them sinh vien vao ds
* 1. In ra ds sinh vien 
* 2. Tim kiem sinh vien theo ho ten (bao gom trung ten)
* 3. Sinh vien nao cao diem nhat, thap diem nhat
* 4. Cap nhat thong tin cua sinh vien theo code
*/

#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string Name;
	string Code;
	float Score;
};

struct StudentNode
{
	Student info;
	StudentNode* next;
};

struct StudentsList
{
	StudentNode* head;
	StudentNode* tail;
};

void Input(Student& a);
void Output(Student a);
void OutputList(StudentsList l);
void AddToHead(StudentsList& l, Student x);
void ListStudentsByName(StudentsList l, string hoten);
StudentNode* GetMax(StudentsList l);
StudentNode* GetMin(StudentsList l);
StudentNode* SearchStudentByCode(StudentsList l, string code);

void main()
{
	StudentsList l;
	l.head = l.tail = NULL;

	int menu;
	do
	{
		cout << "0. Them sinh vien vao danh sach" << endl
			<< "1. In ra danh sach cac sinh vien hien co" << endl
			<< "2. Tim kiem sinh vien theo ho ten, in ra tat ca cac sinh vien (trung ten)" << endl
			<< "3. Cho biet sinh vien nao cao diem nhat, sinh vien nao thap diem nhat trong danh sach" << endl
			<< "4. Cap nhat thong tin cua sinh vien theo MSSV" << endl
			<< "5. Ket thuc" << endl;
		cout << "Moi ban chon chuc nang: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
			case 0:
			{
				Student x;
				int flagToContinue = 1;
				do
				{
					Input(x);
					AddToHead(l, x);

					cout << "Nhan 1 de tiep tuc: ";
					cin >> flagToContinue;
					cin.ignore();

				} while (flagToContinue == 1);
				break;
			}

			case 1:
			{
				if (l.head == NULL)
				{
					cout << "Danh sach trong" << endl;
				}
				else
				{
					OutputList(l);
				}
				cout << "Nhan enter de tiep tuc";
				cin.get();
				break;
			}

			case 2: 
			{
				string hoten;
				cout << "Nhap ho ten can tim: ";
				getline(cin, hoten);
				ListStudentsByName(l, hoten);
				
				cout << "Nhan enter de tiep tuc";
				cin.get();
				break;
			}

			case 3:
			{	
				StudentNode* maxNode = GetMax(l);
				if (maxNode != NULL)
				{
					cout << "Sv co diem cao nhat: ";
					Output(maxNode->info);
				}
				
				StudentNode* minNode = GetMin(l);
				if (minNode != NULL)
				{
					cout << "Sv co diem thap nhat: ";
					Output(minNode->info);
				}

				cout << "Nhan enter de tiep tuc";
				cin.get();
				break;
			}

			case 4:
			{
				int flagToContinue = 1;
				do
				{
					string code;
					cout << "Nhap mssv can tim: ";
					getline(cin, code);
					StudentNode* student = SearchStudentByCode(l, code);
					if (student != NULL)
					{
						cout << "Cap nhat cho sinh vien (mssv: " << code << ")" << endl;
						Input(student->info);
					}
					else
					{
						cout << "Khong tim thay sinh vien voi ma nay" << endl;
					}

					cout << "Nhan 1 de tiep tuc: ";
					cin >> flagToContinue;
				} while (flagToContinue == 1);
				break;
			}
		}

	} while (menu != 5);
	system("pause");
}

void Input(Student & a)
{
	cout << "Nhap ho ten: ";
	getline(cin, a.Name);
	cout << "Nhap MSSV: ";
	getline(cin, a.Code);
	do
	{
		cout << "Nhap Diem TB: ";
		cin >> a.Score;
		cin.ignore();
	} while (a.Score < 0 || a.Score > 10);
}

void Output(Student a)
{
	cout << a.Name << " - " << a.Code << " - " << a.Score << endl;
}

void OutputList(StudentsList l)
{
	StudentNode* p = l.head;
	while (p != NULL)
	{
		Output(p->info);
		p = p->next;
	}
}

StudentNode* GetNode(Student x)
{
	StudentNode* p;
	p = new StudentNode;
	if (p == NULL)
	{
		cout << "Khong du bo nho";
		exit(1);
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void AddToHead(StudentsList& l, Student x)
{
	StudentNode* p;
	p = GetNode(x);
	if (p == NULL)
	{
		cout << "khong tao duoc nut!";
		exit(1);
	}
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}

}

StudentNode* SearchStudentByCode(StudentsList l, string code)
{

	StudentNode* p = l.head;
	while (p != NULL)
	{
		if (code.compare(p->info.Code) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void ListStudentsByName(StudentsList l, string name)
{

	StudentNode* p = l.head;
	while (p != NULL)
	{
		if (name.compare(p->info.Name) == 0)
		{
			Output(p->info);
		}
		p = p->next;
	}
}


StudentNode* GetMax(StudentsList l)
{
	StudentNode* maxScoreStudent = l.head;
	StudentNode* p = l.head;
	while (p != NULL)
	{
		if (p->info.Score > maxScoreStudent->info.Score)
		{
			maxScoreStudent = p;
		}
		p = p->next;
	}
	return maxScoreStudent;
}

StudentNode* GetMin(StudentsList l)
{
	StudentNode* minScoreStudent = l.head;
	StudentNode* p = l.head;
	while (p != NULL)
	{
		if (p->info.Score < minScoreStudent->info.Score)
		{
			minScoreStudent = p;
		}
		p = p->next;
	}
	return minScoreStudent;
}
