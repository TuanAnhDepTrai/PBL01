#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct Student {
    int stt;
    string id;
    string name;
    float markL1;
    float markL2;
    float markPT1;
    float markPT2;
    float markP;
    float markFNT;
    float markAVG = 0;
    string GPA = "-";
};

typedef Student SV;

void printLine(int n);//ham in ra duong ke ngang
void Display(string displayScene);//ham in menu ra man hinh
void CheckInput(SV& sv, int temp);//ham nhap du lieu dau vao
void enterSV(SV a[], int stt, int n);
void updateSVSTT(SV a[], int stt, int n);
void updateSVID(SV a[], string id, int n);
void updateSCORE(SV a[], string id, int n,int tempdiem);
int removebyID(SV a[], string id, int n);
int searchbyNAME(SV a[], char name[], int n);
int searchbyID(SV a[], string id, int n);
void calculateDTB(SV& sv);
void markNumTomarkWord(SV& sv);
int thebiggestSTT(SV a[], int n);
void sortbyDTB(SV a[], int n);
void showStudent(SV a[], int n);
int readFILE(SV a[], char fileName[]);
void writeFILE(SV a[], int n, char fileName[]);
void pressAnyKey();
int flag = 1;
int main() {
    system("COLOR F0");
    char key[MAX]; //bien dieu kien lenh switch
    //dat name cho cac file luu tru diem cac mon hoc
    char fileName1[] = "DataStructure.txt";
    char fileName2[] = "ComputationMethod.txt";
    char fileName3[] = "DiscreteMathematics.txt";
    //khai bao cac mang struct luu tru du lieu 
    SV arraySV1[MAX];
    SV arraySV2[MAX];
    SV arraySV3[MAX];

    int numberOfSV1, numberOfSV2, numberOfSV3;
    numberOfSV1=numberOfSV2=numberOfSV3=0;
    int sttCount1, sttCount2, sttCount3;
    sttCount1=sttCount2=sttCount3=0;

    numberOfSV1 = readFILE(arraySV1, fileName1);
    sttCount1 = thebiggestSTT(arraySV1, numberOfSV1);

    numberOfSV2 = readFILE(arraySV2, fileName2);
    sttCount2 = thebiggestSTT(arraySV2, numberOfSV2);

    numberOfSV3 = readFILE(arraySV3, fileName3);
    sttCount3 = thebiggestSTT(arraySV3, numberOfSV3);
    while (true) {
        flag = 1;
        Display("Display\\MainMenu");
        cout << "Enter your option: ";fflush(stdin);gets(key);
        switch (key[0]) {
        case '1':
            if (atoi(key) == 1){
                system("cls");  
                while (flag){
                    cout << "YOU HAVE CHOOSE THE FUNCTION TO IMPORT ALL STUDENT MARKS!\n";
                    Display("Display\\SubjectMenu");
                    char index1[MAX];
                    cout << "Enter your option: "; fflush(stdin);gets(index1);
                    if (strlen(index1) > 1) strcpy(index1,"4");
                    switch(index1[0]) {
                    case '1':
                        cout << "ENTER DATA STRUCTURE MARK!\n";
                        for (int i = 1; i <= numberOfSV1; i++) {
                            updateSVSTT(arraySV1, i, numberOfSV1);
                        }
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "ENTER COMPUTATION METHOD MARK!\n";
                        for (int i = 1; i <= numberOfSV2; i++) {
                            updateSVSTT(arraySV2, i, numberOfSV2);
                        }
                        pressAnyKey();
                        break;
                    case '3':
                    cout << "ENTER DISCRETE MATHEMATICS MARK!\n";
                        for (int i = 1; i <= numberOfSV3; i++) {
                            updateSVSTT(arraySV3, i, numberOfSV3);
                        }
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                    }
                } 
            }
            if(atoi(key) == 10) {
                if (numberOfSV1 > 0) {
                    writeFILE(arraySV1, numberOfSV1, fileName1);
                    printf("\nWrite to file %s successfully!", fileName1);
                }
                else printf("\nStudent list in file %s is empty!", fileName1);

                if (numberOfSV2 > 0) {
                    writeFILE(arraySV2, numberOfSV2, fileName2);
                    printf("\nWrite to file %s successfully!", fileName2);
                }
                else printf("\nStudent list in file %s is empty!", fileName2);

                if (numberOfSV3 > 0) {
                    writeFILE(arraySV3, numberOfSV3, fileName3);
                    printf("\nWrite to file %s successfully!", fileName3);
                }
                else printf("\nStudent list in file %s is empty!", fileName3);
                pressAnyKey();
                break;
            }
        cout << "\nWrong choice please choose again!";
        pressAnyKey();
        break;
        case '2':
            system("cls");
            while(flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO ENTER MARKS BY STUDENT ID!\n";
                Display("Display\\SubjectMenu");
                string temp1;
                char index2[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index2);
                if (strlen(index2) > 1) strcpy(index2,"4");
                switch(index2[0]){
                    case '1':
                        cout << "ENTER DATA STRUCTURE MARK!\n";
                        cout << "Enter student ID you want to enter marks: "; cin >> temp1;
                        updateSVID(arraySV1,temp1,numberOfSV1);
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "ENTER COMPUTATION METHOD MARK!\n";
                        cout << "Enter student ID you want to enter marks: "; cin >> temp1;
                        updateSVID(arraySV2,temp1,numberOfSV2);
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "ENTER DISCRETE MATHEMATICS MARK!\n";
                        cout << "Enter student ID you want to enter marks: "; cin >> temp1;
                        updateSVID(arraySV3,temp1,numberOfSV3);
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;  
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
            }
        break;
        case '3':
            system("cls");
            while(flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO VIEW MARKS BY STUDENT'S ID!\n";
                Display("Display\\SubjectMenu");
                string temp2;
                char index3[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index3);
                if (strlen(index3) > 1) strcpy(index3,"4");
                switch(index3[0]){
                    case '1':
                        cout << "VIEW DATA STRUCTURE MARKS!\n";
                        cout << "Enter the student ID you want to view the mark: "; cin >> temp2;
                        searchbyID(arraySV1, temp2, numberOfSV1);
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "VIEW COMPUTATION METHOD MARKS!\n";
                        cout << "Enter the student ID you want to view the mark: "; cin >> temp2;
                        searchbyID(arraySV2, temp2, numberOfSV2);
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "VIEW DISCRETE MATHEMATICS MARKS!\n";
                        cout << "Enter the student ID you want to view the mark: "; cin >> temp2;
                        searchbyID(arraySV3, temp2, numberOfSV3);
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
            }
        break;
        case '4':
            system("cls");
            while(flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO EDIT MARKS BY STUDENT ID!\n";
                int flag1 = 1;
                Display("Display\\SubjectMenu");
                string temp3;
                char index4[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index4);
                if (strlen(index4) > 1) strcpy(index4,"4");
                switch(index4[0]){  
                    case '1':
                        cout << "Enter the student ID you want to edit Data Structure marks: "; cin >> temp3;
                        cout << "\nThis is marks before edit!\n";
                        searchbyID(arraySV1, temp3, numberOfSV1);
                        pressAnyKey();
                        system("cls");
                        while (flag1) {
                            Display("Display\\MarkMenu");
                            char i1[MAX];
                            cout << "Enter your option: ";fflush(stdin);gets(i1);
                            switch (i1[0]) {
                                case '1':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,1);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '2':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,2);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '3':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,3);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '4':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,4);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    flag1=0;
                                    pressAnyKey();
                                    break;
                                case '5':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,5);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '6':
                                    updateSCORE(arraySV1, temp3, numberOfSV1,6);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV1, temp3, numberOfSV1);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '0':
                                    cout << "\nRETURN TO MAIN MENU!\n";
                                    flag1 = 0;
                                    pressAnyKey();
                                    break;
                                default:
                                    cout << "\nWrong choice please choose again!";
                                    pressAnyKey();
                                    break;
                            }
                    }
                    break;
                    case '2':
                        cout << "Enter the student ID you want to edit Computation Method marks: "; cin >> temp3;
                        cout << "\nThis is marks before edit!\n";
                        searchbyID(arraySV2, temp3, numberOfSV2);
                        pressAnyKey();
                        system("cls");
                        while (flag1) {
                            Display("Display\\MarkMenu");
                            char i1[MAX];
                            cout << "Enter your option: ";fflush(stdin);gets(i1);
                            switch (i1[0]) {
                                case '1':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,1);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '2':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,2);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '3':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,3);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '4':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,4);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '5':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,5);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '6':
                                    updateSCORE(arraySV2, temp3, numberOfSV2,6);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV2, temp3, numberOfSV2);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '0':
                                    cout << "\nRETURN TO MAIN MENU!\n";
                                    flag = 0;
                                    pressAnyKey();
                                    break;
                                default:
                                    cout << "\nWrong choice please choose again!";
                                    pressAnyKey();
                                    break;
                            }
                    }
                    case '3':
                        cout << "Enter the student ID you want to edit Discrete Mathematics mark: "; cin >> temp3;
                        cout << "\nThis is marks before edit!\n";
                        searchbyID(arraySV3, temp3, numberOfSV3);
                        pressAnyKey();
                        system("cls");
                        while (flag1) {
                            Display("Display\\MarkMenu");
                            char i1[MAX];
                            cout << "Enter your option: ";fflush(stdin);gets(i1);
                            switch (i1[0]) {
                                case '1':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,1);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '2':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,2);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '3':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,3);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '4':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,4);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '5':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,5);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '6':
                                    updateSCORE(arraySV3, temp3, numberOfSV3,6);
                                    system("cls");
                                    cout << "Successful mark correction, This is marks after edit!\n";
                                    searchbyID(arraySV3, temp3, numberOfSV3);
                                    cout<<endl;
                                    pressAnyKey();
                                    break;
                                case '0':
                                    cout << "\nRETURN TO MAIN MENU!\n";
                                    flag1 = 0;
                                    pressAnyKey();
                                    break;
                                default:
                                    cout << "\nWrong choice please choose again!";
                                    pressAnyKey();
                                    break;
                            }
                    }
                    break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
                break;
            }
        break;
        case '5':
            system("cls");
            while(flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO SORT BY AVERAGE MARK (GPA)!\n";
                Display("Display\\SubjectMenu");
                char index5[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index5);
                if (strlen(index5) > 1) strcpy(index5,"4");
                switch(index5[0]){
                    case '1':
                        if (numberOfSV1 > 0) {
                            cout << "Sort Data Structure average mark!\n";
                            sortbyDTB(arraySV1, numberOfSV1);
                            showStudent(arraySV1, numberOfSV1);
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "Sort Computation Method average mark!\n";
                        if (numberOfSV2 > 0) {
                            sortbyDTB(arraySV2, numberOfSV2);
                            showStudent(arraySV2, numberOfSV2);
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "Sort Discrete Mathematics average mark!\n";
                        if (numberOfSV3 > 0) {
                            sortbyDTB(arraySV3, numberOfSV3);
                            showStudent(arraySV3, numberOfSV3);
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
            }
        break;
        case '6':
            system("cls");
            while (flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO VIEW ALL STUDENT'S MARKS!\n";
                Display("Display\\SubjectMenu");
                char index6[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index6);
                if (strlen(index6) > 1) strcpy(index6,"4");
                switch (index6[0]){
                    case '1':
                        cout << "Data Structure marks list!\n";
                        if (numberOfSV1 > 0) showStudent(arraySV1, numberOfSV1);
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "Computation Method marks list!\n";
                        if (numberOfSV2 > 0) showStudent(arraySV2, numberOfSV2);
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "Discrete Mathematics marks list!\n";
                        if (numberOfSV3 > 0) showStudent(arraySV3, numberOfSV3);
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                    }
                }
        break;
        case '7':
            system("cls");
            while (flag) {
                cout << "YOU HAVE CHOOSE FUNCTION ADD NEW STUDENT!\n";
                Display("Display\\SubjectMenu");
                char index7[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index7);
                if (strlen(index7) > 1) strcpy(index7,"4");
                switch (index7[0]){
                    case '1':
                        cout << "\nAdd new student to Data Structure!\n";
                        sttCount1++;
                        enterSV(arraySV1, sttCount1, numberOfSV1);   
                        cout << "\nAdd new student successful!";
                        numberOfSV1++;
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "\nAdd new student to Computation Method!\n";
                        sttCount2++;
                        enterSV(arraySV2, sttCount2, numberOfSV2);
                        cout << "\nAdd new student successful!";
                        numberOfSV2++;
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "\nAdd new student to Discrete Mathematics!\n";
                        sttCount3++;
                        enterSV(arraySV3, sttCount3, numberOfSV3);
                        cout << "\nAdd new student successful!";
                        numberOfSV3++;
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
            }
        break;
        case '8':
            system("cls");
            while (flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO REMOVE STUDENT BY ID!\n";
                Display("Display\\SubjectMenu");
                string index9;
                char index8[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index8);
                if (strlen(index8) > 1) strcpy(index8,"4");
                switch (index8[0]){
                    case '1':
                        cout << "Remove student from Data Structure!\n";
                        if(numberOfSV1 > 0) {
                        cout << "\n Enter the student's ID you want to remove: "; cin >> index9;
                        if (removebyID(arraySV1, index9, numberOfSV1) == 1) {
                            numberOfSV1--;
                            }
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "Remove student from Computation Method!\n";
                        if(numberOfSV2 > 0) {
                        cout << "\n Enter the student's ID you want to remove: "; cin >> index9;
                        if (removebyID(arraySV2, index9, numberOfSV2) == 1) {
                            numberOfSV2--;
                            }
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "Remove student from Discrete Mathematics!\n";
                        if(numberOfSV3 > 0) {
                        cout << "\n Enter the student's ID you want to remove: "; cin >> index9;
                        if (removebyID(arraySV3, index9, numberOfSV3) == 1) {
                            numberOfSV3--;
                            }
                        }
                        else cout << "\nStudent list is empty!";
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        pressAnyKey();
                        break;
                }
            }
        break;
        case '9':
            system("cls");
            while(flag){
                cout << "YOU HAVE CHOOSE FUNCTION TO VIEW MARKS BY STUDENT'S NAME!\n";
                Display("Display\\SubjectMenu");
                char temp2[MAX];
                char index9[MAX];
                cout << "Enter your option: ";fflush(stdin);gets(index9);
                if (strlen(index9) > 1) strcpy(index9,"9");
                switch(index9[0]){
                    case '1':
                        cout << "VIEW DATA STRUCTURE MARKS!\n";
                        cout << "Enter the student's name you want to view the mark: "; fflush(stdin);gets(temp2);fflush(stdin);
                        searchbyNAME(arraySV1, temp2, numberOfSV1);
                        pressAnyKey();
                        break;
                    case '2':
                        cout << "VIEW COMPUTATION METHOD MARKS!\n";
                        cout << "Enter the student's name you want to view the mark: "; fflush(stdin);gets(temp2);fflush(stdin);
                        searchbyNAME(arraySV2, temp2, numberOfSV2);
                        pressAnyKey();
                        break;
                    case '3':
                        cout << "VIEW DISCRETE MATHEMATICS MARKS!\n";
                        cout << "Enter the student'name you want to view the mark: "; fflush(stdin);gets(temp2);fflush(stdin);
                        searchbyNAME(arraySV3, temp2, numberOfSV3);
                        pressAnyKey();
                        break;
                    case '0':
                        cout << "\nRETURN TO MAIN MENU!\n";
                        flag = 0;
                        pressAnyKey();
                        break;
                    default:
                        cout << "\nWrong choice please choose again!";
                        break;
                }
            }
        break;
        case '0':
            cout << "\nYou have chosen to exit the program!\n";
            _getwch();
            return 0;
        default:
            cout << "\nWrong choice please choose again!";
            pressAnyKey();
            break;
            }
        }
    }

void Display(string displayScene) {
    ifstream f;
    f.open(displayScene);
    if(!f)
        cout << "Failed to find file " << displayScene << "!\n";
    string line;
    while(getline(f, line))
        cout << line << endl;
}

void printLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
}
void CheckInput(SV& sv, int stt, int tempdiem) {
    int key=0;  
    while (!key){
        switch (tempdiem){
            case 1:
                cout << "Enter student ID: ";
                break;
            case 2:
                cout << "Enter student name: ";
                break;
            case 3:
                cout << "Enter Lab1 mark: ";
                break;
            case 4:
                cout << "Enter Lab2 mark: ";
                break;
            case 5:
                cout << "Enter Progress Test 1 mark: ";
                break;
            case 6:
                cout << "Enter Progress Test 2 mark: ";
                break;
            case 7:
                cout << "Enter Presentation mark: ";
                break;
            case 8:
                cout << "Enter Final Test mark: ";
                break;
            default:
                cout << "ERROR";
                break;
        } 
        if (tempdiem != 1 && tempdiem != 2){
            char input[100000]; 
            fflush(stdin);
            cin.getline(input, 100000);
            fflush(stdin);
            int len = strlen(input);
            while (true) {
                int temp = 0, len = strlen(input);
                int demc = 0; // Bien dem dau cham
                //TH1: Dau cham nam dau
                if(input[0] == 46) {
                    key = 0;
                    break;
                }
                //kiem tra xem input co phai la so hoac la dau cham hay khong, dem dau cham
                for (int i = 0; i < len; i++){
                    if (input[i] >= 48 && input[i] <= 57 || input[i] == 46) {
                        temp = 0;
                        if( input[i] == 46 ) demc++;
                    }
                    else{
                        temp = 1;
                        break;
                    }
                }
                //neu input dung thi check no la loai diem gi
                if (temp == 0){
                    float diem1 = atof(input);
                    switch (tempdiem){
                        case 3:
                            sv.markL1 = diem1;
                            break;
                        case 4:
                            sv.markL2 = diem1;
                            break;
                        case 5:
                            sv.markPT1 = diem1;
                            break;
                        case 6:
                            sv.markPT2 = diem1;
                            break;
                        case 7:
                            sv.markP = diem1;
                            break;
                        case 8:
                            sv.markFNT = diem1;
                            break;
                        default:
                            cout << "ERROR";
                            break;
                    }
                    //kiem tra xem co bao nhieu dau cham, co nam trong khoang 0-10 hay khong
                    if( diem1 > 10 || diem1 < 0 || demc == len||demc > 1) key = 0;
                    else  key = 1;
                }
                    //break;
                if(key) break;
                else {
                    cout << "Please enter between 0 - 10 !\n";
                    break;
                }
            }
        }
        else if (tempdiem == 2) {
            fflush(stdin);
            getline(cin,sv.name);
            fflush(stdin);
            key=1;
        }
        else {
            fflush(stdin);
            getline(cin,sv.id);
            fflush(stdin);
            key=1;
        }
    }
    sv.stt = stt;
    calculateDTB(sv);
    markNumTomarkWord(sv);
}

void enterSV(SV a[], int stt, int n) {
    printLine(40);
    printf("\nEnter the %dth student: \n", n + 1);
    for (int j = 1;j <= 8; j++){
        CheckInput(a[n], stt, j);
    }
    printLine(40);
}

void updateSVSTT(SV a[], int stt, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].stt == stt) {
            found = 1;
            printLine(40);
            cout << "\n Enter " << a[i].name <<"'s mark" << endl;
            for (int j = 3;j <= 8; j++){
                CheckInput(a[i], stt, j);
            }
            break;
        }
    }
    if (found == 0) {
        printf("\nStudent ID = %d do not exist.", stt);
    }
    else {
        cout << "\nMark entry successfully!\n";
    }
}

void updateSVID(SV a[], string id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Enter " << a[i].name <<"'s mark" << endl;
            for (int j = 3;j <= 8; j++){
                CheckInput(a[i], i, j);
            }
            break;
        }
    }
    if (found == 0) {
        printf("\nStudent ID = %s do not exist.", id.c_str());
    }
    else {
        cout << "\nMark entry successfully!\n";
    }
}

void updateSCORE(SV a[], string id, int n, int tempdiem) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            switch(tempdiem){
                case 1:
                    cout << "\nEdit " << a[i].name << "'s Lab1 mark" << endl;
                    CheckInput(a[i], i, 3);
                    break;
                case 2:
                    cout << "\nEdit " << a[i].name << "'s Lab2 mark" << endl;
                    CheckInput(a[i], i, 4);
                    break;
                case 3:
                    cout << "\nEdit " << a[i].name << "'s Progress Test 1 mark" << endl;
                    CheckInput(a[i], i, 5);
                    break;
                case 4:
                    cout << "\nEdit " << a[i].name << "'s Progress Test 2 mark" << endl;
                    CheckInput(a[i], i, 6);
                    break;
                case 5:
                    cout << "\nEdit " << a[i].name << "'s Presentation" << endl;
                    CheckInput(a[i], i, 7);
                    break;
                case 6:
                    cout << "\nEdit " << a[i].name << "'s Final Test mark" << endl;
                    CheckInput(a[i], i, 8);
                    break;
                default:
                    cout << "ERROR!\n";
                    break;
            }
            break;
        }
    }
    if (found == 0) {
        printf("\nStudent ID = %s do not exist.", id.c_str());
    }
}

int removebyID(SV a[], string id, int n) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\nStudent ID = %s do not exist.", id.c_str());
        return 0;
    } else {
        printf("\nStudent ID = %s deleted", id.c_str());
        return 1;
    }
}

int searchbyNAME(SV a[], char name[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].name.c_str());
        if(strstr(strupr(tenSV), strupr(name))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    if (found == 0) {
        printf("\nStudent %s do not exist.", name);
        return 0;
    }
    else {
        showStudent(arrayFound, found);
        return 1;
    }
}

int searchbyID(SV a[], string id, int n) {
    SV arrayFound[MAX];
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            arrayFound[found] = a[i];
            found++;
            showStudent(arrayFound, found);
            break;
        }
    }
    if (found == 0) {
        printf("\nStudent ID = %s do not exist.", id.c_str());
        return 0;
    }
    else {
        return 1;
    }
}

void calculateDTB(SV& sv) {
    sv.markAVG = sv.markL1*0.1 + sv.markL2*0.1 + sv.markPT1*0.1 + sv.markPT2*0.1 + sv.markP*0.1 + sv.markFNT*0.5;
}

void markNumTomarkWord(SV& sv) {
    if (sv.markAVG < 4.0) sv.GPA = "F";
    else if (sv.markAVG >= 4.0 && sv.markAVG < 5.5) sv.GPA = "D";
    else if (sv.markAVG >= 5.5 && sv.markAVG < 7.0) sv.GPA = "C";
    else if (sv.markAVG >= 7.0 && sv.markAVG < 8.5) sv.GPA = "B";
    else if (sv.markAVG >= 8.5 && sv.markAVG <= 10.0) sv.GPA = "A";
    else sv.GPA = "error";
}

int thebiggestSTT(SV a[], int n) {
    //tim sinh vien co stt lon nhat
    int sttMax = 0;
    if (n > 0) {
        sttMax = a[0].stt;
        for (int i = 0; i < n; i++) {
            if (a[i].stt > sttMax) {
                sttMax = a[i].stt;
            }
        }
    }
    return sttMax;
}

void sortbyDTB(SV a[], int n) {
    //Sap xep theo DTB giam dan
    SV tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].markAVG < a[j].markAVG) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void showStudent(SV a[], int n) {
    printLine(130);
    printf("\n");
    printf("\n%6s%12s%20s%10s%10s%9s%10s%9s%11s%14s%13s","STT","MSSV","FULL NAME","Lab1","Lab2","PT1","PT2","P","FNT","AVG MARK","GPA");
    printf("\n\n");
    printLine(130); 
    printf("\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("%5d%15s%20s%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%10.2f%13s\n",a[i].stt, a[i].id.c_str(), a[i].name.c_str(), a[i].markL1, a[i].markL2, a[i].markPT1, a[i].markPT2, a[i].markP, a[i].markFNT, a[i].markAVG, a[i].GPA.c_str());
    }
    printLine(130);
}

int readFILE(SV a[], char fileName[]) {
    //Khai báo vector để lưu các dòng đọc được
    vector<string> lines;
    string line;
    //Mở file bằng ifstream
    ifstream input_file(fileName);
    //Kiểm tra file đã mở thành công chưa
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << fileName << " " << endl;
        return EXIT_FAILURE;
    }
    //Đọc từng dòng trong
    while (getline(input_file, line)){
        lines.push_back(line);//Lưu từng dòng như một phần tử vào vector lines.
    }
    int i = 0;
    for (int j = 0; j < lines.size(); j+=11){
        a[i].stt = stoi (lines[j]);
        a[i].id = lines [j+1];
        a[i].name = lines[j+2];
        a[i].markL1 = stof (lines[j+3]);
        a[i].markL2 = stof (lines[j+4]);
        a[i].markPT1 = stof (lines[j+5]);
        a[i].markPT2 = stof (lines[j+6]);
        a[i].markP = stof (lines[j+7]);
        a[i].markFNT = stof (lines[j+8]);
        a[i].markAVG = stof (lines[j+9]);   
        a[i].GPA = lines[j+10];
        i++;
    }
    cout << "Number of students in "<<fileName<<" is: "<< i << endl;
    //Đóng file
    input_file.close();
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}

void writeFILE(SV a[], int n, char fileName[]) {
    FILE* fp;
    fp = fopen(fileName, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp,"%d\n%s\n%s\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%s\n", a[i].stt, a[i].id.c_str(), a[i].name.c_str(),a[i].markL1, a[i].markL2, a[i].markPT1, a[i].markPT2, a[i].markP, a[i].markFNT, a[i].markAVG, a[i].GPA.c_str());
    }
    fclose(fp);
}

void pressAnyKey() {
    cout << "\n\nPress any key to continue...";
    _getwch();
    system("cls");
}