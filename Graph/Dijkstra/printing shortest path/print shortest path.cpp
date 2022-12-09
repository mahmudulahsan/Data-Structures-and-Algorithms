#include <bits/stdc++.h>
using namespace std;

void printShortestPath(int currentVertex, vector<int> parents)
{
	if (currentVertex == -1) {
		return;
	}
	printShortestPath(parents[currentVertex], parents);
	cout<<currentVertex<<" ";
}

void printSolution(int start, vector<int> distances, vector<int> parents)
{
	int n = distances.size();
	cout<<"Vertex\t Distance\tPath"<<endl;
	cout<< "------\t --------\t-----";

	for (int vi=0;vi<n;vi++) {
		if (vi != start) {
			cout<<"\n"<<start<<" -> ";
			cout<<vi<< "\t";
			cout<<" "<<distances[vi] << "\t\t";
			printShortestPath(vi, parents);
		}
	}
}

void dijkstra(vector<vector<int>>adjMatrix, int start)
{
	int n = adjMatrix[0].size();
	vector<int> shortestDistances(n);
	vector<bool> added(n);

	for (int i=0;i<n;i++) {
		shortestDistances[i] = INT_MAX;
		added[i] = false;
	}

	shortestDistances[start] = 0;

	vector<int> parents(n);

	parents[start] = -1;

	for (int i = 1; i < n; i++) {
		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vi = 0; vi < n; vi++) {
			if (!added[vi] && shortestDistances[vi] < shortestDistance) {
				nearestVertex = vi;
				shortestDistance = shortestDistances[vi];
			}
		}

		added[nearestVertex] = true;

		for (int vi = 0; vi < n; vi++) {
			int edgeDistance=adjMatrix[nearestVertex][vi];
			if (edgeDistance>0 && ((shortestDistance + edgeDistance) < shortestDistances[vi])) {
				parents[vi] = nearestVertex;
				shortestDistances[vi] = shortestDistance + edgeDistance;
			}
		}
	}

	printSolution(start, shortestDistances, parents);
}

int main()
{
	vector<vector<int> > adjacencyMatrix;

    ifstream input("dijkstra.txt");

    for (int i=0;i<5;i++) {
        vector<int> tmp;
        int x;
        for (int j = 0; j < 5; j++) {
            input>>x;
            tmp.push_back(x);
        }
        adjacencyMatrix.push_back(tmp);
    }

	dijkstra(adjacencyMatrix, 0);

	return 0;
}


//sample inputs
///#1
//0 4 0 0 0 0 0 8 0
//4 0 8 0 0 0 0 11 0
//0 8 0 7 0 4 0 0 2
//0 0 7 0 9 14 0 0 0
//0 0 0 9 0 10 0 0 0
//0 0 4 0 10 0 2 0 0
//0 0 0 14 0 2 0 1 6
//8 11 0 0 0 0 1 0 7
//0 0 2 0 0 0 6 7 0
///#2
//0 10 -1 -1 8
//10 0 8 8 12
//-1 8 0 7 -1
//-1 8 7 0 6
//8 12 -1 6 0
