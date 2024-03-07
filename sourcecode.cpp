#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
using namespace std;
class socialpl;
void gotoXY(int X, int Y)
{
COORD coordinates;
coordinates.X = X;
coordinates.Y = Y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void border(int xLenS = 2, int yLenS = 2, int xLenE = 76, int yLenE = 22)
{
char c1 = 201;
char c2 = 200;
char c3 = 205;
char c4 = 187;
char c5 = 188;
system("cls");
gotoXY(xLenS, yLenS);
cout << c1;
gotoXY(xLenS, yLenE);
cout << c2;
for (int i = xLenS + 1; i <= xLenE - 1; i++) // Top and Bottom Border line
{
gotoXY(i, yLenS);
cout << c3;
// puts(style);
gotoXY(i, yLenE);
// puts(style);
cout << c3;
}
gotoXY(xLenE, yLenS);
cout << c4;
gotoXY(xLenE, yLenE);
cout << c5;
for (int i = yLenS + 1; i <= yLenE - 1; i++) // Left and Right Border Line
{
gotoXY(xLenS, i);
cout << c4;
// puts(style);
gotoXY(xLenE, i);
cout << c5;
// puts(style);
}
cout << endl;
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 70, int yLenE = 25)
{
border(xLenS, yLenS, xLenE, yLenE);
}
void intro()
{
gotoXY(24, 4);
cout << ("WELCOME TO SOCIAL NETWORKING ANALYSIS");
gotoXY(24, 6);
cout << "SUBMITTED BY:";
gotoXY(24, 8);
cout << "MUSKAAN SINGHAL\t\t22103192";
gotoXY(24, 10);
cout << "ANVESHA SRIVASTAVA\t22103205";
gotoXY(24, 12);
cout << ("Press Any key to continue...");
getch();
}
class User
{
public:
int id;
int age;
string contact;
string gen;
string customername = " ";
string pas;
string uppas;
User(){
id=0;
age=0;
gen="";
contact="";
customername="";
}
User(int i, int a, string c, string name, string g)
{
id=i;
age=a;
contact=c;
gen=g;
customername=name;
}
void registerr()
{
cout << endl;
gotoXY(0, 3);
cout << "__________________________" << endl;
gotoXY(29, 5);
cout << "REGISTRATION PAGE" << endl;
gotoXY(0, 7);
cout << "__________________________" << endl;
gotoXY(20, 10);
ofstream file1("Profile.txt", ofstream::app);
cout << "Please Enter your ID: ";
cin >> id;
file1 << id << " ";
fflush(stdin);
gotoXY(20, 12);
cout << "Please Enter your Name: "; // taking data from the user
cin >> customername;
file1 << customername << " ";
cout << endl;
gotoXY(20, 13);
fflush(stdin);
cout << "Please enter your age: ";
cin >> age;
file1 << age << " ";
gotoXY(20, 14);
cout << "Please Enter your gender (M/F/O): "; // taking data from the user
cin >> gen;
file1 << gen << " ";
gotoXY(20, 15);
cout << "Please Enter your contact info: ";
cin >> contact;
file1 << contact << " ";
file1.close();
setpass();
if (pas != uppas)
{
cout << "\t\t Entered password should be same as confirmed password!" <<
endl;
cout << "\t\t TRY AGAIN!" << endl;
setpass();
}
gotoXY(20, 22);
cout << "\t\t REGISTERED SUCCESSFULLY!" << endl;
gotoXY(20, 23);
cout << "\t\t LOGIN TO YOUR ACCOUNT" << endl;
system("PAUSE");
system("CLS");
}
void login()
{
string pass = "";
char ch;
gotoXY(20, 10);
cout << "SOCIAL NETWORKING ANALYSIS \n\n";
gotoXY(20, 12);
cout << "------------------------------";
gotoXY(20, 14);
cout << "LOGIN \n";
gotoXY(20, 15);
cout << "-----------------------------\n\n";
gotoXY(20, 17);
cout << "Enter Password: ";
ch = _getch();
while (ch != 13)
{ // character 13 is enter
pass.push_back(ch);
cout << '*';
ch = _getch();
}
if (pass == pas)
{
gotoXY(20, 19);
cout << "Access Granted! \n";
system("PAUSE");
system("CLS");
}
else
{
cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
system("PAUSE");
system("CLS");
login();
}
}
void setpass()
{
char ch2;
ofstream file1("Profile.txt", ofstream::app);
cout << endl;
gotoXY(20, 16);
cout << "Please Enter your password: ";
ch2 = _getch();
// taking data from the user
while (ch2 != 13)
{ // character 13 is enter
pas.push_back(ch2);
cout << '*';
ch2 = _getch();
}
if (ch2 == 8) // Backspace key pressed
{
if (!pas.empty())
{
cout << "\b \b"; // Move the cursor back and erase the character
pas.pop_back(); // Remove the last character from the password
}
}
else
{
pas.push_back(ch2);
cout << '*';
}
file1 << pas << "\n";
cout << endl;
gotoXY(20, 17);
cout << "Please Confirm your password: ";
ch2 = _getch(); // taking data from the user
while (ch2 != 13)
{ // character 13 is enter
uppas.push_back(ch2);
cout << '*';
ch2 = _getch();
}
if (ch2 == 8) // Backspace key pressed
{
if (!pas.empty())
{
cout << "\b \b"; // Move the cursor back and erase the character
pas.pop_back(); // Remove the last character from the password
}
}
else
{
pas.push_back(ch2);
cout << '*';
}
cout << endl;
}
};
class Node {
public:
int id;
string time;
string name;
string text;
Node* next_post;
Node(int post_id, string post_time, string post_name, string post_text)
: id(post_id), time(post_time), name(post_name), text(post_text), next_post(nullptr) {}
};
class LinkedList {
public:
Node* head;
LinkedList() : head(nullptr) {}
void addPosts(int id, string time, string name, string text) {
Node* new_post = new Node(id, time, name, text);
new_post->next_post = head;
head = new_post;
}
Node* searchPost(int search_id) {
Node* current_post = head;
while (current_post != nullptr && current_post->id != search_id) {
current_post = current_post->next_post;
}
if (current_post == nullptr) {
cout << "SEARCHED ID NOT FOUND" << endl;
} else {
cout << "ID found" << endl;
cout << "ID: " << current_post->id << " TIME: " << current_post->time << endl;
cout << "NAME: " << current_post->name << " TEXT: " << current_post->text <<
endl;
}
return current_post;
}
void viewPost(int search_id) {
Node* savedpost = searchPost(search_id);
if (savedpost != nullptr) {
cout << "VIEW YOUR POST BY ENTERING ID " << search_id << ":" << endl;
cout << "Time: " << savedpost->time << endl;
cout << "Name: " << savedpost->name << endl;
cout << "Text: " << savedpost->text << endl;
} else {
cout << "Post with ID " << search_id << " is not found." << endl;
}
}
void sortPostsByTime() {
if (head == nullptr || head->next_post == nullptr) {
return;
}
Node* current;
Node* last = nullptr;
for (bool swapped = true; swapped; last = current) {
swapped = false;
current = head;
while (current->next_post != last) {
Node* next_node = current->next_post;
if (current->time > next_node->time) {
swap(*current, *next_node);
swapped = true;
}
current = current->next_post;
}
}
}
void displayPosts() {
Node* current_post = head;
while (current_post != nullptr) {
cout << "ID: " << current_post->id << endl;
cout << "Time: " << current_post->time << endl;
cout << "Name: " << current_post->name << endl;
cout << "Text: " << current_post->text << endl;
cout << "-----------------" << endl;
current_post = current_post->next_post;
}
}
void saveToFile(const string& filename) {
ofstream file(filename);
if (file.is_open()) {
Node* current_post = head;
while (current_post != nullptr) {
file << current_post->id << ',' << current_post->time << ',' <<
current_post->name << ',' << current_post->text << '\n';
current_post = current_post->next_post;
}
file.close();
cout << "Posts saved to file: " << filename << endl;
} else {
cout << "Unable to open file for saving." << endl;
}
}
void loadFromFile(const string& filename) {
ifstream file(filename);
if (file.is_open()) {
int id;
string time, name, text;
while (file >> id >> ws && getline(file, time, ',') && getline(file, name, ',') &&
getline(file, text)) {
addPosts(id, time, name, text);
}
file.close();
cout << "Posts loaded from file: " << filename << endl;
} else {
cout << "Unable to open file for loading." << endl;
}
}
};
class Graph {
public:
vector<User> user;
vector<vector<int>> adjacency; // Adjacency list to store edges
void addUser(int i, int age, string c, string s, string gen) {
User userslist(i, age, c, s, gen);
user.push_back(userslist);
adjacency.push_back(vector<int>());
}
void addEdge(int id1, int id2) {
adjacency[id1].push_back(id2);
adjacency[id2].push_back(id1);
}
void displayGraph() {
for (int i = 0; i < user.size(); ++i) {
cout << "Name: " << user[i].customername << " Contact: " << user[i].contact;
cout << " Connected People: ";
for (int j = 0; j < adjacency[i].size(); ++j) {
int k = adjacency[i][j];
cout << user[k].customername;
if (j < adjacency[i].size() - 1)
cout << ", ";
}
cout << endl;
}
}
int searchforindex(string name) {
for (int i = 0; i < user.size(); i++) {
if (user[i].customername == name)
return i;
}
return -1;
}
void displayspecificindex(int i) {
cout << "Name: " << user[i].customername << endl;
cout << "Contact: " << user[i].contact << endl;
cout << "Age: " << user[i].age << endl;
cout << "Gender: " << user[i].gen << endl;
cout << "Number of friends: " << adjacency[i].size() << endl;
cout << "Connected People: ";
for (int j = 0; j < adjacency[i].size(); ++j) {
int k = adjacency[i][j];
cout << user[k].customername;
if (j < adjacency[i].size() - 1)
cout << ", ";
}
cout << endl;
}
void addCon(int i, int age, string c, string s, string gen) {
int x;
cout << "Enter the number of friends of " << s << endl;
fflush(stdin);
cin >> x;
//cout << x << endl;
addUser(i, age, c, s, gen);
int ind = searchforindex(s);
//cout << ind << endl;
cout << "Enter the friends you want " << s << " to connect with" << endl;
fflush(stdin);
while (x--) {
string s2;
cin >> s2;
int d = searchforindex(s2);
// cout << d << endl;
if (d != -1) {
addEdge(ind, d);
cout << "YOU'RE CONNECTED SUCCESSFULLY!" << endl;
} else {
cout << "No user found!" << endl;
}
}
}
void mutualpath(vector<int> &path_visited, vector<int> &visited, int i1, int i2, int n)
{
visited[i1] = 1;
path_visited[i1] = 1;
if (i1 != i2)
{
for (auto j : adjacency[i1])
{
if (!visited[j])
mutualpath(path_visited, visited, j, i2, n);
}
}
else
{
int cnt = 1;
for (int j = 0; j < n; j++)
{
if (path_visited[j] == 1 && cnt != 1)
{
cout << " -> " << user[j].customername;
}
else if (path_visited[j] == 1 && cnt == 1)
{
cout << user[j].customername;
}
cnt++;
}
}
path_visited[i1] = 0;
}
// For finding the path from source location to destination -->
void path(int src, int dest)
{
int n = user.size();
vector<int> visited(n, 0);
vector<int> path_visited(n, 0);
for (int i = 0; i < n; i++)
{
if (!visited[i] && i == src)
{
mutualpath(path_visited, visited, i, dest, n);
}
}
}
};
void handlePostOptions() {
LinkedList postList;
postList.loadFromFile("posts.txt");
int postChoice;
do {
cout << "\nChoose a post option:\n"
<< "1. Add a post\n"
<< "2. Sort posts by time\n"
<< "3. Search for a post by ID\n"
<< "4. View a post by ID\n"
<< "5. Save and exit\n";
cin >> postChoice;
switch (postChoice) {
case 1: {
int id;
string time, name, text;
cout << "Enter Post ID: ";
cin >> id;
cout << "Enter Post Time (format: YYYY-MM-DD HH:MM): ";
cin >> ws;
getline(cin, time);
cout << "Enter Post Name: ";
getline(cin, name);
cout << "Enter Post Text: ";
getline(cin, text);
postList.addPosts(id, time, name, text);
cout << "Post added successfully!" << endl;
} break;
case 2:
postList.sortPostsByTime();
cout << "\nSorted posts by time:" << endl;
postList.displayPosts();
break;
case 3: {
int searchID;
cout << "Enter the ID to search: ";
cin >> searchID;
postList.searchPost(searchID);
} break;
case 4: {
int viewID;
cout << "Enter the ID to view: ";
cin >> viewID;
postList.viewPost(viewID);
} break;
case 5:
postList.saveToFile("posts.txt");
cout << "Exiting post options. Goodbye!" << endl;
break;
default:
cout << "Invalid choice! Please enter a valid option." << endl;
break;
}
} while (postChoice != 5);
}
int main() {
int userChoice;
Graph g;
border();
intro();
User u;
loginFrame();
u.registerr();
loginFrame();
u.login();
g.addUser(1, 20, "912347541", "Saumya", "F");
g.addUser(2, 19, "912347541", "Vanshika", "F");
g.addUser(3, 20, "912347541", "Anvesha", "F");
g.addUser(4, 21, "912347541", "Ariba", "F");
g.addUser(5, 21, "912347541", "Ankita", "F");
g.addUser(6, 11, "912247541", "Naman", "M");
g.addUser(7, 22, "912347542", "Sanat", "M");
g.addUser(8, 25, "9548156550", "Ritu", "F");
g.addUser(9, 51, "915347541", "Shyam", "M");
g.addUser(10, 21, "912367541", "Arushi", "F");
g.addEdge(0, 1);
g.addEdge(1, 2);
g.addEdge(2, 3);
g.addEdge(3, 4);
g.addEdge(1, 3); // Vanshika to Ariba
g.addEdge(1, 4); // Vanshika to Mansi
g.addEdge(2, 4); // Anvesha to Mansi
g.addEdge(0, 5); // Saumya to Khushi
g.addEdge(4, 6); // Mansi to Naman
g.addEdge(5, 7); // Khushi to Pragya
g.displayGraph();
do {
cout<<"\t\t\t\tPROFILE"<<endl;
cout<<"User Name:"<<u.customername<<endl;
cout<<"Age:"<<u.age<<endl;
cout<<"Contact:"<<u.contact<<endl;
cout << "\n\n\t\t\t\t****-------------------------------------***" << endl;
cout << "\t\t\t\t | SOCIAL NETWORKING ANALYSIS | " << endl;
cout << "\t\t\t\t-------------------------------------" << endl;
cout << "\t\t\t\t 1. Show All Users " << endl;
cout << "\t\t\t\t 2. Add Connections " << endl;
cout << "\t\t\t\t 3. Search a user by Name " << endl;
cout << "\t\t\t\t 4. Path of mutual connections " << endl;
cout << "\t\t\t\t 5. Post " << endl;
cout << "\t\t\t\t 6. Exit " << endl;
cout << "\t\t\t\t-------------------------------------" << endl;
cout << "\t\t\t\t Choose Option : [ 1 / 2 / 3 / 4 / 5/ 6 /7]" << endl;
cout << "\t\t\t\t-------------------------------------" << endl;
cin >> userChoice;
switch (userChoice) {
case 1:
g.displayGraph();
break;
case 2:
g.addCon(u.id,u.age,u.contact,u.customername,u.gen);
g.displayGraph();
break;
case 4:{
cout<<"Enter friend 1 name to find mutual connection"<<endl;
string s1;
cin>>s1;
int i1= g.searchforindex(s1);
cout<<"Enter friend 2 name to find mutual connection"<<endl;
string s2;
cin>>s2;
int i2= g.searchforindex(s2);
g.path(i1,i2);
}
break;
case 3:{
cout<<"Enter the name of profile you wish to search"<<endl;
string s;
cin>>s;
int x=g.searchforindex(s);
g.displayspecificindex(x);}
break;
case 5:
handlePostOptions();
break;
case 6:
cout << "Exiting program. Goodbye!" << endl;
break;
default:
cout << "Invalid choice! Please enter a valid option." << endl;
break;
}
} while (userChoice != 6);
return 0;
}
