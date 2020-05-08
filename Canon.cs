 using System;

public class Canon : PrinterWindows
{
    public override void Show()
    {
      Console.WriteLine("Canon display dimension : 4*6");  
    }
    public override void Print()
    {
        Console.WriteLine("Canon Printer is Printing ...");
    }

}