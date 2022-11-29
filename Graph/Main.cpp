#include <iostream>
#include "Data.h"
#include <string>

int main(int argc, char** argv) {
	//bool running = true;
	//int choice, nodes, edges, a, b, c;
	//choice = nodes = edges = 0;
	//std::string* places, place;
	//AdjecencyListGraph obj;

	//while (running) {
	//	system("cls");
	//	std::cout << "[1] Create Graph" << std::endl;
	//	std::cout << "[2] Traversal with DFS" << std::endl;
	//	std::cout << "[3] Traversal with BFS" << std::endl;
	//	std::cout << "[4] Path Cost" << std::endl;
	//	std::cout << "[5] Exit Program" << std::endl;
	//	std::cin >> choice;

	//	switch (choice) {
	//	case 1:
	//		system("cls");
	//		std::cout << "Enter how many nodes: ";
	//		std::cin >> nodes;
	//		obj.createAdjecencyListGraph(nodes);
	//		places = new std::string[nodes];
	//		for (int x = 0; x < nodes; x++) {
	//			system("cls");
	//			std::cout << "Enter Place: ";
	//			std::cin >> place;
	//			places[x] = place;
	//		}
	//		system("cls");
	//		std::cout << "Enter how many edges: ";
	//		std::cin >> edges;
	//		for (int x = 0; x < edges; x++) {
	//			std::cout << "Add edge from: ";
	//			std::cin >> a;
	//			std::cout << "to: ";
	//			std::cin >> b;
	//			std::cout << "Weight: ";
	//			std::cin >> c;
	//			obj.addEdge(a, b, c);
	//		}
	//		system("cls");
	//		obj.listPrint();
	//		system("pause>0");
	//		break;
	//	case 2:
	//		system("cls");
	//		break;
	//	case 3:
	//		system("cls");
	//		break;
	//	case 4:
	//		system("cls");
	//		break;
	//	case 5:
	//		system("cls");
	//		break;
	//	default:
	//		system("cls");
	//		break;
	//	}
	//}

	AdjecencyListGraph obj;
	std::string places[10] = {"Bulacan", "Marikina", "Makati", "Manila", "Quezon City", "Valenzuela", "La Union", "Japan", "Tokyo", "Bigte"};
	obj.createAdjecencyListGraph(10, places);

	obj.addEdge(0, 1, 10);
	obj.addEdge(0, 2, 10);
	obj.addEdge(0, 3, 10);
	obj.addEdge(0, 4, 10);
	obj.addEdge(1, 2, 10);
	obj.addEdge(1, 3, 10);
	obj.addEdge(2, 5, 10);
	obj.addEdge(5, 6, 10);
	obj.addEdge(2, 3, 10);
	obj.addEdge(5, 7, 10);
	obj.addEdge(4, 8, 10);
	obj.addEdge(8, 9, 10);
	obj.addEdge(6, 7, 10);
	obj.addEdge(6, 8, 10);
	obj.addEdge(7, 8, 10);
	obj.listPrint();

	std::cout << "BFS: ";
	obj.BFS(0);
	std::cout << std::endl << "DFS: ";
	obj.DFS(0);
	std::cout << std::endl;
	obj.pathCost("bigte", "quezon city");


	system("pause>0");
}