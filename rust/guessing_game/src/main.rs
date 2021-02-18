use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Guess a number from 1 to 10");

    let number = rand::thread_rng().gen_range(1..10);

    println!("Psst, BTW the secret numb is: {}", number);

    
    loop{
        let mut guess = String::new();
        println!("Your guess? ");
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read");

        println!("Your guess {}", guess);

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&number){
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("Just right!");
                break;
            }
        }
    }
}
