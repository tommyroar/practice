package com.java.tmy.maze.random;

import java.util.*;

import com.java.tmy.maze.random.MazeCell.Wall;

public class Maze {

    private int x_size;
    private int y_size;
    private ArrayList<ArrayList<MazeCell>> matCells;

    //constructor
    Maze(int y_size, int x_size) {
        this.x_size = x_size;
        this.y_size = y_size;
        matCells = new ArrayList<ArrayList<MazeCell>>();
        for (int i=0; i<y_size; i++) {
            matCells.add(new ArrayList<MazeCell>());
            for (int j=0; j<x_size; j++) {
                matCells.get(i).add(new MazeCell());
            }
        }
    }
    
    //return data structure
    public final ArrayList<ArrayList<MazeCell>> getCells () {
    	return this.matCells;
    }

    //generate a random maze
    public void generate (int cx, int cy) {
        ArrayList<Wall> walls = new ArrayList<Wall>();
        walls.add(Wall.N);
        walls.add(Wall.S);
        walls.add(Wall.E);
        walls.add(Wall.W);
        Collections.shuffle(walls);
        int nx, ny;
        for (Wall w : walls) {
            nx = cx + w.dx();
            ny = cy + w.dy();
            
            if (ny < y_size && ny >= 0 &&
                    nx < x_size && nx >= 0 &&
                    matCells.get(ny).get(nx).unset()) {
                if (matCells.get(cy).get(cx).hasWall(w)) {
                    matCells.get(cy).get(cx).cutWall(w);
                }
                if (matCells.get(ny).get(nx).hasWall(w.opposite())) {
                    matCells.get(ny).get(nx).cutWall(w.opposite());
                }
                generate(nx, ny);
            }
        }
    }
    
    //print underlying direction objects
    public void print () {
    	final char wallChar = '*';
    	final char hallChar = ' ';
        StringBuilder sbtop = new StringBuilder();
        StringBuilder sbmid = new StringBuilder();
        StringBuilder sbbot = new StringBuilder();
        System.out.println();
        for (int y=0; y<y_size; y++) {
            for (int x=0; x<x_size; x++) {
                if (y==0 || y==y_size-1) {
                    continue;
                }
                
                if (matCells.get(y).get(x).hasWall(Wall.W)) {
                    sbtop.append(wallChar);
                    sbmid.append(wallChar);
                    sbbot.append(wallChar);
                }
                else {
                    sbtop.append(wallChar);
                    sbmid.append(hallChar);
                    sbbot.append(wallChar);
                }
                
                if (matCells.get(y).get(x).hasWall(Wall.N) &&
                		matCells.get(y).get(x).hasWall(Wall.S)) {
                    sbtop.append(wallChar);
                    sbmid.append(hallChar);
                    sbbot.append(wallChar);
                }
                else if (matCells.get(y).get(x).hasWall(Wall.N)) {
                    sbtop.append(wallChar);
                    sbmid.append(hallChar);
                    sbbot.append(hallChar);
                }
                else if (matCells.get(y).get(x).hasWall(Wall.S)) {
                    sbtop.append(hallChar);
                    sbmid.append(hallChar);
                    sbbot.append(wallChar);
                }
                else {
                    sbtop.append(hallChar);
                    sbmid.append(hallChar);
                    sbbot.append(hallChar);
                }
                
                if (matCells.get(y).get(x).hasWall(Wall.E)) {
                    sbtop.append(wallChar);
                    sbmid.append(wallChar);
                    sbbot.append(wallChar);
                }
                else {
                    sbtop.append(wallChar);
                    sbmid.append(hallChar);
                    sbbot.append(wallChar);
                }
            }
            System.out.println(sbtop.toString() + '\n' + sbmid.toString() + '\n' + sbbot.toString());
            sbtop.setLength(0);
            sbmid.setLength(0);
            sbbot.setLength(0);
        }
    } //end print
    
    public static void main (String[] args) {
    	Maze mz = new Maze(10,15);
    	mz.generate(0, 0);
    	mz.print();
    }
    
} //end Maze class
