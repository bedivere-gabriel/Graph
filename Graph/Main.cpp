#include <iostream>
#include "Data.h"
#include <string>

int main(int argc, char** argv) {
	bool running = true;
	int choice, nodes, edges, a, b, c, start, finish;
	choice = nodes = edges = 0;
	char block = 223;
	std::string* places, place;
	AdjacencyListGraph obj;

	while (running) {
		system("cls");
		std::cout << "[1] Create Graph" << std::endl;
		std::cout << "[2] Traversal with DFS" << std::endl;
		std::cout << "[3] Traversal with BFS" << std::endl;
		std::cout << "[4] Path Cost" << std::endl;
		std::cout << "[5] Exit Program" << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			std::cout << "Enter how many nodes: ";
			std::cin >> nodes;
			places = new std::string[nodes];
			for (int x = 0; x < nodes; x++) {
				system("cls");
				std::cout << "Enter Place: ";
				std::cin >> place;
				places[x] = place;
			}
			obj.createAdjacencyListGraph(nodes, places);
			system("cls");
			std::cout << "Enter how many edges: ";
			std::cin >> edges;
			for (int x = 0; x < edges; x++) {
				system("cls");
				std::cout << "Add edge from: ";
				std::cin >> a;
				std::cout << "to: ";
				std::cin >> b;
				std::cout << "Weight: ";
				std::cin >> c;
				obj.addEdge(a, b, c);
			}
			system("cls");

			for (int x = 0; x < 55; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << "This is the Adjacency List Representation of the Graph" << std::endl;
			obj.listPrint();
			for (int x = 0; x < 55; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << "This is the Adjacency Matrix Representation of the Graph" << std::endl;
			obj.displayMatrix();
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << std::endl << "Press any key to continue...";
			system("pause>0");
			break;
		case 2:
			system("cls");
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << "Traversal using Depth-First Search" << std::endl;
			std::cout << "Starting index: ";
			std::cin >> start;
			obj.DFS(start);
			std::cout << std::endl;
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << std::endl << "Press any key to continue...";
			system("pause>0");
			break;
		case 3:
			system("cls");
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << "Traversal using Breadth-First Search" << std::endl;
			std::cout << "Starting index: ";
			std::cin >> start;
			obj.BFS(start);
			std::cout << std::endl;
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << std::endl << "Press any key to continue...";
			system("pause>0");
			break;
		case 4:
			system("cls");
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << "Path Cost using Dijkstra's Shortest Path Algorithm" << std::endl;
			std::cout << "Enter starting index: ";
			std::cin >> start;
			std::cout << "Enter destination index: ";
			std::cin >> finish;
			std::cout << std::endl;
			obj.displayMinPathDistance(start, finish);
			std::cout << std::endl;
			for (int x = 0; x < 40; x++)
				std::cout << block;
			std::cout << std::endl;
			std::cout << std::endl << "Press any key to continue...";
			system("pause>0");
			break;
		case 5:
			system("cls");
			running = false;
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause>0");
}

/*Tester driver
* 	AdjacencyListGraph obj;
	std::string places[5] = {"Bulacan", "Taguig", "Makati", "Manila", "Bigte"};
	obj.createAdjacencyListGraph(5, places);

	obj.addEdge(0, 1, 5);
	obj.addEdge(1, 2, 4);
	obj.addEdge(1, 3, 6);
	obj.addEdge(2, 3, 3);
	obj.addEdge(2, 4, 2);
	obj.addEdge(3, 4, 6);
	obj.listPrint();

	std::cout << "BFS: ";
	obj.BFS(0);
	std::cout << std::endl << "DFS: ";
	obj.DFS(0);
	std::cout << std::endl;
	std::cout << std::endl;
	obj.displayMatrix();
	std::cout << std::endl;
	std::cout << std::endl;
	obj.displayMinPathDistance(0, 4);
*/