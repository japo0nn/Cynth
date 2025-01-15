func main(){
    int a = 123;
    int b = 321;

    print(a + b);

    Person person_1 = new();
    person_1.age = 18;
    person_2.name = "Eddie";

    Person person_2 = new(20, "John Doe");
}

struct Person{
    int age;
    string name;

    Person(int age, string name){
        this.age = age;
        this.name = name;
    }
}
