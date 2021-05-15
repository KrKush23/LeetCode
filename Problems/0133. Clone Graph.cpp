/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
	void dfs(Node* cur, Node* node, vector<Node*> &visited) {
		// Store the clone
		visited[node->val] = node;
		for (auto i : cur->neighbors) {
			if (visited[i->val] == NULL) {
				Node* newnode = new Node(i->val);
				(node->neighbors).push_back(newnode);
				dfs(i, newnode, visited);
			} else {
				(node->neighbors).push_back(visited[i->val]);
			}
		}
	}
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return NULL;

		// visited array will store the corresponding clones
		vector<Node*> visited(1000, NULL);

		// Clone of root node and storing clone in VISITED
		Node* root = new Node(node->val);
		visited[node->val] = root;

		// Looping through all neighbours of ROOT
		for (auto cur : node->neighbors) {
			// Clone not yet created
			if (visited[cur->val] == NULL) {
				// Create the clone and add to adjacency list of ROOT
				Node* copy = new Node(cur->val);
				(root -> neighbors).push_back(copy);
				// DFS with parent, nbr, visited
				dfs(cur, copy, visited);
			}
			// Clone already created
			else {
				(root->neighbors).push_back(visited[cur->val]);
			}
		}
		return root;
	}
};
