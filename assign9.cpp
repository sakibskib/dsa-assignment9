#include<iostream>
#include<climits>

using namespace std;

class Node{
public:
    Node()
    {
        minL= INT_MAX;
    }
    char node;
    int minL;
    Node* prev;
};
 
void print(Node *node)
{
    if(node->prev != NULL) {
        print(node->prev);
        cout << " -> ";
    }
    cout << node->node;
}

const int SIZE = 7;

int main()
{
    int weights[SIZE][SIZE];    
    for (int a = 0; a < SIZE; a++)
    {
        for (int b = 0; b < SIZE; b++)
        {
            weights[a][b] = INT_MAX;
        }
    }
    weights[0][1] = 2;
    weights[0][2] = 5;
    weights[0][3] = 4;
    weights[1][2] = 2;
    weights[1][4] = 7;
    weights[2][3] = 1;
    weights[2][4] = 4;
    weights[2][5] = 3;
    weights[3][5] = 4;
    weights[4][5] = 1;
    weights[4][6] = 5;
    weights[5][6] = 7;
    
    Node node[8];
    node[0].node = 'O';
    node[0].prev = NULL;
    
    node[1].node = 'A';
    node[2].node = 'B';
    node[3].node = 'C';
    node[4].node = 'D';
    node[5].node = 'E';
    node[6].node = 'T';
    
    // Dijkstra's algorithm implementation
    bool visited[SIZE] = { false };
    node[0].minL = 0;
    for(int i=0; i<SIZE-1; i++) {
        int minIndex = -1;
        for(int j=0; j<SIZE; j++) {
            if(!visited[j] && (minIndex == -1 || node[j].minL < node[minIndex].minL)) {
                minIndex = j;
            }
        }
        visited[minIndex] = true;
        for(int k=0; k<SIZE; k++) {
            if(weights[minIndex][k] != INT_MAX && node[k].minL > node[minIndex].minL + weights[minIndex][k]) {
                node[k].minL = node[minIndex].minL + weights[minIndex][k];
                node[k].prev = &node[minIndex];
            }
        }
    }

    cout << node[6].minL << endl;
    print(&node[6]);
    
    return 0;
}
