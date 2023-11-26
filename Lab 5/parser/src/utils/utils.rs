use std::io::{self, Write};

const GRAMMAR_FILE_PATH: &str = "input/";
const GRAMMAR_EXTENSION: &str = ".in";

// gets the path to the grammar folder
pub fn get_grammar_folder() -> String {
    String::from(GRAMMAR_FILE_PATH)
}

// constructs the full path for a given grammar file
pub fn get_grammar_path(file_name: &str) -> String {
    format!("{}{}{}", GRAMMAR_FILE_PATH, file_name, GRAMMAR_EXTENSION)
}

// reads a usize value from user input, prompting with the given message
pub fn read_usize(prompt: &str) -> usize {
    loop {
        if let Ok(input) = prompt_and_read(prompt) {
            match input.trim().parse() {
                Ok(number) => return number,
                Err(_) => println!("ERROR: Invalid input! Please enter a number."),
            }
        }
    }
}

// reads a String value from user input, prompting with the given message
pub fn read_string(prompt: &str) -> String {
    loop {
        if let Ok(input) = prompt_and_read(prompt) {
            return input.trim().to_string();
        }
    }
}

// prompts the user and reads the input line
fn prompt_and_read(prompt: &str) -> Result<String, String> {
    display_prompt(prompt).map_err(|e| e.to_string())?;
    read_line()
}

// reads a line from the standard input
fn read_line() -> Result<String, String> {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .map(|_| line)
        .map_err(|e| format!("ERROR: Read failed: {}", e))
}

// prints a prompt to the standard output and flushes it
fn display_prompt(prompt: &str) -> Result<(), String> {
    print!("{} ", prompt);
    io::stdout()
        .flush()
        .map_err(|e| format!("ERROR: Flush failed: {}", e))
}
