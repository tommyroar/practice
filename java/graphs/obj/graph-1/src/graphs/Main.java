package graphs;

public class Main {

	public static void main(String[] args) {
			Graph<Integer> g = new Graph<Integer>();
			g.addNode(6);
			g.addNode(7);
			g.addNode(72);
			g.addNode(17);
			g.addNode(37);
			g.addNode(74);
			g.addNode(8);
			g.addEdge(6, 7);
			g.addEdge(6, 72);
			g.addEdge(6, 17);
			g.addEdge(6, 37);
			g.addEdge(7, 8);
			g.addEdge(8, 7);
			g.print(6);
			g.printAll(6);
			g.BFS(6);
			g.DFS(6);
	}

}
