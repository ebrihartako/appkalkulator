using System;



    class Program
    {
        static void Main(string[] args)
        {
         
        
            int pilihan=0;
            int a=0, b=0;
            
            Console.WriteLine("Pilihan menu kalkulator");
            Console.WriteLine( );
            Console.WriteLine("1.Penambahan");
            Console.WriteLine("2.Pengurangan");
            Console.WriteLine("3.Perkalian");
            Console.WriteLine("4.Pembagian");
            Console.WriteLine( );
            Console.WriteLine(" Silahkan Masukan pilihan = ");
            pilihan= int.Parse(Console.ReadLine());
            
            if (pilihan==1)
            {
                Console.WriteLine("inputkan nilai a = ");
                a=int.Parse(Console.ReadLine());
                Console.WriteLine("inputkan nilai b = ");
                b=int.Parse(Console.ReadLine());
                Console.WriteLine("Hasil Penambahan " + a + " + " + b + " = " + Penambahan(a, b));
            }
            
            else if (pilihan==2)
            {
                Console.WriteLine("inputkan nilai a = ");
                a=int.Parse(Console.ReadLine());
                Console.WriteLine("inputkan nilai b = ");
                b=int.Parse(Console.ReadLine());
                Console.WriteLine("Hasil Pengurangan {0} - {1} = {2}", a, b, Pengurangan(a, b));
            }
            
            else if (pilihan==3)
            {
                Console.WriteLine("inputkan nilai a = ");
                a=int.Parse(Console.ReadLine());
                Console.WriteLine("inputkan nilai b = ");
                b=int.Parse(Console.ReadLine());
                Console.WriteLine("Hasil Perkalian {0} * {1} = {2}", a, b, perkalian(a, b));
            }
            else if (pilihan==4)
            {
                Console.WriteLine("inputkan nilai a = ");
                a=int.Parse(Console.ReadLine());
                Console.WriteLine("inputkan nilai b = ");
                b=int.Parse(Console.ReadLine());
                Console.WriteLine("Hasil Pembagian {0} / {1} = {2}", a, b, pembagian(a, b));
            }
            else 
            {
                Console.WriteLine("Maaf, menu yang anda pilih tidak tersedia");
            }
                 
            
            Console.WriteLine("\nTekan sembarang key untuk keluar");
            Console.ReadKey();
          
        }
        static int Penambahan(int a, int b)
        {
            return a + b;
        }
        static int Pengurangan(int a, int b)
        {
            return a - b;
        }
        static int perkalian(int a, int b)
        {
            return a * b;
        }
        static int pembagian(int a, int b)
        {
            return a / b;
        }
    }

        
    

