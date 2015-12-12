package graphs;

import java.util.LinkedList;

public class GraphNode<T> {
	private T data;
	private LinkedList<GraphNode<T>> edges;
	
	public T getData() {
		return data;
	}
	
	GraphNode (T data) {
		this.data = data;
		edges = new LinkedList<GraphNode<T>>();
	}
	
	public boolean containsEdge (GraphNode<T> to) {
		return edges.contains(to);
	}
	
	public void addEdge (GraphNode<T> to) {
		edges.add(to);
	}
	
	public final LinkedList<GraphNode<T>> returnEdges () {
		return this.edges;
	}
	
	public final int degree () {
		return this.edges.size();
	}
	
	public void clearEdges () {
		edges.clear();
	}
	
	public void printEdges () {
		System.out.println("Nodes for " + data);
		for (GraphNode<T> x : edges) {
			System.out.println(x.data);
		}
	}
}
