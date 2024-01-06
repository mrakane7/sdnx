// Wait for the DOM content to load
document.addEventListener('DOMContentLoaded', (event) => {
    // Select the dropdown, menu, and caret elements
    const select = document.querySelector('.dropdown');
    const menu = document.querySelector('.menu');
    const caret = document.querySelector('.caret');

    // Add a click event listener to the dropdown
    select.addEventListener('click', function() {
        // Toggle the 'dropdown-clicked', 'menu-open' and 'caret-rotate' classes respectively on the dropdown, menu and caret
        this.classList.toggle('dropdown-clicked');
        menu.classList.toggle('menu-open');
        caret.classList.toggle('caret-rotate');
    });

    // Select all the menu items
    const menuItems = document.querySelectorAll('.menu li');
    // For each menu item...
    menuItems.forEach((item) => {
        // Add a click event listener
        item.addEventListener('click', function() {
            const selected = document.querySelector('.selected');

            // Set the text content of the 'selected' element to the text content of the clicked menu item
            selected.textContent = this.textContent;
            // Remove the 'dropdown-clicked', 'menu-open' and 'caret-rotate' classes respectively on the dropdown, menu and caret
            select.classList.remove('dropdown-clicked');
            menu.classList.remove('menu-open');
            caret.classList.remove('caret-rotate');
        });
    });
});
