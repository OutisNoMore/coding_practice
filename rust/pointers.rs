fn main(){
    let x: i32 = 1;
    let y = x;
    //both same value, different mem address
    println!("X: {} Y: {}", x, y);

    let s1 = String::from("hello");
    let s2 = s1;
    //s1 becomes invalid/dropped, only s2 exists and points to char array initialized by s1
    let str1 = "world";
    let str2 = str1.clone(); // now both str1 and str2 exist diff mem address
    println!("str1: {}, str2: {}", str1, str2);
    let mut ms1 = String::from("hi");
    changeString(&mut ms1); //have to pass mem address

    let mut a = String::from("help");
    let e = &mut a; //holds a memory address to a, and can change as mutable
    *e = String::from("hello"); //must dereference memory address
    println!("A: {}", a); //a is changed to hello
    a = String::from("me");
    println!("A: {}", a);
    //println!("e: {}", e);// cannot call e because 
    let b = &a;
    let c = &a;
//    let d = &mut a; //problem, can't change a because there are other references 
}

fn changeOwner(string: String){
    //because copy of string is created, original string disappears
    //local variable/parameter also gets lost after function ends
}

//pass by reference, pass the memory address to where string exists in heap
fn reference(string: &String){
//original string still exists
//don't need to dereference
}

fn changeString(string: &mut String){
    //must pass by mutable refernce in order to change
}
