package com.java.tmy.practice.maze;

import java.util.*;

public class MazeCell {
	
	private Set<Wall> walls;
    
	MazeCell () {
        walls = EnumSet.allOf(Wall.class);
    }
	
    public void cutWall (Wall w) {
        walls.remove(w);
    }
    
    public boolean hasWall (Wall w) {
        return walls.contains(w);
    }
    
    public boolean unset () {
        return walls.containsAll(EnumSet.allOf(Wall.class));
    }

	enum Wall {
	    N (0, -1),
	    S (0, 1),
	    E (1, 0),
	    W (-1, 0);
	    private Wall opposite;
	    private final int dx;
	    private final int dy;
	    Wall (int dx, int dy) {
	        this.dx = dx;
	        this.dy = dy;
	    }
	    static {
	        N.opposite = S;
	        S.opposite = N;
	        E.opposite = W;
	        W.opposite = E;
	    }
	    public final int dx () {
	        return this.dx;
	    }
	    public final int dy () {
	        return this.dy;
	    }
	    public final Wall opposite () {
	        return this.opposite;
	    }
	}
}
