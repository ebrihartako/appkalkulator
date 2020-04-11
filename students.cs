namespace baru.LatihanInheritance
{
    public class Student : Person

    { 
        public Student(string name, int age,string studentid,string email)
        :base(name,age)
        {
            StudentId=studentid;
            Email=email;
        }

        public string StudentId {get; set;}
        public string Email {get; set;}

    }
}