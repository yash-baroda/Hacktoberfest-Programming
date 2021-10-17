public class LPS {

    public int findLPSLength(String st) {
      return findLPSLengthRecursive(st, 0, st.length()-1);
    }
  
    private int findLPSLengthRecursive(String st, int startIndex, int endIndex) {
      if(startIndex > endIndex)
        return 0;
        if(startIndex == endIndex)
        return 1;
        if(st.charAt(startIndex) == st.charAt(endIndex))
        return 2 + findLPSLengthRecursive(st, startIndex+1, endIndex-1);
        int c1 = findLPSLengthRecursive(st, startIndex+1, endIndex);
        int c2 = findLPSLengthRecursive(st, startIndex, endIndex-1);
        return Math.max(c1, c2);
    }
      public static void main(String[] args) {
      System.out.println("Rohan Godha HactoberFest 2021 Question");
      LPS lps = new LPS();
      System.out.println(lps.findLPSLength("abdbca"));
      System.out.println(lps.findLPSLength("cddpd"));
      System.out.println(lps.findLPSLength("pqr"));
    }
  }
