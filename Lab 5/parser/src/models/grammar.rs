use std::collections::{HashMap, HashSet};

use std::fs::File;
use std::io::{self, BufRead, BufReader};

use crate::errors::grammar_error::GrammarError;

pub struct Grammar {
    non_terminals: HashSet<String>,
    terminals: HashSet<String>,
    productions: HashMap<String, Vec<String>>,
    start_symbol: String,
}

impl Grammar {
    pub fn new(file_path: &str) -> Result<Self, String> {
        let mut grammar = Self {
            non_terminals: HashSet::new(),
            terminals: HashSet::new(),
            start_symbol: String::new(),
            productions: HashMap::new(),
        };

        match grammar.parse_file(file_path) {
            Ok(_) => Ok(grammar),
            Err(err) => Err(err.to_string()),
        }
    }

    pub fn get_non_terminals(&self) -> &HashSet<String> {
        &self.non_terminals
    }

    pub fn get_terminals(&self) -> &HashSet<String> {
        &self.terminals
    }

    pub fn get_start_symbol(&self) -> &String {
        &self.start_symbol
    }

    pub fn get_productions(&self) -> &HashMap<String, Vec<String>> {
        &self.productions
    }

    // get productions for a given non-terminal
    pub fn get_productions_for(&self, non_terminal: &str) -> Result<&Vec<String>, GrammarError> {
        match self.productions.get(non_terminal) {
            Some(productions) => Ok(productions),
            None => {
                let error = format!("No productions found for non-terminal '{}'.", non_terminal);
                return Err(GrammarError::ParseError(error));
            }
        }
    }

    pub fn cfg_check(&self) -> bool {
        // check if left hand side of each production is a non-terminal
        for (lhs, _) in &self.productions {
            if !self.non_terminals.contains(lhs) {
                return false;
            }
        }

        true
    }

    fn parse_file(&mut self, file_path: &str) -> Result<(), GrammarError> {
        let file = match File::open(file_path) {
            Ok(file) => file,
            Err(err) => {
                let error = format!("Could not open grammar file!\n {}.", err);
                return Err(GrammarError::ParseError(error));
            }
        };

        let reader = BufReader::new(file);
        let mut lines = reader.lines();

        // read non-terminals
        match self.parse_non_terminals(lines.next().map(|r| r.map_err(GrammarError::IOError))) {
            Ok(_) => (),
            Err(err) => return Err(err),
        }

        // read terminals
        match self.parse_terminals(lines.next().map(|r| r.map_err(GrammarError::IOError))) {
            Ok(_) => (),
            Err(err) => return Err(err),
        }

        // read start symbol
        match self.parse_start_symbol(lines.next().map(|r| r.map_err(GrammarError::IOError))) {
            Ok(_) => (),
            Err(err) => return Err(err),
        }

        // read productions
        match self.parse_productions(lines) {
            Ok(_) => (),
            Err(err) => return Err(err),
        }

        Ok(())
    }

    fn parse_non_terminals(
        &mut self,
        non_terminals: Option<Result<String, GrammarError>>,
    ) -> Result<(), GrammarError> {
        match non_terminals {
            Some(Ok(line)) => {
                line.split_whitespace().for_each(|nt| {
                    self.non_terminals.insert(nt.to_string());
                });
                Ok(())
            }

            Some(Err(e)) => Err(e),
            None => {
                let error = format!("Missing set of non-terminals.");
                return Err(GrammarError::ParseError(error));
            }
        }
    }

    fn parse_terminals(
        &mut self,
        terminals: Option<Result<String, GrammarError>>,
    ) -> Result<(), GrammarError> {
        match terminals {
            Some(Ok(line)) => {
                line.split_whitespace().for_each(|nt| {
                    self.terminals.insert(nt.to_string());
                });
            }

            Some(Err(err)) => return Err(err),
            None => {
                let error = format!("Missing set of terminals.");
                return Err(GrammarError::ParseError(error));
            }
        }

        // validate terminals and non-terminals
        match self.validate_terminals() {
            Ok(_) => Ok(()),
            Err(err) => return Err(err),
        }
    }

    fn parse_start_symbol(
        &mut self,
        start_symbol: Option<Result<String, GrammarError>>,
    ) -> Result<(), GrammarError> {
        match start_symbol {
            Some(Ok(line)) => {
                self.start_symbol = line.trim().to_string();
            }

            Some(Err(err)) => return Err(err),
            None => {
                let error = format!("Missing start symbol.");
                return Err(GrammarError::ParseError(error));
            }
        }

        // validate start symbol
        match self.validate_start_symbol() {
            Ok(_) => Ok(()),
            Err(err) => return Err(err),
        }
    }

    fn parse_productions(&mut self, lines: io::Lines<BufReader<File>>) -> Result<(), GrammarError> {
        for line_result in lines {
            let line = line_result
                .map_err(|e| GrammarError::ParseError(format!("Error reading line: {}", e)))?;
            let line = line.trim();

            // skip empty lines
            if line.is_empty() {
                continue;
            }

            // replace \r\n with \n in case of Windows-style line endings
            let line = line.replace("\r\n", "\n");

            // parse the line into productions
            let parts: Vec<&str> = line.split("->").collect();
            if parts.len() != 2 {
                let error = format!("Invalid production format in line: {}", line);
                return Err(GrammarError::ParseError(error));
            }

            let lhs = parts[0].trim().to_string();
            let rhs = parts[1].trim().to_string();

            self.productions
                .entry(lhs)
                .or_insert_with(Vec::new)
                .push(rhs);
        }

        // check if any productions were found
        if self.productions.is_empty() {
            return Err(GrammarError::ParseError(format!(
                "Missing set of productions"
            )));
        }

        // validate productions
        match self.validate_productions() {
            Ok(_) => Ok(()),
            Err(err) => return Err(err),
        }
    }

    fn validate_terminals(&self) -> Result<(), GrammarError> {
        for terminal in &self.terminals {
            if self.non_terminals.contains(terminal) {
                let error = format!(
                    "Symbol '{}' is defined as both a terminal and a non-terminal.",
                    terminal
                );
                return Err(GrammarError::ParseError(error));
            }
        }
        Ok(())
    }

    fn validate_start_symbol(&self) -> Result<(), GrammarError> {
        if self.start_symbol.is_empty() {
            let error = format!("The start symbol is not defined.");
            return Err(GrammarError::ParseError(error));
        }

        if !self.non_terminals.contains(&self.start_symbol) {
            let error = format!(
                "The start symbol '{}' is not a non-terminal.",
                self.start_symbol
            );
            return Err(GrammarError::ParseError(error));
        }

        Ok(())
    }

    fn validate_productions(&self) -> Result<(), GrammarError> {
        for (lhs, rhs_list) in &self.productions {
            for rhs in rhs_list {
                for symbol in rhs.split_whitespace() {
                    if !self.non_terminals.contains(symbol)
                        && !self.non_terminals.contains(&symbol[1..])   // ignore escape
                        && !self.terminals.contains(symbol)
                        && !self.terminals.contains(&symbol[1..])       // ignore escape
                        && symbol != "|"
                    {
                        let error = format!("Symbol '{}' in production '{} -> {}' is neither a terminal nor a non-terminal.", symbol, lhs, rhs);
                        return Err(GrammarError::ParseError(error));
                    }
                }
            }
        }
        Ok(())
    }
}
