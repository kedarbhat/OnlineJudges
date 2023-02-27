class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def dfs(current: List[str]) -> bool:
            if len(current) == n:
                result.append(current[:])
                return True
            current_node = current[-1]
            for i, neighbor in enumerate(graph[current_node]):
                if not visited[current_node][i]:
                    visited[current_node][i] = True
                    dfs_result = dfs(current + [neighbor])
                    visited[current_node][i] = False
                    if dfs_result:
                        return True
            return False
            
            
        def createGraph(tickets: List[List[str]]) -> Dict:
            graph = defaultdict(list)
            tickets.sort()
            for source, dest in tickets:
                 graph[source].append(dest)
            return graph
        
        result = []
        n = len(tickets)+1
        graph = createGraph(tickets)
        visited = {}
        for origin, destinations in graph.items():
            destinations.sort()
            visited[origin] = [False]*len(destinations)
        dfs(["JFK"])
        return min(result)
        