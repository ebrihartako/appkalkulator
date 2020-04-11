using System;
namespace baru.LatihanInheritance
{
    public class Person
    {   
        public Person(string name, int age)
        {
            Name=name;
            Age=age;
        }

        public string Name{get; set;}
        public int Age{get; set;}

        public void GetNameAndAge()
        {
            Console.WriteLine("Person has name : {0} and age : {1} ", Name, Age);
        }

    }
}