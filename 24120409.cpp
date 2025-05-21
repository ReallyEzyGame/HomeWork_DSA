#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int>> convertMatrixToList(const string &filename);
vector<vector<int>> convertListToMatrix(const string &filename);

// Directed or Undirected Graph
bool isDirected(const vector<vector<int>> &adjMatrix);

// The number of vertices.
int countVertices(const vector<vector<int>> &adjMatrix);

// The Number of the Edge
int countEdges(const vector<vector<int>> &adjMatrix);

// List of isolated vertices.
vector<int> getIsolatedVertices(const vector<vector<int>> &adjMatrix);

// Undirected Graph.
bool isCompleteGraph(const vector<vector<int>> &adjMatrix);
// Input: the first line is the size of the Matrix, other lines are the values represent a square matrix has the size of the int in the first line
vector<vector<int>> convertMatrixToList(const string &filename)
{
    ifstream input(filename);
    vector<vector<int>> ans;

    int matrix_size;
    input >> matrix_size;
    if (matrix_size <= 0)
        throw(102); // Invalid matrix size

    ans.push_back(vector<int>(1, matrix_size)); // get the Size of the Matrix

    int row = 0, column = 0;
    while (row < matrix_size)
    {
        column = 0;
        vector<int> list;
        // Get all the egde from a row
        while (column < matrix_size)
        {
            int val = 0;
            input >> val;
            if (val)
                list.push_back(column);
            ++column;
        }
        // Get the Result of a Row
        vector<int> row_res;
        row_res.push_back(list.size());
        for (int val : list)
            row_res.push_back(val);

        ans.push_back(row_res);
        ++row;
    }
    input.close();
    return ans;
}
// Input: the first line is the size of the Matrix, other lines contains the index of the edge in the matrix
vector<vector<int>> convertListToMatrix(const string &filename)
{
    // input file
    ifstream input(filename);
    if (!input.is_open())
        throw(404); // Unable to Open the File: file may not exist

    vector<vector<int>> ans;

    // get from the file
    // the first number is the number the edge connect to
    // the remaining is the index of the egde on the row
    int matrix_size;
    input >> matrix_size;
    if (matrix_size <= 0)
    {
        input.close();
        throw(405);
    } // Invalid matrix Size

    // ans.push_back(vector<int>(1, matrix_size)); // Get the Size of the Matix
    //    Converte Process
    int row = 0, column = 0;
    while (row < matrix_size)
    {
        vector<int> row_list(matrix_size, 0); // Row contains the Edge that current Edge connect to
        int edge_cnt;
        input >> edge_cnt;
        // Get a row of edge that current Edge connect to
        while (edge_cnt > 0)
        {
            int index;
            input >> index;
            row_list[index] = 1;
            --edge_cnt;
        }

        ans.push_back(row_list);
        ++row;
    }
    input.close();
    return ans;
}

// Find if the Graph is Directed or Undirected Grpah
// Consider the matrix Are Square matrix
bool isDirected(const vector<vector<int>> &adjMatrix)
{
    // Empty Case
    if (adjMatrix.empty())
        return 0;

    // The Undirected Graph has matrix[r][c] == matrix[c][r]
    int row = 0, column = 0, bound = adjMatrix.size();
    while (row < bound)
    {
        while (column < bound)
        {
            if (adjMatrix[row][column] != adjMatrix[column][row])
                return 1;
            ++column;
        }
        ++row;
    }
    return 0;
}
// The number of vertices.
int countVertices(const vector<vector<int>> &adjMatrix)
{
    // Empty Case
    if (adjMatrix.empty())
        return -1;
    return adjMatrix.size();
}
// The Number of Edge
int countEdges(const vector<vector<int>> &adjMatrix)
{
    // Empty Case
    if (adjMatrix.empty())
        return -1;

    vector<vector<int>> list = adjMatrix;

    int row = 0, column = 0, cnt = 0;
    while (row < adjMatrix.size())
    {
        column = 0;
        while (column < list[row].size())
        {
            if (list[row][column])
            {
                list[column][row] = 0; // Only Count the Edge Once
                cnt++;
            }
            column++;
        }
        row++;
    }
    return cnt;
}

// List of isolated vertices.
vector<int> getIsolatedVertices(const vector<vector<int>> &adjMatrix)
{
    vector<int> ans;
    // Empty Matrix
    if (adjMatrix.empty())
        return ans;

    int row = 0, column = 0;
    while (row < adjMatrix.size())
    {
        column = 0;
        bool line_zero = 1;
        // Check if it Connects to any Vetex
        while (column < adjMatrix.size())
        {
            if (adjMatrix[row][column])
            {
                line_zero = 0;
                break;
            }
            column++;
        }
        // Check if any Vertex Connects to it
        if (!line_zero)
        {
            int tmp_row = 0;
            while (tmp_row < adjMatrix.size())
            {
                if (adjMatrix[tmp_row][row]) // There is a Vertex Connect to it
                {
                    line_zero = 0;
                    break;
                }
                tmp_row++;
            }
            if (line_zero)
                ans.push_back(row);
        }
        ++row;
    }
    return ans;
}

// Undirected Graph.
bool isCompleteGraph(const vector<vector<int>> &adjMatrix)
{
    // Empty Case
    if (adjMatrix.empty())
        return false;

    // All the Ponit
}
int main()
{
    vector<vector<int>> result = convertListToMatrix("input.txt");
    vector<int> test = getIsolatedVertices(result);
    for (int x : test)
        cout << x << endl;
}