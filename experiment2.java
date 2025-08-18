

import java.util.*;

class experiment2{

  static float disc(float a, float b, float c){
    return (float)(b*b-4*a*c);
  }
  static float root1(float a, float b, float d){
    return (float)((-b+Math.sqrt(d)/2*a));
  }
  static float root2(float a, float b, float d){
    return (float)((-b-Math.sqrt(d)/2*a));
  }

  public static void main(String[] args){
    float r1, r2, a, b, c, d;
    Scanner obj = new Scanner(System.in);
    a = obj.nextFloat();
    b = obj.nextFloat();
    c = obj.nextFloat();
    obj.close();
    d = disc(a,b,c);
    if(d<0){
      System.out.println("Roots are unreal");
    }
    else if(d==0){
      System.out.println("Roots are real and equal");
      r1 = root1(a, b, d);
      r2 = root2(a, b, d);
      System.out.println("first root: " + r1 + "second rooot: "+r2);
    }
    else{
      System.out.println("Roots are real and unequal");
      r1 = root2(a, b, d);
      r2 = root2(a, b, d);
      System.out.println("First root: " + r1 + " Second root: " + r2);
    }
  }
  
}