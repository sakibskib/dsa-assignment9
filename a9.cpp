#include <iostream>
#include <climits>

using namespace std;

class Node {
public:
  Node() {
    minL = INT_MAX;
    prev = NULL;
  }
  char node;
  int minL;
  Node* prev;
};

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  cout << node->node;
  print(node->prev);
}

const int SIZE = 7;

int main() {
  int weights[SIZE][SIZE];
  for (int a = 0; a < SIZE; a++) {
    for (int b = 0; b < SIZE; b++) {
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

  // Calculate the shortest path
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (weights[i][j] != INT_MAX) {
        node[j].minL = min(node[j].minL, weights[i][j]);
      }
    }
  }

  // Print the shortest path
  cout << node[6].minL << endl;
  print(&node[6]);

  return 0;
}