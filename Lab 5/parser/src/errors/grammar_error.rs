use std::fmt;

pub enum GrammarError {
    IOError(std::io::Error),
    ParseError(String),
}

impl fmt::Display for GrammarError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            GrammarError::IOError(ref err) => write!(f, "I/O ERROR: {}", err),
            GrammarError::ParseError(ref desc) => write!(f, "FILE ERROR: {}", desc),
        }
    }
}

impl From<std::io::Error> for GrammarError {
    fn from(err: std::io::Error) -> Self {
        GrammarError::IOError(err)
    }
}
