class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # create graph where the values of a key are prereqs
        def createGraph(prerequisites: List[List[int]]) -> Dict:
            prereqs = {i: [] for i in range(numCourses)}
            for course, prereq in prerequisites:
                prereqs[prereq].append(course)
            return prereqs
        def countParents(graph: Dict, numCourses: int) -> List[int]:
            counts = [0]*numCourses
            for parent in graph:
                for node in graph[parent]:
                    counts[node] += 1
            return counts
        prereqs = createGraph(prerequisites)
        parents_counts = countParents(prereqs, numCourses)
        queue = deque([i for i in range(numCourses) if parents_counts[i] == 0])
        result = []
        while queue:
            current = queue.popleft()
            result.append(current)
            for neighbor in prereqs[current]:
                parents_counts[neighbor] -= 1
                if not parents_counts[neighbor]:
                    queue.append(neighbor)
        return result if len(result) == numCourses else []

        
        
        