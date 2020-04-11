using System;
namespace baru.LatihanInheritance
{
    public class Teacher : Person 
    {   
        public Teacher(string name,int age,string teacherid,string subject)
        :base(name,age)
        {
            TeacherId=teacherid;
            Subject=subject;
        }

        public string TeacherId {get; set;}
        public string  Subject {get; set;}
        
    }
}