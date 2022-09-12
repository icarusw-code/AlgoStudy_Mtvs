## 그래프 이론, DFS, BFS

### 정점과 간선

"어떤 곳" 에서 부터 "무언가로 간다" 라고 했을 때 "어떤 곳"은 **정점(Vertex)** 가 되고 "무언가로 간다"는 **간선(Edge)**

그래프(Graph) : 정점과 간선들로 이루어진 집합



### 트리

그래프 이론에서 사이클이 없는 무방향 그래프 또는 사이클이 없는 방향그래프인 DAG(Directed Acyclic Graph)를 지칭

![image](https://user-images.githubusercontent.com/77170611/189655734-15242b39-610d-404e-8d2a-25bb1cad7a44.png)

트리의 특징

- 부모, 자식 계층구조를 가진다.
- V(노드의 수) - 1 = E(간선의 수) 라는 특징이 있다.
- 임의의 두 노드 사이의 경로는 "유일무이" 하며 "존재" 한다. 즉, 트리 내의 어떤 노드와 어떤 노드 까지 갈 수 있다.

루트 노드 : 가장 위에 있는 노드. 보통 트리 문제에서 탐색할 때 루트노드를 중심으로 탐색을 하면 쉽게 풀린다.

내부 노드 : 루트 노드와 내부노드 사이에 있는 노드를 뜻한다.

리프 노드 : 자식노드가 없는 노드

![image](https://user-images.githubusercontent.com/77170611/189656791-210d40a8-ad09-4620-8441-1c4e927d74fb.png)

이진 트리 : 자식의 노드 수가 2개 이하인 트리를 의미한다.

이진 트리의 종류

![image](https://user-images.githubusercontent.com/77170611/189657052-f7c4a04a-6965-4535-93da-d6b3aa2f6a22.png)



### 이진 탐색 트리

![image](https://user-images.githubusercontent.com/77170611/189657191-127b4c6d-456c-4d24-9679-32114c323c1d.png)

노드의 오른쪽 하위 트리에는 "노드의 값보다 큰 값"이 있는 노드만 포함하고, 왼쪽 하위트리에는 "노드의 값보다 작은값"이 들어있는 트리를 말한다. => "검색"을 하기에 매우 용이하다.



### DAG(Directed Acyclic Graph)

방향성이 있고 사이클이 없는 그래프

![image](https://user-images.githubusercontent.com/77170611/189658153-909189b6-0a74-4463-a06d-90bb635b7d73.png)



### 그래프 표현 방법

#### 1. 인접행렬

그래프에서 정점과 간선의 관계를 나타내는 정사각형 행렬을 의미한다.

2차원 Bool 배열을 이용하여 존재여부를 확인

```c++
bool a[1000][1000];
for(int i = 0; i < V; i++)
{
	for(int j = 0; j < V; j++)
	{
		if(a[i][j])
		{
			cout << i << "부터" << j << "까지의 경로가 존재한다." << "\n";
		}
	}
}
```



#### 2. 인접리스트

정점에서 정점을 연결하는 것을 한나의 연결 리스트를 통해 표현하는것

벡터 여러개를 이용해 인접한 노드들을 그 Vector에 담아준다.

```c++
vector<int> adj[1000];
// 1번 노드에서 2번 노드로 간다.
adj[1]push_back(2);

for(int i = 0; i < V; i++)
{
    for(int there : adj[i])
    {
        
    }
}


```



#### 3. 탐색방법

1. 4가지 방향을 탐색하라고 할때

   ​			(y-1 , x)

   (y, x-1)    (y, x)    (y, x+1)

   ​			(y+1, x)

   ```c++
   // 시계 방향으로 방향 벡터를 만듬
   const int dy[] = {-1, 0, 1, 0};
   const int dx[] = {0, 1, 0, -1}; 
   ```

   예시) 맵은 x,y는 0이상 1000미만의 좌표를 가진다. {1, 1} 좌표에서 4방향을 출력하시오 또한 맵에 벗어나지 않도록

   ```c++
   #include <iostream>
   #include <vector>
   
   int a[1004][1004];
   
   const int dy = {-1, 0, 1, 0};
   const int dx = {0, 1, 0, -1};
   
   int main()
   {
       int y = 1;
       int x = 1;
       for(int i = 0; i <4; i++)
       {
           int ny = y + dy[i];
           int nx = x + dx[i];
           if(ny < 0 || ny >= 1000 || nx < 0 || nx >= 1000) continue;
           cout << ny << " : " << nx "\n";
       }    
       return 0;
   }
   
   ```

   ```
   0 : 1
   1 : 0
   ```

   

2. 노드와 노드 사이의 인접리스트로 주어질 때

   정점으로 부터 연결된 지점을 there로 정의하고 탐색하면 된다.

   ```c++
   #include <iostream>
   #include <vector>
   
   using namespace std;
   
   vector<int> adj[1004];
   
   int main()
   {
       adj[1].push_back(2);
       adj[1].push_back(3);
       for(int there : adj[1])
       {
           cout << there << "\n";
       }
       return 0;
   }
   ```

   ```
   2
   3
   ```



### DFS(깊이 우선 탐색)

특정한 노드에서 가장 멀리 있는 노드를 먼저 탐색하는 알고리즘

주어진 맵 전체를 탐색하면 한번 방문한 노드는 다시 방문하지 않는다.

**수도코드**

어떠한 정점 u의 visited를 참으로 바꾸고, u로 부터 연결되어 있는 v지점을 탐색한다.

이때 방문되지 않은 노드에 대해 재귀적으로 DFS를 호출한다.

```c++
DFS(G, u)
	u.visited = true
	for each v ∈ G.Adj[u]
		if v.visited == false
			DFS(G, v)
```

![image](https://user-images.githubusercontent.com/77170611/189666226-a4e29e69-6663-4e11-9567-e16b5fff1211.png)



**구현 방법**

1. 들어가기 전에 확인 하는 방법

   방문 되었다면 방문을 하지 않고, 방문이 안되어있다면 방문을 하는 방법

   ```c++
   void dfs(int here)
   {
       visited[here] = 1;
       for(int there : adj[here])
       {
           if(visited[there]) continue;
           dfs(there);
       }
   }
   ```

   

2. 일단 들어가서 확인 하는 방법

   ```c++
   void dfs(int here)
   {
   	if(visited[here]) return;
       visited[here] = 1;
       for(int there : adj[here])
       {
           dfs(there);
       }
   }
   ```

   

### BFS(너비 우선 탐색)

노드에서 시작해 이웃한 노드들을 먼저 탐색하는 알고리즘이자 같은 가중치를 가진 그래프에서 최단거리 알고리즘으로 사용된다. 만약 가중치가 다른 그래프라면 다익스트라, 벨만포드 알고리즘을 사용해야한다.

**수도코드**

1. 먼저 시작지점인 u를 "방문처리"하고 "queue" 에 푸시한다. 그리고 q.size() 만큼 while 반목문을 돌면서 큐 앞에 있는 u를 다시 꺼내어 그 u를 중심으로 인접한 노드들을 탐색한다.

   방문한 정점은 다시 방문하지 않고 방문처리를 하면서 queue에 푸시하며 방문처리를 한다.

   ```c++
   BFS(G, u)
   	u.visited = true
   	q.push(u)
   	while(q.size())
   		u = q.front()
   		q.pop()
   		for each v ∈ G.Adj[u]
   			if v.visited == false
   				v.visted = true
   				q.push(v)
   ```

2. 실제 문제 풀때 자주 사용하는 방법

   v.visited = u.visited + 1로 최단거리 배열을 만든다. 

   시작지점이 다수라면 큐에 푸시하는 지점도 다수가 되어야 하므로 모두 visited를 1로 만드록 시작해야 한다.

   ```c++
   BFS(G, u)
       u.visited = 1
       q.push(u)
       while(q.size())
           u = q.front()
           q.pop()
           for each v ∈ G.Adj[u]
               if v.visited == false
                   v.visited = u.visited + 1
                   q.push(v)
   ```

   ![image](https://user-images.githubusercontent.com/77170611/189676210-2ba61726-c62b-42ee-9400-89659037e31b.png)

   

   ![image](https://user-images.githubusercontent.com/77170611/189676329-54563c3c-eda2-494e-9d14-ad4dc3140e26.png)















