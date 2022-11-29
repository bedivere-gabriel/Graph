#pragma once

#include <list>
#include <vector>
#include <iostream>

class AdjecencyListGraph {
private:
	int V;
	std::list <std::pair<int, int>>* adj;
	void DFSUtil(int v, bool visited[]);
	std::string* places;
	std::vector<std::vector<int> > convert(std::list <std::pair<int, int>>* adj, int V);

public:
	void createAdjecencyListGraph(int v, std::string names[]);
	void addEdge(int u, int v, int w);
	void listPrint();
	void DFS(int v);
	void BFS(int s);
	void pathCost(std::string start, std::string finish);
	void printMatrix(std::vector<std::vector<int>> adj, int V);
	~AdjecencyListGraph();
};