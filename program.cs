using System;

namespace ResponsiPemograman2895
{
    class Program
    {
        static void Main(string[] args)
        {
            int gaji1;
            int gaji2;
            karyawan Karyawan1 = new karyawan("1234","Ebri",3000000);
            karyawan Karyawan2 = new karyawan("4321","Po",4000000);
            Console.WriteLine("No Nik/nama \t\tGaji Bulanan");
            Console.WriteLine("---------------------------------------");
            Console.WriteLine("1. "+Karyawan1.nik+" "+Karyawan1.nama+"\t\t"+Karyawan1.gajiBulanan);
            Console.WriteLine("1. "+Karyawan2.nik+" "+Karyawan2.nama+"\t\t"+Karyawan2.gajiBulanan);
            Console.WriteLine("\n\nAsyiik Ada Kenaikan Gaji 10%!!");
            gaji1=(10*Karyawan1.gajiBulanan)/100;
            gaji2=(10*Karyawan2.gajiBulanan)/100;
            Console.WriteLine("No Nik/nama \t\tGaji Bulanan");
            Console.WriteLine("---------------------------------------");
            Console.WriteLine("1. "+Karyawan1.nik+" "+Karyawan1.nama+"\t\t"+(gaji1+Karyawan1.gajiBulanan));
            Console.WriteLine("1. "+Karyawan2.nik+" "+Karyawan2.nama+"\t\t"+(gaji2+Karyawan2.gajiBulanan));
        }
    }
}