mod models;
mod tests;

use models::parser::Parser;

fn main() {
    println!("The LL(1) Parser is not implemented yet.");
    let parser = Parser::new("input/grammar.in").unwrap();

    // sort non terminals by key
    let mut non_terminals: Vec<&String> = parser.get_non_terminals().iter().collect();
    non_terminals.sort();

    print!("\n{} Non Terminals: ", non_terminals.len());
    println!(
        "{}",
        non_terminals
            .iter()
            .map(|s| format!("'{}'", s))
            .collect::<Vec<String>>()
            .join(", ")
    );

    // sort terminals by key but keep shorter terminals first
    let mut terminals: Vec<&String> = parser.get_terminals().iter().collect();
    terminals.sort_by(|a, b| {
        if a.len() == b.len() {
            return a.cmp(b);
        }
        if a.len() < b.len() {
            return std::cmp::Ordering::Less;
        }
        std::cmp::Ordering::Greater
    });

    print!("\n{} Terminals: ", terminals.len());
    println!(
        "{}",
        terminals
            .iter()
            .map(|s| format!("'{}'", s))
            .collect::<Vec<String>>()
            .join(", ")
    );

    println!("\nStart Symbol: '{}'", parser.get_start_symbol());

    // sort productions by key
    let mut productions: Vec<(&String, &Vec<String>)> = parser.get_productions().iter().collect();
    productions.sort_by(|a, b| a.0.cmp(b.0));

    print!("\n{} Productions:\n", productions.len());
    for (non_terminal, production) in productions {
        println!(
            "  '{}': {}",
            non_terminal,
            production
                .iter()
                .map(|s| format!("'{}'", s))
                .collect::<Vec<String>>()
                .join(", ")
        );
    }

    println!("\ngrammar is context free: {}", parser.is_context_free());

    let parser = Parser::new("input/pass_1.in").unwrap();
    println!("\npass_1 is context free: {}", parser.is_context_free());

    let parser = Parser::new("input/pass_2.in").unwrap();
    println!("pass_2 is context free: {}", parser.is_context_free());

    let parser = Parser::new("input/fail_1.in").unwrap();
    println!("fail_1 is context free: {}", parser.is_context_free());

    let parser = Parser::new("input/fail_2.in").unwrap();
    println!("fail_2 is context free: {}", parser.is_context_free());
}
