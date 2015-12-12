package graphs;

import java.util.*;
import java.util.Map.Entry;


/**
 * An object-oriented Graph class, with collections of Nodes and Edges.
 * <p>
 * Nodes are of type {@linkplain graphs.GraphNode}
 * 
 * @author Tommy Doerr
 *
 * @param <T>
 * 	A generic type for each graph node's data 
 */
public class Graph<T> {
	
	private int nodeCount;
	private int edgeCount;
	private Map<T, GraphNode<T>> nodes;
	
	public Graph () {
		nodeCount = 0;
		edgeCount = 0;
		nodes = new TreeMap<T, GraphNode<T>>();
	}
	
	public int getNodeCount() {
		return nodeCount;
	}

	public void setNodeCount(int nodeCount) {
		this.nodeCount = nodeCount;
	}

	public void addNode (T data) {
		nodes.put(data, new GraphNode<T>(data));
		nodeCount++;
	}
	
	public void print (T key) {
		GraphNode<T> node = nodes.get(key);
		node.printEdges();
	}
	
	public void printAll (T key) {
		GraphNode<T> node = nodes.get(key);
		LinkedList<GraphNode<T>> edges = node.returnEdges();
		for (GraphNode<T> itNode : edges) {
			itNode.printEdges();
		}
	}
	
	public void addEdge (T from, T to) {
		GraphNode<T> fromNode = nodes.get(from);
		GraphNode<T> toNode = nodes.get(to);
		try {
			if (!fromNode.containsEdge(toNode)) {
				fromNode.addEdge(toNode);
				edgeCount++;
			}
		} catch (Exception ex) {
			System.err.println(ex.getMessage());
			System.err.println("Exception adding edge from " + from + " to " + to);
		}
	}
	
	public int getEdgeCount() {
		return edgeCount;
	}
	
	public void clear() {
		Iterator<Entry<T, GraphNode<T>>> it = nodes.entrySet().iterator();
		while (it.hasNext()) {
			Map.Entry<T, GraphNode<T>> pair = (Map.Entry<T, GraphNode<T>>)it.next();
			pair.getValue().clearEdges();
			it.remove();
		}
		nodes.clear();
		nodeCount = 0;
		edgeCount = 0;
	}

	public Queue<GraphNode<T>> BFS (T from) {
		System.out.println("BFS");
		Queue<GraphNode<T>> traversal = new ArrayDeque<GraphNode<T>>();
		Map<T, Boolean> visited = new HashMap<T, Boolean>(nodeCount);
		LinkedList<GraphNode<T>> Q = new LinkedList<GraphNode<T>>();
		GraphNode<T> node = nodes.get(from);
		Q.addFirst(node);
		while (!Q.isEmpty()) {
			GraphNode<T> front = Q.pop();
			System.out.println("Visited " + front.getData());
			traversal.add(front);
			for (GraphNode<T> itNode : front.returnEdges()) {
				if (!visited.containsKey(itNode.getData())) {
					visited.put(front.getData(), true);
					Q.add(itNode);
				}
			}
		}
		return traversal;
	}
	
	public void DFS (GraphNode<T> vertex, Map<T, Boolean> visited) {
		System.out.println("Visited " + vertex.getData());
		visited.put(vertex.getData(), true);
		for (GraphNode<T> itNode : vertex.returnEdges()) {
			if (!visited.containsKey(itNode.getData())) {
				DFS(itNode, visited);
			}
		}
	}
	
	public void DFS (T from) {
		System.out.println("DFS");
		Map<T, Boolean> visited = new HashMap<T, Boolean>(nodeCount);
		GraphNode<T> vertex = nodes.get(from);
		DFS(vertex, visited);
	}
	
	public GraphNode<T> copy (T key) {
		GraphNode<T> copyNode = new GraphNode<T>(key);
		GraphNode<T> origNode = nodes.get(key);
		LinkedList<GraphNode<T>> Q = new LinkedList<GraphNode<T>>();
		Q.addFirst(origNode);
		while (!Q.isEmpty()) {
			GraphNode<T> front = Q.pop();
			GraphNode<T> newNode = new GraphNode<T>(front.getData());
			for (GraphNode<T> itNode : front.returnEdges()) {
				if (!newNode.containsEdge(itNode)) {
					System.out.println("Added edge to " + itNode.getData() + " from node " + front.getData());
					newNode.addEdge(itNode);
					Q.push(itNode);
				}
			}
		}
		return copyNode;
	}
	
}
