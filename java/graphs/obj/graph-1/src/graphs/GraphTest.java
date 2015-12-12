package graphs;

import static org.junit.Assert.*;

import java.util.Queue;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class GraphTest<T> {
	
	private Graph<Integer> g;

	@Before
	public void setUp() throws Exception {
		g = new Graph<Integer>();
	}

	@Test
	public void testPrint() {
		fail("Not yet implemented");
	}
	
	@Test 
	public void testAddNode() {
		g.addNode(1);
		g.addNode(2);
		org.junit.Assert.assertTrue(g.getNodeCount() == 2);
		g.addNode(3);
		g.addNode(5);
		g.addNode(134);
		g.addNode(22);
		g.addNode(1314);
		g.addNode(514);
		org.junit.Assert.assertTrue(g.getNodeCount() == 8);
		g.clear();
	}

	@Test
	public void testAddEdge() {
		g.addNode(1);
		g.addNode(2);
		org.junit.Assert.assertTrue(g.getNodeCount() == 2);
		g.addNode(3);
		g.addNode(5);
		g.addNode(134);
		g.addNode(22);
		g.addNode(1314);
		g.addNode(514);
		org.junit.Assert.assertTrue(g.getNodeCount() == 8);
		g.addEdge(1, 2);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 1);
		g.addEdge(1, 5);
		g.addEdge(1, 3);
		g.addEdge(1, 22);
		g.addEdge(2, 22);
		g.addEdge(2, 134);
		g.addEdge(22, 514);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 7);
		g.clear();
	}
	
	@Test
	public void testEdgeAlreadyAdded() {
		g.addNode(22);
		g.addNode(1314);
		g.addNode(514);
		org.junit.Assert.assertTrue(g.getNodeCount() == 3);
		g.addEdge(22, 514);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 1);
		g.addEdge(22, 514);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 1);
	}

	@Test
	public void testBFS() {
		g.addNode(1);
		g.addNode(2);
		org.junit.Assert.assertTrue(g.getNodeCount() == 2);
		g.addNode(3);
		g.addNode(5);
		g.addNode(134);
		g.addNode(22);
		g.addNode(1314);
		g.addNode(514);
		org.junit.Assert.assertTrue(g.getNodeCount() == 8);
		g.addEdge(1, 2);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 1);
		g.addEdge(1, 5);
		g.addEdge(1, 3);
		g.addEdge(1, 22);
		g.addEdge(2, 22);
		g.addEdge(2, 134);
		g.addEdge(22, 514);
		org.junit.Assert.assertTrue(g.getEdgeCount() == 7);
		Queue<GraphNode<Integer>> q = g.BFS(0);
		org.junit.Assert.assertTrue(q.size() == 8);
		g.clear();
	}

	@Test
	public void testDFS() {
		fail("Not yet implemented");
	}

}
