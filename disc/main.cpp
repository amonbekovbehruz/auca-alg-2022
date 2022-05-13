#include<iostream>
#include<vector>
using namespace std;

//print function
void print(vector<int> path){
	for (int i = 0; i < path.size(); ++i)
	{
		cout<<path[i]<<" ";
	}
	cout<<endl;
}

//checks if the dot can be added to the path
bool isSafe(vector<int> path, int curr_v, int count){
	for (int i = 0; i < count; ++i)
	{
		if(path[i] == curr_v)
			return false;
	}
	return true;
}

bool hamiltonianCycle(vector< vector<bool> > &graph, vector<int> &path, int curr_v, int count){

	if (count >= graph[0].size() && graph[curr_v][path[0]] == true)
		return true;

	// checking neighbour vertices
	for (int i = 0; i < graph[0].size(); ++i)
	{
		// check is there an edge
		if(graph[curr_v][i] == true){
			if(isSafe(path, i, count)){
				path[count] = i;

				if(hamiltonianCycle(graph,path,i,count+1)) {return true;}
			}
		}
	}
	return false;
}

/// main function to check the adjacency list
void hamiltonianCycleChecker(vector< vector<bool> > &graph){
	vector<int> path(graph[0].size(),-1); // creating empty matrix

	int count = 0;
	//shows that the first node for the hamiltonian path is 0
	path[count] = 0;
	int curr_v = 0;
	if( hamiltonianCycle(graph,path,curr_v,count+1))
		print(path);
	else
		cout << "No hamiltonian cycle is present\n";
}

int main(){
	vector<vector<bool> >graph1 = {{0, 1, 0, 1, 0},
                                   {1, 0, 1, 1, 1},
                                   {0, 1, 0, 0, 1},
                                   {1, 1, 0, 0, 1},
                                   {0, 1, 1, 1, 0},
                                  };

    hamiltonianCycleChecker(graph1);

    vector<vector<bool> >graph2 = {{0, 1, 0, 1, 0},
                                  {1, 0, 1, 1, 1},
                                  {0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 0},
                                  {0, 1, 1, 0, 0},
                                  };

	hamiltonianCycleChecker(graph2);
}