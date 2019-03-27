import java.util.concurrent.Semaphore;

public class readerwriter

	

{

	static int readcount=0;

	static Semaphore s= new Semaphore(1);

	static Semaphore wrt= new Semaphore(1); 


	static class reader implements Runnable

		

		{

			public void run()

			{

				try

				{

					s.acquire();

					readcount++;

					if(readcount==1)

					wrt.acquire();

					s.release();


					System.out.println(Thread.currentThread()+"reading");

					Thread.sleep(1000);

					System.out.println(Thread.currentThread()+"finished");


					s.acquire();

					readcount--;

					if(readcount==0)

					wrt.release();	

					s.release();

				}

				catch(Exception e)

				{

					System.out.println("exception occured");

				}		

			}

		}

	static class writer implements Runnable

	     

		{

			 public void run()

			{

				 try

				 {

					 wrt.acquire();

					 System.out.println(Thread.currentThread()+"writting");

					 Thread.sleep(1000);

					 System.out.println(Thread.currentThread()+"finished");

					 wrt.release();

				 }

				 catch(Exception e)

				 {

					 System.out.println("exception occured");

				 }

			}

		}

	

	public static void main(String []args)

	{

		reader r1=new reader();

		reader r2=new reader();

		reader r3=new reader();

		reader r4=new reader();

		writer w1=new writer();

		writer w2=new writer();

		writer w3=new writer();

		Thread t1=new Thread(r1);

		Thread t2=new Thread(r2);

		Thread t3=new Thread(r3);

		Thread t4=new Thread(r4);

		Thread t5=new Thread(w1);

		Thread t6=new Thread(w2);

		Thread t7=new Thread(w3);

		t1.start();

		t2.start();

		t3.start();

		t4.start();

		t5.start();

		t6.start();

		t7.start();

	}

}


