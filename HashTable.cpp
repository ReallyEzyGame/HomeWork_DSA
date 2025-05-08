#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#define NUMBER_OF_FIELDS 3
#define CHAR_LENGHT     20           // the Char's Number at the last part of the String
#define HASHTABLE_SIZE  2000
#define BASE            31           // the Number use for Multiply Formula in the Hash Table
#define MODULO          2000         // the Number use for Modulo Formula in the Hash Table
using namespace std;
/*
    07/05/2025, user: Le Thanh Phong
        Adding struct: HashTable, Node, Company
        Adding Function: readCompanyList(), hashString(), createHashTable(), search
    07/05/2025, user: Le Thanh Phong
        Fixed bug: 3 first strange chars "∩╗┐"  when get the first line
                Fix the get information scpoe of a Company in the readCompanyList()
                Add Constructor & Destructor to HashTable structure
                Test Program
    08/05/2025, user: Le Thanh Phong
        Design main() function: handle on Windows & Linux/MacOS
        Testing Programm with the given input
    09/05/2025
        Fixing the Bug when cannot find the Company name
        Run Test on Full Data & Function
    
*/
struct HashTable;
struct Company;
// Using Node for Chain Probing

// Information of a  Company
struct Company
{
    string name;
    string profit_tax;
    string address;
};

struct Node
{
    Company infor;
    Node* next;
    Node(): next(nullptr) {};
};

struct HashTable
{
    int capacity;
    int size =  0;
    vector <Node*> data;          // Containg companies Information
    HashTable(): capacity(HASHTABLE_SIZE), data(capacity)
    {
        int index =  0;
        while (index <  capacity)
        {
            Node* add = new Node;
            add->infor ={"empty","empty","empty"};
            data[index++] = add;
        }
    };
    ~HashTable()
    {
        if (size <= 0) return;
        int index  = 0;
        while (index <  capacity)
        {
            if (data[index] !=  nullptr)
            {
                Node* tmp  = data[index];
                // delete the List in each Cell
                while (tmp->next)
                {
                    Node* del = tmp;
                    tmp  = tmp->next;
                    delete  del;
                }
                // delete the Tail Node
                delete tmp;
            }
            index++;
        }
    };
};

void insert(HashTable* hash_table, Company company);

// Get Companies information from FILE ---> Vector
vector<Company> readCompanyList(string file_name)
{
    ifstream input(file_name);
    if (!input.is_open()) throw(404);

    vector <Company> data;
    vector <string> order; int position = 0;

    // Get the Order of the Information
    // check for the first line to get the correct position of each fields
    string field = "";
    getline(input,field, '|'); field = field.substr(3,field.size()-3);  order.push_back(field);
    getline(input,field, '|'); order.push_back(field);
    getline(input,field,'\n'); order.push_back(field);

    // get the infromation of each line
    int index = 0;      // get Each of fields, return to 1 if when get to the last field
    Company company;
    while (!input.eof())
    {
        // get the information of a field in a line
        string str;
        // get  the  Last field
        if (index == NUMBER_OF_FIELDS - 1)
            {getline(input,str,'\n');}
        // get normal field
        else
            {getline(input, str, '|');}

        if (order[index] == "Ten cong ty") company.name = str;
        else if (order[index] == "MST") company.profit_tax = str;
        else if (order[index] == "Dia chi") company.address = str;
        // Get to the next field or next line
        if (index == NUMBER_OF_FIELDS-1) {data.push_back(company); Company empty; company = empty; index =  0;}
        else  index++;
    }
    input.close();
    return data;
}

// Give the index key in the Hash table
// INPUT:  a string of the Company name
// OUTPUT: an long long index of the company position in the Hash Table
// Hasing still not act as expected due to overflow number --> use other formula/ big number to contains the Result
long long hashString(string company_name)
{
    // Empty String
    if (company_name.empty()) throw (405);

    // get 20 last char/ get all the string
    string str;
    if (company_name.size() <= CHAR_LENGHT) str =  company_name;
    else str = company_name.substr(company_name.size() - (CHAR_LENGHT+1),CHAR_LENGHT);

    // sum up the string follows the Formula
    unsigned long  long result = 0;
    for (int index = 0; index < str.size(); ++index)
    {
        unsigned long long add =  (unsigned)str[index] * pow(BASE,index);
        result +=  add % MODULO;
    }
    // return the result of sum
    result %= MODULO;           // Make sure 'result' doesn't bigger  than MODULO
    return result;
}

// Create a Hash  Table
// Get all the Information to the Hash Table
HashTable* createHashTable(vector<Company> list_company)
{
    HashTable* HsTable = new HashTable[HASHTABLE_SIZE];
    
    // Put Company's infor to the Hash Table
    int index = 0;
    while (index < list_company.size())
    {
        insert(HsTable,list_company[index]);
        ++index; ++HsTable->size;
    }
    return HsTable;
}

// Add a Company to the Hash Table
void insert(HashTable* hash_table, Company company)
{
    // check if the Hash table is null
    if (hash_table == nullptr) throw(405);
    long long key = hashString(company.name);

    // Empty Cells Case
    if ( hash_table->data[key]->infor.name == "empty")
        hash_table->data[key]->infor = company;
    // If the Cells is Occured
    else
    {
        Node* tmp = hash_table->data[key];
        // Move to the Tail Node
        while (tmp->next)
            tmp = tmp->next;
        // Add the New Node to the Tail of the Chain
        Node* newNode  = new Node;
        newNode->infor = company;
        tmp->next = newNode;
    }
}

// Searching for the given Company name
// INPUT: the HashTable contains the Company data, the name of the Company need to find
// OUTPUT: information of the Company with such name
// if there is no Company with such names was found the return empty
Company* search(HashTable* hash_table, string company_name)
{
    // Empty Hash Table
    if (hash_table->data.empty()) throw(406);

    // get the Key value
    long long key = hashString(company_name);
    //Empty Cells
    if(hash_table->data[key]->infor.name == "empty") return nullptr;

    // search the list in the key value position
    Node* tmp = hash_table->data[key];
    while (tmp->next && tmp->infor.name != company_name)
        tmp = tmp->next;
    
    // Found the Company
    if (tmp->infor.name  == company_name) return &tmp->infor;
    //  Cannot find the Company with such name
    else return nullptr;
}

// Notice: the Command line: ./main ./MST.txt ./input.txt ./ output.txt    is the Command line on Linux/MacOS
// this Source Code was written on the Windows machine
int main(int argc, char** argv)
{
    if (argc != 4)
    { cout << "Error: Invalid Argument\n"; return 1;}
    // Check the char '\' in the directory
    char* Source_File, *Input_str, *Output_str;
    // Get the Argument;
    Source_File = argv[1];
    Input_str   = argv[2];
    Output_str  = argv[3];

    // Get the Company List
    vector <Company> comp_list = readCompanyList(Source_File);
    // Create a Hash Table
    HashTable* HsTable = createHashTable(comp_list);
    // Get the Input & Output file
    ifstream input(Input_str);
    if (!input.is_open())
    { cout << "Error: Unable  to  Open the File " << Input_str << " for  Reading\n"; return 1;}

    ofstream output(Output_str);
    output << "// output.txt" <<  endl;

    // Search the Company's Name

    string comp_name; Company* comp_info;
    getline(input,comp_name);
    // Pass the first Line if it not contains information needed
    if (comp_name[0] != '/')
        input.seekg(0,ios::beg);
    
    while (getline(input,comp_name))
    {
        comp_info = search(HsTable,comp_name);

        if (comp_info == nullptr)
            output  << "Cannot Find " << comp_name << " In the HashTable";
        else
            output << comp_info->name << "|" << comp_info->profit_tax << "|" << comp_info ->address;
        if (!input.eof()) output << endl;
    }
    input.close(); output.close();
}