#include <iostream>
#include <conio.h> //this header is needed to use _getch()
#include<windows.h>
#include<string.h>
#include<fstream>
//importing c library in cpp
using namespace std;

int main () {
   
    //further can be modified for zero marks also;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,12);    
    cout<<"\t\tScore calculator with Minus marking"<<endl;
    SetConsoleTextAttribute(h,7);    
    
    //Declaring required variables 
    char PositiveSYMBOL, NegativeSYMBOL ,Input ;
    int PositiveMARKS=0 , NegativeMARKS=0;
    int TotalMarks=0;
    int positiveNO=0,NegativeNo=0;

    cout<<"Enter Positive number to be alloted: ";
    cin>>PositiveMARKS;
    cout<<"Enter Negative number to be alloted: ";
    cin>>NegativeMARKS;
    cout<<"Enter keyboard Symbol for positive marks: ";
    cin>>PositiveSYMBOL;
    cout<<"Enter keyboard Symbol for negative marks: ";
    cin>>NegativeSYMBOL;
    cout<<"Marks calculations starts";
    Sleep(500);
    system("CLS");
ReRun:
    cout<<"ENTER \'0\' AFTER COMPLETION"<<endl;
    int iterator=0;
    do
    {
        iterator++;
        cout<<"Enter ";
        Input = _getch();
        cout<<iterator<<" ";
        if (Input==PositiveSYMBOL)
        {
            positiveNO++;
            TotalMarks=TotalMarks+PositiveMARKS;
        }
        else if (Input==NegativeSYMBOL)
        {
            NegativeNo++;
            TotalMarks=TotalMarks-NegativeMARKS;
        }
        else if (Input=='0')
        {
            cout<<endl;
            cout<<endl;
            printf("total atempted question: %d\n",positiveNO+NegativeNo);
            printf("right question: %d\n",positiveNO);
            printf("Wrong question: %d\n",NegativeNo);
            printf("%d - %d\n",positiveNO*4,NegativeNo);
            cout<<"Total marks are: "<<TotalMarks;
            cout<<endl;
            //creation of file and updating data there 
            ofstream f;
            // f.open("data.txt",ios::in|ios::out);
            f.open("data.txt",std::ios_base::app);//append code 
            f<<positiveNO+NegativeNo<<"\t"<<positiveNO<<"\t"<<NegativeNo<<"\t"<<positiveNO*4<<"-"<<NegativeNo<<"  \t"<<TotalMarks<<"\n";
            
            cout<<"\n1: ReRun for same student differnt section;\n2: ReRun for different student;\n0: End code\nEnter your choice: ";
            char falana;
            falana = _getch();
            if (falana=='1')
            {
                f.close();
                TotalMarks=0; positiveNO=0, NegativeNo=0;  
                cout<<endl;
                goto ReRun;
            }
            else if (falana=='2')
            {
                // string blank="student changed";
                f<<"\n";
                f.close();
                TotalMarks=0; positiveNO=0, NegativeNo=0;
                cout<<endl;  
                system("CLS");
                goto ReRun;
            }
            else if (falana=='0')
            {
		f<<"\n";
                f.close();
                exit(0);
            }
        }
	else
        {
            cout<<"WRONG INPUT :< ";
	    cout<<"PRESS \""<<PositiveSYMBOL<<"\" OR \""<<NegativeSYMBOL<<"\"";
        }
        cout<<endl;

    } while (Input!=0);
	return 0;
}
