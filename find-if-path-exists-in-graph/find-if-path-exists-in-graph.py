class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        def createGraph(edges: List[List[int]]) -> Dict:
            graph = defaultdict(list)
            for edge in edges:
                graph[edge[0]].append(edge[1])
                graph[edge[1]].append(edge[0])
            return graph
        graph = createGraph(edges)
        visited = [False]*n
        queue = deque([source])
        while queue:
            current = queue.popleft()
            if current == destination:
                return True
            if visited[current]:
                continue
            visited[current] = True
            for neighbor in graph[current]:
                queue.append(neighbor)
        return False