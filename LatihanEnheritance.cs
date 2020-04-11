namespace baru.LatihanInheritance
{
    public class Program
    {

        static void Main( string[] args )
        {
            Person person = new Person("joko",19);
            person.GetNameAndAge();

            Teacher teacher = new Teacher("Doni",30,"3123","Math");
            teacher.GetNameAndAge();

            Student student = new Student("Dian",20,"2314","Diansastro@gmail.com");
            student.GetNameAndAge();
        }
    }
}