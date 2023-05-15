
import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Gautam
 */
public class MillerTest {
    
    
   public long power(long ran, long d, long n){                       // function to find rand^r%n
      long temp = 1;
      for(int i = 0; i < d; i++){
           temp *= ran;
              temp = temp % n;
      }
       return temp;
   }
           
   public boolean checkPrime(long n, int iter){     // function to check if prime or not
        if(n <=1)                           // if smaller than 2
            return false;
        if(n == 3 || n == 2)                // if 2 or 3
            return true;
        if(n%2 == 0)                        // if even
            return false;
        long r = n - 1;                     // finding n-1 if odd
       
        while(r%2 == 0)                 // finding r such that r*2^d = n-1
            r = r/2;
        
      
        for(int i = 0; i < iter; i++){ // for iterations
            long ran = ThreadLocalRandom.current().nextLong(2, n-1);      // generating random between 2 and n-1
              long d = r;
              long res = power(ran, d, n);
              while(d != n-1 && res != 1 && res != n-1){                      // keep multiplying while d
                  res = (BigInteger.valueOf(res).multiply(BigInteger.valueOf(res))).mod(BigInteger.valueOf(n)).longValue();
                  d *= 2;
              }
              if(d %2 == 0 && res != n-1)
                  return false;
        }
        return true;
    }
    public static void main(String[] args){
        MillerTest prim = new MillerTest();      // class object
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a positive integer: ");
        boolean isPrime;
        long n = s.nextLong();
        int iter = (int) n/10;                  // number of iterations
        
        isPrime = prim.checkPrime(n, iter);     // storing result    
        
        if(isPrime)
            System.out.println("The number " + n + " is prime.");
        else
            System.out.println("The number " + n + " is not prime.");
    }
}
