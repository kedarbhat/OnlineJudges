<h2><a href="https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/">323. Number of Connected Components in an Undirected Graph</a></h2><h3>Medium</h3><hr>Can you solve this real interview question? Number of Connected Components in an Undirected Graph - You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:

[https://assets.leetcode.com/uploads/2021/03/14/conn1-graph.jpg]


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2


Example 2:

[https://assets.leetcode.com/uploads/2021/03/14/conn2-graph.jpg]


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1


 

Constraints:

 * 1 <= n <= 2000
 * 1 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai <= bi < n
 * ai != bi
 * There are no repeated edges.