use crate::errors::grammar_error::GrammarError;
use crate::models::grammar::Grammar;
use crate::utils::utils::{get_grammar_folder, get_grammar_path, read_string, read_usize};

pub struct Menu {}

impl Menu {
    pub fn new() -> Self {
        Self {}
    }

    pub fn show(&self) {
        let mut grammar: Option<Grammar> = None;
        let menu_items = vec![
            "Exit",
            "Load grammar",
            "Display grammar details",
            "Find productions for a given non-terminal",
            "Context Free Grammar check",
        ];

        loop {
            self.display_menu(&menu_items, "Menu");

            let option = read_usize("\nOption:");
            match option {
                0 => {
                    println!("Exiting...");
                    break;
                }
                1 => {
                    self.load_grammar(&mut grammar);
                }
                2 => {
                    self.grammar_submenu(&grammar);
                }
                3 => {
                    self.productions_for(&grammar);
                }
                4 => {
                    self.is_cfg(&grammar);
                }
                _ => println!("ERROR: Invalid option!"),
            }
        }
    }

    fn display_menu(&self, menu: &[&str], name: &str) {
        println!("\n{}:", name);
        for (index, item) in menu.iter().enumerate() {
            println!("{}. {}", index, item);
        }
    }

    fn load_grammar(&self, grammar: &mut Option<Grammar>) {
        println!(
            "Enter the name of the grammar file from the '{}' folder, without extension.",
            get_grammar_folder().trim_end_matches('/')
        );

        let file_name = read_string("\nFile name:");
        let file_path = get_grammar_path(&file_name);

        *grammar = match Grammar::new(&file_path) {
            Ok(grammar) => Some(grammar),
            Err(e) => {
                println!("Could not load grammar!\n {}.", e);
                return;
            }
        };

        println!("INFO: Grammar loaded successfully!");
    }

    fn grammar_submenu(&self, grammar: &Option<Grammar>) {
        let grammar = match grammar {
            Some(grammar) => grammar,
            None => {
                println!("ERROR: No grammar loaded!");
                return;
            }
        };

        let menu_items = vec![
            "Back",
            "Set of non-terminals",
            "Set of terminals",
            "Start symbol",
            "Set of productions",
        ];

        loop {
            self.display_menu(&menu_items, "Grammar details");

            let option = read_usize("\nOption:");
            match option {
                0 => {
                    println!("Returning to the previous menu...");
                    break;
                }
                1 => {
                    self.display_non_terminals(grammar);
                }
                2 => {
                    self.display_terminals(grammar);
                }
                3 => {
                    self.display_start_symbol(grammar);
                }
                4 => {
                    self.display_productions(grammar);
                }
                _ => println!("ERROR: Invalid option!"),
            }
        }
    }

    fn display_non_terminals(&self, grammar: &Grammar) {
        let mut non_terminals: Vec<&String> = grammar.get_non_terminals().iter().collect();
        non_terminals.sort();

        println!("Set of non-terminals:");
        for non_terminal in non_terminals {
            println!("{}", non_terminal);
        }
    }

    fn display_terminals(&self, grammar: &Grammar) {
        let mut terminals: Vec<&String> = grammar.get_terminals().iter().collect();
        terminals.sort();

        println!("Set of terminals:");
        for terminal in terminals {
            println!("{}", terminal);
        }
    }

    fn display_start_symbol(&self, grammar: &Grammar) {
        println!("Start symbol: {}", grammar.get_start_symbol());
    }

    fn display_productions(&self, grammar: &Grammar) {
        let mut productions: Vec<(String, Vec<String>)> = grammar
            .get_productions()
            .iter()
            .map(|(key, value)| (key.clone(), value.clone()))
            .collect();

        // sort by key
        productions.sort_by(|(key1, _), (key2, _)| key1.cmp(key2));

        println!("Productions:");
        for (non_terminal, production_rules) in productions {
            for production_rule in production_rules {
                println!("{} -> {}", non_terminal, production_rule);
            }
        }
    }

    fn productions_for(&self, grammar: &Option<Grammar>) {
        let grammar = match grammar {
            Some(grammar) => grammar,
            None => {
                println!("ERROR: No grammar loaded!");
                return;
            }
        };

        let non_terminal = read_string("\nNon-terminal:");

        match grammar.get_productions_for(&non_terminal) {
            Ok(production_rules) => {
                println!("Productions for non-terminal '{}':", non_terminal);
                for production in production_rules {
                    println!("{} -> {}", non_terminal, production);
                }
            }
            Err(GrammarError::IOError(e)) => {
                println!("{}", e);
                return;
            }
            Err(GrammarError::ParseError(e)) => {
                println!("{}", e);
                return;
            }
        }
    }

    fn is_cfg(&self, grammar: &Option<Grammar>) {
        let grammar = match grammar {
            Some(grammar) => grammar,
            None => {
                println!("ERROR: No grammar loaded!");
                return;
            }
        };

        println!("Checking if the given grammar is a Context Free Grammar...\n");

        match grammar.cfg_check() {
            Ok(()) => {
                println!("Grammar is a Context Free Grammar!");
            }
            Err(e) => {
                println!("Grammar is not a Context Free Grammar!\n {}.", e);
                return;
            }
        }
    }
}
