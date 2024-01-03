$(document).ready(function() {
  // Check if dark mode preference is stored in local storage
  var isDarkMode = localStorage.getItem("darkMode") === "true";
  
  // Set initial dark mode state
  if (isDarkMode) {
    $("body").addClass("dark-mode");
    $(".switch").addClass("fa-moon").removeClass("fa-sun");
    logo.src = "src-tauri/icons/logo-dark.png";
  }
  
  // Toggle dark mode on switch click
  $(".switch").click(function() {
    $("body").toggleClass("dark-mode");
  
    // Update dark mode preference in local storage
    localStorage.setItem("darkMode", $("body").hasClass("dark-mode"));
  
    if ($("body").hasClass("dark-mode")) {
      $(".switch").toggleClass("fa-sun fa-moon");
      logo.src = "src-tauri/icons/logo-dark.png";
      document.getElementsByClassName("logo").style.translateX = 28;
    } else {
      $(".switch").toggleClass("fa-moon fa-sun");
      logo.src = "src-tauri/icons/logo-light.png";
    }
  });
});  
