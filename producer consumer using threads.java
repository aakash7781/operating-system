//program to solve producer consumer problem using threads
import java.util.ArrayList;

public class producerconsumer{

 public static void main(String args[])
 {
     ArrayList<Integer> buffer=new ArrayList<Integer>();
     Thread t1=new Thread(new Producer(buffer));
     Thread t2=new Thread(new Consumer(buffer));
     t1.start();
     t2.start();
 }
}
class Producer implements Runnable
{
    ArrayList<Integer>b= null;
    final int limit=10;
    int i=0;
    Producer(ArrayList<Integer> buffer)
    {
       b=buffer;
    }
  public void run()
  {
      while(true)
      {
          try
          {
              i++;
              produce(i);
          }
          catch(Exception e)
          {
              System.out.println("exception occuered");
          }
      }
  }
public void produce(int i) throws InterruptedException
{
synchronized(b){
    while(b.size()==limit)
    {
        System.out.println("producer is  waiting");
        b.wait();
    }
}
synchronized(b)
{
    b.add(i);
    System.out.println("producer is producing"+b);
    Thread.sleep(100);
    b.notify();
}
}
}
class Consumer implements Runnable
{
    ArrayList<Integer> b;
    Consumer(ArrayList<Integer>buffer)
    {
        this.b=buffer;
    }
  public void run()
  {
      while(true)
      {
          try
          {
              consume();
          }
          catch(Exception e)
          {
              System.out.println("exception occuered");
          }
      }
  }
public void consume() throws InterruptedException
{
synchronized(b){
    while(b.isEmpty())
    {
        System.out.println("Consumer is  waiting");
        b.wait();
    }
}
synchronized(b)
{
   System.out.println("Consumer is consuming item"+b);
   b.remove(0);
    Thread.sleep(100);
    b.notify();
}
}
}