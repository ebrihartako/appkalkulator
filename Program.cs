using System;

namespace LatihanPolymorphism
{
    class Program
    {
        static void Main(string[] args)
        {
            PrinterWindows printer;

            Console.WriteLine("Pilih Printer:");
            Console.WriteLine("1. Lg");
            Console.WriteLine("2. Canon");
            Console.WriteLine("3. Samsung\n");

            Console.Write("Nomor Printer [1..3]: ");
            int nomorPrinter = Convert.ToInt32(Console.ReadLine());

            if (nomorPrinter == 1)
            {
                printer = new Lg();
            }
            else if (nomorPrinter == 2)
            {
                printer = new Canon();
            }
            else
            {
                printer = new Samsung();
            }

            printer.Show();
            printer.Print();

        }
    }
}
