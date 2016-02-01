package com.tmy.text;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void stringMatch (String txt, String pat) {
      int i=0;
      int j=0;
      System.out.println("Searching for string [" + pat + "] in codex:");
      System.out.println(txt);
      for (i=0; i<(txt.length() - pat.length()); i++) {
        for (j=0; j<pat.length(); j++) {
          if (txt.charAt(i+j) != pat.charAt(j)) {
            break;
          }
        }
        if (j == pat.length()) {
          System.out.println("Pattern found at index " + i);
        }
      }
    }

    public static void main( String[] args )
    {
      String txt = "the wind that shakes the barley";
      String pat = "wind";
      
      stringMatch(txt, pat);
    }
}
