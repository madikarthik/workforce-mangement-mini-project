#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>

#include "title.h"
using namespace std;

//FUNCTION PROTOTYPES
void FeedInfo(); //Creates CompanyWorkforce.txt AND parameters file(NO NEED TO UPDATA)
void UpdateWorkforce();//Used to update in a single run if any additions to team or teams of a company
void ProgramMenu(); //Basic Structure of the project
void Login(); // 1st module of the project
void CEOLogin(); // Used when CEO successfully logins
void AddATeam(); //Used by CEO to add a team
void DeleteATeam(); //Used to remove a team from the Analysis Program
void CompanyPAAM(); // used in CEOLogin
void TeamHeadLogin(string whichteam); // Used when Team Head Logins
void EnterCredits(string teamname); // used in Team Head Login
void TeamPAAM(string teamname); // used in Team Head Login
void BehaviorEval(string teamname); //used in Team Head Login
//void ChangePassword(string teamname); // Team Head can change password
void searchforemp(int id);//Used by CEO
string idtoname(int id);



//CLASSES
//Class 1
//Comments Needed
class Node
{
public:
    int roll; //Comments Needed
    float crr; //Comments Needed
    Node* next; //Comments Needed
};

//Class 2
//Comments Needed
class LinkedList
{
private:
    Node* first; //Comments Needed
    int listsize; //Comments Needed

public:
    //Comments Needed
    LinkedList()
    {
        first = NULL;
        listsize = 0;
    }

    //Comments Needed
    void insertt(int xx,float yy)
    {
        int added = 0;
        Node* p = new Node;
        p->roll = xx;
        p->crr = yy;

        if(first == NULL){
            first = p;
            p->next = NULL;
        }else
        {
            Node* temp = first;
            Node* temp1 = NULL;

            while(temp!=NULL){

                if(p->crr < temp->crr){
                    temp1 = temp;
                    temp = temp->next;
                }else
                {
                    //design this
                    p->next = temp;
                    if(temp==first){
                        first = p;
                    }else
                    {
                        temp1->next = p;
                    }
                    added = 1;
                    break;
                }


            }

            // If the p node comes to the end of the list then it will be credited with addresses
            if(added == 0){
                p->next = NULL;
                temp1->next = p;
            }

        }

    }

    //Comments Needed
    void sendlltofile(string tn)
    {
        //Creating Stream
        string lname = tn + "Analysis" +".txt";
        int n = lname.length();
        char faaname[n+1];
        strcpy(faaname, lname.c_str());
        ofstream ohfile(faaname);
        //Stream Created ohfile

        Node* temp = first;
        while(temp!=NULL){
            ohfile << temp->roll << " " << temp->crr << endl;
            temp = temp->next;
        }

    }
};



//FUNCTIONS
//Comments Needed
void FeedInfo()
{
    ofstream ceoconfidential("CEOConfidential.txt");
    ceoconfidential << "MJCEO" << " " << 3142 << endl;
    ceoconfidential.close();

    // Comments needed
    //This is to generate CompanyWorkforce.txt file as to conduct all the members information in same one file
    //This powerful code will also integrate every new team members in CompanyTeams.txt with CompanyWorkforce.txt file
    ifstream getteams("CompanyTeams.txt");
    string teamname;

    // Cleans off the previous code because the file needs to be opened in Append mode
    ofstream cleanprevious("CompanyWorkforce.txt");
    cleanprevious.close();
    // Fresh file CompanyWorkforce.txt is ready without any data in it

    while(getteams >> teamname){

        string fname = teamname + ".txt";
        int n = fname.length();
        char filename[n+1];
        strcpy(filename, fname.c_str());
        ifstream givemembers(filename);
        int number;
        string empname;

        //Opening a file in append mode and this file is just cleaned by above 2 lines
        ofstream feedme("CompanyWorkforce.txt", ios::app);

        while(givemembers >> number >> empname){

            feedme << number << " " << empname << " " << teamname << endl;

        }

        feedme.close();

    }
    getteams.close();
    // File created for the first time in a run with the name CompanyWorkforce.txt

    //Following are the parameters by which most of the US Commercial Companies use to tally their performance
    ofstream parameters("Parameters.txt");
    parameters << "Control" << endl;
    parameters << "Social_Influence" << endl;
    parameters << "Patience" << endl;
    parameters << "Precision" << endl;
    parameters << "Ambition" << endl;
    parameters << "Positive_Expectancy" << endl;
    parameters << "Composure" << endl;
    parameters << "Analytical" << endl;
    parameters << "Results_Orientation" << endl;
    parameters << "Expressiveness" << endl;
    parameters << "Team_Player" << endl;
    parameters << "Quality_Orientation" << endl;
    parameters.close();
}

//Comments Needed
void UpdateWorkforce()
{
    ifstream getteams("CompanyTeams.txt");
    string teamname;

    // Cleans off the previous code because the file needs to be opened in Append mode
    ofstream cleanprevious("CompanyWorkforce.txt");
    cleanprevious.close();
    // Fresh file CompanyWorkforce.txt is ready without any data in it

    while(getteams >> teamname){

        string fname = teamname + ".txt";
        int n = fname.length();
        char filename[n+1];
        strcpy(filename, fname.c_str());
        ifstream givemembers(filename);
        int number;
        string empname;


        //Opening a file in append mode and this file is just cleaned by above 2 lines
        ofstream feedme("CompanyWorkforce.txt", ios::app);

        while(givemembers >> number >> empname){

            feedme << number << " " << empname << " " << teamname << endl;

        }

        feedme.close();

    }
    getteams.close();
}

//Comments needed
string idtoname(int id)
{
    UpdateWorkforce();

    ifstream getname("CompanyWorkforce.txt");
    int empid;
    string empname;
    string empteam;
    while(getname >> empid >> empname >> empteam){
        if(empid == id){
            break;
        }
    }

    return empname;

}

//Comments Needed
void ProgramMenu()
{
    int menuchoice;
    int exitprogram = 0;

    while(exitprogram == 0){
        system("cls"); // clears screen for this menu and displays neat
        tmain();
        cout << "\t\t1. Login \n\t\t2. About \n\t\t3. Exit\n" << endl;
        cout << " Please enter your choice: ";

        cin >> menuchoice;

        switch(menuchoice)
        {
        case 1:{
            Login();
            break;
        }
        case 2:{
            system("cls");
            cout << "---------" << endl;
            cout << "| ABOUT |" << endl;
            cout << "---------" << endl;
            string about;
            ifstream myfile ("About.txt");
            if (myfile.is_open())
            {
                while ( getline (myfile,about) )
                {
                    cout << about << '\n';
                }
                myfile.close();
            }
            int hahaha;
            cout << endl;
            cout << "Press 1 to return back to MENU: ";
            cin >> hahaha;
            break;
        }
        case 3:{
            exitprogram++;
            break;
        }
        default:{
            cout << "The choice you entered is INVALID." << endl;
            cout << "TRY AGAIN" << endl;
            break;
        }
        }
    }
}

//Comments Needed
void Login() // Flow from ProgramMenu() to WhoIsIt()
{
    string username;
    long int password;
    string un;
    long int pwd;

    passwordretry:
    system("cls"); // Clears screen and system method is from stdlib.h
    tlogin();
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream ceoconfi("CEOConfidential.txt");
    string us;
    int pw;
    ceoconfi >> us >> pw;
    if((username == us) && (password == pw)){
        CEOLogin();
    }else{
            ifstream infile;
            infile.open("Confidential.txt");

            int usemetoretry = 0;
            //Scans Confidential.txt for a perfect combination
            while(infile >> un >> pwd){
                if((username == un) && (password == pwd)){
                    cout << "Login Successful" << endl;
                    usemetoretry++; //Increments not to retry and to confirm successful login.
                    TeamHeadLogin(username);
                    break;
                }
            }
            infile.close();
            // The below block of code will be used to perform RETRY prompts
            if(usemetoretry == 0){
                char wannaretry;
                cout << "You've Entered wrong Credentials. Want to RETRY? (Y/N): ";
                cin >> wannaretry;
                if(wannaretry == 'y' || wannaretry == 'Y'){
                    goto passwordretry;
                }
            }
    }

}

//Comments Needed
void CEOLogin()
{
    int choice;
    int endthis = 0;

    while(endthis == 0){

        system("cls"); // clears screen and displays only the following
        tceo();
        cout << "1. Company Workforce Details" << endl;
        cout << "2. P.A.A.M Analysis" << endl;
        cout << "3. Add a Team" << endl;
        cout << "4. Delete Team" << endl;
        cout << "5. Search for an Employee" << endl;
        cout << "6. Guide" << endl;
        cout << "7. Logout" << endl;
        cout << "\nPlease enter your choose: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                UpdateWorkforce();
                    system("cls");

                    ifstream getcompanynames("CompanyTeams.txt");
                    string teamnames;

                    txyz();
                    while(getcompanynames >> teamnames){

                        // Conversion Begins
                        string tname = teamnames + ".txt";
                        int n = tname.length();
                        char teamname[n+1];
                        strcpy(teamname, tname.c_str());
                        // Conversion Ends
                        ifstream teamfetch(teamname);
                        int empid;
                        string empname;

                        cout << setw(3)<< "Team Name: " << teamnames << endl;
                        cout << setw(3) << "ID" << "\tName" << endl;
                        while(teamfetch >> empid >> empname){

                            cout << setw(3) << empid << "\t" << empname << endl;

                        }
                        cout << " " << endl;

                        teamfetch.close();

                    }

                    int hahaha;
                    cout << "\nPress 1 to return to MAIN MENU: ";
                    cin >> hahaha;
            }

        break;

        case 2:
            {
                system("cls");
                CompanyPAAM();
            }

            break;

        case 3:
            {
                system("cls");
                AddATeam();
            }

            break;

        case 4:
            {
               system("cls");
               DeleteATeam();
               getch();
            }

            break;

        case 5:
            {
                int dothis = 0;
                char retry;
                while(dothis == 0){
                    system("cls");
                    int aaidee;
                    cout << "\nEnter the Employee ID: ";
                    cin >> aaidee;
                    searchforemp(aaidee);
                    cout << "Do you want to make another Search? (Y/N): ";
                    cin >> retry;

                    if(retry == 'N' || retry == 'n'){
                        dothis = 1;
                    }
                }

            }

            break;

        case 6:
            {
                system("cls");
                cout << "---------" << endl;
            cout << "| Guide |" << endl;
            cout << "---------" << endl;
            string about;
            ifstream myfile ("Guide.txt");
            if (myfile.is_open())
            {
                while ( getline (myfile,about) )
                {
                    cout << about << '\n';
                }
                myfile.close();
            }
            int hahaha;
            cout << endl;
            cout << "Press 1 to return back to MENU: ";
            cin >> hahaha;
            }
            break;

        case 7:
            {
                endthis = 1;
            }

            break;

        default:
            {
                cout << "The choice you entered is INVALID." << endl;
                cout << "TRY AGAIN!!!" << endl;
            }

            break;

        }

    }


}

//Comments Needed 01.05.2018
void AddATeam()
{
    cout << "By Creating a Team you are also creating a new Login account for the respective head to operate! " << endl;
    cout << "The default password is 0" << endl;
   // cout << "Password can be changed in future by the team Head" << endl;
    cout << "Perform every entry without spaces" << endl;
    cout << endl;
    string newteamname;
    cout << "Name your team: ";
    cin >> newteamname;
    cout << endl;
    string teamheadname;
    cout << "Assign a Team Head for " << newteamname << " : ";
    cin >> teamheadname;
    cout << endl;

    ofstream appendalways;
    appendalways.open("CompanyTeams.txt", ios::app);
    appendalways << newteamname << endl;
    appendalways.close();
    appendalways.open("Confidential.txt", ios::app);
    appendalways << newteamname << " " << 0 << endl;
    appendalways.close();

    UpdateWorkforce();

    ifstream idavailability("CompanyWorkforce.txt");
    int existingid;
    string existingemp;
    string existingteam;

    int maximum = 0;
    //Resolve this
    while(idavailability >> existingid >> existingemp >> existingteam){
        if(existingid > maximum){
            maximum = existingid;
        }
    }
    idavailability.close();

    string newname = newteamname + ".txt";
    int n = newname.length();
    char teamname[n+1];
    strcpy(teamname, newname.c_str());
    maximum++;
    ofstream teamfilecreation;
    teamfilecreation.open(teamname);
    teamfilecreation << maximum << " " << teamheadname << endl;
    teamfilecreation.close();
    cout << "The file " << newname << " is created!" << endl;
    cout << "Please ask the Team Head " << teamheadname << " to fill in with the employees." << endl;
    UpdateWorkforce();
    //getch();
}

//Comments Needed 01.05.2018
void DeleteATeam()
{
    string deletethis;
    cout << "Enter the Team Name(in same format as registered): ";
    cin >> deletethis;

    string tname1 = deletethis + ".txt";
    int n1 = tname1.length();
    char teamname1[n1+1];
    strcpy(teamname1, tname1.c_str());

    string tname2 = deletethis + "Credits" + ".txt";
    int n2 = tname2.length();
    char teamname2[n2+1];
    strcpy(teamname2, tname2.c_str());

    string tname3 = deletethis + "CreditsParameters" + ".txt";
    int n3 = tname3.length();
    char teamname3[n3+1];
    strcpy(teamname3, tname3.c_str());

    string tname4 = deletethis + "Analysis" + ".txt";
    int n4 = tname4.length();
    char teamname4[n4+1];
    strcpy(teamname4, tname4.c_str());

    remove(teamname1);
    remove(teamname2);
    remove(teamname3);
    remove(teamname4);

    //Erase from Company Teams List
    ifstream findteamtoerase("CompanyTeams.txt");
    string tmname;

    ofstream temp;
    temp.open("temp.txt");

    while(findteamtoerase >> tmname){
        if(tmname != deletethis){
            temp << tmname << endl;
        }
    }

    temp.close();
    findteamtoerase.close();
    remove("CompanyTeams.txt");
    rename("temp.txt","CompanyTeams.txt");
    //Erased and Recreated - Company Teams

    //Erase from Confidential
    ifstream erasefromconfidential("Confidential.txt");
    string teamnm;
    long long int pswd;

    temp.open("temp.txt");

    while(erasefromconfidential >> teamnm >> pswd){
        if(teamnm != deletethis){
            temp << teamnm << " " << pswd << endl;
        }
    }

    temp.close();
    erasefromconfidential.close();
    remove("Confidential.txt");
    rename("temp.txt","Confidential.txt");
    //Erased and Recreated - Confidential
    UpdateWorkforce();

    cout << "The team is no more a part of your Company." << endl;
    cout << "The corresponding files of the same have been successfully ERASED!!!" << endl;
}

//Comments Needed 01.05.2018
void searchforemp(int id)
{
    UpdateWorkforce();

    ifstream workforce("CompanyWorkforce.txt");
    int iden;
    string empname;
    string empteam;

    while(workforce >> iden >> empname >> empteam){
        if(iden == id){
            break;
        }
    }

    workforce.close();

    cout << endl;
    cout << "Team Name: " << "\t" << empteam << endl;
    cout << "Employee ID: " << iden << "\tEmployee Name: " << empname << endl;

    string tname = empteam + "CreditsParameters" + ".txt";
    int n = tname.length();
    char teamname[n+1];
    strcpy(teamname, tname.c_str());

    ifstream crpara(teamname);
    int x[12] = {0};
    while(crpara >> iden >> x[0] >> x[1] >> x[2] >> x[3] >> x[4] >> x[5] >> x[6] >> x[7] >> x[8] >> x[9] >> x[10] >> x[11]){
        if(iden == id){
            break;
        }
    }

    crpara.close();

    cout << "\nControl: " << x[0] << endl;
    cout << "Social_Influence: " << x[1] << endl;
    cout << "Patience: " << x[2] << endl;
    cout << "Precision: " << x[3] << endl;
    cout << "Ambition: " << x[4] << endl;
    cout << "Positive_Expectancy: " << x[5] << endl;
    cout << "Composure: " << x[6] << endl;
    cout << "Analytical: " << x[7] << endl;
    cout << "Results_Orientation: " << x[8] << endl;
    cout << "Expressiveness: " << x[9] << endl;
    cout << "Team_Player: " << x[10] << endl;
    cout << "Quality_Orientation: " << x[11] << endl;


}

//Comments Needed
void TeamHeadLogin(string whichteam)
{

    int choice;
    int endthis = 0;
    while(endthis == 0){
        system("cls");
        displayepic(whichteam);
        cout << "1. Team Workforce Details" << endl;
        cout << "2. Enter Credits" << endl;
        //cout << "3. Search for a Team Member" << endl;
        cout << "3. Add a Team Member" << endl;
        cout << "4. P.A.A.M Analysis" << endl;
        cout << "5. Behavioral Evaluations" << endl;
        //cout << "6. Change Password" << endl;
        cout << "6. Guide" << endl;
        cout << "7. Logout" << endl;

        //To use filenames with streams
        // Conversion Begins
        string fname = whichteam + ".txt";
        int n = fname.length();
        char filename[n+1];
        strcpy(filename, fname.c_str());
        // Conversion Ends

        cout << "\nPlease enter your choice: ";
        cin >> choice;
        switch(choice)
        {

        case 1:
            {
                system("cls");
                ifstream infile(filename);
                int empid;
                string empname;
                ttwd();
                cout << setw(3) << "Team " << whichteam << endl;
                cout << setw(3) << "ID" << "\tName" << endl;
                while(infile >> empid >> empname){
                    cout << setw(3) << empid << "\t" << empname << endl;
                }

                int hahaha;
                cout << endl;
                cout << "Press 1 to return back to MAIN MENU: ";
                cin >> hahaha;
                }

            break;

        case 2:
            {
                system("cls");
                EnterCredits(whichteam);
            }

            break;

        case 3:

            {
            int retry = 0;


            ofstream newteammate; //Sends the fresh data of a new employee to file
            char getanothermem; //To implement the below logic again when label - torecruitanotheremp is called
            //Variables to store Employee id and employee name
            string newempname;


            ifstream infile;
            int empid;
            string empname;

            ifstream idavailability;
            int existingid;
            string existingemp;
            string existingteam;

            int maximum = 0;

            UpdateWorkforce();

            //BEGIN: Generate a max value and assign it to variable
            idavailability.open("CompanyWorkforce.txt");

            while(idavailability >> existingid >> existingemp >> existingteam){
                if(existingid > maximum){
                    maximum = existingid;
                }
            }


            idavailability.close();
            //END: Generate a max value and assign it to variable

            while(retry == 0){

                    system("cls");
                    infile.open(filename);

                    cout << setw(3) << "Team " << whichteam << endl;
                    cout << setw(3) << "ID" << "\tName" << endl;
                    while(infile >> empid >> empname){
                        cout << setw(3) << empid << "\t" << empname << endl;
                    }
                    infile.close();

                    //BEGIN: LOGIC
                    newteammate.open(filename, ios::app);

                    cout << "Enter the Employee name: ";
                    cin >> newempname;
                    maximum++;
                    newteammate << maximum << " " << newempname << endl;
                    newteammate.close();

                    cout << "Do you want to add another team member?" << endl;
                    cin >> getanothermem;

                    if((getanothermem == 'N') || (getanothermem == 'n')){
                        retry = 1;
                    }

                }
            }

            break;

        case 4:
            {
                system("cls");
                TeamPAAM(whichteam);
            }

            break;

        case 5:
            {
                system("cls");
                BehaviorEval(whichteam);
                int hahaha;
                cout << "\nPress 1 to return to MAIN MENU: ";
                cin >> hahaha;
            }

            break;

        /*case 6:
            {
                system("cls");
                ChangePassword(whichteam);
                remove("Confidential.txt");
                rename("temp.txt","Confidential.txt");
                getch();
            }

            break;
            */

        case 6:
            {
                system("cls");
           cout << "---------" << endl;
            cout << "| Guide |" << endl;
            cout << "---------" << endl;
            string about;
            ifstream myfile ("TeamGuid.txt");
            if (myfile.is_open())
            {
                while ( getline (myfile,about) )
                {
                    cout << about << '\n';
                }
                myfile.close();
            }
            int hahaha;
            cout << endl;
            cout << "Press 1 to return back to MENU: ";
            cin >> hahaha;

            }

            break;

        case 7:
            {
                endthis = 1;
            }

            break;

        default:
            {
                cout << "The choice you entered is INVALID." << endl;
                cout << "TRY AGAIN!!!" << endl;

            }

            break;

        }
    }
}

//Comments Needed
void EnterCredits(string teamname)
{
    // Stream needed for getting ID's and Names Begin
    string fname = teamname + ".txt"; // Adding string to a string and saving in a string
    // Conversion Process Begin
    int n = fname.length();
    char filename[n+1];
    strcpy(filename, fname.c_str()); // Copying string content into a char array
    // Conversion Process End
    ifstream infile; // This is the stream
    infile.open(filename);
    int eid;
    string ename;
    // Stream needed for getting ID's and Names End

    // Stream needed to transfer credits data the totals only Begin
    string cfile = teamname + "Credits" + ".txt";
    // Conversion from String to Char
    int k = cfile.length();
    char creditsfile[k+1];
    strcpy(creditsfile, cfile.c_str()); // converting a string into char as we cannot pass string
    // End of conversion
    ofstream outfilecr;
    outfilecr.open(creditsfile);
    // Stream needed to transfer credits data the totals only End

    // Stream needed to transfer credits data the totals only Begin
    string cpfile = teamname + "Credits" + "Parameters" + ".txt";
    // Conversion from String to Char
    int pp = cpfile.length();
    char creditsparafile[pp+1];
    strcpy(creditsparafile, cpfile.c_str()); // converting a string into char as we cannot pass string
    // End of conversion
    ofstream outfilepara;
    outfilepara.open(creditsparafile);
    // Stream needed to transfer credits data the totals only End

    // To fetch parameter names Begin

    // To fetch parameter names End

    int store = 0;
    int total = 0;
    int countt = 1;
    int employeecount = 1;

    //Run this code seperately
    //Run this code seperately
    while(infile >> eid >> ename){
        system("cls"); //using to clean and show every employees seperately
        tcredits();
        cout << "NOTE:" << endl;
        cout << "   1.EVERY PARAMETER SHOULD BE RATED FOR 5 CREDITS" << endl;
        cout << "   2.PLEASE ENTER CREDITS FOR ALL 12 PARAMETERS\n" << endl;
        cout << "\nEmployee Count: '" << employeecount << "'" << endl;
        cout << "Employee ID: " << eid  << "\tEmployee Name: " << ename << endl;
        outfilepara << eid << " ";
        cout << "\n" << endl;
        ifstream inpara("Parameters.txt");
        string parameter;
        while(inpara >> parameter){
            reenter:
            //cout << "Parameter Count: " << countt << endl;
            cout << parameter << " : ";
            cin >> store;
            if (store <= 5) {
            outfilepara << store; }
            // This is done to avoid the last space in the Credits Parameters file
            else {
                cout << "\nERROR: EVERY PARAMETER SHOULD BE RATED BETWEEN 1-5 CREDITS ONLY.\n";
                goto reenter; }

            if(countt < 12){
                outfilepara << " ";
            }
            total = total + store;
            countt++;

            if(countt > 12){
                countt = 1;
            }
        }
        employeecount++;
        inpara.close();

        outfilepara << endl;

        outfilecr << eid << " " << total << endl;
        total = 0;
    }

    outfilecr.close();
    outfilepara.close();
    infile.close();

    cout << "\nHopefully, You are done with Entering Credits to your Employees\n";
    cout << "Go Back to main menu to run P.A.A.M Analysis\n" << endl;

    int hahaha;
    cout << "Press 1 to return to MAIN MENU: " << endl;
    cin >> hahaha;

}

//Comments Needed
void TeamPAAM(string teamname)
{
    //Creating a stream unsorted
    string fname = teamname + "Credits" +".txt";
    int n = fname.length();
    char filename[n+1];
    strcpy(filename, fname.c_str());
    ifstream unsorted(filename);
    int first;
    float second;
    //unsorted stream created

    //Creating an object type LinkedList to add and sort the nodes containing credits in descending order
    LinkedList ll;

    while(unsorted >> first >> second){
        ll.insertt(first, second);
    }

    ll.sendlltofile(teamname);

    // Creating a file with Analysis.txt and opening a stream sorted to the file BEGIN
    string ggname = teamname + "Analysis" + ".txt";
    int g = ggname.length();
    char gname[g+1];
    strcpy(gname, ggname.c_str());
    ifstream sorted(gname); // This is the stream
    int xxx;
    float yyy;
    //Creating a file with Analysis.txt and opening a stream sorted to the file END

    //Used by getnames stream in while loop begin
    string ccname = teamname + ".txt";
    int c = ccname.length();
    char cname[c+1];
    strcpy(cname, ccname.c_str());
    //used by getnames stream in while loop end

    tpaam();
    cout << setw(4) << "ID" << "\tName" << "\t\t\tCredits" << endl;

    while(sorted >> xxx >> yyy){

        // Creating a input stream to fetch names out of employee ID Begin
        ifstream getnames(cname);
        int myid;
        string names;
        // Creating a input stream to fetch names out of employee ID END

        while(getnames >> myid >> names){
            if(myid == xxx){
                    break;
            }
        }
        getnames.close();
        cout << setw(4) << xxx << "\t" << names << "\t\t" << yyy << endl;
    }

    int hahaha;
    cout << "Press 1 to return to MAIN MENU: " << endl;
    cin >> hahaha;
}

//Comments Needed
void BehaviorEval(string teamname)
{
    displayepic(teamname);

    //START: getcount stream era
    string fname = teamname + ".txt";
    int n = fname.length();
    char filename[n+1];
    strcpy(filename, fname.c_str());
    ifstream getcount;
    getcount.open(filename);
    int empid;
    string empname;
    int numberofteammembers = 0;

    while(getcount >> empid >> empname){
        numberofteammembers++;
    }
    getcount.close();
    //END: getcount stream era

    int control[2][numberofteammembers] = {0};
    int socialinfluence[2][numberofteammembers] = {0};
    int patience[2][numberofteammembers] = {0};
    int precision[2][numberofteammembers] = {0};
    int ambition[2][numberofteammembers] = {0};
    int positiveexpextancy[2][numberofteammembers] = {0};
    int composure[2][numberofteammembers] = {0};
    int analytical[2][numberofteammembers] = {0};
    int resultsoreintation[2][numberofteammembers] = {0};
    int expressiveness[2][numberofteammembers] = {0};
    int teamplayer[2][numberofteammembers] = {0};
    int qualityorientation[2][numberofteammembers] = {0};

    string pname = teamname + "Credits" + "Parameters" + ".txt";
    int k = pname.length();
    char parafile[k+1];
    strcpy(parafile, pname.c_str());
    ifstream getparas(parafile);

    for(int i = 1; i<2; i++){

        for(int j=0; j<numberofteammembers; j++){

            while(getparas >> control[0][j] >> control[i][j] >> socialinfluence[i][j] >> patience[i][j] >> precision[i][j] >> ambition[i][j] >> positiveexpextancy[i][j] >> composure[i][j] >> analytical[i][j] >> resultsoreintation[i][j] >> expressiveness[i][j] >> teamplayer[i][j] >> qualityorientation[i][j]){
                socialinfluence[0][j] = patience[0][j] = precision[0][j] = ambition[0][j] = positiveexpextancy[0][j] = composure[0][j] = analytical[0][j] = resultsoreintation[0][j] = expressiveness[0][j] = teamplayer[0][j] = qualityorientation[0][j] = control[0][j];
                break;
            }

        }

    }


    getparas.close();

    int traversal[5] = {0};
    int low[numberofteammembers] = {0};
    int modlow[numberofteammembers] = {0};
    int moderate[numberofteammembers] = {0};
    int modhigh[numberofteammembers] = {0};
    int high[numberofteammembers] = {0};



    ifstream parameters("Parameters.txt");
    string parameter;

    int paracount = 1;


    while(parameters >> parameter){

        cout << paracount <<". " << parameter << endl;

        cout << "LOW" << setw(8) << "\tMOD. LOW" << setw(8) << "\tMODERATE" << setw(8) << "\tMOD. HIGH" << setw(8) << "\tHIGH" << endl;
        //Check this code tomorrow
        if(parameter == "Control"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(control[1][i])
                {
                case 1:
                    low[traversal[0]] = control[0][i];
                    traversal[0]++;

                    break;
                case 2:
                    modlow[traversal[1]] = control[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = control[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = control[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = control[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Social_Influence"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(socialinfluence[1][i])
                {
                case 1:
                    low[traversal[0]] = socialinfluence[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = socialinfluence[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = socialinfluence[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = socialinfluence[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = socialinfluence[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }

        if(parameter == "Patience"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(patience[1][i])
                {
                case 1:
                    low[traversal[0]] = patience[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = patience[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = patience[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = patience[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = patience[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Precision"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(precision[1][i])
                {
                case 1:
                    low[traversal[0]] = precision[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = precision[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = precision[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = precision[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = precision[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Ambition"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(ambition[1][i])
                {
                case 1:
                    low[traversal[0]] = ambition[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = ambition[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = ambition[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = ambition[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = ambition[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Positive_Expectancy"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(positiveexpextancy[1][i])
                {
                case 1:
                    low[traversal[0]] = positiveexpextancy[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = positiveexpextancy[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = positiveexpextancy[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = positiveexpextancy[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = positiveexpextancy[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Composure"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(composure[1][i])
                {
                case 1:
                    low[traversal[0]] = composure[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = composure[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = composure[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = composure[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = composure[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Analytical"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(analytical[1][i])
                {
                case 1:
                    low[traversal[0]] = analytical[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = analytical[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = analytical[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = analytical[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = analytical[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Results_Orientation"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(resultsoreintation[1][i])
                {
                case 1:
                    low[traversal[0]] = resultsoreintation[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = resultsoreintation[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = resultsoreintation[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = resultsoreintation[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = resultsoreintation[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Expressiveness"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(expressiveness[1][i])
                {
                case 1:
                    low[traversal[0]] = expressiveness[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = expressiveness[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = expressiveness[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = expressiveness[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = expressiveness[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Team_Player"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(teamplayer[1][i])
                {
                case 1:
                    low[traversal[0]] = teamplayer[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = teamplayer[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = teamplayer[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = teamplayer[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = teamplayer[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }else

        if(parameter == "Quality_Orientation"){
            memset(traversal, 0, sizeof(traversal));
            memset(low, 0, sizeof(low));
            memset(modlow, 0, sizeof(modlow));
            memset(moderate, 0, sizeof(moderate));
            memset(modhigh, 0, sizeof(modhigh));
            memset(high, 0, sizeof(high));

            for(int i=0; i<numberofteammembers; i++){
                switch(qualityorientation[1][i])
                {
                case 1:
                    low[traversal[0]] = qualityorientation[0][i];
                    traversal[0]++;
                    break;
                case 2:
                    modlow[traversal[1]] = qualityorientation[0][i];
                    traversal[1]++;
                    break;
                case 3:
                    moderate[traversal[2]] = qualityorientation[0][i];
                    traversal[2]++;
                    break;
                case 4:
                    modhigh[traversal[3]] = qualityorientation[0][i];
                    traversal[3]++;
                    break;
                case 5:
                    high[traversal[4]] = qualityorientation[0][i];
                    traversal[4]++;
                    break;
                }
            }

        }


        for(int i=0; i<numberofteammembers; i++){

                    //cout << ((low[i] == 0) ? "  " : low[i]) << setw(8) << ((modlow[i] == 0) ? "  " : modlow[i]) << setw(8) << ((moderate[i] == 0) ? "  " : moderate[i]) << setw(8) << ((modhigh[i] == 0) ? "  " : modhigh[i]) << setw(8) << ((high[i] == 0) ? "  " : high[i]) << endl;
                    cout << setw(3)  << low[i] << "\t" <<modlow[i] << setw(8) << "\t" << moderate[i] << setw(8) << "\t" << modhigh[i] << setw(8) << "\t" << high[i] << endl;

        }

        //Displaying after segregated tabular display

                for(int j=0; j<5; j++){
                    for(int i=0; i<traversal[j]; i++){
                        if(j == 0){
                            if(low[i] != 0){
                                cout << low[i] << " - " << idtoname(low[i]) << ", ";
                            }
                        }else
                        if(j == 1){
                            if(modlow[i] != 0){
                                cout << modlow[i] << " - " << idtoname(modlow[i]) << ", ";
                            }
                        }else
                        if(j == 2){
                            if(moderate[i] != 0){
                                cout << moderate[i] << " - " << idtoname(moderate[i]) << ", ";
                            }
                        }else
                        if(j == 3){
                            if(modhigh[i] != 0){
                                cout << modhigh[i] << " - " << idtoname(modhigh[i]) << ", ";
                            }
                        }else
                        if(j == 4){
                            if(high[i] != 0){
                                cout << high[i] << " - " << idtoname(high[i]) << ", ";
                            }
                        }

                    }

                    if((j == 0) && (traversal[j] != 0)){
                            cout << "\b\b ";
                            if(traversal[j] > 1){
                                cout << "are ";
                            }else{
                                cout << "is ";
                            }

                            if(parameter == "Control"){
                                cout << "low in Controlling feelings and needs a lot of chill pills" << endl;
                            }else
                            if(parameter == "Social_Influence"){
                                cout << "low in Social Influence" << endl;
                            }else
                            if(parameter == "Patience"){
                                cout << "low in Patience" << endl;
                            }else
                            if(parameter == "Precision"){
                                cout << "low in Precision" << endl;
                            }else
                            if(parameter == "Ambition"){
                                cout << "low in Ambition" << endl;
                            }else
                            if(parameter == "Positive_Expectancy"){
                                cout << "low in Positive_Expectancy" << endl;
                            }else
                            if(parameter == "Composure"){
                                cout << "low in Composure" << endl;
                            }else
                            if(parameter == "Analytical"){
                                cout << "low in Analytical" << endl;
                            }else
                            if(parameter == "Results_Orientation"){
                                cout << "low in Results_Orientation" << endl;
                            }else
                            if(parameter == "Expressiveness"){
                                cout << "low in Expressiveness" << endl;
                            }else
                            if(parameter == "Team_Player"){
                                cout << "low in Team_Player" << endl;
                            }else
                            if(parameter == "Quality_Orientation"){
                                cout << "low in Quality_Orientation" << endl;
                            }
                    }else

                    if((j == 1) && (traversal[j] != 0)){
                            cout << "\b\b ";
                            if(traversal[j] > 1){
                                cout << "are ";
                            }else{
                                cout << "is ";
                            }
                        if(parameter == "Control"){
                                cout << "moderately low in Controlling feelings and needs chill pills." << endl;
                            }else
                            if(parameter == "Social_Influence"){
                                cout << "moderately low in Social_Influence" << endl;
                            }else
                            if(parameter == "Patience"){
                                cout << "moderately low in Patience" << endl;
                            }else
                            if(parameter == "Precision"){
                                cout << "moderately low in Precision" << endl;
                            }else
                            if(parameter == "Ambition"){
                                cout << "moderately low in Ambition" << endl;
                            }else
                            if(parameter == "Positive_Expectancy"){
                                cout << "moderately low in Positive_Expectancy" << endl;
                            }else
                            if(parameter == "Composure"){
                                cout << "moderately low in Composure" << endl;
                            }else
                            if(parameter == "Analytical"){
                                cout << "moderately low in Analytical" << endl;
                            }else
                            if(parameter == "Results_Orientation"){
                                cout << "moderately low in Results_Orientation" << endl;
                            }else
                            if(parameter == "Expressiveness"){
                                cout << "moderately low in Expressiveness" << endl;
                            }else
                            if(parameter == "Team_Player"){
                                cout << "moderately low in Team_Player" << endl;
                            }else
                            if(parameter == "Quality_Orientation"){
                                cout << "moderately low in Quality_Orientation" << endl;
                            }
                    }else

                    if((j == 2) && (traversal[j] != 0)){
                            cout << "\b\b ";
                            if(traversal[j] > 1){
                                cout << "are ";
                            }else{
                                cout << "is ";
                            }

                        if(parameter == "Control"){
                                cout << "moderate in Control, and merely acceptable." << endl;
                            }else
                            if(parameter == "Social_Influence"){
                                cout << "moderate in Social_Influence" << endl;
                            }else
                            if(parameter == "Patience"){
                                cout << "moderate in Patience" << endl;
                            }else
                            if(parameter == "Precision"){
                                cout << "moderate in Precision" << endl;
                            }else
                            if(parameter == "Ambition"){
                                cout << "moderate in Ambition" << endl;
                            }else
                            if(parameter == "Positive_Expectancy"){
                                cout << "moderate in Positive_Expectancy" << endl;
                            }else
                            if(parameter == "Composure"){
                                cout << "moderate in Composure" << endl;
                            }else
                            if(parameter == "Analytical"){
                                cout << "moderate in Analytical" << endl;
                            }else
                            if(parameter == "Results_Orientation"){
                                cout << "moderate in Results_Orientation" << endl;
                            }else
                            if(parameter == "Expressiveness"){
                                cout << "moderate in Expressiveness" << endl;
                            }else
                            if(parameter == "Team_Player"){
                                cout << "moderate in Team_Player" << endl;
                            }else
                            if(parameter == "Quality_Orientation"){
                                cout << "moderate in Quality_Orientation" << endl;
                            }
                    }else

                    if((j == 3) && (traversal[j] != 0)){
                            cout << "\b\b ";
                            if(traversal[j] > 1){
                                cout << "are ";
                            }else{
                                cout << "is ";
                            }

                        if(parameter == "Control"){
                                cout << "moderately high in Control, and company is happy for their state." << endl;
                            }else
                            if(parameter == "Social_Influence"){
                                cout << "moderately high in Social_Influence" << endl;
                            }else
                            if(parameter == "Patience"){
                                cout << "moderately high in Patience" << endl;
                            }else
                            if(parameter == "Precision"){
                                cout << "moderately high in Precision" << endl;
                            }else
                            if(parameter == "Ambition"){
                                cout << "moderately high in Ambition" << endl;
                            }else
                            if(parameter == "Positive_Expectancy"){
                                cout << "moderately high in Positive_Expectancy" << endl;
                            }else
                            if(parameter == "Composure"){
                                cout << "moderately high in Composure" << endl;
                            }else
                            if(parameter == "Analytical"){
                                cout << "moderately high in Analytical" << endl;
                            }else
                            if(parameter == "Results_Orientation"){
                                cout << "moderately high in Results_Orientation" << endl;
                            }else
                            if(parameter == "Expressiveness"){
                                cout << "moderately high in Expressiveness" << endl;
                            }else
                            if(parameter == "Team_Player"){
                                cout << "moderately high in Team_Player" << endl;
                            }else
                            if(parameter == "Quality_Orientation"){
                                cout << "moderately high in Quality_Orientation" << endl;
                            }
                    }else

                    if((j == 4) && (traversal[j] != 0)){
                            cout << "\b\b ";
                            if(traversal[j] > 1){
                                cout << "are ";
                            }else{
                                cout << "is ";
                            }

                        if(parameter == "Control"){
                                cout << "highly rated for the ability of controlling oneself." << endl;
                            }else
                            if(parameter == "Social_Influence"){
                                cout << "highly rated for Social_Influence" << endl;
                            }else
                            if(parameter == "Patience"){
                                cout << "highly rated for Patience" << endl;
                            }else
                            if(parameter == "Precision"){
                                cout << "highly rated for Precision" << endl;
                            }else
                            if(parameter == "Ambition"){
                                cout << "highly rated for Ambition" << endl;
                            }else
                            if(parameter == "Positive_Expectancy"){
                                cout << "highly rated for Positive_Expectancy" << endl;
                            }else
                            if(parameter == "Composure"){
                                cout << "highly rated for Composure" << endl;
                            }else
                            if(parameter == "Analytical"){
                                cout << "highly rated for Analytical" << endl;
                            }else
                            if(parameter == "Results_Orientation"){
                                cout << "highly rated for Results_Orientation" << endl;
                            }else
                            if(parameter == "Expressiveness"){
                                cout << "highly rated for Expressiveness" << endl;
                            }else
                            if(parameter == "Team_Player"){
                                cout << "highly rated for Team_Player" << endl;
                            }else
                            if(parameter == "Quality_Orientation"){
                                cout << "highly rated for Quality_Orientation" << endl;
                            }
                    }

                }

        cout << endl;
        cout << endl;
        //getch();

        paracount++;
    }

    parameters.close();

}

//Comments Needed
/*void ChangePassword(string teamname)
{


    int checkthis;
    cout << "Please enter your present password: ";
    cin >> checkthis;

    ifstream forachange;
    forachange.open("Confidential.txt");
    string tmname;
    long long int pwd;

    while(forachange >> tmname >> pwd){
        if(tmname == teamname){
            break;
        }
    }

    forachange.close();

    if(pwd == checkthis){
        long long int thenewone;
        cout << "Please enter the NEW password: ";
        cin >> thenewone;
        ifstream teee("Confidential.txt");

        ofstream temp("temp.txt");

        while(teee >> tmname >> pwd){
            if(tmname != teamname){
                temp << tmname << " " << pwd << endl;
            }else{
                temp << tmname << " " << thenewone << endl;
            }

        }
        temp.close();
        teee.close();

        cout << "Password Changed Successfully." << endl;

    }else{
        cout << "Wrong Password!!!" << endl;
    }


}*/

//Comments Needed
void CompanyPAAM()
{
    ifstream getteams;
    getteams.open("CompanyTeams.txt");
    string teamname;

    ofstream createtoclean("CompanyCredits.txt");
    createtoclean.close();

    while(getteams >> teamname){

        string fname = teamname + "Analysis" +".txt";
        int n = fname.length();
        char filename[n+1];
        strcpy(filename, fname.c_str());
        ifstream feedunsorted(filename);
        int first;
        float second;

        ofstream unsorted;
        unsorted.open("CompanyCredits.txt", ios::app);

        while(feedunsorted >> first >> second){

            unsorted << first << " " << second << endl;

        }

        feedunsorted.close();
        unsorted.close();

    }

    ifstream unsorted("CompanyCredits.txt");

    //Creating an object type LinkedList to add and sort the nodes containing credits in descending order
    LinkedList ll;
    int first;
    float second;

    while(unsorted >> first >> second){
        ll.insertt(first, second);
    }

    ll.sendlltofile("Company");

    ifstream sorted("CompanyAnalysis.txt"); // This is the stream
    int xxx;
    float yyy;
    //Creating a file with Analysis.txt and opening a stream sorted to the file END
    tpaam();
    cout << "Company Name: XYZ" << endl;
    cout << setw(4) << "ID" << "\tName" << "\t\t\tCredits" << "\t\t\tTeam Name" << endl;


    while(sorted >> xxx >> yyy){

        UpdateWorkforce();
        ifstream getname("CompanyWorkforce.txt");
        int num;
        string nam;
        string tmname;

        while(getname >> num >> nam >> tmname){

            if(xxx == num){
                break;
            }

        }

        cout << setw(4) << xxx << "\t" << nam << "\t\t" << yyy << "\t\t" << tmname << endl;

        getname.close();


    }

    int hahaha;
    cout << "Press 1 to return to MAIN MENU: " << endl;
    cin >> hahaha;



}



int main()
{
    system("color 2F");
    rename("AAA.txt","Confident.txt");
    FeedInfo(); // Creates informational files in an Alien Environment.
    ProgramMenu(); // This sets up strong baseline to PROGRAM MENU. We programmers call it "PROGRAM MENU".


    return 0;
}

