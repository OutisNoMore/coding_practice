fn fibo(terms: i32) -> i32{
    if terms <= 1 {
         return terms;
    }

    fibo(terms-1) + fibo(terms-2)
}

fn main(){
    println!("Please enter terms: ");
    let mut n = String::new();
    std::io::stdin()
        .read_line(&mut n)
        .expect("fail...");

    let nth: i32 = n.trim().parse().expect("bad input!");
    let mut x: i32 = 0;
    loop {
        if nth == x {
            break;
        }
        print!("{} ", fibo(x));
        x = x + 1;
    } println!();

    x = x - 1;
    while x >= 0 {
        print!("{} ", fibo(x));
        x = x - 1;
    } println!();

    for numb in 0..nth {
        print!("{} ", fibo(numb));
    } println!();

    let str1 = String::from("who are");
    //in str1 at index , there is character 
    for (index, character) in str1.chars().enumerate() { 
        println!("index: {} value: {}", index, character);
    }

    for character in str1.chars() {
        if character == ' ' {
            print!(" \"space\" ");
            continue;
        }
        print!("{}", character);
    } println!();

    println!("str1: {}", str1);
}
