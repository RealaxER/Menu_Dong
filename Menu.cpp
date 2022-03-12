//  ==================== LÝ THUYEST ==============
//1. Trình bày điểm giống, khác của : malloc, calloc, realloc, new
// Đều có thể cấp phát một vùng nhớ cho con trỏ 
// Nhưng ở đây malloc có thể cấp phát cả một vùng lớn , calloc từng phần , relloc mở rộng thu hẹp được vùng nhớ cụx
// hoặc tạo ra một vùng nhớ khi chưa trỏ đi đâu ,
// new lại có cơ chế như malloc vì vậy ta phải xây dựng một hàm mở rộng thu hẹp riêng;
// 
//2. Tại sao biến con trỏ phải cần quan tâm việc truyền tham chiếu khi thay đổi miền giá trị trong hàm
// Con trỏ là một dạng đặc biệt nó không như biến thường, mảng cũng chỉ là 1 dạng con trỏ ngầm khi chúng ta 
// tạo ra một hàm riêng thì nếu truyền vào đó một con trỏ ở hàm main thì địa chỉ của 2 con trỏ là 1 và khí đó 
// thay một 1 sẽ làm cả 2 thay đổi 
//
#include < iostream>
using namespace std;
void show(int* p, int n);
void enter(int* p, int n);
void change_memory(int*& p, int& old, int new_memory);
void _delete(int*& p, int& n, int location);
void Add(int*& p, int& n, int location, int value);
void final_odd_value(int* p, int n);
void allowable_value(int* p, int n);
int max(int* p, int n);
int min(int* p, int n);
void ascending(int* p, int n);
void merge(int*& p, int*& p2, int& n, int m);
void board()
{
	for (int i = 0; i <20;i++)
	{
		cout << "." << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t." << endl;
	}
	for (int i = 0; i < 80; i++)
	{
		cout << ".";
	}
}
int main()
{
	board();
	//===================MENU TĨNH =======================
	int* p = NULL; int n = 0;
	while (true)
	{
		system("cls");
		cout << "1. Nhap phan tu  " << endl;
		cout << "2.Xuat " << endl;
		cout << "3.Them mot phan tu tu vi tri dang nhap tu ban phim " << endl;
		cout << "4. Xoa 1 phan tu tu vt nhap tu ban phim " << endl;
		cout << "5.Xoa gia tri ma khong nho vi tri " << endl; // xóa giá trị mà mình không nhớ nếu không có thì cout << " Khong co gia tri nay "; 
		cout << "0.Để thoát " << endl;
		//  Trên là bảng hướng dẫn sử dụng 
		int choice; cout << "Enter your choice: " << endl; cin >> choice; // Nhập sự lựa chọn của bạn vào từ bàn phím ( Enter your choice from the keyboard ) 
		switch (choice)
		{
			case 1:
			{
				int count; cout << "\nEnter the count to add : "; cin >> count; //  Nhập số lượng giá trị ban đầu ( số lượng )
				for (int i = 1; i < count; i++)
				{
					int x; cout << "Nhap gia tri thu : " << i << endl; cin >> x;
					Add(p, n, n, x);
				}
				break;
			}
			case 2:
			{
				show(p, n); //  hiển thị ra màn hình 
				system("pause"); // dừng màn hình để hiện thị nếu không sẽ bị câu lệnh break làm mất;
				break;
			}
			case 3:
			{
				if (n == 0)
				{
					cout << " \nYou have not enter the value "; // nếu n = 0  thì cout  ra bạn chưa nhập giá trị 
					system("pause");
					break;
				}
				int count; cout << "\nEnter the count to add"; cin >> count; /// Khai báo và hỏi xem số lượng phần tử mình muốn thêm 
				for (int i = 0; i < count; i++)
				{
					int location; cout << "\nEnter the location to add"; cin >> location; // Nhập vị trị để thêm 
					int value; cout << "\n Enter the value to add"; cin >> value; // Nhập giá trị cần thêm 
					Add(p, n, location, value); // Hàm thêm  
				}
			}
			case 4:
			{
				if (n == 0)
				{
					cout << " \nYou have not enter the value "; // nếu n = 0  thì cout  ra bạn chưa nhập giá trị 
					system("pause");
					break;
				}
				int count; cout << "\nEnter the count to add"; cin >> count; /// Khai báo và hỏi xem số lượng phần tử mình muốn xóa
				for (int i = 0; i < count; i++)
				{
					int location; cout << "\nEnter the location to delete "; ; cin >> location; // Khai báo và yêu cầu nhập vị trí muốn xóa 
					_delete(p, n, location);																			 // hàm xóa
				}
			}
			case 5:
			{
					if(n == 0)
					{
						cout << " \nYou have not enter the value "; // nếu n = 0  thì cout  ra bạn chưa nhập giá trị 
						system("pause");
						break; 
					}
				int value; cout << "Enter the value to delete "; cin >> value; // Nhập giá trị cần xóa ;
				bool check = false ; // khai báo hàm kiểm tra nếu kiểm tra không có giá trị này thì cout << không thể xóa 
					for (int i = 0; i < n; i++)
					{
						if (p[i] == value);
						{
							_delete(p, n, i);
							check = true;
						}
					}
						if (check == false)
						{
							cout << " This value is not available " << endl;
							system("pause");
						}
				break;
			}
		} // vòng switch 
	} // vòng while 
}// main 


	//int n; cout << "Enter to N : " << endl; cin >> n;
	//int m; cout << "Enter to M : " << endl; cin >> m;
	//int* p = new int[n];
//	int* p2 = new int[m];
//	enter(p, n);
	//enter(p2, m);
	//merge(p, p2,n, m);
	//show(p, n);

	/*final_odd_value(p, n);
	allowable_value(p, n);*/
	//ascending(p, n);
	//cout << "\t\t\n===== " << n << " =====" << endl;
	//Add(p, n);
	//show(p, 10);
	//cout << "\t\t\n===== " << n << " =====" << endl;
	//_delete(p, n);
	//show(p, 10);
	//cout << "\t\t\n===== " << n << " =====" << endl;
	//change_memory(p, n, n - 1);
	//show(p, 10);
	//cout << "\t\t\n===== " << n << " =====" << endl;
	//change_memory(p, n, n + 1);
	//show(p, 10);
	//cout << "\t\t\n===== " << n << " =====" << endl;
void merge(int*& p, int*& p2, int& n, int m)
{
	change_memory(p, n, n + m);
	int count = 0;
	for (int i = n; i < n + m; i++)
	{
		p[i] = p2[count];
		count++;
	}
	delete[] p2;

}
void enter(int* p, int n)
{
	cout << "===ENTER VALUE===" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter value " << i << " : " << endl;
		cin >> p[i];
	}
}
void show(int* p, int n)
{
	cout << "===SHOW VALUE=== " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << endl;
	}
}
void Add(int*& p, int& n, int location, int value)
{
	change_memory(p, n, n + 1);
	for (int i = n - 1; i > location; i--)
	{
		p[i] = p[i - 1];
	}
	p[location] = value;
}
void _delete(int*& p, int& n , int location)
{
	for (int i = location; i < n; i++)
	{
		p[i] = p[i + 1];
	}
	change_memory(p, n, n--);
}
void change_memory(int*& p, int& old, int new_memory)
{
	int* temp = p;
	p = new int[new_memory];
	if (old > new_memory)
	{
		for (int i = 0; i < new_memory; i++)
		{
			p[i] = temp[i];
		}
		old -= abs(old - new_memory);
	}
	else
	{
		for (int i = 0; i < old; i++)
		{
			p[i] = temp[i];
		}
		old += abs(old - new_memory);
	}
	delete[] temp;
}
void final_odd_value(int* p, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (p[i] % 2 != 0)
		{
			temp = p[i];
		}
	}
	cout << "final odd value is : " << temp << endl;
}
int max(int* p, int n)
{
	int MAX = p[0];
	for (int i = 1; i < n; i++)
	{
		if (p[i] > MAX)
		{
			MAX = p[i];
		}
	}
	return MAX;
}
int min(int* p, int n)
{
	int MIN = p[0];
	for (int i = 1; i < n; i++)
	{
		if (MIN > p[i])
		{
			MIN = p[i];
		}
	}
	return MIN;
}
void allowable_value(int* p, int n)
{
	cout << "allowable value is :  [ " << max(p, n) << "," << min(p, n) << " ]" << endl;
}
void ascending(int* p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (p[i + 1] < p[i])
		{
			cout << "No ascending  " << endl;
			return;
		}
	}
	cout << " these is ascending " << endl;
}
