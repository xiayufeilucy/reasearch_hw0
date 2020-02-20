use std :: env;
use std :: fs :: File;
use std :: io :: prelude :: *;
use std::io::{BufRead, BufReader};
use std::str::FromStr;

fn main() {
    let args : Vec<String> = env :: args().collect();
    let input_file_name = args[1].clone();
    let output_file_name = args[2].clone();
    let n : i32 = args[3].clone().parse().unwrap();

    let input_file = File :: open (input_file_name). expect ("Cannot open input file!");
    let mut output_file = File :: create (output_file_name). expect ("Cannot open output file!");

    let reader = BufReader::new(input_file);

    for (index, line) in reader.lines().enumerate() {
        let int : i32 = line.unwrap().parse().unwrap();
        if int < n{
            let mut to_write = int.to_string();
            write!(output_file, "{} \n", to_write);
        }
    }
    
}
