fn main(){
    println!("helo world");
    let x = 6; // immutable/constant by default
    let x = 7; // this is allowed, shadowing x
    let x = "a"; // legal bcause we are creating new variable
    // x = 1; // illegal
    let mut y = 7; //declare/specify y is mutable
    y = 6; //legal
//    y = "a"; // illegal because y is already typed as int, strong, static typing
    //data types: i32..., u32... String, bool, f32, 
    let z: i32 = 15;
    let a: String = "ab".to_string(); //"ab" considered a &str
    let b: f32 = 2.2;
    let c: bool = false;
    //arrays
    let d = [1, 2, 3,4];
    //tuples
    let e: (i32, f64, u8) = (500, 1.2, 1);
    let f: i32 = e.0; //500
    let g: i32 = {
        let s = z + e.0;
        s
    };
    println!("x: {}, y: {}", x, y);
    sum(1, 2);
    sum(e.0, z);
}

// has two signed 32 bit int parameters: x, y
// returns a signed 32 bit int
fn sum(x: i32, y: i32) -> i32{
    println!("The sum is: {}", x +y);
//    x + y //has to have no semicolon or else considered a statement/ won't return
    return x + y; //this is ok
}
