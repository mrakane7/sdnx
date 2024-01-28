document.querySelector('.checkbox').addEventListener('click', function() {
    const checkmark = this.querySelector('.fas');
    if (checkmark.style.display === 'none') {
        checkmark.style.display = 'block';
    } else {
        checkmark.style.display = 'none';
    }
});
