mod errors;
mod models;
mod utils;
mod view;

use view::menu::Menu;

fn main() {
    let menu = Menu::new();
    menu.show();
}
