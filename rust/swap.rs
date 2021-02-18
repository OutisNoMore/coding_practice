//& is by reference, but is more like just a pointer, expects a mem address
fn swap(a: &mut i32, b: &mut i32){
    let temp = *b;
    *b = *a;
    *a = temp;
}

//even though is memory address, can call its functions/attributes without dereferencing
//no need for x->len() like in c++
fn add(x: &String) -> usize {
    x.len()
}

fn main(){
    let mut i1 = 1;
    let mut i2 = 2;
    println!("i1: {}, i2: {}", i1, i2);

    let str1 = String::from("abc");
    println!("Length: {}", add(&str1)); //give memory address of str1
    //& is pass memory address
    swap(&mut i1, &mut i2);

    println!("After swap\n i1: {}, i2: {}", i1, i2);
}
