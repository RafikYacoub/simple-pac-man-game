#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
const int COUNT = 591;
const int INFINITE = 9999;
const int terminal = 56;

vector<int> Dijkstra(int **Graph, int startNode, int terminal);

void main()
{
	ifstream input;
	int x;
	input.open("matrix.txt");

	int** Graph = new int* [COUNT];
	for (int i = 0; i < COUNT; i++)
		*(Graph + i) = new int[COUNT];

	for (int i =0 ; i< COUNT ; i++)
		for (int j = 0; j < COUNT; j++)
		{
			input >> x;
			*(*(Graph + i) + j) = x; 

		}


vector<int> paths = Dijkstra(Graph, 0, terminal);
	for (int j = 0; j <paths.size(); j++)
		cout << paths[j] << " ";
	cout << endl;

}
vector<int> Dijkstra(int **Graph, int startNode ,int terminal)
{
	int costs[COUNT], previous[COUNT];
	int** temp = new int* [COUNT];
	for (int i = 0; i < COUNT; i++)
		*(temp + i) = new int[COUNT];

	bool visited[COUNT];
	// temp
	for (int i = 0; i < COUNT; i++)
		for (int j = 0; j < COUNT; j++)
			if (Graph[i][j] == 0)
				temp[i][j] = INFINITE;
			else
				temp[i][j] = Graph[i][j];
	// costs, previous, and visited
	for (int i = 0; i < COUNT; i++)
	{
		costs[i] = temp[startNode][i];
		previous[i] = startNode;
		visited[i] = false;
	}
	// startNode
	costs[startNode] = 0;
	visited[startNode] = true;

	int count = 1, nextNode, minimumCost;
	while (count < COUNT)
	{
		// Find the minimum cost in order to visit a node.
		minimumCost = INFINITE; 
		for (int i = 0; i < COUNT; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		// Visit the node.
		visited[nextNode] = true;
		// Update the costs of the children of the visited node.
		for (int i = 0; i < COUNT; i++)
			if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + temp[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}

	for (int i = 0; i < COUNT; i++)
		delete[] * (temp + i);
	delete[] temp;
	// Fill the paths.
	int j;
	vector<vector<int>> paths;
	paths.resize(COUNT);
	for (int i = 0; i < COUNT; i++)
	{
		paths[i].push_back(i);
		if (i != startNode)
		{
			j = i;
			do
			{
				j = previous[j];
				paths[i].push_back(j);
			} while (j != startNode);
		}
	}

	reverse(paths[terminal].begin(), paths[terminal].end());
	return paths[terminal];
}