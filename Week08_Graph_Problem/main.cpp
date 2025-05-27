#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

#include <cmath>
using namespace std;

/*
        21/05/2025, Initialize Functions & Definition for functions before
        22/05/2025, Definition for Functions isBipairtite(), isCompleteBipairtite()
        23 - 25/05/2025,Definition for the Remainin funcions
*/

vector<vector<int>> convertMatrixToList(const string &filename);
vector<vector<int>> convertListToMatrix(const string &filename);

bool isBipartite(const std::vector<std::vector<int>> &adjMatrix);
bool isCompleteBipartite(const vector<vector<int>> &adjMatrix);
bool isDirected(const vector<vector<int>> &adjMatrix);
vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>> &adjMatrix);
int countVertices(const vector<vector<int>> &adjMatrix);
int countEdges(const vector<vector<int>> &adjMatrix);
vector<int> getIsolatedVertices(const vector<vector<int>> &adjMatrix);
vector<vector<int>> getComplementGraph(const vector<vector<int>> &adjMatrix);
vector<int> findEulerCycle(const vector<vector<int>> &adjMatrix);
vector<vector<int>> dfsSpanningTree(const vector<vector<int>> &adjMatrix, int start);
vector<vector<int>> bfsSpanningTree(const vector<vector<int>> &adjMatrix, int start);
bool isConnected(int u, int v, const vector<vector<int>> &adjMatrix);
vector<int> bellmanFord(int start, int end, const vector<vector<int>> &adjMatrix);



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
                // There is a Vertex Connect to it
                if (adjMatrix[tmp_row][row])
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
// Each Vertices must Connects to each another except connect to Itself
bool isCompleteGraph(const vector<vector<int>> &adjMatrix)
{
    // Empty Case
    if (adjMatrix.empty())
        return false;

    // Check if there is a Node not Connect to other
    int row = 0, column = 0, width = adjMatrix.size();
    while (row < width)
    {
        while (column < width)
        {
            // A Vertex node doesn't Connect to another Node
            if (!(adjMatrix[row][column]) && (row != column))
                return 0;
            ++column;
        }
        ++row;
    }
    return 1;
}

// Undirected Graph
// An Undirected Graph is a Bipartie graph if and only if it doesn't contains any even vertexs cycle
// To Detect a Cycle with number of Vetex in the Cycle is even we need to use Deapth First Search
// The Function Using non-Recursive Backtracking so there will be a Stack to record the path and its next_node
// A vector<int> to mark all the Vertexs that have been visited(the number will different with the default)
bool isBipartite(const vector<vector<int>> &adjMatrix)
{
    int vertex = 0; // Evaluate  all the vertex in the graph
    while (vertex < adjMatrix.size())
    {
        // The Starting Point of the Path/Cycle
        vector<int> record(adjMatrix.size(), -1);           // Record the Path
        stack<pair<int, int>> path;                         // contains the vertex & its current next vertext
        int cur_vertex = vertex, next_vertex = 0, step = 0; // Each move to the New vertex cost 1
        // Detect whether it is a Path/Odd Cycle or even Cycle
        do
        {
            // DFS on vertex
            while (next_vertex < adjMatrix.size() && !adjMatrix[cur_vertex][next_vertex])
                next_vertex++;
            // No Further Walk to go, BackTrack to the Previous Vertex
            if (next_vertex >= adjMatrix.size())
            {
                if (path.empty())
                    break;
                // BackTracking
                // BackTrack
                pair<int, int> tmp = path.top();
                path.pop();
                step = record[tmp.first];
                record[tmp.first] = -1;
                // Go another Path
                cur_vertex = tmp.first;
                next_vertex = ++tmp.second;
                continue;
            }

            // Cycle Detected
            if (record[next_vertex] != -1)
            {
                // Check if it is a cycle & Detect Even Cycle
                if (record[vertex] - record[next_vertex] > 1 && ((step - record[next_vertex] + 1) % 2 == 1))
                    return 0;
                next_vertex++; // Ignore the cycle, visit next vertex
            }
            // The Walk is still a Path
            else
            {
                record[cur_vertex] = step++;
                path.push({cur_vertex, next_vertex}); // Save the vertex & its next vertex
                cur_vertex = next_vertex;
                next_vertex = 0; // Find next vertex of the next node
            }
        } while (true);
        ++vertex;
    }
    return 1;
}

// Undirected Graph
bool isCompleteBipartite(const vector<vector<int>> &adjMatrix)
{
    // Empty  Case
    if (adjMatrix.empty())
        return false;
    // Check if it's a Biparite Graph
    if (!isBipartite(adjMatrix))
        return false;

    vector<int> set1; // Contains all the Vertexs connects to a point
    vector<int> set2; // Contains all the Vertexs doesn't connect to that point
    // choose point 0
    int zero = 0;
    int vertex = 1;
    set2.push_back(zero);
    while (vertex < adjMatrix.size())
    {
        if (adjMatrix[vertex][zero])
            set1.push_back(vertex);
        else
            set2.push_back(vertex);
        ++vertex;
    }

    // Check if each Vertecies of set1 connect to All in set2
    for (int x : set1)
    {
        for (int v : set2)
        {
            // There is a Point not Connect to
            if (!adjMatrix[x][v])
                return 0;
        }
    }
    return 1;
}

// Generate a base undirected graph from a given directed graph.
vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>> &adjMatrix)
{
    if (adjMatrix.empty())
        return adjMatrix;

    vector<vector<int>> undireted_graph = adjMatrix;
    int row = 0, column = 0;
    while (row < adjMatrix.size())
    {
        column = 0;
        while (column < adjMatrix.size())
        {
            undireted_graph[row][column] = undireted_graph[column][row] = max(undireted_graph[row][column], undireted_graph[column][row]);
            ++column;
        }
        ++row;
    }
    return undireted_graph;
}

//  Generate a complement graph from a given undirected graph and output its adjacency matrix (*undirected graph).
vector<vector<int>> getComplementGraph(const vector<vector<int>> &adjMatrix)
{
    // Empty Matrix
    if (adjMatrix.empty())
        return adjMatrix;

    vector<vector<int>> completement(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
    int size = adjMatrix.size();
    for (int i  =  0; i < size; ++i)
        for (int j =  0; j < adjMatrix[i].size();++j)
        {
            completement[i][j] = !adjMatrix[i][j];
        }
    return completement;
}

// Determine the Euler cycle from a given graph using Hierholzer’s Algorithm.
//  Because Directed an Undirected Graph has a different in way to connect between Vertex
//  So the way to mark each path is Different
vector<int> findEulerCycle(const vector<vector<int>> &adjMatrix)
{
    vector<int> euler_cycle;
    vector<pair<int, int>> path;
    vector<vector<int>> graph = adjMatrix;

    // Empty Matrix
    if (adjMatrix.empty())
        return euler_cycle;
    // DFS search
    const int size = adjMatrix.size();

    int start_vertex = 0;
    int cur_vertex = start_vertex, next_vertex = 0; // Default the first vertex is 0(optional)
    bool directed = isDirected(adjMatrix);          // Directed & Undirected Graph Connects its Vertex Different
    while (true)
    {
        while (next_vertex < size && !graph[cur_vertex][next_vertex])
            ++next_vertex;
        if (next_vertex == size)
        {
            // Euler Cycle won't stuck at any Vertex but the starting One( this case is 0)
            if (cur_vertex != start_vertex)
            {
                vector<int> empty_walk;
                return empty_walk;
            }
            // BackTracking
            while (!path.empty() && next_vertex == adjMatrix.size())
            {
                pair<int, int> tmp = path.back();
                path.pop_back();
                cur_vertex = tmp.first;
                next_vertex = tmp.second;
                ++next_vertex;
                // Move to the Next Vertex
                while (next_vertex < adjMatrix.size() && !graph[cur_vertex][next_vertex])
                    ++next_vertex;

                if (next_vertex == adjMatrix.size())
                    continue;
                if (!path.empty())
                    path.back().second = next_vertex;
                // Restore the Edge
                if (directed)
                    graph[tmp.first][tmp.second] = 1;
                else
                    graph[tmp.first][tmp.second] = graph[next_vertex][tmp.second] = 1;
            }

            if (path.empty())
            {
                euler_cycle.push_back(start_vertex);
                break;
            }
            if (!euler_cycle.empty())
            {
                while (euler_cycle.back() != cur_vertex)
                    euler_cycle.pop_back();
                if (!euler_cycle.empty())
                    euler_cycle.pop_back();
            }
            continue;
        }
        // Earse the Edge has been gone  through
        if (directed)
            graph[cur_vertex][next_vertex] = 0;
        else
            graph[cur_vertex][next_vertex] = graph[next_vertex][cur_vertex] = 0;
        // Move to the Next Vertex
        path.push_back({cur_vertex, next_vertex});
        euler_cycle.push_back(cur_vertex);
        cur_vertex = next_vertex;
        next_vertex = 0;
    }
    return euler_cycle;
}

vector<vector<int>> dfsSpanningTree(const vector<vector<int>> &adjMatrix, int start)
{
    int size = adjMatrix.size();
    vector<vector<int>> spanning_tree(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
    vector<bool> record(adjMatrix.size(), 0); //  Record all vertex have gone through
    // Empty Matrix
    if (adjMatrix.empty())
        return spanning_tree;

    // DFS search on Graph
    int cur_vertex = start, next_vertex = 0;
    stack<pair<int, int>> trace; // contains the previous vertex and its next vertex
    do
    {
        while (next_vertex < size && !adjMatrix[cur_vertex][next_vertex])
            next_vertex++;
        // BackTracking
        if (next_vertex == size)
        {
            cur_vertex = trace.top().first;
            next_vertex = ++trace.top().second;
            trace.pop();

            continue;
        }
        // Move to the Next Vertex
        else
        {
            // Vetex's Already been Colored
            if (record[next_vertex])
                next_vertex++;
            // Otherwise
            else
            {
                // Connect to  the Spanning Tree
                spanning_tree[cur_vertex][next_vertex] = spanning_tree[next_vertex][cur_vertex] = adjMatrix[cur_vertex][next_vertex];

                trace.push({cur_vertex, next_vertex});
                record[next_vertex] = 1; // Color the Vertex
                // Move to the Next Vertex
                cur_vertex = next_vertex;
                next_vertex = 0;
            }
        }
    } while (!trace.empty());
    return spanning_tree;
}

vector<vector<int>> bfsSpanningTree(const vector<vector<int>> &adjMatrix, int start)
{
    int size = adjMatrix.size();
    vector<vector<int>> spanning_tree(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
    vector<bool> record(adjMatrix.size(), 0); //  Record all vertex have gone through
    // Empty Matrix
    if (adjMatrix.empty())
        return spanning_tree;

    // BFS Search on a Graph
    int cur_vertex = start, next_vertex = 0;
    queue<pair<int, int>> trace; // contains the previous vertex and its next vertex
    trace.push({cur_vertex, next_vertex});
    do
    {
        while (next_vertex < size && !adjMatrix[cur_vertex][next_vertex])
            next_vertex++;
        // Found a Vertex Connect to Current Vertex
        if (next_vertex < size)
        {
            // Egde has not been Connected
            if (!record[next_vertex])
            {
                spanning_tree[cur_vertex][next_vertex] = spanning_tree[next_vertex][cur_vertex] = adjMatrix[cur_vertex][next_vertex];
                record[next_vertex] = 1; // Color the Vertex
                trace.push({next_vertex, -1});
            }
            next_vertex++; // Move to the Next Vertex
        }
        // Dead End
        else
        {
            trace.pop();
            cur_vertex = trace.front().first;
            next_vertex = ++trace.front().second;
            continue;
        }
    } while (!trace.empty());
    return spanning_tree;
}

// Verify the connection between two vertices of a given graph.
bool isConnected(int u, int v, const vector<vector<int>> &adjMatrix)
{
    int size = adjMatrix.size();
    vector<bool> record(adjMatrix.size(), 0); //  Record all vertex have gone through

    // Empty Matrix
    if (adjMatrix.empty())
        return false;

    // BFS Search on a Graph
    int cur_vertex = u, next_vertex = 0;
    queue<pair<int, int>> trace; // contains the previous vertex and its next vertex
    trace.push({cur_vertex, next_vertex});
    do
    {
        while (next_vertex < size && !adjMatrix[cur_vertex][next_vertex])
            next_vertex++;
        // Found a Vertex Connect to Current Vertex
        if (next_vertex < size)
        {
            if (next_vertex == v)
                return true;
            // Egde has not been Connected
            if (!record[next_vertex])
            {
                record[next_vertex] = 1; // Color the Vertex
                trace.push({next_vertex, -1});
            }
            next_vertex++; // Move to the Next Vertex
        }
        // Dead End
        else
        {
            trace.pop();
            cur_vertex = trace.front().first;
            next_vertex = ++trace.front().second;
            continue;
        }
    } while (!trace.empty());
    return false || isConnected(v, u, adjMatrix);
}

/*
vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix)
{
    vector<vector<int>> graph(adjMatrix.size(),vector<int>(adjMatrix.size(),INT_MAX));

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> frontier;
    vector<int> distance(adjMatrix.size(),INT_MAX); // Contains Distance of each Vertex from Starting Vertex
    vector<int> path;                               // the Path from the Starting vertex to Destination Vertex
    // Empty Matrix
    if (adjMatrix.empty()) return path;

    const int size = adjMatrix.size();

    int cur_vertex = start, des_vertex = 0;

    distance[cur_vertex] =  0;                       // Initialize the Starting position
    path.push_back(cur_vertex);
    frontier.push({0, cur_vertex});

    while (!frontier.empty())
    {
        // Take a Vertex to Explore
        cur_vertex = frontier.top().second;
        des_vertex = 0;
        frontier.pop();
        // Get all the Possible Vertex
        while (des_vertex < size)
        {
            if (adjMatrix[cur_vertex][des_vertex] != 0)
            {
                int dist = distance[cur_vertex] + adjMatrix[cur_vertex][des_vertex];
                if (dist < distance[des_vertex])        // There's a Path Shorter
                {
                    graph[cur_vertex][des_vertex] = graph[des_vertex][cur_vertex] = dist;
                    path.push_back(des_vertex);
                    distance[des_vertex] = dist;

                    frontier.push({dist, des_vertex});
                }
            }
            des_vertex++;
        }
    }
    // Retreve from the End Vertex
        stack <int> result;
        while (cur_vertex != start)
        {
            int smallest_index = 0;     // index of the Smallest edge
            cur_vertex = end; des_vertex = 0;
            while (des_vertex < size)
            {
                smallest_index = graph[cur_vertex][des_vertex] < graph[cur_vertex][smallest_index] ? des_vertex:smallest_index;
                ++des_vertex;
            }

            cur_vertex = smallest_index;
            des_vertex = 0;
            result.push(cur_vertex);
        }
        vector <int> path_result  = {start};
        while (!result.empty())
        {
            path_result.push_back(result.top());
            result.pop();
        }
        return path_result;
}*/
// This Version was Fixed by ChatGPT to hanlde remaining error
// the old version is in the comment section above
vector<int> dijkstra(int start, int end, const vector<vector<int>> &adjMatrix)
{
    const int size = adjMatrix.size();

    vector<int> distance(size, INT_MAX);
    vector<int> prev(size, -1); // lưu đỉnh trước đó trong đường đi
    vector<bool> visited(size, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (int v = 0; v < size; ++v)
        {
            if (adjMatrix[u][v] > 0)
            { // nếu có cạnh
                int alt = distance[u] + adjMatrix[u][v];
                if (alt < distance[v])
                {
                    distance[v] = alt;
                    prev[v] = u; // ghi nhận đỉnh trước
                    pq.push({alt, v});
                }
            }
        }
    }

    // Xây dựng đường đi từ end về start
    vector<int> path;
    for (int at = end; at != -1; at = prev[at])
    {
        path.push_back(at);
    }
    path = vector<int>(path.rbegin(), path.rend());

    if (path[0] != start)
        return {}; // không có đường đi

    return path;
}

vector<int> bellmanFord(int start, int end, const vector<vector<int>> &adjMatrix)
{
    // Empty Matrix
    if (adjMatrix.empty())
        return {};

    const int size = adjMatrix.size();

    vector<int> distance(size, INT_MAX);
    vector<int> predecessor(size, -1);
    queue<int> frontier;

    int  u = start;
    distance[start] = 0;                    // Initialize the Starting Vertex as starting Vertex
    // Relax Egde repeately
    for (int i = 1; i <= size - 1; ++i)
    {
        for (int v = 0; v <  size; ++v)
        {
            int weight = adjMatrix[u][v];
            if (weight && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
                // Save the neighbour Vertex for later Visit
                frontier.push(v);
            }
        }
        // Visit Next Vertex
        u = frontier.front(); frontier.pop();
    }
    // Check for Negative-Weight Cycle
    for (int i = 0;  i <= size -1; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int weight = adjMatrix[i][j];
            if (weight == 0) continue;      // Unconnected Vertex
            if (distance[i] + weight < distance[j])
            {
                predecessor[j] = i;
                // Negative Cycle Exist
                //Find a Vertex in the Cycle
                vector<bool>  visited(size,false);
                visited[j] = true;
                while (!visited[i])
                {
                    visited[i] = true;
                    i = predecessor[i];
                }
                // i is the Vertex in the Cycle
                // Find the Cycle itself
                vector<int> ncycle = {i};
                j = predecessor[i];
                while (j != i)
                {
                    ncycle.push_back(j);
                    j = predecessor[j];
                }
                // Execute Error
                cout << "Graph Contains a Negative-Weight Cycle\n";
                for (int x: ncycle)
                    cout << x << "\t";
                cout << endl;
                return {};
            }
        }
    }

    // Trace Back the Path if there is a Valid Path
    if (predecessor[end] != -1)
    {
        vector<int> path;
        int vertex = end;
        while (vertex != start)
        {
            path.push_back(vertex);
            vertex = predecessor[vertex];
        }
        path.push_back(start);                          // Push the starting Vertex

        path = vector<int>(path.rbegin(), path.rend());
        return path;
    }
    //  No Valid Path was Found
    return {};
}
