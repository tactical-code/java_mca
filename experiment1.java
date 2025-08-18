

import java.util.*;

class experiment1{
  public static void main(String[] args){
    float r1, r2, a, b, c, d;
    Scanner obj = new Scanner(System.in);
    a = obj.nextFloat();
    b = obj.nextFloat();
    c = obj.nextFloat();
    obj.close();
    d = (float)(b*b*4*a*c);
    if(d<0){
      System.out.println("Roota are unreal");
    }
    else if(d==0){
      System.out.println("Roots are real and unequal");
      r1 = (float)(-b/2*a);
      r2 = (float)(-b/2*a);
      System.out.println("first root: " + r1 + "second rooot: "+r2);
    }
    else{
      System.out.println("Roots are real and unequal");
      r1 = (float)((-b+Math.sqrt(d)/2*a));
      r2 = (float)((-b-Math.sqrt(d)/2*a));
      System.out.println("First root: " + r1 + " Second root: " + r2);
    }
  }

}