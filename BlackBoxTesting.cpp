#include <iostream>
using namespace std;
 
// Hàm kiểm tra năm nhuận
bool isLeapYear(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        return true;
    }
    return false;
}
 
// Hàm trả về số ngày trong tháng thuộc năm cho trước
int numOfDayInMonth(int nMonth, int nYear)
{
    int nNumOfDays;
    switch (nMonth)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
nNumOfDays = 31;
break;
        case 4: case 6: case 9: case 11:
nNumOfDays = 30;
break;
        case 2:
            if (isLeapYear(nYear))
            {
                nNumOfDays = 29;
            } else {
                nNumOfDays = 28;
            }
        	break;
    }
    return nNumOfDays;
}
 
// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool isValidDate(int nDay, int nMonth, int nYear)
{
    if (nYear < 0)
    {
        return false;
    }
    if (nMonth < 1 || nMonth > 12)
    {
        return false;
    }
    if (nDay < 1 || nDay > numOfDayInMonth(nMonth, nYear))
    {
        return false;
    }
 
    return true;
}
 
 
int main()
{
    int nDay, nMonth, nYear;
    cout << "Day, Month, Year: ";
    cin >> nDay >> nMonth >> nYear;
 
    if (isValidDate(nDay, nMonth, nYear))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
