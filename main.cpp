#include <iostream>
#include <stack>
#include <list>
#include <time.h>


using namespace std;

// клас для представлення графа
class Graph {
 // No. вершин
 int K;

 // вказівник на масив, який містить списки суміжності
 list<int>* adj;

 // фунцкія, яка використовує topologicalSort
 void topologicalSortUtil(int k, bool visited[], stack<int>& Stack);
    
public:
 Graph(int K);
 // функція, яка додає ребро до графу
 void addEdge(int k, int l);

 // друкує topologicalSort готового графа
 void topologicalSort();
};

Graph::Graph(int K)
{
 this->K = K;
 adj = new list<int>[K];
}

void Graph::addEdge(int k, int l)
{

 //Додає l до списку k
 adj[k].push_back(l);
}

// Рекурсивна функція, яку використовує topologicalSort
void Graph::topologicalSortUtil(int k, bool visited[],
 stack<int>& Stack)
{
 // позначає поточний вузол як відвіданий
 visited[k] = true;

 //Повторює для всіх вершин, прилеглих до цієї вершини
 list<int>::iterator i;
 for (i = adj[k].begin(); i != adj[k].end(); ++i)
  if (!visited[*i])
   topologicalSortUtil(*i, visited, Stack);

 // додає вершину до стаку, що зберігає результат
 Stack.push(k);
}

// функція виконує topologicalSort, використовуючи рекурсвність topologicalSortUtil
void Graph::topologicalSort()
{
 stack<int> Stack;

 //Позначає всі вершини як не відвідані
 bool* visited = new bool[K];
 for (int i = 0; i < K; i++)
  visited[i] = false;

 //Викликає рекурсивну функцію помічника для зберігання топологічного сортування, починаючи з усіх вершин по черзі
 for (int i = 0; i < K; i++)
  if (visited[i] == false)
   topologicalSortUtil(i, visited, Stack);

 // друкує вміст стеку
 while (Stack.empty() == false) {
  cout << Stack.top() << " ";
  Stack.pop();
 }
}
// перевіряє вищевказані функції
int main()
{
 //Створює граф
 Graph G(6);
 G.addEdge(5, 2);
 G.addEdge(5, 0);
 G.addEdge(4, 0);
 G.addEdge(4, 1);
 G.addEdge(2, 3);
 G.addEdge(3, 1);

 cout << "Topological Sort of the graph G is:\n";
 G.topologicalSort();

 return 0;
}
